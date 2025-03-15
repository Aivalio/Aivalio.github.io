/* This is the Implementation.c file for my module */

#include "DLLInterface.h"
#include <stdlib.h>
#include <stdio.h>

// Function to initialize by default a doubly-linked list
DoubleLink* Create(void) {

    DoubleLink* List = (DoubleLink*)malloc(sizeof(DoubleLink)); // Memory allocation via the malloc function
    if (List == NULL) {
        fprintf(stderr, "Failed to allocate memory due to exhaustion\n");
        return NULL; // If the allocation fails, the function terminates and outputs the appropriate message
    } else {
        List->Head = NULL;
        List->Tail = NULL;
        return List; // The head and tail point to NULL data
    }
}

// Function to print the list
void print(DoubleLink* List) {

    if (List == NULL || List->Head == NULL) {
        fprintf(stderr, "Attempt to print an empty list\n");
        return; // If the list is empty, the function terminates and outputs an error message
    } else {

        ListNode* temp = List->Head; // A pointer to hold the current node each time and print it
        while (temp != NULL) { // While loop to traverse the node of the list
            printf("%d ", temp->value); // Print the value
            temp = temp->next; // Move on to the next node
        }
        printf("\n"); // Fix missing semicolon
    }
}

// Function to check if my list is empty, using a pointer to it
int Empty(DoubleLink* List) {

    return (List == NULL || List->Head == NULL); // Checking the Head of the List
}

// Function to get the size of the list
int Size(DoubleLink* List) {

    int length = 0; // Initialize a counter for the size of the list

    ListNode* current = List->Head;
    if (current == NULL) {
        fprintf(stderr, "Please modify this pointer\n");
        return 0; // Return 0 if the list is empty
    } else {

        while (current != NULL) { // A loop to traverse the list nodes
            length++; // Increase the length counter
            current = current->next; // Move the pointer to the next node
        }
    }
    return length; // Return the length
}

// Function to remove a node from the list
void Remove(DoubleLink* List, int i) {

    if (List == NULL || List->Head == NULL) {
        fprintf(stderr, "Function termination\n");
        return;
    }

    ListNode* current = List->Head; // Declare a pointer to the Head initially in order to hold the node each time

    while (current != NULL) {
        if (current->value == i) {

            if (current->prev) current->prev->next = current->next;
            else List->Head = current->next;

            if (current->next) current->next->prev = current->prev;
            else List->Tail = current->prev;

            ListNode* Deleted = current;
            current = current->next;
            free(Deleted);
        } else {
            current = current->next;
        }
    }
}

// Function to get the element of the first node
int GetFirtst(DoubleLink* List) {

    if (List == NULL || List->Head == NULL) {
        fprintf(stderr, "Attempt to access an empty list\n"); 
        return -1; // Return an error flag 
    } else {

        return List->Head->value;
    }
}

// Function to get the element of the last node
int GetLast(DoubleLink* List) {

    if (List == NULL || List->Tail == NULL) {
        fprintf(stderr, "Attempt to access an empty list\n"); 
        return -1; // Return an error flag 
    } else {

        return List->Tail->value;
    }
}

// Function to get the previous node's value
int GetPrev(ListNode* Node) {

    if (Node == NULL || Node->prev == NULL) {
        fprintf(stderr, "No valid previous element detected\n");
        return -1; // Return an error flag 
    } else {

        return Node->prev->value;
    }
}

// Function to get the next node's value
int GetNext(ListNode* Node) {

    if (Node == NULL || Node->next == NULL) {
        fprintf(stderr, "No valid next element detected\n");
        return -1; // Return an error flag 
    } else {

        return Node->next->value;
    }
}

// Function to get a node at a specific index
ListNode* GetNode(DoubleLink* List, int index) {

    if (List == NULL || List->Head == NULL || index < 0) {
        fprintf(stderr, "Invalid list or index\n");
        return NULL;
    } else {

        ListNode*temp=List->Head;
        int i=0;

        do {

            if(i==index) {
                return temp;
            }
            temp=temp->next;
            i++
        } while(temp!=NULL)
    }

    return NULL
}
