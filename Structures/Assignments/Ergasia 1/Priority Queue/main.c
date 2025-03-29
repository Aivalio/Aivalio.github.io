
#include <stdio.h>
#include "PQInterface.h"

typedef PQItem SortingArray[MAXCOUNT];

// Function to sort the PQ
void PriorityQueueSort(SortingArray A) {
    
    PriorityQueue PQ = InitializeQueue();
    
    for (int i = 0; i < MAXCOUNT; ++i) Insert(A[i], PQ);
    for (int i = MAXCOUNT - 1; i >= 0; --i) A[i] = Remove(PQ);
}

// Calculation of the sqaure of a number
int SquareOf(int n) {
    
    return n*n;
}

// Main function to test the functionality of the PQ
int main(void) {
    
    SortingArray B;
    
    for (int i = 0; i < 10; ++i) {
        B[i] = SquareOf(3 * i - 13);
        printf("%d ", B[i]);
    }
    printf("\n"); // Filling of the queue

    PriorityQueueSort(B); // Sorting of the queue

    for (int i = 0; i < 10; ++i) {
        printf("%d ", B[i]);
    }
    printf("\n"); // Printing of the queue
    
    return 0; // Successful program termination
}
