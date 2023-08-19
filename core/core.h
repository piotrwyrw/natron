//
// Created by Piotr Krzysztof Wyrwas on 18.08.23.
//

#ifndef BFCMP_CORE_H
#define BFCMP_CORE_H

#include <stdlib.h>

#ifndef BF_ALLOC_STEP_SIZE
#   define BF_ALLOC_STEP_SIZE 10
#endif

#define BLOCK_EXEC for (;;) {}

extern unsigned char *arr; /* The cells the brainfuck program will operate on */
extern size_t arr_len; /* The number of cells / size of the above array. Should not be modified once set. */
extern size_t arr_ix; /* Current index [cell number] */
extern char lc; /* Last character printed by `bf_in()` */

void bf_init();

static void _bf_alloc_nxt();

char bf_end();

void bf_ptr_inc();

void bf_ptr_dec();

void bf_ptr_inc_n(size_t);

void bf_ptr_dec_n(size_t);

void bf_set(char);

char bf_get();

void bf_inc_arr(size_t);

void bf_dec_arr(size_t);

void bf_out();

void bf_out_n(size_t);

void bf_in();

#endif //BFCMP_CORE_H