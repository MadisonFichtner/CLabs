/**
* Author Madison Fichtner
* Date: 2/7/17
* InLab 2
**/

#include <stdio.h>
#include <math.h>

double getInput(void);

/**
* getInput takes input from the user, prompting them to enter an odd number between 1 and 9.
* It checks to make sure that the number is both between 1 and 9, and that it is odd, if it is
* not both of these, it prompts the user until they enter a valid number
**/
double getInput(void)
{
	double input = -1; //setting original input to -1 to avoid discrepancy
	while(input < 0) //while input is not above 0 do:
	{
		//prompt user for integer
		printf("Enter a number: ");

		//take input from user as a double, updating input
		scanf("%lf", &input);

		//if the number is valid, return
		return(input);
	}
}

int main(void)
{
	//initialization of all the numbers we are searching for
	double lowest;
	double highest;
	double average;
	double range;
	double sD;
	double sum;
	double sumSquared;
	double size = -1;

	//prompts user for number of values they want to enter
	while(size < 0)
	{
		printf("Enter a value for N that is >= 0: ");
		scanf("%lf", &size);
		if(size < 0)
			printf("Invalid value for N \n");
	}

	int i;
	for(i = 0; i < size; i++)
	{
		//temp is the number the user enters for each go around and is used to update the above variables
		double temp = getInput();
		//sets lowest to temp if it is the lowest number entered thus far
		if(temp < lowest || i == 0)
			lowest = temp;
		//sets highest to temp if it is the highest number entered thus far
		else if(temp > highest || i == 0)
			highest = temp;
		//increments sum based on temp
		sumSquared += temp*temp;
		sum += temp;
	}

	if(size == 0) // if 0 is entered, the calculated average and sd will be 0 instead of inf or -nan
	{
		average = 0;
		sD = 0;
	}
	else
	{
		average = sum / size; //calculates average
		sD = sqrt(sumSquared / size - (average * average));  //calculates standard deviation
	}

	range = highest - lowest; //calculates range

	//prints the output of all the calculated numbers
	printf("The highest is: %.3lf", highest);
	printf("\n");
	printf("The lowest is: %.3lf", lowest);
	printf("\n");
	printf("The average is: %.3lf", average);
	printf("\n");
	printf("The range is: %.3lf", range);
	printf("\n");
	printf("The standard deviation is: %.3lf", sD);
	printf("\n");


	return(0);
}
