/*This is the Implementation.c file for my module*/

#include "DLLInterface.h"
#include <stdlib.h>
#include <stdio.h>

// Function to print the list
void print(DoubleLink*List) {

    if(List==NULL) {
        fprintf(stderr, "Attempt to print an empty list\n");
        return; // If the list is empty, the functions terminates and outputs an error message
    } else {

        ListNode*temp=List->Head; // A pointer to hold the current node each time and print it
        while(temp!=NULL) { // While loop to traverse he node of the list
            printf("%d", temp->value); // Print the  value
            temp=temp->next; // Move on to the next node
        }
        printf("\n")
    }
}

// Function to check if my list is empty, using a pointer to it
int Empty(DoubleLink*List) {

    return(List->Head==NULL); // Checking the Head of the List
}

int Size(DoubleLink*List) {

    int length=0; // Initializa a counter for the size of the list

    ListNode*current=List->Head;
    if(current==NULL) {
        fprintf(stderr, "Please modify this pointer\n");
        return 1;
    } else {

        do {

            length++;
            current=current->next
        } while(current!=NULL);
    }
    return length;
}

void Remove(DoubleLink*List, int data) {

    if(List==NULL) {
        fprintf(stderr, "Function termination\n");
        return;
    }
    ListNode*temp=List->Head;
    
    do {

        if(temp->value=data) {
            
        }
    }

}