//
// Created by Piotr Krzysztof Wyrwas on 15.08.23.
//

#include "clipp.h"
#include "color.h"

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>

unsigned int arg_i = 0;
unsigned int arg_ct = 0;
char **arg_vec = NULL;

#define BIND_CLI_PARAM(tag, dst) \
        if (strcmp(arg_vec[arg_i], tag) == 0) { \
            if (arg_i + 1 >= arg_ct) {          \
                return (struct Clip) {};\
            }                    \
            dst = malloc(strlen(arg_vec[arg_i + 1]) + 1);                     \
            strcpy(dst, arg_vec[++ arg_i]);     \
            arg_i ++;                     \
            continue;\
        }


#define BIND_CLI_PARAM_ENUM(tag, dst, val) \
        if (strcmp(arg_vec[arg_i], tag) == 0) { \
            dst = val;                     \
            arg_i ++;                     \
            continue;\
        }


struct Clip parse_clip(int argc, char **argv)
{
        arg_i = 1; // Start at the second index, since the index 0 is occupied by default
        arg_ct = argc;
        arg_vec = argv;

        tmp_clip = (struct Clip) {};

        tmp_clip.parse_ok = true;

        if (argc < 2)
                return tmp_clip;

        // The default mode of operation should be compilation
        tmp_clip.mode = MODE_COMPILE;

        for (;;) {
                if (arg_i >= arg_ct)
                        break;

                BIND_CLI_PARAM("--source", tmp_clip.in);
                BIND_CLI_PARAM("--output", tmp_clip.out);

                BIND_CLI_PARAM_ENUM("--compile", tmp_clip.mode, MODE_COMPILE)
                BIND_CLI_PARAM_ENUM("--reformat", tmp_clip.mode, MODE_REFORMAT)

                CLR_PRINTF(ANSI_COLOR_RED, "[ERR] Unknown command line parameter: %s.\n", arg_vec[arg_i]);
                return (struct Clip) {.parse_ok = false};
        };

        return tmp_clip;
}

int clip_check_integrity(struct Clip *clip)
{
        if (!clip->parse_ok)
                return EXIT_FAILURE;

        if (!clip->out) {
                CLR_PRINTF(ANSI_COLOR_RED, "[ERR] Required parameter not set: --output\n");
                return EXIT_FAILURE;
        }

        if (!clip->in) {
                CLR_PRINTF(ANSI_COLOR_RED, "[ERR] Required parameter not set: --source\n");
                return EXIT_FAILURE;
        }

        return EXIT_SUCCESS;
}