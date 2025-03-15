/*This is the Interface.h file DLLInterface.h for my module*/
#include <stdio.h>
#include <stdlib.h>

// Declaration of a list node and a variable of such type
typedef struct listnode {

    int value;
    struct listnode*next;
    struct listnode*prev;
} ListNode;

// Declaration of a doubly-linked list and a variable of such type
typedef struct {

    ListNode*Head;
    ListNode*Tail;
} DoubleLink;

// Basic functions to handle a doubly-linked list
void print(DoubleLink*); // Function to print the list
int size(DoubleLink*); // Function to calculate the size of the list
int Empty(DoubleLink*); // Function to check whether the list is empty or not
int Remove(DoubleLink*, int ); // Function to remove a node from th list

// Functions to add a node to the list
void AddBefore
void AddAfter
void AddLast
void AddFirst

// Functions to access and control the elements of the list
int GetFirst(DoubleLink*)
int GetLast(DoubleLink*)
int GetPrev(ListNode*)
int GetNext(ListNode*)
ListNode*GetNode(DoubleLink*, int )

// Function to create a list
DoubleLink*Create(void)
