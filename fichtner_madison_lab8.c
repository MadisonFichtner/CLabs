#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//Defining the max size of the sentence string
#define SIZE 132

//Defining my string, and the Line data type of size 132
typedef char Line[SIZE];
typedef char *String;

//I took the route of first reversing all characters in the string, then reversing the order of each word
void reverse(char *s);
void reverse_chars(char *left, char *right);

int main(int argc, char *argv[])
{
	//Creating line, to store input from user as type Line
	Line line;
	//A placeholding pointer to the last value in Line is *end
	char * end;
	//N is the number inputed through the command line. atoi takes in the arguement as an integer
	int N;
	N = atoi(argv[1]);

	//For loop to run N number of times, receiving input of string, and outputting the reverse order
	for(int i = 0; i < N; i++)
	{
		//Takes user input, and stores it in line
		if(fgets(line, SIZE, stdin))
		{
			//Sets end to the last character in line
			end = (line + strlen(line) - 1);
			//Reverses characters
			reverse_chars(line, end);
			//Reverses line
			reverse(line);
		}
		//Prints out reversed line
//		printf("%s", line);
		puts(line);
	}
}

//Reverse takes in a string of characters, and completely flips all the characters in said string so they are backwards
void reverse(char *sentence)
{
	//Placeholders for the start and end of the string
	char * start;
	char * end;
	//Boolean to keep track of if there is a space
	_Bool inword = 0;

	//While sentence has a character
	while(*sentence)
	{
		//If the next character is not a space, and inword is false
		if(!isspace(*sentence) && (inword == 0))
		{
			//Set start to the string and flip inword
			start = sentence;
			inword = 1;
		}
		//Else if the next character is a space, and inword is true
		else if(isspace(*sentence) && (inword == 1))
		{
			//Set end to the second to last character in sentence, since the last is \0
			end = sentence-1;
			inword = 0;
			reverse_chars(start, end);
		}
		sentence++;
	}
	if(*sentence == '\0')
		reverse_chars(start, sentence-1);
}

//Reverse_chars takes in the left and right placeholders of the sentence, and moves through the sentence, flipping each word.
void reverse_chars(char *left, char *right)
{
	char temp;
	while(right>left)
	{
		temp = *left;
		*left = *right;
		*right = temp;
		left++;
		right--;
	}
}
