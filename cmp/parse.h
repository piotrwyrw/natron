//
// Created by Piotr Krzysztof Wyrwas on 21.08.23.
//

#ifndef BFCMP_PARSE_H
#define BFCMP_PARSE_H

#include "trans.h"

enum status {
        STATUS_OK,
        STATUS_EOF,
        STATUS_ERR
};

struct unit_header {
        char *id;
        _Bool main;
};

extern char last_identifier[];

int identifier(struct CompilerEnv *env);

int skip_spaces(struct CompilerEnv *env);

int parse_unit_header(struct unit_header *ptr, struct CompilerEnv *env);

__attribute__((unused)) char *isolate_till(char c, struct CompilerEnv *env);

#endif //BFCMP_PARSE_H
