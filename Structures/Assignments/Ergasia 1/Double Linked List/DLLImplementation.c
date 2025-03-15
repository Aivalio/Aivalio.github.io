/*This is the Implementation.c file for my module*/

#include "DLLInterface.h"
#include <stdlib.h>
#include <stdio.h>

// Fucntion to initialize by default a doubly-linked list
DoubleLink*Create(void) {

    DoubleLink*List=(DoubleLink*)malloc(sizeof(DoubleLink)); // Memory allocation via the malloc function
    if(List==NULL) {
        fprintf(stderr, "Failed to allocate memory due to exhaustion\n");
        return NULL; // If the allocation fails, the fucntion terminates and outputs the appropriate message
    } else {

        List->Head=NULL;
        List->Tail=NULL;
        return List; // The head and tail point to NULL data
    }
}

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

        do { // A loop to traverse the list nodes

            length++; // Increase the length counter
            current=current->next // Move the pointer to the next node
        } while(current!=NULL); // Prerequisite
    }
    return length; // Return the length
}

// Function to remove a node from the list
void Remove(DoubleLink* List, int i) {
    
    if (List == NULL) {
        fprintf(stderr, "Function termination\n");
        return;
    }
    
    ListNode* current = List->Head; // Declare a pointer to the Head initially in order to hold the node each time

     {
        if (current->value == i) {
            
            if (current->prev) current->prev->next = current->next;
            else List->Head = current->next; 

            if (current->next) current->next->prev = current->prev;
            else List->Tail = current->prev;

            ListNode*Deleted = current;
            current = current->next;
            free(Deleted);
        } else {
            current = current->next;
        }
    } while(current);
}



