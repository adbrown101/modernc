#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

double picalc(int N) {
	double pi = 3.0;
	double oldpi = 2.0;
	N += 3;
	printf("pistr length = %d\n", N);
	size_t i = 1;
	char pistr[N];
	char oldpistr[N];
	for(;;) {
		sprintf(pistr, "%f", pi);
		sprintf(oldpistr, "%f", oldpi);
		if(strcmp(pistr, oldpistr) == 0) {
			break;
		}
		int j = i * 2;
		int k = j + 1;
		int l = k + 1;
		oldpi = pi;
		double frac = (double)(4.0 / (j * k * l));
		if (i % 2 == 0) {
			pi -= frac;
		}
		else {
			pi += frac;
		}
		++i;
	}
	printf("%s = %s\n", pistr, oldpistr);
	printf("The number of loops is %d\n", i);
	return pi;
}

int main(int argc, char *argv[argc + 1]) {
	if (argc == 2) {
		int N = atoi(argv[1]);
		printf("number of places = %d\n", N);
		double pi = picalc(N);
		printf("pi = %.*f\n", N, pi);
	}
	return EXIT_SUCCESS;
}
