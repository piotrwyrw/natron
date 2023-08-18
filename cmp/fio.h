//
// Created by Piotr Krzysztof Wyrwas on 16.08.23.
//

/**
 * File I/O
 */
#ifndef BFCMP_FIO_H
#define BFCMP_FIO_H

#include <stdio.h>

static size_t _file_ln(FILE *);

static char *_file_rd_direct(FILE *);

char *file_rd(char *);

#endif //BFCMP_FIO_H
