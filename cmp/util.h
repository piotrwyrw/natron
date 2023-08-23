//
// Created by Piotr Krzysztof Wyrwas on 16.08.23.
//

#ifndef BFCMP_UTIL_H
#define BFCMP_UTIL_H

#include <stdlib.h>

#define TMP_BUFFER_SIZE 100

extern char tmp_buffer[];

char *repeat(char c, size_t n);

size_t count_following(unsigned int org, char *str, char c);

#endif //BFCMP_UTIL_H
