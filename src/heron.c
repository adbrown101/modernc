#include <stdio.h>
#include <stdlib.h>

/* lower and upper iteration limits centred agournd 1.0 */
static double const eps1m01 = 1.0 - 0x1P-01;
static double const eps1p01 = 1.0 + 0x1P-01;
static double const eps1m24 = 1.0 - 0x1P-24;
static double const eps1p24 = 1.0 + 0x1P-24;

int main(int argc, char* argv[argc+1]) {
	printf("eps1m01 = %.5f, \teps1p01 = %.5f\n", eps1m01, eps1p01);
	for (int i = 1; i < argc; ++i) { // process args
		double const a = strtod(argv[i], 0); // argv -> double
		double x = 1.0;
		for (;;) {   // by powers of 2
			printf("intermediate 01: %.e\n", x);
			double prod = a*x;
			if (prod < eps1m01) {
				x *= 2.0;
			} else if (eps1p01 < prod) {
				x *= 0.5;
			} else {
				break;
			}
		}
		for (;;) { // heron approximation
			printf("intermediate he: %.5e\n", x);
			double prod = a*x;
			if ((prod < eps1m24) || (eps1p24 < prod)) {
				x *= (2.0 - prod);
			} else {
				break;
			}
		}
		printf("heron: a=%.5e, \tx=%.5e, \ta*x=%.12f\n",
			a, x, a*x);
	}
	return EXIT_SUCCESS;
}
