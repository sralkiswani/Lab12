// Programmer: Samer Alkiswani
// Program name: Letter Grade
// Program task: The program asks the user to enter 8 grades in the range of 0 to 100, displays the letter grades for all sorted scores, and displays the average letter grade and score of all scores

#include <stdio.h> // Preprocesser directive that calls to standard input/output library functions

#define SIZE 8  // Define the number of elements in an array

// Function prototype of sorting the grades ascendingly 
void sortGradesAscending (int a[]);  

// Fuction prototyoe of determining the letter grade
char determineLetterGrade (int score); 

int main (void) {

    int gradesArray[SIZE] = {0}; // Declare array "gradesArray" and initialize the values of all its elements to 0
    
    int grade; // Declare "grade"

    puts (""); 

    for (int i = 0; i < SIZE; ++i ) {

        printf ("Enter grade %d:\t", i + 1); // Display prompt to enter the grades
        
        scanf ("%d", &grade); // Read the grades

        while (grade > 100 || grade < 0) {

            printf ("The grade is out of range. Re-enter grade %d (between 0 and 100): ", i + 1); // Display an error message
            scanf ("%d", &grade); // Re-read the grade

        }

        gradesArray[i] = grade; // Assign grades entered to the value of elements of array "gradesArray"

    }

    sortGradesAscending(gradesArray); // Call function "sortGradesAscending"

    puts ("");

    puts ("Sorted grades:"); // Display header

    for (int i = 0; i < SIZE; ++i) {

        printf ("%d - %c\n", gradesArray[i], determineLetterGrade(gradesArray[i])); // Print the grade and the letter grade

    }

    puts (""); 

    float total = 0; // Declare "total" and assign 0 to it

    for (int i = 0; i < SIZE; ++i) {

        total = total + gradesArray[i]; // Sum all the elements of array "gradesArray"

    }

    float average = total / SIZE; // Declare "average" and assign the value of "total / 8" to it

    printf ("Grade average of the %d grades: %0.1f%% - %c\n", SIZE, average, determineLetterGrade(average)); // Display the average and letter grade of all scores

} 

// Function definition of sorting the grades ascendingly 
void sortGradesAscending(int a[]) {

    for (int pass = 1; pass < SIZE; ++pass) {

        for (int i = 0; i < SIZE - 1; ++i) {

            if (a[i] > a [i + 1]) {

                int hold = a[i]; // Declare "hold" and assign the value of element a[i] to it

                a[i] = a[i + 1]; // assign the value of element a[i + 1] to a[i]

                a[i + 1] = hold; // assign "hold" to element a[i + 1]

            }

        }
 
    }

}

// Function definition of determining the letter grade
char determineLetterGrade (int score) {

// Check the score passed from function "main" and return the letter grade associated with each sore to function "main"
 
    if (score >= 90) {
        return 'A';
    }

    else if (score >= 80) {
        return 'B';
    }

    else if (score >= 70) {
        return 'C';
    }

    else if (score >= 60) {
        return 'D';
    }

    else {
        return 'F';
    }


}