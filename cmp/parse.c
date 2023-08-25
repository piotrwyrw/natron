//
// Created by Piotr Krzysztof Wyrwas on 22.08.23.
//

#include "parse.h"
#include "defs.h"

#include <string.h>
#include <stdbool.h>

char last_identifier[MAX_IDEN_LENGTH] = {0};

int identifier(struct CompilerEnv *env, _Bool peek)
{
        if (!is_letter(env->src[env->offset])) {
                return FAILURE;
        }

        /* Clear the last identifier buffer before writing to it */
        memset(last_identifier, 0, MAX_IDEN_LENGTH);

        char c;
        size_t i = 0;
        char *ptr = last_identifier;

        while (is_letter((c = env->src[env->offset + (i++)]))) {
                *(ptr++) = c;
                if (ptr > last_identifier + MAX_IDEN_LENGTH) {
                        ERROR("Identifier too long: An identifier must be shorter than %ld characters.\n",
                              MAX_IDEN_LENGTH)
                        return FAILURE; /* We're out of memory for the identifier */
                }
        }

        if (!peek) {
                env->offset += i - 1;
        }

        return SUCCESS;
}

int skip_spaces(struct CompilerEnv *env)
{
        if (env->offset >= env->len) {
                return WARNING;
        }

        size_t i = 0;
        _Bool comment = false;
        char c;

        if (env->src[env->offset] == '#') {
                comment = true;
        }

        while (is_space_ext(env->src[env->offset + (i++)]) || comment) {
                c = env->src[env->offset + i - 1];

                /* Is the next char a comment-init ? */
                if (env->offset + i < env->len) {
                        if (env->src[env->offset + i] == '#') {
                                comment = true;
                                continue;
                        }
                }

                if (c == '#') {
                        comment = true;
                }

                if (comment && c == '\n') {
                        comment = false;
                }

                if (env->offset + i >= env->len) {
                        return WARNING;
                }
        }

        env->offset += i - 1;

        return SUCCESS;
}

#define IDENTIFIER(...) \
        if (identifier(env, false) == FAILURE) { \
                ERROR(__VA_ARGS__) \
                return FAILURE; \
        }

#define EXPECT(c, ...) \
        if (env->src[env->offset] != c) { \
                ERROR(__VA_ARGS__)        \
                return FAILURE; \
        }

int parse_unit_header(struct unit_header *ptr, struct CompilerEnv *env)
{
        if (skip_spaces(env) == WARNING) {
                return WARNING;
        }

        _Bool main = false;

        /* Look for the main flag */
        if (env->src[env->offset] == '&') {
                main = true;

                env->offset++; /* Skip the attribute ('&') */

                if (skip_spaces(env) == WARNING) {
                        ERROR("Could not parse: Reached end of file after main attribute of unit '%s'.\n",
                              last_identifier)
                        return FAILURE;
                }

        }

        IDENTIFIER("Expected identifier, got '%c'\n", env->src[env->offset])

        if (skip_spaces(env) == WARNING) {
                ERROR("Could not parse: Reached end of file after identifier '%s'.\n", last_identifier)
                return FAILURE;
        }

        EXPECT('{', "Expected '{' after identifier '%s'. Got '%c' instead.\n", last_identifier, env->src[env->offset])

        env->offset++; /* Skip the '{' */
        if (env->offset >= env->len) {
                ERROR("Expected brainfuck code after '{' in unit '%s'. Reached end of file while parsing.\n",
                      last_identifier)
                return FAILURE;
        }

        ptr->id = strdup(last_identifier);
        ptr->main = main;

        if (main) {
                if (env->main_set) {
                        ERROR("There may only be a single main unit. Previous: '%s'.\n", env->main)
                        return FAILURE;
                }
                env->main_set = true;
                strcpy(env->main, last_identifier);
        }

        return SUCCESS;
}

int parse_unit_call(struct unit_call *ptr, struct CompilerEnv *env)
{
        char c = env->src[env->offset];
        if (c != '@' && c != '$') {
                ERROR("Illegal state.");
                return FAILURE;
        }

        env->offset++; /* Skip the '@' or '$' */

        /* There should be no spaces between the '@' ('$') and the identifier. */

        IDENTIFIER("Expected identifier immediately after '%c', got '%c'\n", c, env->src[env->offset])

        ptr->id = strdup(last_identifier);

        return SUCCESS;
}

/* "externalize" identifier */
int parse_unit_externalize(struct unit_externalise *ptr, struct CompilerEnv *env)
{
        if (skip_spaces(env) == WARNING) {
                return WARNING;
        }

        char c;

        c = env->src[env->offset];
        IDENTIFIER("Expected \"externalize\", got '%c'.\n", c)

        if (strcmp(last_identifier, "externalize") != 0) {
                ERROR("Expected 'externalize' at the beginning of an externalization statement.\n");
                return FAILURE;
        }

        if (skip_spaces(env) == WARNING) {
                ERROR("Failed to parse: Reached end of file after 'externalize', expected identifier.\n");
                return FAILURE;
        }

        c = env->src[env->offset];
        IDENTIFIER("Expected identifier after \"externalize\", got '%c'.\n", c);

        ptr->id = strdup(last_identifier);

        return SUCCESS;
}

#undef IDENTIFIER
#undef EXPECT

__attribute__((unused)) char *isolate_till(char c, struct CompilerEnv *env)
{
        char *buff = NULL;
        size_t i = 0;
        size_t len = 0;

        /* This pass establishes the length of the dynamically-allocated buffer we need */
        while ((env->offset + (i++)) < env->len) {
                if (env->src[env->offset + i] == c) {
                        i--; /* `c` is a closing delimiter, and should not be a part of the isolated string */
                        goto len_estab;
                }
                len++;
        }

        ERROR("Could not find following '%c'.\n", c)
        return NULL;

        len_estab:

        buff = calloc(len + 1, sizeof(char));

        /* Remember: We did not alter env->offset yet, so it will act as out string's origin */
        memccpy(buff, env->src + env->offset, i, sizeof(char));

        env->offset += i;

        return buff;
}
