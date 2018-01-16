/*
   * Homegrown strncpy test program
   * Author: Madison Fichtner
   */
	#include <stdio.h>
	#include <string.h>

  // Function prototypes
	char *my_strncpy(char *dest, char *source, int n);
	char *my_strncat(char *dest, char *source, int n);

  // ********* Insert your my_strncpy implementation here! *************
	char *my_strncpy(char *dest, char *source, int n)
	{
		// temp set to the destination
		char *temp = dest;

		// while n != 0
		while(n--)
		{
			// set the temporary letter to the letter in the source
			*temp++ = *source++;
		}

		// set the last char in temp as null
		*temp++ = '\0';

		return dest;
	}


  // ********* Insert your my_strncat implementation here! *************
	char *my_strncat(char *dest, char *source, int n)
	{
		// local set to the destination, and n1 to keep count against n
		char *local = dest;
		int n1 = 0;

		// while dest exists, increment it
		while(*dest)
		{
			dest++;
		}
		dest--;

		// if destination isn't null
		if(dest != "\n")
		{
			dest++;
		}

		// while n1 is less than n, set destination character to source character and increment both. Can also be written in a for loop.
		while(n1 < n)
		{
			*dest = *source;
			dest++;
			source++;
			n1++;
		}

		// set last character as null
		*dest = '\0';

		return dest;
	}

int main() {
    // Test your function with various source strings and values of n

	char testSrc[] = "Hello";
	char testDest[40] = "world";
	int n = 5;

	my_strncat(testDest, testSrc, n);
	printf("CAT: %s \n", testDest);

	my_strncpy(testDest, testSrc, n);
	printf("CPY: %s \n", testDest);

	printf("%s \n", testDest);
    	return 0;
 }

