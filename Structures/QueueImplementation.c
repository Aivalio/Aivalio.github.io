/*This is the file QueueImplementation.c*/
#include <stdio.h>
#include <stdlib.h>
#include "QueueInterface.h"

void InitializeQueue(Queue*Q) {

    Q->Count=0;
    Q->Front=0;
    Q->Rear=0;
}

int Empty(Queue*Q) {

    return(Q->Count==0);
}

int Full(Queue*Q) {

    return(Q->Count==MAXQUEUESIZE);
}

void Insert(ItemType R, Queue*Q) {

    if(Q->Count==MAXQUEUESIZE) {
        fprintf(stderr, "Attempt to insert an item in a full queue\n");
        return;
    }

    else {

        Q->Items[Q->Rear]=R;
        Q->Rear=(Q->Rear+1)%MAXQUEUESIZE;
        (Q->Count)++;
    }
}

void Remove(Queue*Q, ItemType*F) {

    if(Q->Count==0) {
        fprintf(stderr, "Attempt to remove an item from an empty queue\n");
        return;
    } 
    else {

        *F=Q->Items[Q->Front];
        Q->Front=(Q->Front+1)%MAXQUEUESIZE;
        (Q->Count)++;
    }
}