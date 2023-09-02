//
// Created by Piotr Krzysztof Wyrwas on 21.08.23.
//

#ifndef NATRON_PARSE_H
#define NATRON_PARSE_H

#include "trans.h"

inline static _Bool is_primitive(char c)
{
        return c == '>' || c == '<' || c == '+' || c == '-' || c == '.';
}

inline static _Bool is_space(char c)
{
        return c == ' ' || c == '\t';
}

inline static _Bool is_letter(char c)
{
        return (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || c == '_';
}

inline static _Bool is_space_ext(char c)
{
        return is_space(c) || c == '\n';
}

inline static _Bool is_illegal_op(char c)
{
        return !is_primitive(c) && c != '[' && c != ']' && !is_space(c) && c != '\n';
}

inline static _Bool is_call_initiator(char c)
{
        return c == '@' || c == '$';
}

struct unit_header {
        char *id;
        _Bool main;
};

struct unit_call {
        char *id;
};

struct unit_externalise {
        char *id;
        _Bool native;
};

extern char last_identifier[];

int identifier(struct CompilerEnv *env, _Bool peek);

int skip_spaces(struct CompilerEnv *env);

int parse_unit_header(struct unit_header *ptr, struct CompilerEnv *env);

int parse_unit_call(struct unit_call *ptr, struct CompilerEnv *env);

int parse_unit_externalize(struct unit_externalise *ptr, struct CompilerEnv *env);

__attribute__((unused)) char *isolate_till(char c, struct CompilerEnv *env);

#endif //NATRON_PARSE_H
