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

int main(int argc, char **argv) {

    char *src = NULL;
    FILE *outf = NULL;

    struct Clip params = parse_clip(argc, argv);

    if (clip_chk_integrity(&params))
        goto fail_and_quit;

    src = file_rd(params.in);

    if (!src) {
        printf("[ERR] Failed to open input file '%s' for reading: %s\n", params.in, strerror(errno));
        goto fail_and_quit;
    }

    outf = fopen(params.out, "w");

    if (!outf) {
        printf("[ERR] Cannot open output file '%s' for writing: %s\n", params.out, strerror(errno));
        goto fail_and_quit;
    }

    struct CompilerEnv env = {
            .out = outf,
            .src = src,
            .includes = {
                    "stdlib.h"
            },
            .includes_ct = 1
    };

    int cmp_status = compile(&env);
    fclose(env.out);

    if (cmp_status == EXIT_FAILURE) {
        if (remove(params.out) < 0)
            printf("[ERR] Failed to remove flawed compiler output: %s.\n", strerror(errno));
    } else {
        printf("[OK] Compilation successful with %d operations.\n", env.op_ct);
    }

    return cmp_status;

    // Only meant to be used in case of an irrecoverable failure
    fail_and_quit:
    free(src);
    fclose(outf);
    return EXIT_FAILURE;
}
