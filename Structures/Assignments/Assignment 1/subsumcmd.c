/* File: subsum.c */
// Code author: Nikos Aivaliotis (modified for readability)

#include <stdio.h>
#include <stdlib.h>

// Αναδρομική συνάρτηση για τον έλεγχο ύπαρξης μη κενού υποσυνόλου με άθροισμα 0
int hasZeroSubsetSum(int *numbers, int size, int sum, int count) {
    if (sum == 0 && count > 0) // Αν βρήκαμε μη κενό υποσύνολο με άθροισμα 0
        return 1;
    if (size == 0) // Αν εξαντλήσαμε τα στοιχεία χωρίς επιτυχία
        return 0;

    // Δοκιμάζουμε είτε να αγνοήσουμε είτε να συμπεριλάβουμε το τελευταίο στοιχείο
    int exclude = hasZeroSubsetSum(numbers, size - 1, sum, count);
    int include = hasZeroSubsetSum(numbers, size - 1, sum - numbers[size - 1], count + 1);

    return exclude || include;
}

int main(void) {
    int size;
    int *numbers;

    // Ask the user to enter the number of elements
    printf("Please give me the number of elements: ");
    int result=scanf("%d", &size);

    if(result=EOF || result!=1) {
        fprintf(stderr, "No valid number provided\n");
        return 1;
    }


    // Memory allocation, using malloc, for the making and filling of the array
    numbers = (int *)malloc(size * sizeof(int));
    if (numbers == NULL) {
        fprintf(stderr, "Memory allocation failed due to exhaustion\n");
        return 1;
    }

    // The user inserts elements with a loop
    printf("Please fill up the array with numbers of yours: ");
    for(int i = 0; i < size; i++) {
        scanf("%d", &numbers[i]);
    }

    // Check 
    printf("Checking is being conducted...\n");
    int found = hasZeroSubsetSum(numbers, size, 0, 0);

    // Print the result in each case
    if (found)
        printf("There is a subset with sum=0\n");
    else
        printf("There is no such subset with sum=0\n");

    // Free the memory allocated by me
    free(numbers);
    return 0; // Successful termination of the program
}