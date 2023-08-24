//
// Created by Piotr Krzysztof Wyrwas on 20.08.23.
//

#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "fmt.h"
#include "../parse.h"

static char lastC = 0;
static _Bool newline;

static enum status reformat_unit(struct CompilerEnv *env);

static int reformat_next(struct CompilerEnv *env);

int reformat(struct CompilerEnv *env)
{
        if (!sanity_check_env(env)) {
                return FAILURE;
        }

        enum status last_status;

        do {
                if (skip_spaces(env) == WARNING) {
                        return SUCCESS;
                }
        } while ((last_status = reformat_unit(env)) == STATUS_OK);

        if (last_status == STATUS_ERR) {
                return FAILURE;
        }

        if (!env->main_set) {
                WARN("For the program to be standalone, it requires a main unit to be set. However, in this program, no unit is marked as such.\n")
        }

        return SUCCESS;
}

static enum status reformat_unit(struct CompilerEnv *env)
{
        if (env->offset >= env->len) {
                return STATUS_EOF;
        }

        struct unit_header header;
        enum status parse_status;

        if (!(parse_status = parse_unit_header(&header, env))) {
                return STATUS_ERR;
        }

        if (parse_status == WARNING) {
                return STATUS_EOF;
        }

        char *id = header.id;
        char _id[MAX_IDEN_LENGTH];

        /* Move dynamic string to stack to save us some headache */
        strcpy(_id, id);
        free(id);

        if (unit_exists(_id, env)) {
                ERROR("The identifier of a unit must be unique: Attempted redefinition of '%s'.\n", _id);
                return STATUS_ERR;
        }

        if (!add_unit_env(env, _id)) {
                ERROR("Not enough memory to store unit '%s'. The compiler allows up to %ld unit definitions.\n",
                      id, MAX_UNITS_COUNT)
                return STATUS_ERR;
        }

        if (header.main) {
                fprintf(env->out, "&");
        }

        fprintf(env->out, "%s\n{\n", _id);

        env->indent = 1;

        newline = true;

        struct unit_call call;

        for (; env->offset < env->len; env->offset++) {
                if (skip_spaces(env) == WARNING) {
                        continue;
                }

                if (env->src[env->offset] == '@' || env->src[env->offset] == '$') {
                        char c = env->src[env->offset];

                        if (!parse_unit_call(&call, env)) {
                                return STATUS_ERR;
                        }

                        if (c == '@' && strcmp(call.id, _id) == 0) {
                                WARN("On unit call '%s' in '%s': Recursion is not recommended.\n", call.id, _id)
                        }

                        if (c == '$') {
                                WARN("On native call '%s' in '%s': It is not recommended to use native C calls; doing so may cause unexpected behaviour, as natron cannot guarantee the presence of the callee.\n",
                                     call.id, _id)
                        }

                        if (c == '@' && !unit_exists(call.id, env)) {
                                ERROR("Attempting to call undefined unit '%s' from within '%s'.\n", call.id, id)
                                free(call.id);
                                return STATUS_ERR;
                        }

                        if (!newline) {
                                fprintf(env->out, "\n");
                        }

                        fprintf(env->out, "%s%c%s\n", repeat('\t', env->indent), c, call.id);
                        newline = true;
                        free(call.id);
                        env->offset--;
                        continue;
                }
                if (env->src[env->offset] == '}') {
                        break;
                }
                if (!reformat_next(env)) {
                        return STATUS_ERR;
                }
        }

        if (env->src[env->offset] != '}') {
                ERROR("Expected '}' at the end of unit '%s'.\n", _id)
                return STATUS_ERR;
        }

        if (env->loop_ct != 0) {
                ERROR("There are unclosed loops left in the code.\n")
                return STATUS_ERR;
        }

        env->offset++; /* Skip '}' */

        if (!newline) {
                fprintf(env->out, "\n");
        }

        fprintf(env->out, "}");

        if (skip_spaces(env) != WARNING) {
                fprintf(env->out, "\n\n");
        }

        return STATUS_OK;
}

static int reformat_next(struct CompilerEnv *env)
{
        CURRENT_CHAR(c)

        static _Bool newline_long; /* A snapshot of `newline` from the beginning of the unit. Occasionally useful */
        newline_long = newline;

        if (lastC == '[' && c != ']') {
                fprintf(env->out, "\n%s", repeat('\t', env->indent));
        }

        /* Non-brainfuck characters are not allowed in the source code - We have comments for that */
        if (is_illegal_op(c)) {
                FAIL_WRONG_OP(c) /* See `trans.h` */
        }

        /* If the last character is a loop character, we want to add */
        /* some fitting indentation */
        if (newline) {
                fprintf(env->out, "%s", repeat('\t', (c == ']') ? env->indent - 1 : env->indent));
                newline = false;
        }

        /* If the character is primitive (+-><.,) just print it as-is, as the condition above */
        /* will take care of the indentation */
        if (is_primitive(c)) {
                fprintf(env->out, "%c", c);
                goto exit_ok;
        }

        /* In case of a loop-opening symbol, go to the next line and increment the indentation step */
        if (c == '[') {
                if (is_primitive(lastC) && !newline_long)
                        fprintf(env->out, " ");
                fprintf(env->out, "[");
                env->indent++;
                goto exit_ok;
        }

        /* Close the loop in a similarly visually appealing manner */
        if (c == ']') {
                if (lastC != '[' && !newline_long) {
                        fprintf(env->out, "\n");
                        newline = true;
                }
                fprintf(env->out, "%s]", repeat('\t', (lastC != '[') ? (--env->indent) : 0));
                if (!newline) {
                        env->indent--;
                }
                fprintf(env->out, "\n");
                newline = true;
                goto exit_ok;
        }

        exit_ok:
        lastC = c;
        return SUCCESS;
}