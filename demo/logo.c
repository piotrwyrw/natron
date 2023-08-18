#include <stdio.h>
#include <stdlib.h>

extern void bf_init();
extern char bf_end();
extern void bf_ptr_inc_n(size_t);
extern void bf_ptr_dec_n(size_t);
extern void bf_set(char);
extern char bf_get();
extern void bf_in();
extern void bf_out();

int main(void) {
	bf_init();
	bf_set(bf_get() + 4);
	while (bf_get()) {
		bf_set(bf_get() - 1);
		bf_ptr_inc_n(1);
		bf_set(bf_get() + 8);
		bf_ptr_dec_n(1);
	} // -- 1
	bf_ptr_inc_n(1);
	bf_out();
	while (bf_get()) {
		bf_set(bf_get() - 1);
		bf_ptr_inc_n(1);
		bf_set(bf_get() + 3);
		bf_ptr_dec_n(1);
	} // -- 2
	bf_ptr_inc_n(1);
	bf_set(bf_get() - 1);
	bf_out();
	bf_out();
	bf_set(bf_get() + 1);
	while (bf_get()) {
		bf_set(bf_get() - 1);
		bf_ptr_inc_n(1);
		bf_set(bf_get() + 3);
		bf_ptr_dec_n(1);
	} // -- 3
	bf_ptr_inc_n(1);
	bf_out();
	bf_out();
	bf_out();
	bf_out();
	bf_out();
	bf_out();
	bf_out();
	bf_out();
	bf_out();
	while (bf_get()) {
		bf_set(bf_get() - 1);
		bf_ptr_inc_n(1);
		bf_set(bf_get() + 3);
		bf_ptr_dec_n(1);
	} // -- 4
	bf_ptr_inc_n(1);
	bf_set(bf_get() - 1);
	bf_out();
	bf_out();
	bf_out();
	bf_out();
	bf_out();
	bf_out();
	bf_set(bf_get() + 1);
	while (bf_get()) {
		bf_set(bf_get() - 1);
		bf_ptr_inc_n(1);
		bf_set(bf_get() + 3);
		bf_ptr_dec_n(1);
	} // -- 5
	bf_ptr_inc_n(1);
	bf_out();
	bf_out();
	bf_out();
	bf_out();
	bf_out();
	bf_out();
	bf_out();
	bf_out();
	bf_out();
	bf_out();
	bf_out();
	bf_out();
	bf_out();
	bf_out();
	bf_out();
	bf_out();
	bf_out();
	bf_out();
	bf_out();
	bf_out();
	bf_out();
	bf_out();
	bf_out();
	bf_out();
	bf_out();
	bf_out();
	bf_out();
	bf_out();
	bf_out();
	bf_out();
	bf_out();
	bf_out();
	bf_out();
	bf_out();
	bf_out();
	bf_out();
	bf_out();
	bf_out();
	bf_out();
	bf_out();
	bf_out();
	bf_out();
	bf_out();
	bf_ptr_inc_n(1);
	bf_set(bf_get() + 10);
	bf_out();
	bf_ptr_inc_n(1);
	bf_set(bf_get() - 2);
	while (bf_get()) {
		bf_set(bf_get() - 2);
		bf_ptr_inc_n(1);
		bf_set(bf_get() + 3);
		bf_ptr_dec_n(1);
	} // -- 6
	bf_ptr_inc_n(1);
	bf_set(bf_get() - 1);
	bf_out();
	while (bf_get()) {
		bf_set(bf_get() - 4);
		bf_ptr_inc_n(1);
		bf_set(bf_get() + 1);
		bf_ptr_dec_n(1);
	} // -- 7
	bf_ptr_inc_n(1);
	bf_set(bf_get() + 1);
	bf_out();
	bf_out();
	bf_set(bf_get() - 1);
	while (bf_get()) {
		bf_set(bf_get() - 1);
		bf_ptr_inc_n(1);
		bf_set(bf_get() + 3);
		bf_ptr_dec_n(1);
	} // -- 8
	bf_ptr_inc_n(1);
	bf_set(bf_get() - 1);
	bf_out();
	bf_set(bf_get() + 1);
	while (bf_get()) {
		bf_set(bf_get() - 3);
		bf_ptr_inc_n(1);
		bf_set(bf_get() + 1);
		bf_ptr_dec_n(1);
	} // -- 9
	bf_ptr_inc_n(1);
	bf_set(bf_get() + 1);
	bf_out();
	bf_out();
	bf_out();
	bf_out();
	bf_out();
	bf_out();
	bf_out();
	while (bf_get()) {
		bf_set(bf_get() - 2);
		bf_ptr_inc_n(1);
		bf_set(bf_get() + 3);
		bf_ptr_dec_n(1);
	} // -- 10
	bf_ptr_inc_n(1);
	bf_set(bf_get() - 1);
	bf_out();
	bf_set(bf_get() + 1);
	while (bf_get()) {
		bf_set(bf_get() - 3);
		bf_ptr_inc_n(1);
		bf_set(bf_get() + 2);
		bf_ptr_dec_n(1);
	} // -- 11
	bf_ptr_inc_n(1);
	bf_out();
	bf_out();
	bf_out();
	bf_out();
	bf_out();
	bf_out();
	bf_set(bf_get() - 1);
	while (bf_get()) {
		bf_set(bf_get() - 1);
		bf_ptr_inc_n(1);
		bf_set(bf_get() + 3);
		bf_ptr_dec_n(1);
	} // -- 12
	bf_ptr_inc_n(1);
	bf_set(bf_get() - 1);
	bf_out();
	bf_set(bf_get() + 1);
	while (bf_get()) {
		bf_set(bf_get() - 3);
		bf_ptr_inc_n(1);
		bf_set(bf_get() + 1);
		bf_ptr_dec_n(1);
	} // -- 13
	bf_ptr_inc_n(1);
	bf_set(bf_get() + 1);
	bf_out();
	bf_out();
	bf_out();
	bf_out();
	bf_out();
	bf_out();
	bf_out();
	bf_out();
	bf_out();
	bf_out();
	bf_out();
	bf_out();
	bf_out();
	bf_out();
	bf_out();
	bf_out();
	bf_out();
	bf_out();
	bf_out();
	bf_out();
	bf_out();
	bf_out();
	bf_out();
	bf_out();
	bf_out();
	bf_out();
	bf_out();
	bf_out();
	bf_out();
	bf_out();
	bf_out();
	bf_out();
	bf_out();
	bf_out();
	bf_out();
	bf_out();
	bf_out();
	bf_out();
	bf_out();
	bf_out();
	bf_out();
	bf_out();
	bf_ptr_inc_n(1);
	bf_set(bf_get() + 10);
	bf_out();
	bf_ptr_inc_n(1);
	bf_set(bf_get() - 2);
	while (bf_get()) {
		bf_set(bf_get() - 2);
		bf_ptr_inc_n(1);
		bf_set(bf_get() + 3);
		bf_ptr_dec_n(1);
	} // -- 14
	bf_ptr_inc_n(1);
	bf_set(bf_get() - 1);
	bf_out();
	while (bf_get()) {
		bf_set(bf_get() - 4);
		bf_ptr_inc_n(1);
		bf_set(bf_get() + 1);
		bf_ptr_dec_n(1);
	} // -- 15
	bf_ptr_inc_n(1);
	bf_set(bf_get() + 1);
	bf_out();
	bf_set(bf_get() + 4);
	bf_out();
	bf_out();
	bf_set(bf_get() - 1);
	while (bf_get()) {
		bf_set(bf_get() - 3);
		bf_ptr_inc_n(1);
		bf_set(bf_get() + 1);
		bf_ptr_dec_n(1);
	} // -- 16
	bf_ptr_inc_n(1);
	bf_set(bf_get() - 2);
	bf_out();
	bf_out();
	bf_out();
	bf_out();
	bf_set(bf_get() + 1);
	while (bf_get()) {
		bf_set(bf_get() - 1);
		bf_ptr_inc_n(1);
		bf_set(bf_get() + 3);
		bf_ptr_dec_n(1);
	} // -- 17
	bf_ptr_inc_n(1);
	bf_out();
	bf_out();
	bf_set(bf_get() - 1);
	while (bf_get()) {
		bf_set(bf_get() - 1);
		bf_ptr_inc_n(1);
		bf_set(bf_get() + 4);
		bf_ptr_dec_n(1);
	} // -- 18
	bf_ptr_inc_n(1);
	bf_out();
	while (bf_get()) {
		bf_set(bf_get() - 4);
		bf_ptr_inc_n(1);
		bf_set(bf_get() + 1);
		bf_ptr_dec_n(1);
	} // -- 19
	bf_ptr_inc_n(1);
	bf_set(bf_get() + 1);
	bf_out();
	bf_out();
	bf_set(bf_get() + 4);
	bf_out();
	bf_out();
	bf_out();
	bf_out();
	bf_out();
	bf_out();
	while (bf_get()) {
		bf_set(bf_get() + 4);
		bf_ptr_inc_n(1);
		bf_set(bf_get() - 3);
		bf_ptr_dec_n(1);
	} // -- 20
	bf_ptr_inc_n(1);
	bf_set(bf_get() + 1);
	bf_out();
	bf_set(bf_get() + 1);
	while (bf_get()) {
		bf_set(bf_get() - 3);
		bf_ptr_inc_n(1);
		bf_set(bf_get() + 1);
		bf_ptr_dec_n(1);
	} // -- 21
	bf_ptr_inc_n(1);
	bf_set(bf_get() + 1);
	bf_out();
	bf_out();
	bf_out();
	bf_out();
	bf_out();
	bf_out();
	bf_out();
	bf_out();
	bf_out();
	while (bf_get()) {
		bf_set(bf_get() - 1);
		bf_ptr_inc_n(1);
		bf_set(bf_get() + 3);
		bf_ptr_dec_n(1);
	} // -- 22
	bf_ptr_inc_n(1);
	bf_set(bf_get() - 1);
	bf_out();
	bf_out();
	bf_out();
	bf_out();
	bf_out();
	bf_out();
	bf_out();
	bf_set(bf_get() + 1);
	while (bf_get()) {
		bf_set(bf_get() - 1);
		bf_ptr_inc_n(1);
		bf_set(bf_get() + 3);
		bf_ptr_dec_n(1);
	} // -- 23
	bf_ptr_inc_n(1);
	bf_out();
	bf_out();
	while (bf_get()) {
		bf_set(bf_get() - 1);
		bf_ptr_inc_n(1);
		bf_set(bf_get() + 3);
		bf_ptr_dec_n(1);
	} // -- 24
	bf_ptr_inc_n(1);
	bf_set(bf_get() - 1);
	bf_out();
	bf_out();
	bf_out();
	bf_out();
	bf_out();
	bf_out();
	bf_set(bf_get() + 1);
	while (bf_get()) {
		bf_set(bf_get() - 1);
		bf_ptr_inc_n(1);
		bf_set(bf_get() + 3);
		bf_ptr_dec_n(1);
	} // -- 25
	bf_ptr_inc_n(1);
	bf_out();
	while (bf_get()) {
		bf_set(bf_get() - 1);
		bf_ptr_inc_n(1);
		bf_set(bf_get() + 3);
		bf_ptr_dec_n(1);
	} // -- 26
	bf_ptr_inc_n(1);
	bf_set(bf_get() - 1);
	bf_out();
	bf_out();
	bf_out();
	bf_out();
	bf_set(bf_get() + 1);
	while (bf_get()) {
		bf_set(bf_get() - 1);
		bf_ptr_inc_n(1);
		bf_set(bf_get() + 3);
		bf_ptr_dec_n(1);
	} // -- 27
	bf_ptr_inc_n(1);
	bf_out();
	bf_out();
	bf_out();
	bf_out();
	while (bf_get()) {
		bf_set(bf_get() - 1);
		bf_ptr_inc_n(1);
		bf_set(bf_get() + 3);
		bf_ptr_dec_n(1);
	} // -- 28
	bf_ptr_inc_n(1);
	bf_set(bf_get() - 1);
	bf_out();
	bf_out();
	bf_out();
	bf_out();
	bf_out();
	bf_out();
	bf_set(bf_get() + 1);
	while (bf_get()) {
		bf_set(bf_get() - 1);
		bf_ptr_inc_n(1);
		bf_set(bf_get() + 3);
		bf_ptr_dec_n(1);
	} // -- 29
	bf_ptr_inc_n(1);
	bf_out();
	bf_out();
	bf_ptr_inc_n(1);
	bf_set(bf_get() + 10);
	bf_out();
	bf_ptr_inc_n(1);
	bf_set(bf_get() - 2);
	while (bf_get()) {
		bf_set(bf_get() - 2);
		bf_ptr_inc_n(1);
		bf_set(bf_get() + 3);
		bf_ptr_dec_n(1);
	} // -- 30
	bf_ptr_inc_n(1);
	bf_set(bf_get() - 1);
	bf_out();
	while (bf_get()) {
		bf_set(bf_get() - 4);
		bf_ptr_inc_n(1);
		bf_set(bf_get() + 1);
		bf_ptr_dec_n(1);
	} // -- 31
	bf_ptr_inc_n(1);
	bf_set(bf_get() + 1);
	bf_out();
	bf_set(bf_get() + 4);
	bf_out();
	bf_out();
	bf_set(bf_get() - 4);
	bf_out();
	bf_out();
	bf_out();
	bf_out();
	bf_set(bf_get() - 1);
	while (bf_get()) {
		bf_set(bf_get() - 1);
		bf_ptr_inc_n(1);
		bf_set(bf_get() + 3);
		bf_ptr_dec_n(1);
	} // -- 32
	bf_ptr_inc_n(1);
	bf_set(bf_get() - 1);
	bf_out();
	bf_set(bf_get() + 1);
	while (bf_get()) {
		bf_set(bf_get() - 3);
		bf_ptr_inc_n(1);
		bf_set(bf_get() + 1);
		bf_ptr_dec_n(1);
	} // -- 33
	bf_ptr_inc_n(1);
	bf_set(bf_get() + 1);
	bf_out();
	bf_set(bf_get() - 1);
	while (bf_get()) {
		bf_set(bf_get() - 1);
		bf_ptr_inc_n(1);
		bf_set(bf_get() + 4);
		bf_ptr_dec_n(1);
	} // -- 34
	bf_ptr_inc_n(1);
	bf_out();
	while (bf_get()) {
		bf_set(bf_get() - 4);
		bf_ptr_inc_n(1);
		bf_set(bf_get() + 1);
		bf_ptr_dec_n(1);
	} // -- 35
	bf_ptr_inc_n(1);
	bf_set(bf_get() + 1);
	bf_out();
	bf_set(bf_get() + 4);
	bf_out();
	bf_out();
	bf_set(bf_get() - 1);
	while (bf_get()) {
		bf_set(bf_get() - 3);
		bf_ptr_inc_n(1);
		bf_set(bf_get() + 1);
		bf_ptr_dec_n(1);
	} // -- 36
	bf_ptr_inc_n(1);
	bf_set(bf_get() - 2);
	bf_out();
	bf_set(bf_get() + 1);
	while (bf_get()) {
		bf_set(bf_get() - 1);
		bf_ptr_inc_n(1);
		bf_set(bf_get() + 3);
		bf_ptr_dec_n(1);
	} // -- 37
	bf_ptr_inc_n(1);
	bf_out();
	bf_out();
	bf_set(bf_get() - 1);
	while (bf_get()) {
		bf_set(bf_get() - 1);
		bf_ptr_inc_n(1);
		bf_set(bf_get() + 3);
		bf_ptr_dec_n(1);
	} // -- 38
	bf_ptr_inc_n(1);
	bf_set(bf_get() - 1);
	bf_out();
	bf_set(bf_get() - 1);
	while (bf_get()) {
		bf_set(bf_get() - 3);
		bf_ptr_inc_n(1);
		bf_set(bf_get() + 4);
		bf_ptr_dec_n(1);
	} // -- 39
	bf_ptr_inc_n(1);
	bf_out();
	bf_out();
	bf_set(bf_get() - 1);
	while (bf_get()) {
		bf_set(bf_get() - 3);
		bf_ptr_inc_n(1);
		bf_set(bf_get() + 1);
		bf_ptr_dec_n(1);
	} // -- 40
	bf_ptr_inc_n(1);
	bf_set(bf_get() - 2);
	bf_out();
	bf_out();
	bf_out();
	bf_out();
	bf_out();
	bf_out();
	bf_set(bf_get() + 1);
	while (bf_get()) {
		bf_set(bf_get() - 1);
		bf_ptr_inc_n(1);
		bf_set(bf_get() + 3);
		bf_ptr_dec_n(1);
	} // -- 41
	bf_ptr_inc_n(1);
	bf_out();
	bf_out();
	while (bf_get()) {
		bf_set(bf_get() - 2);
		bf_ptr_inc_n(1);
		bf_set(bf_get() + 3);
		bf_ptr_dec_n(1);
	} // -- 42
	bf_ptr_inc_n(1);
	bf_set(bf_get() - 1);
	bf_out();
	bf_set(bf_get() + 1);
	while (bf_get()) {
		bf_set(bf_get() - 3);
		bf_ptr_inc_n(1);
		bf_set(bf_get() + 2);
		bf_ptr_dec_n(1);
	} // -- 43
	bf_ptr_inc_n(1);
	bf_out();
	bf_out();
	bf_out();
	bf_out();
	bf_out();
	bf_out();
	bf_out();
	bf_set(bf_get() - 1);
	while (bf_get()) {
		bf_set(bf_get() - 1);
		bf_ptr_inc_n(1);
		bf_set(bf_get() + 3);
		bf_ptr_dec_n(1);
	} // -- 44
	bf_ptr_inc_n(1);
	bf_set(bf_get() - 1);
	bf_out();
	bf_set(bf_get() + 1);
	while (bf_get()) {
		bf_set(bf_get() - 3);
		bf_ptr_inc_n(1);
		bf_set(bf_get() + 4);
		bf_ptr_dec_n(1);
	} // -- 45
	bf_ptr_inc_n(1);
	bf_out();
	while (bf_get()) {
		bf_set(bf_get() - 4);
		bf_ptr_inc_n(1);
		bf_set(bf_get() + 1);
		bf_ptr_dec_n(1);
	} // -- 46
	bf_ptr_inc_n(1);
	bf_set(bf_get() + 1);
	bf_out();
	bf_out();
	bf_out();
	bf_out();
	bf_out();
	bf_out();
	bf_set(bf_get() - 1);
	while (bf_get()) {
		bf_set(bf_get() - 1);
		bf_ptr_inc_n(1);
		bf_set(bf_get() + 3);
		bf_ptr_dec_n(1);
	} // -- 47
	bf_ptr_inc_n(1);
	bf_set(bf_get() - 1);
	bf_out();
	bf_set(bf_get() + 1);
	while (bf_get()) {
		bf_set(bf_get() - 3);
		bf_ptr_inc_n(1);
		bf_set(bf_get() + 1);
		bf_ptr_dec_n(1);
	} // -- 48
	bf_ptr_inc_n(1);
	bf_set(bf_get() + 1);
	bf_out();
	bf_out();
	bf_out();
	bf_out();
	bf_set(bf_get() - 1);
	while (bf_get()) {
		bf_set(bf_get() - 1);
		bf_ptr_inc_n(1);
		bf_set(bf_get() + 3);
		bf_ptr_dec_n(1);
	} // -- 49
	bf_ptr_inc_n(1);
	bf_set(bf_get() - 1);
	bf_out();
	bf_set(bf_get() + 1);
	while (bf_get()) {
		bf_set(bf_get() - 3);
		bf_ptr_inc_n(1);
		bf_set(bf_get() + 1);
		bf_ptr_dec_n(1);
	} // -- 50
	bf_ptr_inc_n(1);
	bf_set(bf_get() + 1);
	bf_out();
	bf_out();
	while (bf_get()) {
		bf_set(bf_get() - 2);
		bf_ptr_inc_n(1);
		bf_set(bf_get() + 3);
		bf_ptr_dec_n(1);
	} // -- 51
	bf_ptr_inc_n(1);
	bf_set(bf_get() - 1);
	bf_out();
	bf_set(bf_get() + 1);
	while (bf_get()) {
		bf_set(bf_get() - 3);
		bf_ptr_inc_n(1);
		bf_set(bf_get() + 2);
		bf_ptr_dec_n(1);
	} // -- 52
	bf_ptr_inc_n(1);
	bf_out();
	bf_out();
	bf_out();
	bf_out();
	bf_out();
	bf_out();
	bf_set(bf_get() - 1);
	while (bf_get()) {
		bf_set(bf_get() - 1);
		bf_ptr_inc_n(1);
		bf_set(bf_get() + 3);
		bf_ptr_dec_n(1);
	} // -- 53
	bf_ptr_inc_n(1);
	bf_set(bf_get() - 1);
	bf_out();
	bf_set(bf_get() + 1);
	while (bf_get()) {
		bf_set(bf_get() - 3);
		bf_ptr_inc_n(1);
		bf_set(bf_get() + 1);
		bf_ptr_dec_n(1);
	} // -- 54
	bf_ptr_inc_n(1);
	bf_set(bf_get() + 1);
	bf_out();
	bf_ptr_inc_n(1);
	bf_set(bf_get() + 10);
	bf_out();
	bf_ptr_inc_n(1);
	bf_set(bf_get() - 2);
	while (bf_get()) {
		bf_set(bf_get() - 2);
		bf_ptr_inc_n(1);
		bf_set(bf_get() + 3);
		bf_ptr_dec_n(1);
	} // -- 55
	bf_ptr_inc_n(1);
	bf_set(bf_get() - 1);
	bf_out();
	while (bf_get()) {
		bf_set(bf_get() - 4);
		bf_ptr_inc_n(1);
		bf_set(bf_get() + 1);
		bf_ptr_dec_n(1);
	} // -- 56
	bf_ptr_inc_n(1);
	bf_set(bf_get() + 1);
	bf_out();
	bf_set(bf_get() + 4);
	bf_out();
	bf_out();
	bf_out();
	bf_out();
	bf_out();
	bf_out();
	bf_out();
	while (bf_get()) {
		bf_set(bf_get() + 4);
		bf_ptr_inc_n(1);
		bf_set(bf_get() - 3);
		bf_ptr_dec_n(1);
	} // -- 57
	bf_ptr_inc_n(1);
	bf_set(bf_get() + 1);
	bf_out();
	bf_set(bf_get() + 1);
	while (bf_get()) {
		bf_set(bf_get() - 3);
		bf_ptr_inc_n(1);
		bf_set(bf_get() + 4);
		bf_ptr_dec_n(1);
	} // -- 58
	bf_ptr_inc_n(1);
	bf_out();
	while (bf_get()) {
		bf_set(bf_get() - 4);
		bf_ptr_inc_n(1);
		bf_set(bf_get() + 1);
		bf_ptr_dec_n(1);
	} // -- 59
	bf_ptr_inc_n(1);
	bf_set(bf_get() + 1);
	bf_out();
	bf_set(bf_get() + 4);
	bf_out();
	bf_out();
	bf_set(bf_get() - 4);
	bf_out();
	bf_set(bf_get() - 1);
	while (bf_get()) {
		bf_set(bf_get() - 1);
		bf_ptr_inc_n(1);
		bf_set(bf_get() + 3);
		bf_ptr_dec_n(1);
	} // -- 60
	bf_ptr_inc_n(1);
	bf_set(bf_get() - 1);
	bf_out();
	bf_set(bf_get() + 1);
	while (bf_get()) {
		bf_set(bf_get() - 3);
		bf_ptr_inc_n(1);
		bf_set(bf_get() + 1);
		bf_ptr_dec_n(1);
	} // -- 61
	bf_ptr_inc_n(1);
	bf_set(bf_get() + 1);
	bf_out();
	bf_out();
	bf_out();
	bf_set(bf_get() - 1);
	while (bf_get()) {
		bf_set(bf_get() - 1);
		bf_ptr_inc_n(1);
		bf_set(bf_get() + 4);
		bf_ptr_dec_n(1);
	} // -- 62
	bf_ptr_inc_n(1);
	bf_out();
	while (bf_get()) {
		bf_set(bf_get() - 4);
		bf_ptr_inc_n(1);
		bf_set(bf_get() + 1);
		bf_ptr_dec_n(1);
	} // -- 63
	bf_ptr_inc_n(1);
	bf_set(bf_get() + 1);
	bf_out();
	bf_out();
	bf_out();
	bf_out();
	bf_out();
	bf_out();
	bf_set(bf_get() - 1);
	while (bf_get()) {
		bf_set(bf_get() - 1);
		bf_ptr_inc_n(1);
		bf_set(bf_get() + 3);
		bf_ptr_dec_n(1);
	} // -- 64
	bf_ptr_inc_n(1);
	bf_set(bf_get() - 1);
	bf_out();
	bf_set(bf_get() + 1);
	while (bf_get()) {
		bf_set(bf_get() - 3);
		bf_ptr_inc_n(1);
		bf_set(bf_get() + 4);
		bf_ptr_dec_n(1);
	} // -- 65
	bf_ptr_inc_n(1);
	bf_out();
	while (bf_get()) {
		bf_set(bf_get() - 4);
		bf_ptr_inc_n(1);
		bf_set(bf_get() + 1);
		bf_ptr_dec_n(1);
	} // -- 66
	bf_ptr_inc_n(1);
	bf_set(bf_get() + 1);
	bf_out();
	bf_out();
	bf_set(bf_get() + 4);
	bf_out();
	bf_out();
	bf_out();
	bf_out();
	bf_out();
	bf_out();
	bf_out();
	while (bf_get()) {
		bf_set(bf_get() - 5);
		bf_ptr_inc_n(1);
		bf_set(bf_get() + 3);
		bf_ptr_dec_n(1);
	} // -- 67
	bf_ptr_inc_n(1);
	bf_out();
	while (bf_get()) {
		bf_set(bf_get() - 4);
		bf_ptr_inc_n(1);
		bf_set(bf_get() + 1);
		bf_ptr_dec_n(1);
	} // -- 68
	bf_ptr_inc_n(1);
	bf_set(bf_get() + 1);
	bf_out();
	bf_set(bf_get() + 4);
	bf_out();
	bf_out();
	bf_out();
	bf_out();
	bf_out();
	bf_out();
	while (bf_get()) {
		bf_set(bf_get() + 4);
		bf_ptr_inc_n(1);
		bf_set(bf_get() - 3);
		bf_ptr_dec_n(1);
	} // -- 69
	bf_ptr_inc_n(1);
	bf_set(bf_get() + 1);
	bf_out();
	bf_set(bf_get() - 1);
	while (bf_get()) {
		bf_set(bf_get() - 3);
		bf_ptr_inc_n(1);
		bf_set(bf_get() + 4);
		bf_ptr_dec_n(1);
	} // -- 70
	bf_ptr_inc_n(1);
	bf_out();
	bf_out();
	bf_out();
	bf_out();
	while (bf_get()) {
		bf_set(bf_get() + 4);
		bf_ptr_inc_n(1);
		bf_set(bf_get() - 3);
		bf_ptr_dec_n(1);
	} // -- 71
	bf_ptr_inc_n(1);
	bf_set(bf_get() + 1);
	bf_out();
	bf_set(bf_get() + 1);
	while (bf_get()) {
		bf_set(bf_get() - 3);
		bf_ptr_inc_n(1);
		bf_set(bf_get() + 4);
		bf_ptr_dec_n(1);
	} // -- 72
	bf_ptr_inc_n(1);
	bf_out();
	while (bf_get()) {
		bf_set(bf_get() - 4);
		bf_ptr_inc_n(1);
		bf_set(bf_get() + 1);
		bf_ptr_dec_n(1);
	} // -- 73
	bf_ptr_inc_n(1);
	bf_set(bf_get() + 1);
	bf_out();
	bf_out();
	bf_set(bf_get() + 4);
	bf_out();
	bf_out();
	bf_out();
	bf_out();
	bf_out();
	bf_out();
	while (bf_get()) {
		bf_set(bf_get() + 4);
		bf_ptr_inc_n(1);
		bf_set(bf_get() - 3);
		bf_ptr_dec_n(1);
	} // -- 74
	bf_ptr_inc_n(1);
	bf_set(bf_get() + 1);
	bf_out();
	while (bf_get()) {
		bf_set(bf_get() + 2);
		bf_ptr_inc_n(1);
		bf_set(bf_get() - 3);
		bf_ptr_dec_n(1);
	} // -- 75
	bf_ptr_inc_n(1);
	bf_out();
	bf_ptr_inc_n(1);
	bf_set(bf_get() - 2);
	while (bf_get()) {
		bf_set(bf_get() - 2);
		bf_ptr_inc_n(1);
		bf_set(bf_get() + 3);
		bf_ptr_dec_n(1);
	} // -- 76
	bf_ptr_inc_n(1);
	bf_set(bf_get() - 1);
	bf_out();
	while (bf_get()) {
		bf_set(bf_get() - 4);
		bf_ptr_inc_n(1);
		bf_set(bf_get() + 1);
		bf_ptr_dec_n(1);
	} // -- 77
	bf_ptr_inc_n(1);
	bf_set(bf_get() + 1);
	bf_out();
	bf_set(bf_get() + 4);
	bf_out();
	bf_out();
	bf_set(bf_get() - 4);
	bf_out();
	bf_out();
	bf_set(bf_get() - 1);
	while (bf_get()) {
		bf_set(bf_get() - 1);
		bf_ptr_inc_n(1);
		bf_set(bf_get() + 4);
		bf_ptr_dec_n(1);
	} // -- 78
	bf_ptr_inc_n(1);
	bf_out();
	while (bf_get()) {
		bf_set(bf_get() - 4);
		bf_ptr_inc_n(1);
		bf_set(bf_get() + 1);
		bf_ptr_dec_n(1);
	} // -- 79
	bf_ptr_inc_n(1);
	bf_set(bf_get() + 1);
	bf_out();
	bf_set(bf_get() + 4);
	bf_out();
	bf_out();
	while (bf_get()) {
		bf_set(bf_get() - 5);
		bf_ptr_inc_n(1);
		bf_set(bf_get() + 3);
		bf_ptr_dec_n(1);
	} // -- 80
	bf_ptr_inc_n(1);
	bf_out();
	while (bf_get()) {
		bf_set(bf_get() - 4);
		bf_ptr_inc_n(1);
		bf_set(bf_get() + 1);
		bf_ptr_dec_n(1);
	} // -- 81
	bf_ptr_inc_n(1);
	bf_set(bf_get() + 1);
	bf_out();
	bf_set(bf_get() + 4);
	bf_out();
	bf_out();
	bf_out();
	bf_out();
	bf_set(bf_get() - 4);
	bf_out();
	bf_out();
	bf_out();
	bf_out();
	bf_set(bf_get() - 1);
	while (bf_get()) {
		bf_set(bf_get() - 1);
		bf_ptr_inc_n(1);
		bf_set(bf_get() + 3);
		bf_ptr_dec_n(1);
	} // -- 82
	bf_ptr_inc_n(1);
	bf_set(bf_get() - 1);
	bf_out();
	bf_set(bf_get() - 1);
	while (bf_get()) {
		bf_set(bf_get() - 3);
		bf_ptr_inc_n(1);
		bf_set(bf_get() + 4);
		bf_ptr_dec_n(1);
	} // -- 83
	bf_ptr_inc_n(1);
	bf_out();
	bf_out();
	bf_out();
	bf_out();
	bf_out();
	bf_out();
	while (bf_get()) {
		bf_set(bf_get() - 5);
		bf_ptr_inc_n(1);
		bf_set(bf_get() + 3);
		bf_ptr_dec_n(1);
	} // -- 84
	bf_ptr_inc_n(1);
	bf_out();
	while (bf_get()) {
		bf_set(bf_get() - 4);
		bf_ptr_inc_n(1);
		bf_set(bf_get() + 1);
		bf_ptr_dec_n(1);
	} // -- 85
	bf_ptr_inc_n(1);
	bf_set(bf_get() + 1);
	bf_out();
	bf_set(bf_get() + 4);
	bf_out();
	bf_out();
	bf_set(bf_get() - 4);
	bf_out();
	bf_out();
	bf_out();
	bf_out();
	bf_out();
	bf_out();
	bf_set(bf_get() - 1);
	while (bf_get()) {
		bf_set(bf_get() - 1);
		bf_ptr_inc_n(1);
		bf_set(bf_get() + 4);
		bf_ptr_dec_n(1);
	} // -- 86
	bf_ptr_inc_n(1);
	bf_out();
	while (bf_get()) {
		bf_set(bf_get() - 4);
		bf_ptr_inc_n(1);
		bf_set(bf_get() + 1);
		bf_ptr_dec_n(1);
	} // -- 87
	bf_ptr_inc_n(1);
	bf_set(bf_get() + 1);
	bf_out();
	bf_set(bf_get() + 4);
	bf_out();
	bf_out();
	bf_set(bf_get() - 4);
	bf_out();
	bf_set(bf_get() - 1);
	while (bf_get()) {
		bf_set(bf_get() - 1);
		bf_ptr_inc_n(1);
		bf_set(bf_get() + 4);
		bf_ptr_dec_n(1);
	} // -- 88
	bf_ptr_inc_n(1);
	bf_out();
	while (bf_get()) {
		bf_set(bf_get() - 4);
		bf_ptr_inc_n(1);
		bf_set(bf_get() + 1);
		bf_ptr_dec_n(1);
	} // -- 89
	bf_ptr_inc_n(1);
	bf_set(bf_get() + 1);
	bf_out();
	bf_set(bf_get() + 4);
	bf_out();
	bf_out();
	bf_set(bf_get() - 4);
	bf_out();
	bf_set(bf_get() - 1);
	while (bf_get()) {
		bf_set(bf_get() - 1);
		bf_ptr_inc_n(1);
		bf_set(bf_get() + 4);
		bf_ptr_dec_n(1);
	} // -- 90
	bf_ptr_inc_n(1);
	bf_out();
	while (bf_get()) {
		bf_set(bf_get() - 4);
		bf_ptr_inc_n(1);
		bf_set(bf_get() + 1);
		bf_ptr_dec_n(1);
	} // -- 91
	bf_ptr_inc_n(1);
	bf_set(bf_get() + 1);
	bf_out();
	bf_set(bf_get() + 4);
	bf_out();
	bf_out();
	while (bf_get()) {
		bf_set(bf_get() - 5);
		bf_ptr_inc_n(1);
		bf_set(bf_get() + 3);
		bf_ptr_dec_n(1);
	} // -- 92
	bf_ptr_inc_n(1);
	bf_out();
	while (bf_get()) {
		bf_set(bf_get() - 4);
		bf_ptr_inc_n(1);
		bf_set(bf_get() + 1);
		bf_ptr_dec_n(1);
	} // -- 93
	bf_ptr_inc_n(1);
	bf_set(bf_get() + 1);
	bf_out();
	bf_set(bf_get() + 4);
	bf_out();
	bf_out();
	bf_set(bf_get() - 4);
	bf_out();
	bf_out();
	bf_set(bf_get() - 1);
	while (bf_get()) {
		bf_set(bf_get() - 1);
		bf_ptr_inc_n(1);
		bf_set(bf_get() + 4);
		bf_ptr_dec_n(1);
	} // -- 94
	bf_ptr_inc_n(1);
	bf_out();
	while (bf_get()) {
		bf_set(bf_get() - 4);
		bf_ptr_inc_n(1);
		bf_set(bf_get() + 1);
		bf_ptr_dec_n(1);
	} // -- 95
	bf_ptr_inc_n(1);
	bf_set(bf_get() + 1);
	bf_out();
	bf_set(bf_get() + 4);
	bf_out();
	bf_out();
	bf_ptr_inc_n(1);
	bf_set(bf_get() + 10);
	bf_out();
	bf_ptr_inc_n(1);
	bf_set(bf_get() - 2);
	while (bf_get()) {
		bf_set(bf_get() - 2);
		bf_ptr_inc_n(1);
		bf_set(bf_get() + 3);
		bf_ptr_dec_n(1);
	} // -- 96
	bf_ptr_inc_n(1);
	bf_set(bf_get() - 1);
	bf_out();
	while (bf_get()) {
		bf_set(bf_get() - 4);
		bf_ptr_inc_n(1);
		bf_set(bf_get() + 1);
		bf_ptr_dec_n(1);
	} // -- 97
	bf_ptr_inc_n(1);
	bf_set(bf_get() + 1);
	bf_out();
	bf_set(bf_get() + 4);
	bf_out();
	bf_out();
	bf_set(bf_get() - 1);
	while (bf_get()) {
		bf_set(bf_get() - 3);
		bf_ptr_inc_n(1);
		bf_set(bf_get() + 1);
		bf_ptr_dec_n(1);
	} // -- 98
	bf_ptr_inc_n(1);
	bf_set(bf_get() - 2);
	bf_out();
	bf_out();
	bf_set(bf_get() - 1);
	while (bf_get()) {
		bf_set(bf_get() - 2);
		bf_ptr_inc_n(1);
		bf_set(bf_get() + 1);
		bf_ptr_dec_n(1);
	} // -- 99
	bf_ptr_inc_n(1);
	bf_out();
	bf_set(bf_get() + 1);
	while (bf_get()) {
		bf_set(bf_get() - 3);
		bf_ptr_inc_n(1);
		bf_set(bf_get() + 2);
		bf_ptr_dec_n(1);
	} // -- 100
	bf_ptr_inc_n(1);
	bf_out();
	bf_set(bf_get() + 4);
	bf_out();
	bf_out();
	while (bf_get()) {
		bf_set(bf_get() - 5);
		bf_ptr_inc_n(1);
		bf_set(bf_get() + 3);
		bf_ptr_dec_n(1);
	} // -- 101
	bf_ptr_inc_n(1);
	bf_out();
	while (bf_get()) {
		bf_set(bf_get() - 4);
		bf_ptr_inc_n(1);
		bf_set(bf_get() + 1);
		bf_ptr_dec_n(1);
	} // -- 102
	bf_ptr_inc_n(1);
	bf_set(bf_get() + 1);
	bf_out();
	bf_set(bf_get() + 4);
	bf_out();
	bf_out();
	bf_set(bf_get() - 4);
	bf_out();
	bf_out();
	bf_out();
	bf_out();
	bf_out();
	bf_out();
	bf_out();
	bf_out();
	bf_out();
	bf_out();
	bf_out();
	bf_out();
	bf_out();
	bf_set(bf_get() - 1);
	while (bf_get()) {
		bf_set(bf_get() - 1);
		bf_ptr_inc_n(1);
		bf_set(bf_get() + 4);
		bf_ptr_dec_n(1);
	} // -- 103
	bf_ptr_inc_n(1);
	bf_out();
	while (bf_get()) {
		bf_set(bf_get() - 4);
		bf_ptr_inc_n(1);
		bf_set(bf_get() + 1);
		bf_ptr_dec_n(1);
	} // -- 104
	bf_ptr_inc_n(1);
	bf_set(bf_get() + 1);
	bf_out();
	bf_set(bf_get() + 4);
	bf_out();
	bf_out();
	bf_set(bf_get() - 1);
	while (bf_get()) {
		bf_set(bf_get() - 3);
		bf_ptr_inc_n(1);
		bf_set(bf_get() + 1);
		bf_ptr_dec_n(1);
	} // -- 105
	bf_ptr_inc_n(1);
	bf_set(bf_get() - 2);
	bf_out();
	bf_out();
	bf_out();
	bf_out();
	bf_out();
	bf_set(bf_get() + 1);
	while (bf_get()) {
		bf_set(bf_get() - 1);
		bf_ptr_inc_n(1);
		bf_set(bf_get() + 3);
		bf_ptr_dec_n(1);
	} // -- 106
	bf_ptr_inc_n(1);
	bf_out();
	bf_set(bf_get() - 1);
	while (bf_get()) {
		bf_set(bf_get() - 1);
		bf_ptr_inc_n(1);
		bf_set(bf_get() + 4);
		bf_ptr_dec_n(1);
	} // -- 107
	bf_ptr_inc_n(1);
	bf_out();
	while (bf_get()) {
		bf_set(bf_get() - 4);
		bf_ptr_inc_n(1);
		bf_set(bf_get() + 1);
		bf_ptr_dec_n(1);
	} // -- 108
	bf_ptr_inc_n(1);
	bf_set(bf_get() + 1);
	bf_out();
	bf_set(bf_get() + 4);
	bf_out();
	bf_out();
	bf_set(bf_get() - 4);
	bf_out();
	bf_set(bf_get() - 1);
	while (bf_get()) {
		bf_set(bf_get() - 1);
		bf_ptr_inc_n(1);
		bf_set(bf_get() + 4);
		bf_ptr_dec_n(1);
	} // -- 109
	bf_ptr_inc_n(1);
	bf_out();
	while (bf_get()) {
		bf_set(bf_get() - 4);
		bf_ptr_inc_n(1);
		bf_set(bf_get() + 1);
		bf_ptr_dec_n(1);
	} // -- 110
	bf_ptr_inc_n(1);
	bf_set(bf_get() + 1);
	bf_out();
	bf_set(bf_get() + 4);
	bf_out();
	bf_out();
	bf_set(bf_get() - 4);
	bf_out();
	bf_set(bf_get() - 1);
	while (bf_get()) {
		bf_set(bf_get() - 1);
		bf_ptr_inc_n(1);
		bf_set(bf_get() + 4);
		bf_ptr_dec_n(1);
	} // -- 111
	bf_ptr_inc_n(1);
	bf_out();
	while (bf_get()) {
		bf_set(bf_get() - 4);
		bf_ptr_inc_n(1);
		bf_set(bf_get() + 1);
		bf_ptr_dec_n(1);
	} // -- 112
	bf_ptr_inc_n(1);
	bf_set(bf_get() + 1);
	bf_out();
	bf_set(bf_get() + 4);
	bf_out();
	bf_out();
	while (bf_get()) {
		bf_set(bf_get() - 5);
		bf_ptr_inc_n(1);
		bf_set(bf_get() + 3);
		bf_ptr_dec_n(1);
	} // -- 113
	bf_ptr_inc_n(1);
	bf_out();
	while (bf_get()) {
		bf_set(bf_get() - 4);
		bf_ptr_inc_n(1);
		bf_set(bf_get() + 1);
		bf_ptr_dec_n(1);
	} // -- 114
	bf_ptr_inc_n(1);
	bf_set(bf_get() + 1);
	bf_out();
	bf_set(bf_get() + 4);
	bf_out();
	bf_out();
	bf_set(bf_get() - 1);
	while (bf_get()) {
		bf_set(bf_get() - 3);
		bf_ptr_inc_n(1);
		bf_set(bf_get() + 1);
		bf_ptr_dec_n(1);
	} // -- 115
	bf_ptr_inc_n(1);
	bf_set(bf_get() - 2);
	bf_out();
	bf_out();
	bf_set(bf_get() - 1);
	while (bf_get()) {
		bf_set(bf_get() - 2);
		bf_ptr_inc_n(1);
		bf_set(bf_get() + 1);
		bf_ptr_dec_n(1);
	} // -- 116
	bf_ptr_inc_n(1);
	bf_out();
	bf_set(bf_get() + 1);
	while (bf_get()) {
		bf_set(bf_get() - 3);
		bf_ptr_inc_n(1);
		bf_set(bf_get() + 2);
		bf_ptr_dec_n(1);
	} // -- 117
	bf_ptr_inc_n(1);
	bf_out();
	bf_set(bf_get() + 4);
	bf_out();
	bf_out();
	bf_ptr_inc_n(1);
	bf_set(bf_get() + 10);
	bf_out();
	bf_ptr_inc_n(1);
	bf_set(bf_get() - 2);
	while (bf_get()) {
		bf_set(bf_get() - 2);
		bf_ptr_inc_n(1);
		bf_set(bf_get() + 3);
		bf_ptr_dec_n(1);
	} // -- 118
	bf_ptr_inc_n(1);
	bf_set(bf_get() - 1);
	bf_out();
	while (bf_get()) {
		bf_set(bf_get() - 4);
		bf_ptr_inc_n(1);
		bf_set(bf_get() + 1);
		bf_ptr_dec_n(1);
	} // -- 119
	bf_ptr_inc_n(1);
	bf_set(bf_get() + 1);
	bf_out();
	bf_set(bf_get() + 4);
	bf_out();
	bf_out();
	bf_set(bf_get() - 4);
	bf_out();
	bf_out();
	bf_out();
	bf_out();
	bf_set(bf_get() + 4);
	bf_out();
	bf_out();
	while (bf_get()) {
		bf_set(bf_get() - 5);
		bf_ptr_inc_n(1);
		bf_set(bf_get() + 3);
		bf_ptr_dec_n(1);
	} // -- 120
	bf_ptr_inc_n(1);
	bf_out();
	while (bf_get()) {
		bf_set(bf_get() - 4);
		bf_ptr_inc_n(1);
		bf_set(bf_get() + 1);
		bf_ptr_dec_n(1);
	} // -- 121
	bf_ptr_inc_n(1);
	bf_set(bf_get() + 1);
	bf_out();
	bf_set(bf_get() + 4);
	bf_out();
	bf_out();
	bf_set(bf_get() - 4);
	bf_out();
	bf_out();
	bf_out();
	bf_out();
	bf_out();
	bf_out();
	bf_out();
	bf_out();
	bf_out();
	bf_out();
	bf_out();
	bf_out();
	bf_out();
	bf_out();
	bf_set(bf_get() - 1);
	while (bf_get()) {
		bf_set(bf_get() - 1);
		bf_ptr_inc_n(1);
		bf_set(bf_get() + 3);
		bf_ptr_dec_n(1);
	} // -- 122
	bf_ptr_inc_n(1);
	bf_set(bf_get() - 1);
	bf_out();
	bf_set(bf_get() - 1);
	while (bf_get()) {
		bf_set(bf_get() - 3);
		bf_ptr_inc_n(1);
		bf_set(bf_get() + 4);
		bf_ptr_dec_n(1);
	} // -- 123
	bf_ptr_inc_n(1);
	bf_out();
	bf_out();
	bf_set(bf_get() - 4);
	bf_out();
	bf_out();
	bf_out();
	bf_out();
	bf_out();
	bf_set(bf_get() - 1);
	while (bf_get()) {
		bf_set(bf_get() - 1);
		bf_ptr_inc_n(1);
		bf_set(bf_get() + 3);
		bf_ptr_dec_n(1);
	} // -- 124
	bf_ptr_inc_n(1);
	bf_set(bf_get() - 1);
	bf_out();
	bf_set(bf_get() + 1);
	while (bf_get()) {
		bf_set(bf_get() - 3);
		bf_ptr_inc_n(1);
		bf_set(bf_get() + 4);
		bf_ptr_dec_n(1);
	} // -- 125
	bf_ptr_inc_n(1);
	bf_out();
	while (bf_get()) {
		bf_set(bf_get() - 4);
		bf_ptr_inc_n(1);
		bf_set(bf_get() + 1);
		bf_ptr_dec_n(1);
	} // -- 126
	bf_ptr_inc_n(1);
	bf_set(bf_get() + 1);
	bf_out();
	bf_set(bf_get() + 4);
	bf_out();
	bf_out();
	bf_set(bf_get() - 4);
	bf_out();
	bf_set(bf_get() - 1);
	while (bf_get()) {
		bf_set(bf_get() - 1);
		bf_ptr_inc_n(1);
		bf_set(bf_get() + 4);
		bf_ptr_dec_n(1);
	} // -- 127
	bf_ptr_inc_n(1);
	bf_out();
	while (bf_get()) {
		bf_set(bf_get() - 4);
		bf_ptr_inc_n(1);
		bf_set(bf_get() + 1);
		bf_ptr_dec_n(1);
	} // -- 128
	bf_ptr_inc_n(1);
	bf_set(bf_get() + 1);
	bf_out();
	bf_set(bf_get() + 4);
	bf_out();
	bf_out();
	bf_set(bf_get() - 4);
	bf_out();
	bf_set(bf_get() - 1);
	while (bf_get()) {
		bf_set(bf_get() - 1);
		bf_ptr_inc_n(1);
		bf_set(bf_get() + 4);
		bf_ptr_dec_n(1);
	} // -- 129
	bf_ptr_inc_n(1);
	bf_out();
	while (bf_get()) {
		bf_set(bf_get() - 4);
		bf_ptr_inc_n(1);
		bf_set(bf_get() + 1);
		bf_ptr_dec_n(1);
	} // -- 130
	bf_ptr_inc_n(1);
	bf_set(bf_get() + 1);
	bf_out();
	bf_set(bf_get() + 4);
	bf_out();
	bf_out();
	while (bf_get()) {
		bf_set(bf_get() - 5);
		bf_ptr_inc_n(1);
		bf_set(bf_get() + 3);
		bf_ptr_dec_n(1);
	} // -- 131
	bf_ptr_inc_n(1);
	bf_out();
	while (bf_get()) {
		bf_set(bf_get() - 4);
		bf_ptr_inc_n(1);
		bf_set(bf_get() + 1);
		bf_ptr_dec_n(1);
	} // -- 132
	bf_ptr_inc_n(1);
	bf_set(bf_get() + 1);
	bf_out();
	bf_set(bf_get() + 4);
	bf_out();
	bf_out();
	bf_set(bf_get() - 4);
	bf_out();
	bf_out();
	bf_out();
	bf_out();
	bf_set(bf_get() + 4);
	bf_out();
	bf_out();
	bf_ptr_inc_n(1);
	bf_set(bf_get() + 10);
	bf_out();
	while (bf_get()) {
		bf_set(bf_get() - 1);
		bf_ptr_inc_n(1);
		bf_set(bf_get() + 3);
		bf_ptr_dec_n(1);
	} // -- 133
	bf_ptr_inc_n(1);
	bf_set(bf_get() + 2);
	bf_out();
	bf_set(bf_get() - 1);
	while (bf_get()) {
		bf_set(bf_get() - 1);
		bf_ptr_inc_n(1);
		bf_set(bf_get() + 3);
		bf_ptr_dec_n(1);
	} // -- 134
	bf_ptr_inc_n(1);
	bf_set(bf_get() - 1);
	bf_out();
	bf_set(bf_get() - 1);
	while (bf_get()) {
		bf_set(bf_get() - 3);
		bf_ptr_inc_n(1);
		bf_set(bf_get() + 4);
		bf_ptr_dec_n(1);
	} // -- 135
	bf_ptr_inc_n(1);
	bf_out();
	bf_out();
	bf_out();
	bf_out();
	bf_out();
	bf_out();
	bf_out();
	bf_set(bf_get() - 4);
	bf_out();
	bf_out();
	bf_set(bf_get() - 1);
	while (bf_get()) {
		bf_set(bf_get() - 1);
		bf_ptr_inc_n(1);
		bf_set(bf_get() + 3);
		bf_ptr_dec_n(1);
	} // -- 136
	bf_ptr_inc_n(1);
	bf_set(bf_get() - 1);
	bf_out();
	bf_set(bf_get() - 1);
	while (bf_get()) {
		bf_set(bf_get() - 3);
		bf_ptr_inc_n(1);
		bf_set(bf_get() + 4);
		bf_ptr_dec_n(1);
	} // -- 137
	bf_ptr_inc_n(1);
	bf_out();
	bf_out();
	bf_set(bf_get() - 4);
	bf_out();
	bf_out();
	bf_out();
	bf_out();
	bf_out();
	bf_out();
	bf_out();
	bf_out();
	bf_out();
	bf_out();
	bf_out();
	bf_out();
	bf_out();
	bf_out();
	bf_out();
	bf_set(bf_get() - 1);
	while (bf_get()) {
		bf_set(bf_get() - 1);
		bf_ptr_inc_n(1);
		bf_set(bf_get() + 3);
		bf_ptr_dec_n(1);
	} // -- 138
	bf_ptr_inc_n(1);
	bf_set(bf_get() - 1);
	bf_out();
	bf_set(bf_get() - 1);
	while (bf_get()) {
		bf_set(bf_get() - 3);
		bf_ptr_inc_n(1);
		bf_set(bf_get() + 4);
		bf_ptr_dec_n(1);
	} // -- 139
	bf_ptr_inc_n(1);
	bf_out();
	bf_out();
	bf_out();
	bf_out();
	bf_out();
	bf_out();
	bf_out();
	bf_set(bf_get() - 4);
	bf_out();
	bf_set(bf_get() - 1);
	while (bf_get()) {
		bf_set(bf_get() - 1);
		bf_ptr_inc_n(1);
		bf_set(bf_get() + 3);
		bf_ptr_dec_n(1);
	} // -- 140
	bf_ptr_inc_n(1);
	bf_set(bf_get() - 1);
	bf_out();
	bf_set(bf_get() - 1);
	while (bf_get()) {
		bf_set(bf_get() - 3);
		bf_ptr_inc_n(1);
		bf_set(bf_get() + 4);
		bf_ptr_dec_n(1);
	} // -- 141
	bf_ptr_inc_n(1);
	bf_out();
	bf_out();
	bf_set(bf_get() - 4);
	bf_out();
	bf_out();
	bf_set(bf_get() - 1);
	while (bf_get()) {
		bf_set(bf_get() - 1);
		bf_ptr_inc_n(1);
		bf_set(bf_get() + 3);
		bf_ptr_dec_n(1);
	} // -- 142
	bf_ptr_inc_n(1);
	bf_set(bf_get() - 1);
	bf_out();
	bf_set(bf_get() - 1);
	while (bf_get()) {
		bf_set(bf_get() - 3);
		bf_ptr_inc_n(1);
		bf_set(bf_get() + 4);
		bf_ptr_dec_n(1);
	} // -- 143
	bf_ptr_inc_n(1);
	bf_out();
	bf_out();
	bf_set(bf_get() - 4);
	bf_out();
	bf_out();
	bf_set(bf_get() - 1);
	while (bf_get()) {
		bf_set(bf_get() - 1);
		bf_ptr_inc_n(1);
		bf_set(bf_get() + 3);
		bf_ptr_dec_n(1);
	} // -- 144
	bf_ptr_inc_n(1);
	bf_set(bf_get() - 1);
	bf_out();
	bf_set(bf_get() - 1);
	while (bf_get()) {
		bf_set(bf_get() - 3);
		bf_ptr_inc_n(1);
		bf_set(bf_get() + 4);
		bf_ptr_dec_n(1);
	} // -- 145
	bf_ptr_inc_n(1);
	bf_out();
	bf_out();
	while (bf_get()) {
		bf_set(bf_get() - 5);
		bf_ptr_inc_n(1);
		bf_set(bf_get() + 3);
		bf_ptr_dec_n(1);
	} // -- 146
	bf_ptr_inc_n(1);
	bf_out();
	while (bf_get()) {
		bf_set(bf_get() - 4);
		bf_ptr_inc_n(1);
		bf_set(bf_get() + 1);
		bf_ptr_dec_n(1);
	} // -- 147
	bf_ptr_inc_n(1);
	bf_set(bf_get() + 1);
	bf_out();
	bf_set(bf_get() + 4);
	bf_out();
	bf_out();
	bf_out();
	bf_out();
	bf_out();
	bf_out();
	bf_out();
	bf_set(bf_get() - 4);
	bf_out();
	bf_ptr_inc_n(1);
	bf_set(bf_get() + 10);
	bf_out();
	while (bf_get()) {
		bf_set(bf_get() - 1);
		bf_ptr_inc_n(1);
		bf_set(bf_get() + 3);
		bf_ptr_dec_n(1);
	} // -- 148
	bf_ptr_inc_n(1);
	bf_set(bf_get() + 2);
	bf_out();
	bf_out();
	bf_out();
	bf_out();
	bf_out();
	bf_out();
	bf_out();
	bf_out();
	bf_out();
	bf_out();
	bf_out();
	bf_out();
	bf_out();
	bf_out();
	bf_out();
	bf_out();
	bf_out();
	bf_out();
	bf_out();
	bf_out();
	bf_out();
	bf_out();
	bf_out();
	bf_out();
	bf_out();
	bf_out();
	bf_out();
	bf_out();
	bf_out();
	bf_out();
	bf_out();
	bf_out();
	bf_out();
	bf_out();
	bf_out();
	bf_out();
	bf_out();
	bf_out();
	bf_out();
	bf_out();
	bf_out();
	bf_out();
	bf_out();
	bf_out();
	bf_out();
	bf_out();
	bf_out();
	bf_out();
	bf_out();
	bf_out();
	bf_out();
	bf_set(bf_get() - 1);
	while (bf_get()) {
		bf_set(bf_get() - 1);
		bf_ptr_inc_n(1);
		bf_set(bf_get() + 4);
		bf_ptr_dec_n(1);
	} // -- 149
	bf_ptr_inc_n(1);
	bf_out();
	while (bf_get()) {
		bf_set(bf_get() - 4);
		bf_ptr_inc_n(1);
		bf_set(bf_get() + 1);
		bf_ptr_dec_n(1);
	} // -- 150
	bf_ptr_inc_n(1);
	bf_set(bf_get() + 1);
	bf_out();
	bf_set(bf_get() + 4);
	bf_out();
	bf_out();
	bf_set(bf_get() - 4);
	bf_out();
	bf_out();
	bf_out();
	bf_out();
	bf_out();
	bf_out();
	bf_ptr_inc_n(1);
	bf_set(bf_get() + 10);
	bf_out();
	while (bf_get()) {
		bf_set(bf_get() - 1);
		bf_ptr_inc_n(1);
		bf_set(bf_get() + 3);
		bf_ptr_dec_n(1);
	} // -- 151
	bf_ptr_inc_n(1);
	bf_set(bf_get() + 2);
	bf_out();
	bf_out();
	bf_out();
	bf_out();
	bf_out();
	bf_out();
	bf_out();
	bf_out();
	bf_out();
	bf_out();
	bf_out();
	bf_out();
	bf_out();
	bf_out();
	bf_out();
	bf_out();
	bf_out();
	bf_out();
	bf_out();
	bf_out();
	bf_out();
	bf_out();
	bf_out();
	bf_out();
	bf_out();
	bf_out();
	bf_out();
	bf_out();
	bf_out();
	bf_out();
	bf_out();
	bf_out();
	bf_out();
	bf_out();
	bf_out();
	bf_out();
	bf_out();
	bf_out();
	bf_out();
	bf_out();
	bf_out();
	bf_out();
	bf_out();
	bf_out();
	bf_out();
	bf_out();
	bf_out();
	bf_out();
	bf_out();
	bf_out();
	bf_out();
	bf_set(bf_get() - 1);
	while (bf_get()) {
		bf_set(bf_get() - 1);
		bf_ptr_inc_n(1);
		bf_set(bf_get() + 4);
		bf_ptr_dec_n(1);
	} // -- 152
	bf_ptr_inc_n(1);
	bf_out();
	while (bf_get()) {
		bf_set(bf_get() - 4);
		bf_ptr_inc_n(1);
		bf_set(bf_get() + 1);
		bf_ptr_dec_n(1);
	} // -- 153
	bf_ptr_inc_n(1);
	bf_set(bf_get() + 1);
	bf_out();
	bf_set(bf_get() + 4);
	bf_out();
	bf_out();
	bf_set(bf_get() - 4);
	bf_out();
	bf_out();
	bf_out();
	bf_out();
	bf_out();
	bf_out();
	bf_ptr_inc_n(1);
	bf_set(bf_get() + 10);
	bf_out();
	while (bf_get()) {
		bf_set(bf_get() - 1);
		bf_ptr_inc_n(1);
		bf_set(bf_get() + 3);
		bf_ptr_dec_n(1);
	} // -- 154
	bf_ptr_inc_n(1);
	bf_set(bf_get() + 2);
	bf_out();
	bf_out();
	bf_out();
	bf_out();
	bf_out();
	bf_out();
	bf_out();
	bf_out();
	bf_out();
	bf_out();
	bf_out();
	bf_out();
	bf_out();
	bf_out();
	bf_out();
	bf_out();
	bf_out();
	bf_out();
	bf_out();
	bf_out();
	bf_out();
	bf_out();
	bf_out();
	bf_out();
	bf_out();
	bf_out();
	bf_out();
	bf_out();
	bf_out();
	bf_out();
	bf_out();
	bf_out();
	bf_out();
	bf_out();
	bf_out();
	bf_out();
	bf_out();
	bf_out();
	bf_out();
	bf_out();
	bf_out();
	bf_out();
	bf_out();
	bf_out();
	bf_out();
	bf_out();
	bf_out();
	bf_out();
	bf_out();
	bf_out();
	bf_out();
	bf_out();
	bf_set(bf_get() - 1);
	while (bf_get()) {
		bf_set(bf_get() - 1);
		bf_ptr_inc_n(1);
		bf_set(bf_get() + 3);
		bf_ptr_dec_n(1);
	} // -- 155
	bf_ptr_inc_n(1);
	bf_set(bf_get() - 1);
	bf_out();
	bf_set(bf_get() - 1);
	while (bf_get()) {
		bf_set(bf_get() - 3);
		bf_ptr_inc_n(1);
		bf_set(bf_get() + 4);
		bf_ptr_dec_n(1);
	} // -- 156
	bf_ptr_inc_n(1);
	bf_out();
	bf_out();
	bf_set(bf_get() - 4);
	bf_out();
	bf_out();
	bf_out();
	bf_out();
	bf_out();
	bf_out();
	return bf_end();
}
