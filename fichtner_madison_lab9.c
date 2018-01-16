/**
* Author: Madison Fichtner
**/

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

//Defining maximum elements to check if user input is appropriate
#define MAX_ELEMENTS 20

//Defining data type element_t to store information about each element entered
typedef struct{
	int atomN; //Stores the atomic number of the element
	char name[100]; //Stores name of the element
	char symbol[3]; //Stores the 2 character long symbol of the element
	char class[100]; //Stores the sub class of the element
	double weight; //Stores the weight of the element
	int electrons[7]; //Stores the individual electrons of the element in an array
}element_t;

//Function prototypes
//Both receive the number of elements, and the array of elements
void scan_element(int n, element_t *array);
void print_element(int n, element_t *array);

//Main function
int main(int argc, char *argv[]){
	//If no arguement is passed in the command line, give an error and end the program
	if(argv[1] == 0)
	{
		printf("ERROR: You must provide exactly one arguement to this program.\n");
		exit(0);
	}
	//If there is an arguement passed, set the arguement to elements, which will be the total number of elements the user will enter
	int elements = atoi(argv[1]);
	//If the number entered is less than 0, or greater than the maximum number of elements of 20, give an error and end the program
	if(elements > MAX_ELEMENTS || elements <= 0)
	{
		printf("ERROR: You must provide an integer greater than 0 and less than or equal to 20\n");
		exit(0);
	}

	//Initialize an array of type elements, with the entered size "elements"
	element_t e[elements];

	//Function to prompt user and save their entries
	scan_element(elements, e);
}

//print_element takes in the number of elements, and the array of elements
//It prints the users input in the format described in the lab
void print_element(int n, element_t *e)
{
	for(int i = 0; i < n; i++)
	{
		printf("---------------\n");
		printf("| %d\t%.4lf\n", e[i].atomN, e[i].weight);
		printf("| %s\t%s\n", e[i].symbol, e[i].name);
		printf("| ");
		for(int j = 0; j < 7; j++)
		{
			//If the next electron is 0, break, and quit printing electrons
			if(e[i].electrons[j] == 0)
				break;
			//Otherwise, keep printing electrons
			printf("%d ", e[i].electrons[j]);
		}
		printf("\n---------------\n");
	}
}

void scan_element(int n, element_t *e)
{
	//largest maintains the largest atomic number, and largestName maintains the name of the element with the largest atomic number
	int largest = -1;
	char largestName[100];
	//smallest maintains the smallest atomic number, and smallestName maintains the name of the element with the smallest atomic number
	int smallest = 300;
	char smallestName[100];

	//Take user input n number of times, based on what number of elements they requested to enter when the program began
	for(int j = 0; j < n; j++)
	{
		//Store the data entered into all the different variables of the element_t structure
		scanf("%d %s %s %s %lf %d %d %d %d %d %d %d", &e[j].atomN, &e[j].name, &e[j].symbol, &e[j].class, &e[j].weight,
		&e[j].electrons[0], &e[j].electrons[1], &e[j].electrons[2], &e[j].electrons[3], &e[j].electrons[4], &e[j].electrons[5], &e[j].electrons[6]);

		//If the atomic number of e[j] is larger than the current largest, set the largest to e[j].atomN, and set largestName to e[j].name
		if(e[j].atomN > largest)
		{
			largest = e[j].atomN;
			strncpy(largestName, e[j].name, sizeof(largestName));
		}
		//If the atomic number of e[j] is smaller than the current smallest, set smallest to e[j].atomN, and set smallestName to e[j].name
		if(e[j].atomN < smallest)
		{
			smallest = e[j].atomN;
			strncpy(smallestName, e[j].name, sizeof(smallestName));

		}
	}

	//Print out the number of elements, and the smallest and largest elements entered
	printf("\n%d total elements.\n", n);
	printf("%s had the smallest atomic number: %d\n", smallestName, smallest);
	printf("%s had the largest atomic number: %d\n", largestName,  largest);

	//Print collected data in the format described in the lab
	print_element(n, e);
}
