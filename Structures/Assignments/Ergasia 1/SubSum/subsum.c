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
     
     int sumarray[] = {-76, 90, 108, 45, 76, 87}; // Define an array and initialize it with integers
     int capacity = sizeof(sumarray) / sizeof(sumarray[0]); // The size of the array
 
     if (subsetSum(sumarray, capacity, 0))
         fprintf(stderr, "Failure\nn");
     else
         fprintf(stderr, "No set with sum equal to zero\n");
         return 1; // The program exits with code 1 and a proeper error message
 
     return 0; // Successful program termination
 }
