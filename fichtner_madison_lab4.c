#include <stdio.h>
#include <math.h>

/**
*  creating enums for sine, cosine, tangent, and quit to refer to later more easily
**/
typedef enum{
	Sine,
	Cosine,
	Tangent,
	QUIT,
} menu_t;

/**
*  creating local variables, including the permanent
*  variables for loop limit and PI. Selected keeps track of what
*  number is typed by the user before being translated to the menu_t enum
*  type object that is selection.
**/
int selected;;
menu_t selection;
double PI = 3.14159;
int LOOP_LIMIT = 90;

/**
*  Initializing functions
**/
void get_input(void);
void calculate(menu_t selection);
double degreesToRadians(int degrees);

// Main function
int main(void){
	while(selected != 4){ //While QUIT is not selected, continue to run
		get_input();
		if(selected == 3) //Breaks while loop once 3 is selected
			break;
	}
}

// Function used to prompt the user for an option, which it then saves as a menu_t item.
// Then it calls the calculate() function with the users response
void get_input(void){
	printf("Please choose an option: (0) Sine (1) Cosine (2) Tangent (3) QUIT \n");
	printf("Enter your choice > ");
	scanf("%d", &selected);
		switch(selected){
		case 0: //if 0 is selected, set selection to Sine
			selection = Sine;
			break;
		case 1: //if 1 is selected, set selection to Cosine
			selection = Cosine;
			break;
		case 2: //if 2 is selected, set Selection to Tangent
			selection = Tangent;
			break;
		case 3: //if 3 is selected, QUIT the program
			selection = QUIT;
			printf("You chose QUIT. Thank you, come again! \n");
			break;
		default: //if any other option is selected, prompt the user to try again
			printf("%d", selected);
			printf(" is an invalid option. Please try again. \n");
	}

	calculate(selection); //calls calculate that takes the users input and prints out the solutions
}

void calculate(menu_t selection)
{
	double radian; //keeps track of the radians
	switch(selection){
		case Sine: //if the input is Sine
			for(int i = 0; i <= LOOP_LIMIT; i += 15) //starting at 0, and incrementing by 15, translate to radians and solve using sin(radian)
			{
				printf("\t sin(");
				printf("%d", i);
				printf(") = ");
				radian = degreesToRadians((double)i); //translates to radians
				radian = sin(radian); //calculates sine
				printf("%.4lf", radian);
				printf("\n");
			}
			break;
		case Cosine:
			for(int i = 0; i <= LOOP_LIMIT; i += 15) //starting at 0, and incrementing by 15, translate to radians and solve using cos(radian)
			{
				printf("\t cos(");
                                printf("%d", i);
                                printf(") = ");
                                radian = degreesToRadians((double)i); //translates to radians
                                radian = cos(radian); //calculates cosine
                                printf("%.4lf", radian);
                                printf("\n");

			}
			break;
		case Tangent: //starting at 0, and incrementing by 15, translate to radians and solve using tan(radian)
			for(int i = 0; i <= LOOP_LIMIT; i += 15)
                        {
                                printf("\t tan(");
                                printf("%d", i);
                                printf(") = ");
                                radian = degreesToRadians((double)i); //translates to radians
                                radian = tan(radian); //calculates tangent
				if(radian > 10000.00){
					printf("UNDEFINED"); //if the tangent is undefined or infinity, return UNDEFINED
				}
				else{
                                	printf("%.4lf", radian); //else, return the value
				}
                                printf("\n");

                        }
			break;
		case QUIT:
			break;
	}
}

/**
*  Function to change degrees to radians using the permanent variable, PI
**/
double degreesToRadians(int degrees)
{
	double radian = PI * ((double)degrees / 180);
	return radian;
}
