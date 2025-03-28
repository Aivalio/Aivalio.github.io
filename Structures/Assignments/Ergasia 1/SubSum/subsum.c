/*File:subsum.c*/

#include <stdio.h>
#include <stdlib.h>

 // Function to find the powerset
 int subsetSum(int *array, int value, int sum) {
     if (sum == 0) // Default case
         return 1;
     if (value == 0) // No set found after check
         return 0;
 
     // Choice: include or exclude the element
     return subsetSum(array, value - 1, sum) || subsetSum(array, value - 1, sum - array[value - 1]);
 }
 
 // Main function for simulation
 int main(void) {
     
     int*sumarray; // Declare a pointer for my array
     int capacity; // The size of the array
     
     printf("Please give me the number if terms to be added: "); // Prompt the user to enter the array size
     int result=scanf("%d\n", &capacity); // Store the input to an integer

     if(result==EOF || result!=1) {
        fprintf(stderr, "No valid input given\n");
        return 1;
     } // Check for valid input and an error message

     sumarray=(int*)malloc(capacity*sizeof(int)); // Memory allocation for my array
     if(sumarray==NULL) {
        frpintf(stderr, "Memory allocation failed due to exhaustion\n");
        return -1; // Termination of the program
     }

     for(int i=0; i<capacity; i++) {
        scanf("%d\n", &sumarray[i]);
     } // Filling of the array by the user

     for(int i=0; i<capacity; i++) {
        printf("%d\n", sumarray[i]);
     } // Printing of the array
     
     if (subsetSum(sumarray, capacity, 0))
         fprintf(stderr, "Failure\nn");
     else
         fprintf(stderr, "No set with sum equal to zero\n");
         return 1; // The program exits with code 1 and a proeper error message
 
    free(sumarray); // Memory deallocation
    return 0; // Successful program termination
 }
