#include <stdio.h>
#include <stdlib.h>

// Declaration of a list node and a variable of such type
typedef struct listnode {
    int value;
    struct listnode* next;
    struct listnode* prev;
} ListNode;

// Declaration of a doubly-linked list and a variable of such type
typedef struct {
    ListNode* Head;
    ListNode* Tail;
} DoubleLink;

// List creation
DoubleLink* Create();

// List information
int Size(DoubleLink* list);
int IsEmpty(DoubleLink* list);

// Accessing elements
int GetFirst(DoubleLink* list);
int GetLast(DoubleLink* list);
ListNode* GetNode(DoubleLink* list, int i);
int GetPrev(ListNode* node);
int GetNext(ListNode* node);

// Adding nodes
void AddBefore(DoubleLink* list, ListNode* node, int i);
void AddAfter(DoubleLink* list, ListNode* node, int i);
void AddFirst(DoubleLink* list, int i);
void AddLast(DoubleLink* list, int i);

// Removing nodes
void Remove(DoubleLink* list, int i);

// Printing list
void Print(DoubleLink* list);

