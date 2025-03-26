/*This is the main.c file*/
#include <stdio.h>
#include "PQInterface.h"
#include <math.h>

typedef PQItem SortingArray[MAXCOUNT];

// Function to sort the PQ
void PriorityQueueSort(SortingArray A) {
    
    PriorityQueue PQ = InitializeQueue();
    
    for (int i = 0; i < MAXCOUNT; ++i) Insert(A[i], PQ);
    for (int i = MAXCOUNT - 1; i >= 0; --i) A[i] = Remove(PQ);
}

// Function to return the square of a number
int SquareOf(int n) {
    
    return n*n;
}

// Main function to test the functionality of the PQ
int main(void) {
    
    SortingArray A;
    
    for (int i = 0; i < 10; ++i) {
        A[i] = SquareOf(3 * i - 13);
        printf("%d ", A[i]);
    }
    printf("\n"); // Filling of the queue

    PriorityQueueSort(A); // Sorting of the queue

    for (int i = 0; i < 10; ++i) {
        printf("%d ", A[i]);
    }
    printf("\n"); // Printing of the queue
    
    return 0; // Successful program termination
}
