//
// Created by Piotr Krzysztof Wyrwas on 16.08.23.
//

#include "fio.h"

#include <stdlib.h>

/**
 * Warning: This will reset the file position !
 */
static size_t file_length(FILE *fptr)
{
        fseek(fptr, 0, SEEK_END);

        size_t len = ftell(fptr);

        /* Reset the pointer */
        rewind(fptr);

        return len;
}

static char *file_read_direct(FILE *fptr)
{
        size_t ln = file_length(fptr);

        char *buffer = calloc(ln, sizeof(char));

        if (!buffer)
                return NULL;

        fread(buffer, sizeof(char), ln, fptr);
        return buffer;
}

char *file_read(char *path)
{
        FILE *fptr = fopen(path, "r");

        if (!fptr)
                return NULL;

        char *buff = file_read_direct(fptr);

        fclose(fptr);

        return buff;
}
