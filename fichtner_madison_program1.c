/**
* Program 1
* Draw a diamond based on input by user
* Author: Madison Fichtner -02284423
**/


#include <stdio.h>

//creating my validation function, using if/then statements to filter the input correctly.
int is_valid(int num){
	if (num > 9){
                printf("You have entered a number greater than 9. Please try again. \n");
                return(0);
        }
	 if (num < 1){
                printf("You have entered a number less than 1. Please try again. \n");
                return(0);
        }
	if ( num % 2 == 0 ){
                printf("You have entered an even number. Please try again. \n");
                return(0);
        }
	else if (num > 0 && num < 10){
		return(1);
	}
}
//creating my input function, I then run is_valid within it to check the value given.
int get_input (void){ int input;
	printf("Enter an odd number between 1 and 9 > ");
	scanf("%d", &input);
		if (is_valid(input)){
			return input;
	}
		else{
		get_input();
	}
}
//creating my print_pattern function
void print_pattern (int get) {
	int i; int j; //
	printf("\n");
	for (i=1; i<= get; i+=2){ //using i as my counting variable
	j = 1;
	printf("%*s",get-i,""); //putting spaces incrementing by i variable
		while(j <= i){
			printf("%d ",j);	//printing my lines of numbers
			j++; //incrementing my number count according to j
		}
		printf("\n");
	}
	for (i=get-2; i>=1; i-=2){	//this is the same setup, only counting down
	j = 1;
	printf("%*s",get-i,"");
		while(j <= i){
			printf("%d ",j);
			j++;
		}
		printf("\n");
	}
}

//main function
int main (void){
	int x = get_input(); //	printf("Passing in %d to print_pattern\n", X1);
	print_pattern(x);
	printf("\n");
	return(0);
}
