//
// Created by Piotr Krzysztof Wyrwas on 22.08.23.
//

#include "parse.h"

#include <string.h>

char last_identifier[MAX_IDEN_LENGTH] = {0};

int identifier(struct CompilerEnv *env)
{
        if (!is_letter(env->src[env->offset])) {
                return EXIT_FAILURE;
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
                        return EXIT_FAILURE; /* We're out of memory for the identifier */
                }
        }

        env->offset += i;

        return EXIT_SUCCESS;
}

int skip_spaces(struct CompilerEnv *env)
{
        size_t i = 0;

        while (is_space_ext(env->src[env->offset + (i++)])) {
                if (env->offset + i >= env->len) {
                        return EXIT_FAILURE;
                }
        }

        env->offset += i - 1;

        return EXIT_SUCCESS;
}

char *isolate_till(char c, struct CompilerEnv *env)
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

        ERROR("Could not find following '%c'.\n", c);
        return NULL;

        len_estab:

        buff = calloc(len + 1, sizeof(char));

        /* Remember: We did not alter env->offset yet, so it will act as out string's origin */
        memccpy(buff, env->src + env->offset, i, sizeof(char));

        env->offset += i;

        return buff;
}
