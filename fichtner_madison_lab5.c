/**
* Author: Madison Fichtner
* Lab 5
* ID: 02284423
**/

#include <stdio.h>

//Creating local variables

//Array of size 12
int barcode[12];

//Sum of odds, and evens.
int sumOdds;
int sumEvens;
int totalSum;

//Check digit and last digit
int checkDigit;
int lastDigit;

//Instantiating functions
int get_input(void);
int get_sums(int *barcode, int n);

//Main function
int main(void){
	get_input();

	printf("You entered the numbers: ");

	//For loop to print out barcode that was entered
	for(int i = 0; i <= 11; i++)
	{
		printf("%d", barcode[i]);
		printf(" ");
	}

	//Print out the sum of the odds * 3
	printf("\nSTEP 1: Sum of odds times 3 is ");
	printf("%d \n", sumOdds);

	//Print out the sum of the evens
	printf("STEP 2: Sum of the even digits is ");
	printf("%d \n", sumEvens);

	//Print out the total sum
	printf("STEP 3: Total sum is ");
	printf("%d \n", totalSum);

	//Print out the check digit
	printf("STEP 4: Calculated check digit is ");
	printf("%d \n", checkDigit);

	//Whether check digit and last digit match, respond valid or invalid
	printf("STEP 5: Check digit and last digit ");
	if(lastDigit == checkDigit){
		printf("match \n");
		printf("Barcode is VALID. \n");
	}
	else{
		printf("do not match \n");
		printf("Barcode is INVALID. \n");
	}
	printf("\n");
}

int get_input(void){
	//Prompt the user for input
	printf("\nEnter a bar code to check. Seperate digits with a space > \n");

	//For loop to save the users input
	for(int i = 0; i <= 11; i ++)
	{
		//Temporary variable to store user input for ever number entered
		int temp = 0;
		scanf("%d", &temp);

		//If the number entered is above 9, it's invalid and will re run the function
		if(temp > 9){
			get_input();
		}
		//Otherwise, add temp to the array
		else{
			barcode[i] = temp;
		}
	}

	//Set last digit to the last variable in the array
	lastDigit = barcode[11];
	get_sums(barcode, 12);
	printf("\n");
	return(0);
}

int get_sums(int *barcode, int n){
	//Calculates the sum for odds sans *3
	for(int i = 0; i <= 10; i+=2)
	{
		sumOdds += barcode[i];
	}

	//Calculates the sum for evens
	for(int j = 1; j <= 10; j+=2)
	{
		sumEvens += barcode[j];
	}

	//Update even and odds, keep even the same, and multiply odds by 3
	sumEvens = sumEvens;
	sumOdds = sumOdds * 3;

	//Add the calculated sums
	totalSum = sumEvens + sumOdds;

	//If the last digit is 0, set check digit to 0
	if(totalSum % 10 == 0)
		checkDigit = 0;

	//Otherwide, set check digit to 10 - n where n is the last digit
	else
		checkDigit = 10 - (totalSum % 10);

	return(0);
}
