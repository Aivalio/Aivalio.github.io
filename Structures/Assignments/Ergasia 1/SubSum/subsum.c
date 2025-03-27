/*File:subsum.c*/
 //Code author: Nikos Aivaliotis
 
 #include <stdio.h>
 #include <stdlib.h>
#include <stdint.h>
 
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
     
     int array[] = {-76, 90, 108, 45, 76, 87}; // Define an array and initialize it with integers
     int size = sizeof(array) / sizeof(array[0]); // The size of the array
 
     if (subsetSum(array, size, 0))
         printf("Υπάρχει υποσύνολο με άθροισμα 0\n");
     else
         fprintf(stderr, "Δεν υπάρχει υποσύνολο με άθροισμα 0\n");
         return 1; // The program exits with code 1 and a proeper error message
 
     return 0; // Successful program termination
 }
