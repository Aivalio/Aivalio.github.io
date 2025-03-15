
    #include <stdio.h>
#include <stdlib.h>

#include "DoublyLinkedList.h"

// List creation
DoubleLink* Create() {
    DoubleLink* list = (DoubleLink*)malloc(sizeof(DoubleLink));
    if (list == NULL) {
        printf("Error: Memory allocation failed!\n");
        exit(1);
    }
    list->Head = NULL;
    list->Tail = NULL;
    return list;
}

// List information
int Size(DoubleLink* list) {
    int count = 0;
    ListNode* current = list->Head;
    while (current != NULL) {
        count++;
        current = current->next;
    }
    return count;
}

int IsEmpty(DoubleLink* list) {
    return (list->Head == NULL);
}

// Accessing elements
int GetFirst(DoubleLink* list) {
    if (list == NULL || list->Head == NULL) {
        printf("Error: The list is empty!\n");
        exit(1);
    }
    return list->Head->value;
}

int GetLast(DoubleLink* list) {
    if (list == NULL || list->Tail == NULL) {
        printf("Error: The list is empty!\n");
        exit(1);
    }
    return list->Tail->value;
}

ListNode* GetNode(DoubleLink* list, int i) {
    if (list == NULL) return NULL;
    ListNode* current = list->Head;
    while (current != NULL) {
        if (current->value == i) return current;
        current = current->next;
    }
    return NULL;
}

int GetPrev(ListNode* node) {
    if (node == NULL || node->prev == NULL) {
        printf("Error: No previous element!\n");
        exit(1);
    }
    return node->prev->value;
}

int GetNext(ListNode* node) {
    if (node == NULL || node->next == NULL) {
        printf("Error: No next element!\n");
        exit(1);
    }
    return node->next->value;
}

// Adding nodes
void AddBefore(DoubleLink* list, ListNode* node, int i) {
    if (list == NULL || node == NULL) return;
    ListNode* newNode = (ListNode*)malloc(sizeof(ListNode));
    newNode->value = i;
    newNode->prev = node->prev;
    newNode->next = node;
    
    if (node->prev != NULL) node->prev->next = newNode;
    else list->Head = newNode;
    
    node->prev = newNode;
}

void AddAfter(DoubleLink* list, ListNode* node, int i) {
    if (list == NULL || node == NULL) return;
    ListNode* newNode = (ListNode*)malloc(sizeof(ListNode));
    newNode->value = i;
    newNode->next = node->next;
    newNode->prev = node;
    
    if (node->next != NULL) node->next->prev = newNode;
    else list->Tail = newNode;
    
    node->next = newNode;
}

void AddFirst(DoubleLink* list, int i) {
    if (list == NULL) return;
    ListNode* newNode = (ListNode*)malloc(sizeof(ListNode));
    newNode->value = i;
    newNode->next = list->Head;
    newNode->prev = NULL;

    if (list->Head != NULL) list->Head->prev = newNode;
    else list->Tail = newNode;

    list->Head = newNode;
}

void AddLast(DoubleLink* list, int i) {
    if (list == NULL) return;
    ListNode* newNode = (ListNode*)malloc(sizeof(ListNode));
    newNode->value = i;
    newNode->next = NULL;
    newNode->prev = list->Tail;

    if (list->Tail != NULL) list->Tail->next = newNode;
    else list->Head = newNode;

    list->Tail = newNode;
}

// Removing nodes
void Remove(DoubleLink* list, int i) {
    if (list == NULL) return;
    ListNode* current = list->Head;
    
    while (current != NULL) {
        if (current->value == i) {
            ListNode* toDelete = current;
            if (current->prev != NULL) current->prev->next = current->next;
            else list->Head = current->next;

            if (current->next != NULL) current->next->prev = current->prev;
            else list->Tail = current->prev;

            current = current->next;
            free(toDelete);
        } else {
            current = current->next;
        }
    }
}

// Printing list
void Print(DoubleLink* list) {
    if (list == NULL) return;
    ListNode* current = list->Head;
    while (current != NULL) {
        printf("%d ", current->value);
        current = current->next;
    }
    printf("\n");
}
