/* This is the StackInterface.h file */
#include "StackTypes.h"

// Functions to handle my stack

void Initialize(Stack *S); // Function to initialize my stack
int Empty(Stack *S); // Function to check if my stack is empty or not
int Full(Stack *S); // Function to check uf my stack is full or not
void Push(ItemType X, Stack *S); // Function to push an item to mys stack
void Pop(Stack *S, ItemType *X); // Function to remove an item from my stack