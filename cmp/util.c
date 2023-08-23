//
// Created by Piotr Krzysztof Wyrwas on 16.08.23.
//

#include "util.h"

#include <string.h>
#include <stdio.h>

char tmp_buffer[TMP_BUFFER_SIZE] = { 0 };

char *repeat(char c, size_t n)
{
        memset(tmp_buffer, 0, TMP_BUFFER_SIZE);
        for (size_t i = 0; i < n; i++)
                tmp_buffer[i] = c;
        return tmp_buffer;
}

/**
 * Count continuous sequence
 */
size_t count_following(size_t org, char *str, char c)
{
        size_t n = 0;

        size_t len = strlen(str);

        if (org >= len)
                return 0;

        for (size_t i = org; i < len; i++)
                if (str[i] == c) n++; else break;

        return n;
}