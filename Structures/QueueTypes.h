/*This is the file QueueTypes.h*/

#define MAXQUEUESIZE 10

typedef int ItemType;
/*The item type can be arbitary*/

typedef struct {

    int Count;
    int Front;
    int Rear;
    ItemType Items[MAXQUEUESIZE];
} Queue;