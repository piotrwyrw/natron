//
// Created by Piotr Krzysztof Wyrwas on 16.08.23.
//

#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "trans.h"
#include "util.h"
#include "color.h"
#include "parse.h"

void free_units_env(struct CompilerEnv *env)
{
        for (size_t i = 0; i < env->units_ct; i++) {
                free(env->units[i]);
        }
}

int add_unit_env(struct CompilerEnv *env, char *id)
{
        if (env->units_ct >= MAX_UNITS_COUNT) {
                return FAILURE;
        }

        env->units[env->units_ct++] = strdup(id);
        return SUCCESS;
}

_Bool unit_exists(char *id, struct CompilerEnv *env)
{
        for (size_t i = 0; i < env->units_ct; i++) {
                if (strcmp(env->units[i], id) == 0) {
                        return true;
                }
        }

        return false;
}

int sanity_check_env(struct CompilerEnv *env)
{
        if (!env->src) {
                return FAILURE;
        }

        if (!env->out) {
                return FAILURE;
        }

        env->offset = 0;
        env->loop_sub_zero = true; /* We start at "-1" */
        env->len = strlen(env->src);
        env->op_ct = 0;
        env->units_ct = 0;

        return SUCCESS;
}

static void gen_preamble(struct CompilerEnv *);

static int compile_next_brainfuck_operator(struct CompilerEnv *env);

static int compile_externalize(struct CompilerEnv *env);

static int compile_unit(struct CompilerEnv *env, _Bool *first);

static int compile_next(struct CompilerEnv *env, struct unit_call *call, char *id);

int exec_on_externalize(struct CompilerEnv *env, int (fun(struct CompilerEnv *)), _Bool first, _Bool trans)
{
        if (skip_spaces(env) == WARNING) {
                return WARNING;
        }

        if (identifier(env, true) != SUCCESS) {
                return WARNING;
        }

        if (strcmp(last_identifier, "externalize") != 0 && strcmp(last_identifier, "native") != 0) {
                return WARNING;
        }

        if (trans && !first) {
                ERROR("The externalize statement must precede all unit definitions in the file.\n")
                return FAILURE;
        }

        if (!fun(env)) {
                return FAILURE;
        }

        return SUCCESS;
}

int compile(struct CompilerEnv *env)
{
        if (!sanity_check_env(env)) {
                return FAILURE;
        }

        gen_preamble(env);

        int last_status;
        int status;

        _Bool first = true;

        while (true) {
                status = exec_on_externalize(env, compile_externalize, first, true);

                if (status == SUCCESS) {
                        continue;
                } else if (!status) {
                        return FAILURE;
                }

                last_status = compile_unit(env, &first);

                if (last_status != SUCCESS) {
                        break;
                }
        }

        if (last_status == FAILURE) {
                return FAILURE;
        }

        if (!env->main_set) {
                WARN("For the program to be standalone, it requires a main unit to be set. However, in this program, no unit is marked as such.\n")
        } else {
                EMIT(env, "int main(void)\n"
                          "{\n"
                          "\tbf_init();\n"
                          "\tfun_%s();\n"
                          "\treturn bf_end();\n"
                          "}", env->main)
        }

        return SUCCESS;
}

static int compile_externalize(struct CompilerEnv *env)
{
        struct unit_externalise ext;

        int status = parse_unit_externalize(&ext, env);

        if (status == FAILURE) {
                return FAILURE;
        }

        if (status == WARNING) {
                return WARNING;
        }

        add_unit_env(env, ext.id);

        if (ext.native) {
                EMIT(env, "void %s(void); // NATIVE\n\n", ext.id);
        } else {
                EMIT(env, "void fun_%s(void); // NON-NATIVE\n\n", ext.id);
        }

        free(ext.id);

        return SUCCESS;
}

static int compile_unit(struct CompilerEnv *env, _Bool *first)
{
        if (env->offset >= env->len) {
                return WARNING; /* We're at the end of the file; Nothing left to do. */
        }

        /* Unit header */
        struct unit_header header;
        int parse_status;

        if (!(parse_status = parse_unit_header(&header, env))) {
                return FAILURE;
        }

        if (parse_status == WARNING) {
                return WARNING;
        }

        char *id = header.id;

        if (unit_exists(id, env)) {
                ERROR("The identifier of a unit must be unique: Attempted redefinition of '%s'.\n", id);
                free(id);
                return FAILURE;
        }

        if (!add_unit_env(env, id)) {
                ERROR("Not enough memory to store unit '%s'. The compiler allows up to %ld unit definitions.\n",
                      id, MAX_UNITS_COUNT)
                free(id);
                return FAILURE;
        }

        /* Compile the brainfuck itself */

        if (header.main) {
                EMIT(env, "// Unit \"%s\" (fun_%s) is marked as MAIN\n", id, id)
        }

        EMIT(env, "void fun_%s(void)\n{\n", id)
        env->indent++;

        int status;
        struct unit_call call;

        for (; env->offset < env->len; env->offset++) {
                status = compile_next(env, &call, id);
                if (status == FAILURE) {
                        return FAILURE;
                }
                if (status == WARNING) {
                        break;
                }
        }

        if (env->loop_ct != 0) {
                ERROR("There are unclosed loops in unit '%s'.\n", id)
                free(id);
                return FAILURE;
        }

        env->indent--;
        EMIT(env, "}\n\n")

        if (env->src[env->offset] != '}') {
                ERROR("Expected '}' at the end of unit '%s'. Reached end of file while parsing.\n", id)
                free(id);
                return FAILURE;
        }

        free(id);

        env->offset++; /* Skip the '}' */

        *first = false;
        return SUCCESS;
}

static int compile_next(struct CompilerEnv *env, struct unit_call *call, char *id)
{
        if (skip_spaces(env) == WARNING) {
                return WARNING;
        }

        if (is_call_initiator(env->src[env->offset])) {
                char c = env->src[env->offset];

                if (!parse_unit_call(call, env)) {
                        return FAILURE;
                }

                if (c == '@' && strcmp(call->id, id) == 0) {
                        WARN("On unit call '%s' in '%s': Recursion is not recommended.\n", call->id, id)
                }

                if (c == '@' && !unit_exists(call->id, env)) {
                        ERROR("Attempting to call undefined unit '%s' from within '%s'.\n", call->id, id)
                        free(call->id);
                        return FAILURE;
                }

                if (c == '$') {
                        WARN("On native call '%s' in '%s': Native function calls are not recommended.\n",
                             call->id, id)
                }

                if (c == '@') {
                        EMIT(env, "fun_%s(); // @\n", call->id)
                } else {
                        EMIT(env, "%s(); // $\n", call->id)
                }

                free(call->id);

                env->offset--;
                return SUCCESS;
        }

        if (env->src[env->offset] == '}') {
                return WARNING;
        }

        if (!compile_next_brainfuck_operator(env)) {
                free(id);
                return FAILURE;
        }

        return SUCCESS;
}

static void gen_preamble(struct CompilerEnv *env)
{
        EMIT(env, "/**\n"
                  " * Generated by natron\n"
                  " */\n\n")

        /* Include all requested headers */
        for (size_t i = 0; i < env->includes_ct; i++) {
                EMIT(env, "#include <%s>\n", env->includes[i])
        }

        EMIT(env, "\n")

        /* Extern-s to the core lib functions */
        EMIT(env, "void bf_init();\n\n")
        EMIT(env, "char bf_end();\n\n")
        EMIT(env, "void bf_ptr_inc_n(size_t);\n\n")
        EMIT(env, "void bf_ptr_dec_n(size_t);\n\n")
        EMIT(env, "void bf_inc_arr(size_t);\n\n")
        EMIT(env, "char bf_dec_arr(size_t);\n\n")
        EMIT(env, "void bf_in();\n\n")
        EMIT(env, "void bf_out_n(size_t);\n\n")
        EMIT(env, "char bf_get();\n\n")
}

static int compile_next_brainfuck_operator(struct CompilerEnv *env)
{
        CURRENT_CHAR(op)

        size_t rep = count_following(env->offset, env->src, op);

        if (is_primitive(op)) {
                if (rep > 1)
                        env->offset += rep - 1;
                env->op_ct += rep;
        }

        if (is_illegal_op(op)) {
                FAIL_WRONG_OP(op) /* See `trans.h` */
        }

        switch (op) {

                default: ERROR("Not a brainfuck operator: '%c'\n", op)
                        return FAILURE;

                case '+': {
                        EMIT(env, "bf_inc_arr(%ld);\n", rep)
                        break;
                }
                case '-': {
                        EMIT(env, "bf_dec_arr(%ld);\n", rep)
                        break;
                }
                case '>': {
                        EMIT(env, "bf_ptr_inc_n(%ld);\n", rep)
                        break;
                }
                case '<': {
                        EMIT(env, "bf_ptr_dec_n(%ld);\n", rep)
                        break;
                }
                case '[': {
                        add_loop(env);
                        EMIT(env, "while (bf_get()) {\n")
                        env->op_ct++; /* In case of loops: We only count one of the two operators as an operation (in this case the opening bracket) */
                        env->loop_ct++;
                        env->indent++;
                        break;
                }
                case ']': {
                        env->indent--;
                        env->loop_ct--;
                        if (env->loop_ct < 0) {
                                ERROR("Syntax error: There are unclosed loops.\n")
                                return FAILURE;
                        }
                        EMIT(env, "} /* L%ld */\n", delete_loop(env))
                        break;
                }
                case '.': {
                        env->op_ct += rep;
                        EMIT(env, "bf_out_n(%ld);\n", rep)
                        break;
                }
                case ',': {
                        env->op_ct++;
                        EMIT(env, "bf_in();\n")
                        break;
                }
        }

        return SUCCESS;
}

static void refresh_loop_number(struct CompilerEnv *env)
{
        if (env->loop_index >= 0) {
                env->loop_no = env->loops[env->loop_index];
        } else {
                env->loop_no = -1;
        }
}

size_t add_loop(struct CompilerEnv *env)
{
        if (!env->loop_sub_zero) {
                env->loop_index++;
        } else {
                env->loop_sub_zero = false;
        }

        env->loops[env->loop_index] = ++env->max_loop;

        size_t last_no = env->max_loop;

        refresh_loop_number(env);

        return last_no;
}

size_t delete_loop(struct CompilerEnv *env)
{
        if (env->loop_index == 0)
                env->loop_sub_zero = true;
        else
                env->loop_index--;

        size_t last_no = env->loop_no;

        refresh_loop_number(env);

        return last_no;
}

