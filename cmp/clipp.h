//
// Created by Piotr Krzysztof Wyrwas on 15.08.23.
//

#ifndef BFCMP_CLIPP_H
#define BFCMP_CLIPP_H

enum OperationMode {
        MODE_COMPILE,
        MODE_REFORMAT
};

/**
 * Commandline Parameters
 */
struct Clip {
        char *in; /* Input file name */
        char *out; /* Output file name */
        enum OperationMode mode; /* What should this instance do? */
        _Bool parse_ok; /* False if any syntax errors were encountered during parsing */
} tmp_clip;

extern unsigned int arg_i;
extern unsigned int arg_ct;
extern char **arg_vec;

struct Clip parse_clip(int argc, char **argv);
void free_clip(struct Clip *clip);

int clip_check_integrity(struct Clip *clip);

#endif //BFCMP_CLIPP_H
