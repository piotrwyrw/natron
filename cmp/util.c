//
// Created by Piotr Krzysztof Wyrwas on 16.08.23.
//

#include "util.h"

#include <string.h>
#include <stdio.h>

char *_ctimes(char c, size_t n) {
    char *arr = calloc(n + 1, sizeof(char));
    for (size_t i = 0; i < n; i++)
        arr[i] = c;
    return arr;
}

/**
 * Count continuous sequence
 */
size_t countcs(unsigned int org, char *str, char c) {
    size_t n = 0;

    size_t len = strlen(str);

    if (org >= len)
        return 0;

    for (size_t i = org; i < len; i++)
        if (str[i] == c) n++; else break;

    return n;
}

/**
 * Requires a buffer of 12 bytes (characters)
 */
void _loop_id(char * const buff, unsigned int i) {
    memset(buff, 0, 12);
    sprintf(buff, "l%d", i);
}