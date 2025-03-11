/* File: subsum.c */
 // Code author: Nikos Aivaliotis
 
 #include <stdio.h>
 #include <stdlib.h>
 
 // Recursive function to check for the existence of a non-empty subset with sum 0
 int hasZeroSubsetSum(int *numbers, int size, int sum, int count) {
     if (sum == 0 && count > 0) // If a non-empty subset with sum 0 is found
         return 1;
     if (size == 0) // If all elements are exhausted without success
         return 0;
 
     // Try either excluding or including the last element
     int exclude = hasZeroSubsetSum(numbers, size - 1, sum, count);
     int include = hasZeroSubsetSum(numbers, size - 1, sum - numbers[size - 1], count + 1);
 
     return exclude || include; // Return which case is true (or either of them)
 }
 
 int main(void) {
     
     int size;
     int *numbers;
 
     // Ask the user to enter the number of elements
     printf("Please give me the number of elements: ");
     int result = scanf("%d", &size);
 
     if (result == EOF || result != 1) { // Fixing incorrect assignment (=) to comparison (==)
         fprintf(stderr, "No valid number provided\n");
         return 1;
     }
 
     // Memory allocation using malloc for creating and filling the array
     numbers = (int *)malloc(size * sizeof(int));
     if (numbers == NULL) {
         fprintf(stderr, "Memory allocation failed due to exhaustion\n");
         return 1; // Exit with code 1
     }
 
     // The user inserts elements with a loop
     printf("Please fill up the array with numbers of yours: ");
     for (int i = 0; i < size; i++) {
         scanf("%d", &numbers[i]); // User-given numbers
     }
 
     // Check for a subset with sum 0
     printf("Checking is being conducted...\n");
     int found = hasZeroSubsetSum(numbers, size, 0, 0);
 
     // Print the result in each case
     if (found)
         printf("There is a subset with sum=0\n");
     else
         printf("There is no such subset with sum=0\n");
 
     // Free the allocated memory
     free(numbers);
     return 0; // Successful termination of the program
 }