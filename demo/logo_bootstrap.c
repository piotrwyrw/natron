/**
 * Generated by natron
 */

#include <stdlib.h>

void bf_init();

char bf_end();

void bf_ptr_inc_n(size_t);

void bf_ptr_dec_n(size_t);

void bf_inc_arr(size_t);

char bf_dec_arr(size_t);

void bf_in();

void bf_out_n(size_t);

char bf_get();

void fun_logo(void);

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