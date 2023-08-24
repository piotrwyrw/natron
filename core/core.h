//
// Created by Piotr Krzysztof Wyrwas on 18.08.23.
//

#ifndef NATRON_CORE_H
#define NATRON_CORE_H

#include <stdlib.h>

#ifndef BF_ALLOC_STEP_SIZE
#   define BF_ALLOC_STEP_SIZE 10
#endif

void bf_init(void);

char bf_end(void);

void bf_ptr_inc_n(size_t);

void bf_ptr_dec_n(size_t);

void bf_set(char);

char bf_get(void);

void bf_inc_arr(size_t);

void bf_dec_arr(size_t);

void bf_out_n(size_t);

void bf_in(void);

#endif //NATRON_CORE_H