/*This is the StackImplementation.c file*/

#include <stdio.h>
#include <stdlib.h>
#include "StackInterface.h"

// Function to initialize my stack
void Initialize(Stack*S) {

    S->Count=0; // The stack has no elements, so the count equals to zero
}

// Function to check if the stack is empty
int Empty(Stack*S) {

    return(S->Count==0);
}

// Function to check if the stack is full
int Full(Stack*S) {

    return(S->Count==MAXSTACKSIZE);
}

// Function to push an item to my list
void push(ItemType X, Stack*S) {

    if(S->Count==MAXSTACKSIZE) {
        fprintf(stderr, "Stack Overflow detected. Failure\n");
        return;
    } else {

        S->Items[S->Count++]=X; // The item is added to my stack
    }
}

//Function to remove an item from my list
void pop(ItemType*X, Stack*S) {

    if(S->Count==0) {
        fprintf(stderr, "Attempt to get an item from an empty stack\n");
        return;
    } else {

        *X = S->Items[--S->Count]; // The item is removed from my stack
    }
}
