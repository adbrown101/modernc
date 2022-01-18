#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

double vectmult(size_t N, double A[static N], double B[static N] ) {
	double c = 0.0;
	for(size_t i = 0; i < N; ++i) {
		c += A[i]*B[i];
	}
	return c;
}

void matmult(size_t M, size_t N, double A[static M][N], double B[static N], double C[static M]) {
	for (size_t i = 0; i < M; ++i) {
		C[i] = vectmult(N, A[i], B);
	}
}

#define SIZE_N 3
#define SIZE_M 4

int main(void) {
	double A[SIZE_M][SIZE_N] = { { 1.0, 2.0, 5.0, }, { 2.0, 3.0, 4.0, }, { 1.0, 3.0, 2.0, }, { 2.0, 6.0, 1.0, } };
	double B[SIZE_N] = { 3.0, 4.0, 6.0, };
	double C[SIZE_M];
	matmult(SIZE_M, SIZE_N, A, B, C);
	for(size_t i = 0; i < SIZE_M; ++i) {
		printf("C[%zd] = %f\n", i, C[i]);
	}
	return EXIT_SUCCESS;
}
