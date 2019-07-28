#include <stdio.h>
#include <gsl/gsl_sf_bessel.h>
#include <gsl/gsl_math.h>

int main() {

	double x = 6.0, y = gsl_sf_bessel_J0(x);
	printf("J0(%g) = %.18e\n", x, y);

	double t = M_PI, e = gsl_expm1(t);
	printf("exp(%g) - 1 = %.18e\n", t, e);
}
