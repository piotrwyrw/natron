//
// Created by Piotr Krzysztof Wyrwas on 15.08.23.
//

#include "clipp.h"

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

unsigned int arg_ix = 0;
unsigned int arg_ct = 0;
char **arg_vec = NULL;

#define eternal for (;;)

#define BIND_CLI_PARAM(tag, dst) \
        if (strcmp(arg_vec[arg_ix], tag) == 0) { \
            if (arg_ix + 1 >= arg_ct) {          \
                return (struct Clip) {NULL, NULL};\
            }                    \
            dst = malloc(strlen(arg_vec[arg_ix + 1]) + 1);                     \
            strcpy(dst, arg_vec[++ arg_ix]);     \
            arg_ix ++;                     \
            continue;\
        }


struct Clip parse_clip(int argc, char **argv) {
    arg_ix = 1; // Start at the second index, since the index 0 is occupied by default
    arg_ct = argc;
    arg_vec = argv;

    tmp_clip = (struct Clip) {};

    eternal {
        if (arg_ix + 1 >= arg_ct)
            break;

        BIND_CLI_PARAM("--source", tmp_clip.in);
        BIND_CLI_PARAM("--output", tmp_clip.out);
    };

    return tmp_clip;
}

int clip_chk_integrity(struct Clip *clip) {
    if (!clip->out) {
        printf("Required parameter not set: --output\n");
        return EXIT_FAILURE;
    }

    if (!clip->in) {
        printf("Required parameter not set: --source\n");
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}