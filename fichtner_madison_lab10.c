/**
* Author: Madison Fichtner
* Last edited: April 27
* Element database, Inlab 10
**/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Defining the elements dictionary, and the number of elements
#define ELEMENT_FILENAME "element_db.csv"
#define LINE_SIZE 128

//Creating element_t structure
typedef struct {
    int atomic_number;
    char symbol[4];
    char name[25];
    float atomic_weight;
    char state[25];
    char bonding_type[25];
    char discovered[25];
} element_t;

//find_element checks to see if the entered element exists, and print_element prints it to the user, and a file if requested
element_t * find_element( element_t * list, char * symbol );
void print_element(element_t *element, FILE * output);

int main( int argc, char * argv[] ) {
    //If no arguement was passed, return an error
    if ( argc < 2 )
    {
        printf(" ERROR: Please provide at least one program argument.\n");
        return 0;
    }

    //Allocate memory for the 118 elements
    element_t * elements = (element_t *)calloc( LINE_SIZE , sizeof( element_t ) );

    //Open file
    FILE * element_file = fopen( ELEMENT_FILENAME, "r" );

    //If the file exists
    if ( element_file != NULL )
    {
        char line[100];
	//While there is still a line left in the file
        while( fgets(line, LINE_SIZE, element_file ) != NULL )
        {
            // remove newline character from line
            char * nl = strchr( line, '\n' );
            if ( nl )
            {
                *nl = '\0';
            }

	    //Create memory for a temporary element
            element_t e;

            char * str;
	    const char s[2] = ",";
            int col = 0;

	    //Break line into tokens to process data
	    str = strtok(line, s);
	    //While the line still has information in it, set each variable to the information in the line
            while ( str != NULL )
            {
		switch( col )
                {
                    case 0:
                        e.atomic_number = atoi( str );
                        break;
                    case 1:
	                strcpy( e.symbol, str);
                        break;
		    case 2:
			strcpy( e.name, str);
			break;
		    case 3:
			e.atomic_weight = atof( str );
			break;
		    case 4:
			strcpy( e.state, str);
			break;
		    case 5:
			strcpy( e.bonding_type, str);
			break;
		    case 6:
			strcpy( e.discovered, str);
			break;
                }
		col++;
                str = strtok(NULL, s);
            }
	    //Set the array of elements to the found data each line
            elements[ e.atomic_number - 1 ] = e;
        }
	//Close the dictionary of elements file
        fclose( element_file );
    }

    // process program arguments. Initially set the output file to NULL
    FILE * output_f = NULL;

    //For the length of the arguements given, check for a filename and if not, check if elements entered exist and print them out if they do
    int i;
    for( i = 1; i < argc; i++ )
    {
        if ( i == 1 ) // check for filename
        {
            char * dot = strchr( argv[i], '.' );
            if ( dot )
            {
                // this is a filename
                output_f = fopen( argv[i], "w" );
                continue;
            }
        }

        // Look up this element
        element_t * ele = find_element( elements, argv[i] );
        if ( ele != NULL )
        {
	      print_element(ele, output_f);
        }
	//Return that it doesnt exist
	else
	{
		printf("WARNING: No such element: %s\n", argv[i]);
	}
     }
    //close the output file
    if(output_f != NULL)
    {
          fclose(output_f);
    }
    return 0;
}

//Finds the elements entered, if they do not exists, returns null
element_t * find_element( element_t * list, char * symbol )
{
    int i;
    for( i = 0; i < 118; i++ )
    {
        if ( strcmp( list[i].symbol, symbol ) == 0 )
        {
            element_t * result = &list[i];
            return result;
        }
    }
    return NULL;
}

//print_element takes in the number of elements, and the array of elements
//It prints the users input in the format described in the lab
void print_element(element_t *e, FILE *output) {
	printf("---------------\n");
	printf("| %d\t%.4lf\n", e->atomic_number, e->atomic_weight);
	printf("| %s\t%s\n", e->symbol, e->name);
	printf("| %s\n", e->state);
	printf("| %s\n", e->bonding_type);
	printf("| Found: %s\n", e->discovered);
	printf("---------------\n");
	if(output != NULL)
	{
		fprintf(output, "---------------\n");
        	fprintf(output, "| %d\t%.4lf\n", e->atomic_number, e->atomic_weight);
       	 	fprintf(output, "| %s\t%s\n", e->symbol, e->name);
	        fprintf(output, "| %s\n", e->state);
        	fprintf(output, "| %s\n", e->bonding_type);
        	fprintf(output, "| Found: %s\n", e->discovered);
		fprintf(output, "---------------\n");
	}
}
