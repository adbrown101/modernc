/* -*- mode: C -*- */
#include <stdlib.h>
#include <stdio.h>

/* The main thing this program does */
int main(void) {
	// Declarations
	double A[5] = {
		[0] = 9.0,
		[1] = 2.9,
		[4] = 3.E+25,
		[3] = .00007,
	};

	// Doing some work
	for (size_t i = 0; i < 5; i++) {
		printf("element %zu is %g, \tits square is %g\n",
			   i,
			   A[i],
			   A[i]*A[i]);
	}
	for(size_t i = 0; i < 10; ++i) {
		size_t j = 3;
		printf("i = %zu, j = %zu\n", i, j);
	}
	return EXIT_SUCCESS;
}
