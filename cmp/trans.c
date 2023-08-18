//
// Created by Piotr Krzysztof Wyrwas on 16.08.23.
//

#include "trans.h"
#include "util.h"

#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define EMIT(env, ...) {\
            fprintf(env->out, "%s", _ctimes('\t', env->indent));               \
            fprintf(env->out, __VA_ARGS__); \
        }

#define IS_QUANTIFIABLE(c) (c == '>' || c == '<' || c == '+' || c == '-')

int compile(struct CompilerEnv *env) {
    if (!env->src)
        return EXIT_FAILURE;

    if (!env->out)
        return EXIT_FAILURE;

    env->offset = 0;
    env->_loop_sub_zero = true; /* We start at "-1" */
    env->len = strlen(env->src);
    env->op_ct = 0;

    _gen_preamble(env);

    EMIT(env, "int %s(void) {\n", BRAINFUCK_MAIN_FUNCTION)
    env->indent++;

    EMIT(env, "bf_init();\n");

    for (; env->offset < env->len; env->offset++)
        if (_compile_next(env)) return EXIT_FAILURE;

    EMIT(env, "return bf_end();\n")

    env->indent--;
    EMIT(env, "}\n")

    if (env->loop_ct != 0) {
        printf("Syntax error: There are unclosed loops.\n");
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}

static void _gen_preamble(struct CompilerEnv *env) {
    // Include all requested headers
    for (unsigned int i = 0; i < env->includes_ct; i++) EMIT(env, "#include <%s>\n", env->includes[i])

    EMIT(env, "\n")

    // Extern-s to the core lib functions
    EMIT(env, "extern void bf_init();\n");
    EMIT(env, "extern char bf_end();\n");
    EMIT(env, "extern void bf_ptr_inc_n(size_t);\n");
    EMIT(env, "extern void bf_ptr_dec_n(size_t);\n");
    EMIT(env, "extern void bf_set(char);\n");
    EMIT(env, "extern char bf_get();\n");
    EMIT(env, "extern void bf_in();\n");
    EMIT(env, "extern void bf_out();\n\n");
}

static int _compile_next(struct CompilerEnv *env) {

    if (env->offset >= env->len) {
        printf("Error: Offset is pointing outside of the source code.\n");
        return EXIT_FAILURE;
    }

    char op = env->src[env->offset];

    size_t rep = countcs(env->offset, env->src, op);

    if (IS_QUANTIFIABLE(op)) {
        if (rep > 1)
            env->offset += rep - 1;
        env->op_ct += rep;
    }

//    char id[12] = {0};

    switch (op) {

        default:
            return EXIT_SUCCESS;

        case '+': {
            EMIT(env, "bf_set(bf_get() + %ld);\n", rep)
            break;
        }
        case '-': {
            EMIT(env, "bf_set(bf_get() - %ld);\n", rep);
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
            _loop_add(env);
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
                printf("Syntax error: There are unclosed loops.\n");
                return EXIT_FAILURE;
            }
            EMIT(env, "} // -- %d\n", _loop_del(env));
            break;
        }
        case '.': {
            env->op_ct++;
            EMIT(env, "bf_out();\n");
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

static void _loop_rel(struct CompilerEnv *env) {
    if (env->_loop_index >= 0)
        env->loop_no = env->loops[env->_loop_index];
    else
        env->loop_no = -1;
}

static unsigned int _loop_add(struct CompilerEnv *env) {
    if (!env->_loop_sub_zero)
        env->_loop_index++;
    else
        env->_loop_sub_zero = false;

    env->loops[env->_loop_index] = ++env->_max_loop;

    unsigned int last_no = env->_max_loop;

    _loop_rel(env);

    return last_no;
}

static unsigned int _loop_del(struct CompilerEnv *env) {
    if (env->_loop_index == 0)
        env->_loop_sub_zero = true;
    else
        env->_loop_index--;

    unsigned int last_no = env->loop_no;

    _loop_rel(env);

    return last_no;
}

