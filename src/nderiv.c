#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double nderiv(double (*f)(double), double x) {
	static double const dx = 0x1P-24;
	double deriv = (f(x + dx) - f(x - dx))/(2 * dx);
	return deriv;
}

double sqr(double x) {
	return pow(x, 2);
}

int main(void) {
	double deriv = nderiv(sqrt, 4.0);
	printf("Deriv is %.2f\n", deriv);
}
