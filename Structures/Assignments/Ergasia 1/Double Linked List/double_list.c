/*This is the client program for my module*/
/*File:double_list.c*/

#include <stdio.h>
#include <stdlib.h>
#include "DLLInterface.h"

int main(void) {
    // Creation of a doubly-linked list
    DoubleLink* List = Create();

    if (List == NULL) {
        fprintf(stderr, "Failed to initialize the list\n");
        return 1;
    }

    // Calling of AddFirst function to fill the list
    AddFirst(List, 10);
    AddLast(List, 20);
    AddLast(List, 30);
    AddFirst(List, 5);

    // List printing
    printf("List printed: ");
    print(List);
    
    // Printing of the first list element
    printf("First element of the list: %d\n", GetFirst(List));
    
    // Printing of the last list element
    printf("Last element of the list: %d\n", GetLast(List));

    // Creation of a Node to use AddBefore and AddAfter
    ListNode*Node=malloc(ListNode*)malloc(sizeof(ListNode));
    if(Node==NULL) {
        fprintf(stderr, "Failed to allocate memory\n");
        return 1;
    } else {

        AddBefore(List , Node, 35);
        AddAfter(List, Node, 44);
    }

    // Printing of the new list
    printf("The new list is: ");
    print(List);

    // Removal of an element
    Remove(List, 10);
    printf("The new list is: ");
    print(List);

    // Memory deallocation
    free(Node); 
    free(List);
    
    return 0; // Successful program termination
}
