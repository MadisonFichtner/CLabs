/*
* Madison Fichtner
* Lab 1, CSCI 112
* 1/18/2017
*/

#include <stdio.h>

int main(void)
{
	/* declare required variable */
	double celsius = 0, fahrenheit = 0;

	/* get the temperature in Celsius */
	printf("Enter a temperature in degrees Celsius: ");

	/* convert to Fahrenheit */
	scanf("%lf", &celsius);
	fahrenheit = (9.0/5.0) * celsius + 32.0;	

	/* print out the temp in Fahrenheit */
	printf("That is %.2f Fahrenheit \n", fahrenheit);

	/* get the temp in Fahrenheit */
	printf("Enter a temperature in degrees Fahrenheit: ");

	/* convert to Celsius */
	scanf("%lf", &fahrenheit);
	celsius = (fahrenheit - 32.0) * 5 / 9;

	/* print out the temp in Celsius */
	printf("That is %.2f Celsius \n", celsius);

	/* exit with no errors */
	return(0);
}
