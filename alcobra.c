#include <stdio.h>
#include "matrix.h"
#include "special_math.h"

int main()
{
	double x = -5.0;
	double y = -6.0;

	printf("Hello World\n");
	printf("abs(-5.0) = %f\n", abs(x));
	printf("abs(5.0) = %f\n", abs(-x));
	printf("sigmoid(-6.0) = %f\n", sigmoid(y));
	printf("d_sigmoid(-6.0) = %f\n", d_sigmoid(y));
	printf("rand_weight() = %f\n", rand_weight());
	return 0;
}
