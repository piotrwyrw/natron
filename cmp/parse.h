//
// Created by Piotr Krzysztof Wyrwas on 21.08.23.
//

#ifndef NATRON_PARSE_H
#define NATRON_PARSE_H

#include "trans.h"

struct unit_header {
        char *id;
        _Bool main;
};

struct unit_call {
        char *id;
};

struct unit_externalise {
        char *id;
};

extern char last_identifier[];

int identifier(struct CompilerEnv *env, _Bool peek);

int skip_spaces(struct CompilerEnv *env);

int parse_unit_header(struct unit_header *ptr, struct CompilerEnv *env);

int parse_unit_call(struct unit_call *ptr, struct CompilerEnv *env);

int parse_unit_externalize(struct unit_externalise *ptr, struct CompilerEnv *env);

__attribute__((unused)) char *isolate_till(char c, struct CompilerEnv *env);

#endif //NATRON_PARSE_H
