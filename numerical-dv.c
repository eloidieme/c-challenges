#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char* argv[argc+1]) {
	double x = strtod(argv[1], 0);
	double h = strtod(argv[2], 0);

	double pre = sqrt(x - h);
	double post = sqrt(x + h);

	double dx_num = (post - pre) / (2*h);
	double dx_ana = 1.0/(2*sqrt(x));

	printf("Square root of %.5g: %.5g\nNumerical derivative: %.5g\nAnalytical derivative: %.5g\n", x, sqrt(x), dx_num, dx_ana);
	return EXIT_SUCCESS;
}
