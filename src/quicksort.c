#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void printarr(char* A[], int l, int r) {
	for(int i = l; i < r; ++i) {
		printf("%s, ", A[i]);
	}
	printf("%s\n", A[r]);
}

void swaparr(char* A[], int i, int j) {
	char* ival = A[i];
	char* jval = A[j];
	A[i] = jval;
	A[j] = ival;
}

int partition(char* A[], int low, int high) {
	char* pivot = A[high];
	int i = low - 1;
	for (int j = low; j < high; ++j) {
		if (strcmp(A[j], pivot) < 0) {
			++i;
			swaparr(A, i, j);
		}
	}
	int pi = i + 1;
	swaparr(A, pi, high);
	return pi;
}

void quicksort(char* A[], int low, int high) {
	if (low < high) {
		// Find the pivot position pi
		int pi = partition(A, low, high);
		quicksort(A, low , pi - 1);
		quicksort(A, pi + 1, high);
	}

}

void testsort(char* A[], int l, int r) {
	for(int i = l; i < r; ++i) {
		if (strcmp(A[i + 1], A[i]) < 0) {
			printf("Test Failed\n");
			break;
		}
	}

}

int main(void) {
	char* A[8] = {
		"hello",
		"alan",
		"fred",
		"joe",
		"dave",
		"zoe",
		"simon",
		"jennifer",
	};
	size_t len = sizeof(A)/sizeof(A[0]);
	printarr(A, 0, len - 1);
	quicksort(A, 0, len - 1);
	printarr(A, 0, len - 1);
	testsort(A, 0, len - 1);
	return EXIT_SUCCESS;
}
