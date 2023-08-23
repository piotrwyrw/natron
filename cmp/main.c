//
// Created by Piotr Krzysztof Wyrwas on 15.08.23.
//

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

#include "clipp.h"
#include "fio.h"
#include "trans.h"
#include "fmt/fmt.h"
#include "color.h"
#include "help.h"

static struct Clip cli_params;
static struct CompilerEnv env;
static char *src;
static FILE *outf;

static int compile_source(void)
{
        int cmp_status = compile(&env);
        fclose(env.out);

        if (cmp_status == EXIT_FAILURE) {
                if (remove(cli_params.out) < 0) {
                        ERROR("Failed to remove flawed compiler output: %s.\n", strerror(errno))
                }
                ERROR("Compilation failed.\n")
        } else {
                OK("Compilation successful with %d operations: [%s -> %s]\n", env.op_ct, cli_params.in,
                   cli_params.out)
        }

        return cmp_status;
}

static int reformat_source(void)
{
        int fmt_status = reformat(&env);
        fclose(env.out);

        if (fmt_status == EXIT_FAILURE) {
                if (remove(cli_params.out) < 0) {
                        ERROR("Failed to remove flawed reformatted output: %s.\n", strerror(errno))
                }
                ERROR("Reformatting failed.\n")
        } else {
                OK("Reformatting successful: [%s -> %s]\n", cli_params.in, cli_params.out)
        }

        return fmt_status;
}


int main(int argc, char **argv)
{
        if (argc < 2) {
                show_help();
                return 0;
        }

        src = NULL;
        outf = NULL;

        cli_params = parse_clip(argc, argv);

        if (clip_check_integrity(&cli_params)) {
                return EXIT_FAILURE;
        }

        src = file_read(cli_params.in);

        if (!src) {
                ERROR("Failed to open input file '%s' for reading: %s\n", cli_params.in, strerror(errno))
                return EXIT_FAILURE;
        }

        outf = fopen(cli_params.out, "w");

        if (!outf) {
                ERROR("Cannot open output file '%s' for writing: %s\n", cli_params.out, strerror(errno))
                return EXIT_FAILURE;
        }

        env = (struct CompilerEnv) {
                .out = outf,
                .src = src,
                .includes = {
                        "stdlib.h"
                },
                .includes_ct = 1
        };

        if (cli_params.mode == MODE_COMPILE) {
                return compile_source();
        } else {
                return reformat_source();
        }
}

/* Clean up the memory alloc-s */
__attribute__((destructor, used)) void finalize_allocations()
{
        free(src);
        fclose(outf);
        free_clip(&cli_params);
        free_units_env(&env);
}
