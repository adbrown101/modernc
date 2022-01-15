#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <limits.h>
#include <inttypes.h>

int main(void) {
	const uint16_t V = UINT16_MAX;
	const uint16_t A = 240;
	const uint16_t B = 287;
	const uint16_t a = -A;
	const uint16_t b = ~A + 1;
	const uint16_t c =  -B;
	const uint16_t d = ~B + 1;

	printf("V = %x\n"
		   "A = %x\n"
		   "B = %x\n"
		   "-A = %x\n"
		   "-A = %x\n"
		   "-B = %x\n"
		   "-B = %x\n", V, A, B, a, b, c, d);
	return EXIT_SUCCESS;
}
