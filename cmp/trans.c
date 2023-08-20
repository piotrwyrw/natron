//
// Created by Piotr Krzysztof Wyrwas on 16.08.23.
//

#include "trans.h"
#include "util.h"

#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

static void gen_preamble(struct CompilerEnv *);
static int compile_next(struct CompilerEnv *);

int sanity_check_env(struct CompilerEnv *env)
{
        if (!env->src)
                return EXIT_FAILURE;

        if (!env->out)
                return EXIT_FAILURE;

        env->offset = 0;
        env->_loop_sub_zero = true; /* We start at "-1" */
        env->len = strlen(env->src);
        env->op_ct = 0;

        return EXIT_SUCCESS;
}

int compile(struct CompilerEnv *env)
{
        if (sanity_check_env(env))
                return EXIT_FAILURE;

        gen_preamble(env);

        EMIT(env, "int %s(void) {\n", BRAINFUCK_MAIN_FUNCTION)
        env->indent++;

        EMIT(env, "bf_init();\n");

        for (; env->offset < env->len; env->offset++)
                if (compile_next(env)) return EXIT_FAILURE;

        EMIT(env, "return bf_end();\n")

        env->indent--;
        EMIT(env, "}\n")

        if (env->loop_ct != 0) {
                printf("[ERR] Syntax error: There are unclosed loops.\n");
                return EXIT_FAILURE;
        }

        return EXIT_SUCCESS;
}

static void gen_preamble(struct CompilerEnv *env)
{
        EMIT(env, "/**\n"
                  " * Generated by bf-cmp\n"
                  " */\n\n");

        // Include all requested headers
        for (unsigned int i = 0; i < env->includes_ct; i++) EMIT(env, "#include <%s>\n", env->includes[i])

        EMIT(env, "\n")

        // Extern-s to the core lib functions
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
        ENV_CURR(op)

        size_t rep = count_following(env->offset, env->src, op);

        if (IS_PRIMITIVE(op)) {
                if (rep > 1)
                        env->offset += rep - 1;
                env->op_ct += rep;
        }

        switch (op) {

                default:
                        return EXIT_SUCCESS;

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
                                printf("[ERR] Syntax error: There are unclosed loops.\n");
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
        if (env->_loop_index >= 0) {
                env->loop_no = env->loops[env->_loop_index];
        } else {
                env->loop_no = -1;
        }
}

unsigned int add_loop(struct CompilerEnv *env)
{
        if (!env->_loop_sub_zero)
                env->_loop_index++;
        else
                env->_loop_sub_zero = false;

        env->loops[env->_loop_index] = ++env->_max_loop;

        unsigned int last_no = env->_max_loop;

        refresh_loop_number(env);

        return last_no;
}

unsigned int delete_loop(struct CompilerEnv *env)
{
        if (env->_loop_index == 0)
                env->_loop_sub_zero = true;
        else
                env->_loop_index--;

        unsigned int last_no = env->loop_no;

        refresh_loop_number(env);

        return last_no;
}

