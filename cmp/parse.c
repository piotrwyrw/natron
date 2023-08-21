//
// Created by Piotr Krzysztof Wyrwas on 22.08.23.
//

#include "parse.h"

#include <string.h>

char last_identifier[MAX_IDEN_LENGTH] = { 0 };

int identifier(struct CompilerEnv *env)
{
        /* Clear the last identifier buffer before writing to it */
        memset(last_identifier, 0, MAX_IDEN_LENGTH);

        char c;
        unsigned int i = 0;
        char *ptr = last_identifier;

        while (IS_LETTER((c = env->src[env->offset + (i ++)]))) {
                *(ptr ++) = c;
                if (ptr > last_identifier + MAX_IDEN_LENGTH)
                        return EXIT_FAILURE; /* We're out of memory for the identifier */
        }

        return EXIT_SUCCESS;
}