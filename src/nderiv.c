#include <stdio.h>
#include <stdlib.h>
#include <tgmath.h>

int main(void) {
	static double complex const dx = 0x1P-24;
	static double complex const x = -4.0;
	double complex deriv = (sqrt(x + dx) - sqrt(x - dx))/(2*dx);
	printf("Deriv is %f%+fi\n", creal(deriv), cimag(deriv));
}
