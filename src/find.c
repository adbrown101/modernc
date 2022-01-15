#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

void makeset(size_t N, size_t parent[static N]) {
	for (size_t i = 0; i < N; ++i) {
		parent[i] = SIZE_MAX;
	}
}

void printset(size_t N, size_t parent[static N]) {
	for (size_t i = 0; i < N; ++i) {
		printf("%zd ", parent[i]);
	}
	printf("\n");
}

size_t Find(size_t N, size_t parent[static N], size_t i) {
	if (parent[i] == SIZE_MAX) {
		return i;
	} else {
		return Find(N, parent, parent[i]);
	}
}

void FindReplace(size_t N, size_t parent[static N], size_t i, size_t rep) {
	if (parent[i] == SIZE_MAX) {
		parent[i] = rep;
	} else {
		size_t prev_parent = parent[i];
		parent[i] = rep;
		FindReplace(N, parent, prev_parent, rep);
	}
}

size_t FindCompress(size_t N, size_t parent[static N], size_t i) {
	size_t iroot = Find(N, parent, i);
	if (i != iroot) {
		size_t prev_parent = parent[i];
		parent[i] = iroot;
		i = FindCompress(N, parent, prev_parent);
	}
	return i;
}

void Union (size_t N, size_t parent[static N], size_t i, size_t j) {
	FindCompress(N, parent, i);
	FindReplace(N, parent, i, FindCompress(N, parent, j));
}

#define TABLESIZE 10

int main(void) {
	size_t parent[TABLESIZE];
	makeset(TABLESIZE, parent);
	FindReplace(TABLESIZE, parent, 6, 2);
	FindReplace(TABLESIZE, parent, 4, 6);
	FindReplace(TABLESIZE, parent, 5, 4);
	FindReplace(TABLESIZE, parent, 3, 5);
	/* FindCompress(TABLESIZE, parent, 3); */
	Union(TABLESIZE, parent, 3, 7);
	printset(TABLESIZE, parent);
	return EXIT_SUCCESS;
}
