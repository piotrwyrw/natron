//
// Created by Piotr Krzysztof Wyrwas on 16.08.23.
//

#include "fio.h"

#include <stdlib.h>

/**
 * Warning: This will reset the file position !
 */
static size_t _file_ln(FILE *fptr) {
    if (!fptr)
        return 0;

    fseek(fptr, 0, SEEK_END);

    size_t len = ftell(fptr);

    // Reset the pointer
    rewind(fptr);

    return len;
}

static char *_file_rd_direct(FILE *fptr) {
    size_t ln = _file_ln(fptr);

    char *buffer = calloc(ln, sizeof(char));

    if (!buffer)
        return NULL;

    fread(buffer, sizeof(char), ln, fptr);
    return buffer;
}

char *file_rd(char *path) {
    FILE *fptr = fopen(path, "r");

    if (!fptr)
        return NULL;

    char *buff = _file_rd_direct(fptr);

    fclose(fptr);

    return buff;
}
