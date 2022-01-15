#include <stdio.h>
#include <stdlib.h>


void printarr(double A[], int l, int r) {
	for(int i = l; i < r; ++i) {
		printf("%.2f, ", A[i]);
	}
	printf("%.2f\n", A[r]);
}

void merge(double A[], int l, int m, int r) {
	// generate temp arrays
	int n1 = m - l + 1;
	int n2 = r - m;
	double L[n1];
	double M[n2];
	for (int i = 0; i < n1; ++i) {
		L[i] = A[l + i];
	}
	for (int j = 0; j < n2; ++j) {
		M[j] = A[m + 1 + j];
	}
	// printarr(L, 0, n1-1);
	// printarr(M, 0, n2-1);
	int i = 0;
	int j = 0;
	int k = l;

	// reload sorted A while L and M still have numbers
	while ((i < n1) && (j < n2)) {
		if (L[i] <= M[j]) {
			A[k] = L[i];
			++i;
		} else {
			A[k] = M[j];
			++j;
		}
		++k;
	}

	// remaining in L
	while (i < n1) {
		A[k] = L[i];
		++i;
		++k;
	}

	// remaining in M
	while (j < n2) {
		A[k] = M[j];
		++j;
		++k;
	}

}

void mergesort(double A[], int l, int r) {
	if (r > l) {
		int m = (l + r) / 2;
		mergesort(A, l , m);
		mergesort(A, m + 1, r);
		merge(A, l, m, r);
	}

}

void testsort(double A[], int l, int r) {
	for(int i = l; i < r; ++i) {
		if (A[i + 1] < A[i]) {
			printf("Test Failed\n");
			break;
		}
	}

}

int main(void) {
	double A[9] = {
		12.0,
		3.25,
		4.0,
		37.03,
		28.2,
		13.17,
		7.77,
		8.0,
		17.3,
	};
	size_t len = sizeof(A)/sizeof(A[0]);
	printarr(A, 0, len - 1);
	mergesort(A, 0, len - 1);
	testsort(A, 0, len - 1);
	printarr(A, 0, len - 1);
	return EXIT_SUCCESS;
}
