/*This is the PQInterface.h*/

#define MAXCOUNT 10

typedef int PQItem;

typedef struct PriorityQueueTag *PriorityQueue;

PriorityQueue InitializeQueue(void);
int Empty(PriorityQueue);
int Full(PriorityQueue);
void Insert(PQItem, PriorityQueue);
PQItem Remove(PriorityQueue);