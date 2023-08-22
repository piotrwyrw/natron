//
// Created by Piotr Krzysztof Wyrwas on 21.08.23.
//

#ifndef BFCMP_PARSE_H
#define BFCMP_PARSE_H

#include "trans.h"

#define IS_LETTER(c) ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || c == '_')
#define MAX_IDEN_LENGTH ((size_t) 100)

extern char last_identifier[];

int identifier(struct CompilerEnv *env);
int skip_spaces_till(char c, struct CompilerEnv *env);
char *isolate_till(char c, struct CompilerEnv *env);

#endif //BFCMP_PARSE_H
