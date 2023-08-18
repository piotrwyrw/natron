//
// Created by Piotr Krzysztof Wyrwas on 18.08.23.
//

#include "core.h"

#include <stdio.h>
#include <signal.h>
#include <string.h>

unsigned char *arr = NULL;
size_t arr_len = 0;
size_t arr_ix = 0;
char lc = 0xA;

void bf_init() {
    arr_len = 0;
    arr_ix = 0;
    _bf_alloc_nxt();
}

static void _bf_alloc_nxt() {
    size_t _arr_len = arr_len;
    arr_len += BF_ALLOC_STEP_SIZE;

    if (!arr) {
        arr = calloc(arr_len, sizeof(char));
        return;
    }

    void *_arr = arr;

    arr = realloc(arr, arr_len);

    if (arr) {
        // Only fill the newly-allocated portion with 0's
        memset(arr + _arr_len, 0, BF_ALLOC_STEP_SIZE);

        return;
    }

    printf("Reallocation to next step (%ld bytes) failed.\n", arr_len);
    free(_arr);
    raise(SIGTERM);

    // Wait forever to give the signal the best chances of being caught
    BLOCK_EXEC
}

char bf_end() {
    char _c = arr[arr_ix];
    free(arr);
    arr = NULL;
    return _c;
}

void bf_ptr_inc() {
    if (arr_ix + 1 < arr_len)
        arr_ix++;
    else {
        _bf_alloc_nxt();
        bf_ptr_inc();
    }
}

void bf_ptr_dec() {
    if (arr_ix - 1 >= 0)
        arr_ix--;
}

void bf_ptr_inc_n(size_t n) {
    for (size_t i = 0; i < n; i ++)
        bf_ptr_inc();
}

void bf_ptr_dec_n(size_t n) {
    for (size_t i = 0; i < n; i ++)
        bf_ptr_dec();
}

void bf_set(char c) {
    arr[arr_ix] = c;
}

char bf_get() {
    return arr[arr_ix];
}

void bf_out() {
    putchar(arr[arr_ix]);
}

void bf_in() {
    if (lc != '\n')
        putchar('\n');

    printf("@%ld :: ", arr_ix);
    arr[arr_ix] = getc(stdin);
    fflush(stdin);
}
