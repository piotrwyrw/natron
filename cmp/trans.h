//
// Created by Piotr Krzysztof Wyrwas on 15.08.23.
//

#ifndef BFCMP_TRANS_H
#define BFCMP_TRANS_H

#include <stdio.h>

#include "util.h"

#define BRAINFUCK_MAX_LOOPS 100
#define BRAINFUCK_MAX_INCLUDES 2
#define BRAINFUCK_MAIN_FUNCTION "main"
#define BRAINFUCK_CELL_COUNT 30000

#define EMIT(env, ...) {\
            fprintf(env->out, "%s", repeat('\t', env->indent));               \
            fprintf(env->out, __VA_ARGS__); \
        }

#define IS_PRIMITIVE(c) (c == '>' || c == '<' || c == '+' || c == '-' || c == '.')

#define ENV_CURR(id) \
        if (env->offset >= env->len) { \
            printf("[ERR] Offset is pointing outside of the source code.\n"); \
            return EXIT_FAILURE; \
        }            \
        char id = env->src[env->offset];

struct CompilerEnv {
        char *src;
        size_t offset; /* Offset from the base of the source string */
        size_t len; /* Length of the source string */
        FILE *out;

        unsigned int indent; /* Keeps track of the indentation */

        char *includes[BRAINFUCK_MAX_INCLUDES]; /* The headers to include in the resulting C file */
        unsigned int includes_ct; /* Size of the include array */

        // The following section is dedicated to keeping track of the loops.
        // Only use with the wrapper functions `refresh_loop_number()`, `add_loop()` and `delete_loop()` !
        unsigned int loops[BRAINFUCK_MAX_LOOPS]; /* Keep track of loop numbering */
        unsigned int loop_no; /* The current loop number. Updated automatically - Do not overwrite manually! */
        _Bool _loop_sub_zero; /* True - If you delete the 0th loop. Emulates a negative number. Managed automatically - don't alter manually. */
        unsigned int _loop_index; /* The index pointing to the current loop number. Don't touch! */
        unsigned int _max_loop; /* Max loop number. Do not mess with this. */
        unsigned int loop_ct; /* For keeping track of (un)closed loops */

        unsigned int op_ct; /* Just for the final success message. Yep, no other purpose. */
};

int sanity_check_env(struct CompilerEnv *env);

int compile(struct CompilerEnv *env);

unsigned int add_loop(struct CompilerEnv *env);

unsigned int delete_loop(struct CompilerEnv *env);

#endif //BFCMP_TRANS_H
