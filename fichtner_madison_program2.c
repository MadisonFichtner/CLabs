/**
* Author: Madison Fichtner
* Program 2: Qucksort
**/

#include "stdio.h"
#include "math.h"

#define MAX_ARRAY_SIZE 50 //using SIZE for array size

// function prototype to partition the array
int partition( int array[], int low, int high );

// Array function
int populate_array(int array[])
{
	// Receiving user input
	printf("Enter the value for n >\n");

	int n;
	int i;

	// n holds the array size
	scanf("%d", &n);

	// While loop to make sure number inputed is within the array size boundary of 50
	while (n > MAX_ARRAY_SIZE){
		printf("INVALID >\n");
 		scanf("%d", &n);
	}

	//Receives array contents
	printf("Enter %d integers (positive, negative, or zero\n", n);

	for (i = 0; i < n; i++){
		scanf("%d", &array[i]);
	}
	return(n);
}

// Print array function that simply prints out the array
void print_array( int array[], int n )
{
	int i;

        for (i = 0; i < n; i++){
  		printf("%+5d\n", array[i]);
	}
}

// Swap function used to move the array values to the sorted positions
void swap ( int array[], int index1, int index2 )
{
	int temp = array[index1];

	array[index1] = array[index2];

	// Temp is necessary to keep track of both variables being moved
	array[index2] = temp;
}

// Recursive function that uses the partition funciton to sort around the pivot point
void quicksort( int array[], int low, int high ){
	if (low < high){
		int pivot = partition(array, low, high);

		// Recursive functions
		quicksort(array, low, pivot-1);
		quicksort(array, pivot+1, high);
	}
}

// Partition function that sets the pivot and swaps accordingly
int partition( int array[], int low, int high ){
	int pivot = array[high];
	int i = low - 1;
	int j;

	// Loop using swap to sort the values in the array
	for (j = low; j < high; j++){
		if (array[j] <= pivot){
			i = i+1;
			swap(array, i, j);
		}
	}
	swap(array, i+1, high);
	return(i+1);
}

// Main function
int main (void){
	// Initializing array using the max array size
	int array[MAX_ARRAY_SIZE];

	// Setting n equal to the populate_array function
	int n = populate_array(array);

	// Prints out unsorted array
	printf("The initial array contains:\n");
	print_array(array, n);

	// Sorts array
	quicksort(array, 0, n-1);

	// Prints sorted array
	printf("The array is now sorted:\n");
	print_array(array, n);

	return(0);
}
