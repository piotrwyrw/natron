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

static void gen_preamble(struct CompilerEnv *);

static int compile_next(struct CompilerEnv *);

int sanity_check_env(struct CompilerEnv *env)
{
        if (!env->src)
                return EXIT_FAILURE;

        if (!env->out)
                return EXIT_FAILURE;

        env->offset = 0;
        env->loop_sub_zero = true; /* We start at "-1" */
        env->len = strlen(env->src);
        env->op_ct = 0;

        return EXIT_SUCCESS;
}

static enum status compile_unit(struct CompilerEnv *env);

int compile(struct CompilerEnv *env)
{
        if (sanity_check_env(env))
                return EXIT_FAILURE;

        gen_preamble(env);

        enum status last_status;

        /* Compile all units */
        while ((last_status = compile_unit(env)) == STATUS_OK) {}

        if (last_status == STATUS_ERR) {
                return EXIT_FAILURE;
        }

        return EXIT_SUCCESS;
}

static enum status compile_unit(struct CompilerEnv *env)
{

        if (env->offset >= env->len) {
                return STATUS_EOF; /* We're at the end of the file; Nothing left to do. */
        }

        /* Unit header */
        struct unit_header header;
        int parse_status;

        if ((parse_status = parse_unit_header(&header, env)) == EXIT_FAILURE) {
                return STATUS_ERR;
        }

        if (parse_status == EXIT_WARNING) {
                return STATUS_EOF;
        }

        char *id = header.id;

        /* Compile the brainfuck itself */
        if (strcmp(id, "main") == 0) {
                EMIT(env, "int main(void)\n{\n")
                env->indent++;
                EMIT(env, "bf_init();\n")
        } else {
                EMIT(env, "void %s(void)\n{\n", last_identifier);
                env->indent++;
        }

        for (; env->offset < env->len; env->offset++) {
                if (env->src[env->offset] == '}') {
                        break;
                }
                if (compile_next(env)) {
                        free(id);
                        return STATUS_ERR;
                }
        }

        if (env->loop_ct != 0) {
                ERROR("There are unclosed loops in unit '%s'.\n", id);
                free(id);
                return STATUS_ERR;
        }

        if (strcmp(id, "main") == 0) {
                EMIT(env, "return bf_end();\n")
        }

        env->indent--;
        EMIT(env, "}\n\n");

        if (env->src[env->offset] != '}') {
                ERROR("Expected '}' aft the end of unit '%s'. Reached end of file while parsing.\n", id)
                free(id);
                return STATUS_ERR;
        }

        free(id);

        env->offset++; /* Skip the '}' */

        return STATUS_OK;
}

__attribute__((unused)) _Bool is_comment_line(struct CompilerEnv *env)
{
        size_t org = 0;
        char c;

        /* Find the origin -> Index 0 || the character after the last \n */
        if (env->offset == 0) {
                org = 0;
                goto scan_line;
        }

        for (size_t i = env->offset; true; i--) {
                if (env->src[i] == '\n') {
                        org = i + 1;
                        break;
                }

                if (i == 0) {
                        break;
                }
        }

        scan_line:;

        /* Scan the entire line (from `org` to the next \n) and check if there is anything before a comment symbol (#) */
        /* If there is nothing besides (white)spaces, the comment occupies the entire line -> return true */
        /* Otherwise, it is an inline comment -> return false */

        for (size_t i = org; i < env->len; i++) {
                c = env->src[i];

                /* This line is empty. This is a weird return value, as it shouldn't ever happen under regular circumstances. */
                /* We are however not going to return false, as this would confuse the reformatting module */
                if (c == '\n')
                        return true;

                if (is_space(c))
                        continue;

                if (c == '#')
                        return true;

                /* If we encounter any other characters on the line -> false */
                return false;
        }

        return true;
}

size_t skip_comment(struct CompilerEnv *env)
{
        CURRENT_CHAR(c)

        size_t skip = 0;

        /* Not a comment. */
        if (c != '#')
                return 0;

        /* If the comment symbol is the last character in the file, return 1 (just to skip it) */
        if (env->offset + 1 >= env->len)
                return 1;

        skip++;

        /* Loop through all remaining characters until reaching a new-line */
        for (; env->offset + skip < env->len; skip++) {
                c = env->src[env->offset + skip];

                if (c == '\n') {
                        break;
                }
        }

        return skip;
}

static void gen_preamble(struct CompilerEnv *env)
{
        EMIT(env, "/**\n"
                  " * Generated by bf-cmp\n"
                  " */\n\n");

        /* Include all requested headers */
        for (unsigned int i = 0; i < env->includes_ct; i++) EMIT(env, "#include <%s>\n", env->includes[i])

        EMIT(env, "\n")

        /* Extern-s to the core lib functions */
        EMIT(env, "extern void bf_init();\n");
        EMIT(env, "extern char bf_end();\n");
        EMIT(env, "extern void bf_ptr_inc_n(size_t);\n");
        EMIT(env, "extern void bf_ptr_dec_n(size_t);\n");
        EMIT(env, "extern void bf_inc_arr(size_t);\n");
        EMIT(env, "extern char bf_dec_arr(size_t);\n");
        EMIT(env, "extern void bf_in();\n");
        EMIT(env, "extern void bf_out_n(size_t);\n");
        EMIT(env, "extern char bf_get();\n\n");
}

static int compile_next(struct CompilerEnv *env)
{
        CURRENT_CHAR(op)

        size_t rep;

        /* Check for comments and skip if necessary*/
        if (op != '#')
                goto not_a_comment;

        env->offset += skip_comment(env);

        return EXIT_SUCCESS;

        not_a_comment:

        rep = count_following(env->offset, env->src, op);

        if (is_primitive(op)) {
                if (rep > 1)
                        env->offset += rep - 1;
                env->op_ct += rep;
        }

        if (is_illegal_op(op)) {
                FAIL_WRONG_OP(op) /* See `trans.h` */
        }

        switch (op) {

                default:
                        break;

                case '+': {
                        EMIT(env, "bf_inc_arr(%ld);\n", rep)
                        break;
                }
                case '-': {
                        EMIT(env, "bf_dec_arr(%ld);\n", rep);
                        break;
                }
                case '>': {
                        EMIT(env, "bf_ptr_inc_n(%ld);\n", rep);
                        break;
                }
                case '<': {
                        EMIT(env, "bf_ptr_dec_n(%ld);\n", rep);
                        break;
                }
                case '[': {
                        add_loop(env);
                        EMIT(env, "while (bf_get()) {\n");
                        env->op_ct++; /* In case of loops: We only count one of the two operators as an operation (in this case the opening bracket) */
                        env->loop_ct++;
                        env->indent++;
                        break;
                }
                case ']': {
                        env->indent--;
                        env->loop_ct--;
                        if (env->loop_ct < 0) {
                                ERROR("Syntax error: There are unclosed loops.\n");
                                return EXIT_FAILURE;
                        }
                        EMIT(env, "} // -- %d\n", delete_loop(env));
                        break;
                }
                case '.': {
                        env->op_ct += rep;
                        EMIT(env, "bf_out_n(%ld);\n", rep);
                        break;
                }
                case ',': {
                        env->op_ct++;
                        EMIT(env, "bf_in();\n");
                        break;
                }
        }

        return EXIT_SUCCESS;
}

static void refresh_loop_number(struct CompilerEnv *env)
{
        if (env->loop_index >= 0) {
                env->loop_no = env->loops[env->loop_index];
        } else {
                env->loop_no = -1;
        }
}

unsigned int add_loop(struct CompilerEnv *env)
{
        if (!env->loop_sub_zero)
                env->loop_index++;
        else
                env->loop_sub_zero = false;

        env->loops[env->loop_index] = ++env->max_loop;

        unsigned int last_no = env->max_loop;

        refresh_loop_number(env);

        return last_no;
}

unsigned int delete_loop(struct CompilerEnv *env)
{
        if (env->loop_index == 0)
                env->loop_sub_zero = true;
        else
                env->loop_index--;

        unsigned int last_no = env->loop_no;

        refresh_loop_number(env);

        return last_no;
}

