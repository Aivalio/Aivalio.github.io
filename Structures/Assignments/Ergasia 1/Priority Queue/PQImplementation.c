/*This is the PQImplementation.c*/
#include <stdio.h>
#include <stdlib.h>
#include "PQInterface.h"

typedef struct PQNodeTag {
    PQItem NodeItem;
    struct PQNodeTag *Link;
} PQListNode;

struct PriorityQueueTag {
    int Count;
    PQListNode *ItemList;
};

// Function to initialize my PQ
PriorityQueue InitializeQueue(void) {
    
    PriorityQueue PQ = (PriorityQueue)malloc(sizeof(struct PriorityQueueTag));
    if(PQ==NULL) {
        fprintf(stderr, "Memory allocation failed due to exhaustion\n");
        exit(EXIT_FAILURE);
    }
    
    PQ->Count = 0; // The counter is initialized to zero
    PQ->ItemList = NULL; // No items contained in my PQ
    
    return PQ;
}

int Empty(PriorityQueue PQ) {
    
    return (PQ->Count == 0); // Check the counter
}

int Full(PriorityQueue PQ) {
    
    return (PQ->Count == MAXCOUNT); // Check if the PQ is full
}

PQListNode *SortedInsert(PQItem Item, PQListNode *P) {
    
    PQListNode *N;
    if (!P || Item >= P->NodeItem) {
        N = (PQListNode *)malloc(sizeof(PQListNode));
        if(!N) {
            fprintf(stderr, "Memory allocation failed due to exhaustion\n");
            exit(EXIT_FAILURE);
        }
        
        N->NodeItem = Item;
        N->Link = P;
        
        return N;
    }
    
    P->Link = SortedInsert(Item, P->Link);
    
    return P;
}

// Function to insert an item to my PQ
void Insert(PQItem Item, PriorityQueue PQ) {
    
    if (!Full(PQ)) {
        
        PQ->Count++;
        PQ->ItemList = SortedInsert(Item, PQ->ItemList);
    }
}

// Fucntion to remove the item with the highest priority
PQItem Remove(PriorityQueue PQ) {
    if (!Empty(PQ)) {
        PQItem temp = PQ->ItemList->NodeItem;
        PQListNode *toDelete = PQ->ItemList;
        PQ->ItemList = PQ->ItemList->Link;
        free(toDelete);
        PQ->Count--;
        return temp;
    }
    return -1; // Indication of an empty queue
}
