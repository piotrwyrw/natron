/**
 * Generated by natron
 */

#include <stdlib.h>

extern void bf_init();

extern char bf_end();

extern void bf_ptr_inc_n(size_t);

extern void bf_ptr_dec_n(size_t);

extern void bf_inc_arr(size_t);

extern char bf_dec_arr(size_t);

extern void bf_in();

extern void bf_out_n(size_t);

extern char bf_get();

extern void fun_logo(void);

void fun_proxy_run_logo(void)
{
        fun_logo();
}

void fun_entry(void)
{
        fun_proxy_run_logo();
}

int main(void)
{
        bf_init();
        fun_entry();
        return bf_end();
}