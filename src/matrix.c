#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdint.h>

void create_matrix(size_t N, double Astart[static N], size_t rows, size_t cols, double A[static rows][cols]) {
	size_t k = 0;
	for(size_t i = 0; i < rows; ++i) {
		for(size_t j = 0; j < cols; ++j) {
			A[i][j] = Astart[k];
			k += 1;
		}
	}
}

double vectmult(size_t M, double A[static M], size_t N, double B[static M][N], size_t col ) {
	double c = 0.0;
	for(size_t i = 0; i < M; ++i) {
		c += A[i]*B[i][col];
	}
	return c;
}

void matmult(size_t M, size_t N, double A[static M][N], size_t P, double B[static N][P], double C[static N][P]) {
	for (size_t j = 0; j < P; ++j) {
		for (size_t i = 0; i < M; ++i) {
			C[i][j] = vectmult(N, A[i], P, B, j);
		}
	}
}

void joinmat(size_t Rows, size_t M, double A[static Rows][M], size_t N, double B[static Rows][N], double C[static Rows][M+N] ) {
	for(size_t i = 0; i < Rows; ++i) {
		size_t a = 0;
		for(size_t j = 0; j < M; ++j) {
			C[i][a] = A[i][j];
			a += 1;
		}
		for(size_t k = 0; k < N; ++k) {
			C[i][a] = B[i][k];
			a += 1;
		}
	}
}

size_t max_rows(size_t piv, size_t rows, size_t cols, double A[static rows][cols]) {
	size_t max_row = SIZE_MAX;
	double max_val = 0.0;
	static double const small = 0x1P-24;
	for(size_t i = piv; i < rows; ++i) {
		if (fabs(A[i][piv]) > max_val + small) {
			max_row = i;
			max_val = fabs(A[i][piv]);
		}
	}
	return max_row;
}

void swap_rows(size_t prow, size_t row_max, size_t rows, size_t cols, double A[static rows][cols]) {
	if(row_max > prow) {
		for (size_t i = 0; i < cols; ++i){
			double temp;
			temp = A[row_max][i];
			A[row_max][i] = A[prow][i];
			A[prow][i] = temp;
		}
	}
}

void printarr(size_t cols, double A[static cols]) {
	printf("|");
	for(size_t i = 0; i < cols-1; ++i) {
		printf("%.4f ", A[i]);
	}
	printf("%.4f|\n", A[cols-1]);
}

void printmat(size_t rows, size_t cols, double A[static rows][cols]) {
	for(size_t i = 0; i < rows; ++i) {
		printarr(cols, A[i]);
	}
	printf("\n");
}

void gauss(size_t rows, size_t cols, double A[static rows][cols]) {
	// pivot row / column
	// swap rows to get biggest absolute no on top
	static double const small = 0x1P-24;
	for(size_t piv = 0; piv < rows; ++piv) {
		size_t i_max = max_rows(piv, rows, cols, A);
		if (i_max != SIZE_MAX) {
			swap_rows(piv, i_max, rows, cols, A);
			for(size_t i = 0; i < rows; ++i) {
				if (i != piv) {
					double f = A[i][piv] / A[piv][piv];
					for(size_t j = 0; j < cols; ++j) {
						A[i][j] -= A[piv][j]*f;
					}
				}
			}
		}
	}

	for(size_t i = 0; i < rows; ++i) {
		double temp = A[i][i];
		if(fabs(A[i][i]) > 0.0 + small) {
			for(size_t j = 0; j < cols; ++j) {
				if(i == j) {
					A[i][j] = 1.0;
				} else {
					A[i][j] = A[i][j]/temp;
				}
				if(fabs(A[i][j]) < small) {
					A[i][j] = 0.0;
				}
			}
		}
	}
}

#define SIZE_K 3
#define SIZE_M 3
#define SIZE_N 4

int main(void) {
	double Astart[9] = {
		3.0, 0.0, 2.0,
		2.0, 0.0, -2.0,
		0.0, 1.0, 1.0,
	};
	double Bstart[9] = {
		1.0, 0.0, 0.0,
		0.0, 1.0, 0.0,
		0.0, 0.0, 1.0,
	};
	double A[SIZE_M][SIZE_M];
	create_matrix(9, Astart, SIZE_M, SIZE_M, A);
	printmat(SIZE_M, SIZE_M, A);
	double B[SIZE_M][SIZE_K];
	create_matrix(6, Bstart, SIZE_M, SIZE_K, B);
	printmat(SIZE_M, SIZE_K, B);
	double C[SIZE_M][SIZE_K];
	matmult(SIZE_M, SIZE_M, A, SIZE_K, B, C);
	printmat(SIZE_M, SIZE_K, C);
	double D[SIZE_M][SIZE_M+SIZE_K];
	joinmat(SIZE_M, SIZE_M, A, SIZE_K, B, D);
	printmat(SIZE_M, SIZE_M+SIZE_K, D);
	gauss(SIZE_M, SIZE_M+SIZE_K, D);
	printmat(SIZE_M, SIZE_M+SIZE_K, D);
	return EXIT_SUCCESS;
}

// -1/3z = 4/15; z = -4/5;
// 5/3y = 20/3; y = 4;
// 9x + 3y + 4z = 7; 45/5x + 60/5 - 16/5 = 35/5; 45/5x = -9/5; x = -1/5;
