/* sequence computation */

#include <stdio.h>

double get_next(double val1, double val2);
double get_input(void);
double print_result(double finalVal);

double main(void)
{
	double x1;
	x1 = get_input();

	double x2;
	x2 = get_input();

	double x3;
	x3 = get_next(x1, x2);

	double x4;
	x4 = get_next(x2, x3);

	double x5;
	x5 = get_next(x3, x4);

	print_result(x5);
}

double print_result(double val)
{
	printf("The result is %.2f \n ", val);
}

double get_next(double val1, double val2)
{
	double next;
	next = (val1 / 2) + (3 * val2);

	return(next);
}

double get_input(void)
{
	double num;
	printf("Please enter a number: ");
	scanf("%lf", &num);

	printf("You chose the number: %f \n ", num);

	return(num);
}


