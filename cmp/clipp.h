//
// Created by Piotr Krzysztof Wyrwas on 15.08.23.
//

#ifndef BFCMP_CLIPP_H
#define BFCMP_CLIPP_H

/**
 * Commandline Parameters
 */
struct Clip {
    char *in; /* Input file name */
    char *out; /* Output file name */
} tmp_clip;

extern unsigned int arg_ix;
extern unsigned int arg_ct;
extern char **arg_vec;

struct Clip parse_clip(int, char **);

int clip_chk_integrity(struct Clip *);

#endif //BFCMP_CLIPP_H
