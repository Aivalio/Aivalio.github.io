/* File: Interface.h */

// This is the Interface.h file for defining a doubly-linked list 

#ifndef DLLINTERFACE_H
#define DLLINTERFACE_H

// Struct definition for a doubly-linked list node
typedef struct ListNode {
    int value;               // The value contained in the node
    struct ListNode* next;   // Pointer to the next node
    struct ListNode* prev;   // Pointer to the previous node
} ListNode; // Variable for struct ListNode type

// Struct definition for the doubly-linked list
typedef struct DoubleLink {
    ListNode* Head;  // Pointer to the first node
    ListNode* Tail;  // Pointer to the last node
} DoubleLink; // Variable for struct DoubleLink type

// Function prototypes for the doubly-linked list operations

// Create a new doubly linked list
DoubleLink* Create(void); 

// Print the contents of the list
void print(DoubleLink* List);

// Check if the list is empty
int Empty(DoubleLink* List);

// Get the size of the list
int Size(DoubleLink* List);

// Remove a node at a given index
void Remove(DoubleLink* List, int i);

// Get the value of the first node
int GetFirst(DoubleLink* List);

// Get the value of the last node
int GetLast(DoubleLink* List);

// Get the value of the previous node
int GetPrev(ListNode* Node);

// Get the value of the next node
int GetNext(ListNode* Node);

// Get a node at a specific index
ListNode* GetNode(DoubleLink* List, int index);

// Add a new node at the beginning of the list
void AddFirst(DoubleLink* List, int data);

// Add a new node at the end of the list
void AddLast(DoubleLink* List, int data);

// Add a new node before a given node
void AddBefore(DoubleLink* List, ListNode* Node, int data);

// Add a new node after a given node
void AddAfter(DoubleLink* List, ListNode* Node, int data);

#endif // DLLINTERFACE_H
