/*This is the StackTypes.h file to determine the type of my stack*/

#define MAXSTACKSIZE 100 // Maximum stack size

typedef float ItemType;

typedef struct{
    
    int Count;
    ItemType Items[MAXSTACKSIZE];
} Stack; // A variable of type struct for my stack