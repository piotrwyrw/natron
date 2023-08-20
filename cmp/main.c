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

static struct Clip cli_params;
static struct CompilerEnv env;

static int compile_source()
{
        int cmp_status = compile(&env);
        fclose(env.out);

        if (cmp_status == EXIT_FAILURE) {
                if (remove(cli_params.out) < 0)
                        printf("[ERR] Failed to remove flawed compiler output: %s.\n", strerror(errno));
        } else {
                printf("[OK] Compilation successful with %d operations.\n", env.op_ct);
        }

        return cmp_status;
}

static int reformat_source()
{
        int fmt_status = reformat(&env);
        fclose(env.out);

        if (fmt_status == EXIT_FAILURE) {
                if (remove(cli_params.out) < 0)
                        printf("[ERR] Failed to remove flawed reformatted output: %s.\n", strerror(errno));
        } else {
                printf("[OK] Reformatting successful.\n");
        }

        return fmt_status;
}


int main(int argc, char **argv)
{

        char *src = NULL;
        FILE *outf = NULL;

        cli_params = parse_clip(argc, argv);

        if (clip_check_integrity(&cli_params))
                goto fail_and_quit;

        src = file_read(cli_params.in);

        if (!src) {
                printf("[ERR] Failed to open input file '%s' for reading: %s\n", cli_params.in, strerror(errno));
                goto fail_and_quit;
        }

        outf = fopen(cli_params.out, "w");

        if (!outf) {
                printf("[ERR] Cannot open output file '%s' for writing: %s\n", cli_params.out, strerror(errno));
                goto fail_and_quit;
        }

        env = (struct CompilerEnv) {
                .out = outf,
                .src = src,
                .includes = {
                        "stdlib.h"
                },
                .includes_ct = 1
        };

        if (cli_params.mode == MODE_COMPILE)
                return compile_source();
        else
                return reformat_source();

        // Only meant to be used in case of an irrecoverable failure
        fail_and_quit:
        free(src);
        fclose(outf);
        return EXIT_FAILURE;
}
