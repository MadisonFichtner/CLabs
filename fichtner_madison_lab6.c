/**
*	Author: Madison Fichtner
*	Lab 6
**/

#include <stdio.h>
#include <math.h>

//Initializing Function Prototypes
void equation1(float *result);
void equation2(float *result);
void equation3(float *result);
void equation4(float *result);

//User input function prototypes
float get_position_initial(void);
float get_position_final(void);
float get_velocity_initial(void);
float get_velocity_final(void);
float get_acceleration(void);
float get_time(void);
int user_menu(void);

//Creating variables
float Xi;
float Xf;
float Vi;
float Vf;
float a;
float t;


int main(void){
// Print welcome message
        printf("Welcome to the MOTION EQUATION CALCULATOR\n\n");

        // Variable for the user choice menu.
        int user_choice;

        do
        {
            user_choice = user_menu();  // print menu, validate choice is between 1 and 5

            // You will pass the address of this variable to your equation functions.
            float result;               // Variable to hold calculated result
	    float *resultP;
	    resultP  = &result;
            // Handle menu choice selected by user
            switch( user_choice )
            {
                // equations will pass in the result pointer so it can be updated
		case 1:
		    equation1(resultP);
		    break;
		case 2:
		    equation2(resultP);
		    break;
		case 3:
	 	    equation3(resultP);
		    break;
		case 4:
		    equation4(resultP);
		    break;
                case 5:
                    // exit program if user selected QUIT
                    printf("Thank you for using the MOTION EQUATION CALCULATOR. Goodbye.\n");
                    return 0;
                    break;
            }

            // Print out the calculated result with four digits after the decimal place
            printf("Your result is %.4f.\n\n", result);


        } while ( user_choice != 5 );

        return 0; // exit with no error
}

int user_menu(void){
	// Initially set input to 0
	int user_input = 0;
	printf("\nChoose a motion equation 1-4 or choose 5 to QUIT > ");
	scanf("%d", &user_input);

	// If user input is equal to or less than 0 or greater than or equal to 6, prompt the user again
	if(user_input <= 0 || user_input >= 6)
	{
		printf("\nInvalid Option. Please try again.");
		user_menu();
	}
	// If user input is 5, simply return 5
	else if(user_input == 5)
	{
		return user_input;
	}
	// If user input is 1-4, also return
	else
	{
		return user_input;
	}

	return 0;
}

// equation 1 finds the final velocity
void equation1(float * result){
	Vi = get_velocity_initial();
	a = get_acceleration();
	t = get_time();
	*result = Vi + (a * t);
}

// equation 2 finds the final position
void equation2(float * result){
	Xi = get_position_initial();
	Vi = get_velocity_initial();
	t = get_time();
	a = get_acceleration();
	*result = Xi + (Vi * t) + (.5 * (a * pow(t, 2)));
}

// equation 3 finds the final velocity
void equation3(float * result){
	Vi = get_velocity_initial();
	a = get_acceleration();
	Xf = get_position_final();
	Xi = get_position_initial();
	*result = sqrt(pow(Vi, 2) + 2 * (a * (Xf - Xi)));
}

// equation 4 finds the final position
void equation4(float * result){
	Xi = get_position_initial();
	Vf = get_velocity_final();
	Vi = get_velocity_initial();
	t = get_time();
	*result = Xi + ((.5 * (Vf + Vi)) * t);
}

// prompts the user, and saves their entry as the initial position to be used in the equation functions
float get_position_initial(void){
	printf("Enter initial position >  ");
	scanf("%f", &Xi);
	return Xi;
}

// prompts the user, and saves their entry as the final position to be used in the equation functions
float get_position_final(void){
	printf("Enter final position >  ");
	scanf("%f", &Xf);
	return Xf;
}

// prompts the user, and saves their entry as the initial velocity to be used in the equation functions
float get_velocity_initial(void){
	printf("Enter initial velocity > ");
	scanf("%f", &Vi);
	return Vi;
}

// prompts the user, and saves their entry as the final velocity to be used in the equation functions
float get_velocity_final(void){
	printf("Enter final velocity > ");
	scanf("%f", &Vf);
	return Vf;
}

// prompts the user, and saves their entry as the acceleration to be used in the equation functions
float get_acceleration(void){
	printf("Enter acceleration > ");
	scanf("%f", &a);
	return a;
}

// prompts the user, and saves their entry as the times to be used in the equation functions
float get_time(void){
	printf("Enter time > ");
	scanf("%f", &t);
	return t;
}
