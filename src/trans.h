//
// Created by Piotr Krzysztof Wyrwas on 15.08.23.
//

#ifndef BFCMP_TRANS_H
#define BFCMP_TRANS_H

#include <stdio.h>

#define BRAINFUCK_MAX_LOOPS 100
#define BRAINFUCK_MAX_INCLUDES 2
#define BRAINFUCK_MAIN_FUNCTION "main"
#define BRAINFUCK_CELL_COUNT 30000

struct CompilerEnv {
    char *src;
    unsigned int offset; /* Offset from the base of the source string */
    unsigned int len; /* Length of the source string */
    FILE *out;

    unsigned int indent; /* Keeps track of the indentation */

    char *includes[BRAINFUCK_MAX_INCLUDES]; /* The headers to include in the resulting C file */
    unsigned int includes_ct; /* Size of the include array */

    // The following section is dedicated to keeping track of the loops.
    // Only use with the wrapper functions `_loop_rel()`, `_loop_add()` and `_loop_del()` !
    unsigned int loops[BRAINFUCK_MAX_LOOPS]; /* Keep track of loop numbering */
    unsigned int loop_no; /* The current loop number. Updated automatically - Do not overwrite manually! */
    _Bool _loop_sub_zero; /* True - If you delete the 0th loop. Emulates a negative number. Managed automatically - don't alter manually. */
    unsigned int _loop_index; /* The index pointing to the current loop number. Don't touch! */
    unsigned int _max_loop; /* Max loop number. Do not mess with this. */
    unsigned int loop_ct; /* For keeping track of (un)closed loops */

    unsigned int op_ct; /* Just for the final success message. Yep, no other purpose. */
};

int compile(struct CompilerEnv *);

static void _gen_preamble(struct CompilerEnv *);

static int _compile_next(struct CompilerEnv *);

static void _loop_rel(struct CompilerEnv *);

static unsigned int _loop_add(struct CompilerEnv *);

static unsigned int _loop_del(struct CompilerEnv *);

#endif //BFCMP_TRANS_H
