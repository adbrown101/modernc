#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double rndpi(double pi, size_t N) {
	size_t mult = pow(10, N);
	return round(pi * mult)/mult;
}

double picalc(size_t N) {
	double pi = 3.0;
	double oldpi = 2.0;
	size_t i = 1;
	for(;;) {
		if (rndpi(pi, N) == rndpi(oldpi, N)) {
			break;
		}
		size_t j = i * 2;
		size_t k = j + 1;
		size_t l = k + 1;
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
	printf("No of loops %zu\n", i);
	return pi;
}

int main(void) {
	size_t N = 10;
	printf("number of places = %zu\n", N);
	double pi = picalc(N);
	printf("pi = %.10f\n", pi);
	return EXIT_SUCCESS;
}
