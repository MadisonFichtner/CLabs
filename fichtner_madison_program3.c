/**
* Author: Madison Fichtner
* Last Edited: 4/20
* Program 3
**/

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#define NAME_SIZE 25

//student structure definition
typedef struct{
	int sid;
	char lastName[NAME_SIZE];
	char firstName[NAME_SIZE];
	float* grades;
	float gpa;
}student;

//Function prototypes
student scan(int gradeNums);
void print(student* student, int students, int grades);
float gpa(student student, int gradeNums);
void freeMemory(student *student, int students);

int main()
{
	//Initializing integers to take the user input for # of students and grades
	int students = 0;
	int grades = 0;

	//Prompting user for input and saving said input in 'students' and 'grades'
	printf("Enter the number of students: ");
	scanf("%d", &students);
	printf("Enter the number of grades (per student): ");
	scanf("%d", &grades);

	//Returning the # of students and grades entered
	printf("Number of students: %d\n", students);
	printf("Number of grades (each): %d\n", grades);

	//Initializing and allocating memory for a new array of students
	student* studentArray;
	studentArray = (student*)calloc(students, sizeof(student));

	//For each student, run the scan() function to take user input for each student record
	for(int i = 0; i < students; i++)
	{
		studentArray[i] = scan(grades);
	}

	//Return the list of students to the user
	print(studentArray, students, grades);

	//Free the programs used memory of the students to prevent leakage
	freeMemory(studentArray, students);
}

//Free memory clears the memory used in the program to store students
void freeMemory(student *student, int students)
{
	for(int i = 0; i < students; i++)
	{
		free(student[i].grades);
	}
	free(student);
	student = NULL;
}

//Scan takes the users input and saves it in each respectable student structure
student scan(int gradeNums)
{
	//Creating a new temporary student 's'
	student s;

	//Creating and allocating memory for the students grade array
	float* grades;
	grades = (float*)calloc(gradeNums, sizeof(float));

	//Take user input for ID, and name
	scanf("%d %s %s", &s.sid, &s.lastName, &s.firstName);

	//Take user input for the number of grades requested to be entered by the user
	for(int i = 0; i < gradeNums; i++)
	{
		scanf("%f", &grades[i]);
	}

	//Set individual students 'grades' variable to the populated array found in the last step
	s.grades = grades;
	//Set GPA
	s.gpa = gpa(s, gradeNums);
	//Return the temporary student
	return s;
}

//Print returns the student records
void print(student* student, int students, int grades)
{
	//For the number of students in the databse
	for(int i = 0; i < students; i++)
	{
		//Print out ID, name, GPA, followed by the students individual grades on next line
		printf("ID: %d, Name: %s %s, GPA: %.2f\n", student[i].sid, student[i].firstName, student[i].lastName, student[i].gpa);
		printf("Grades: ");
		for(int k = 0; k < grades; k++)
		{
			printf("%.1f ", student[i].grades[k]);
		}
		printf("\n");
	}
}

//gpa calculates a students GPA
float gpa(student student, int gradeNums)
{
	//Initially set gpa to 0
	float gpa = 0;
	for(int i = 0; i < gradeNums; i++)
	{
		//Increment GPA by each grade in the array of grades
		gpa += student.grades[i];
	}
	//Set GPA to the sum of all the grades divided by the number of grades
	gpa = gpa / gradeNums;

	//Return the students GPA as a float
	return gpa;
}
