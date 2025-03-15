/* This is the Implementation.c file for my module */

#include "DLLInterface.h"
#include <stdlib.h>
#include <stdio.h>

// Function to initialize by default a doubly-linked list
DoubleLink* Create(void) {

    DoubleLink* List = (DoubleLink*)malloc(sizeof(DoubleLink)); // Memory allocation via the malloc function
    if (List == NULL) {
        fprintf(stderr, "Failed to allocate memory due to exhaustion\n");
        return NULL; // If the allocation fails, the function terminates and outputs the appropriate message
    } else {
        List->Head = NULL;
        List->Tail = NULL;
        return List; // The head and tail point to NULL data
    }
}

// Function to print the list
void print(DoubleLink* List) {

    if (List == NULL || List->Head == NULL) {
        fprintf(stderr, "Attempt to print an empty list\n");
        return; // If the list is empty, the function terminates and outputs an error message
    } else {

        ListNode* temp = List->Head; // A pointer to hold the current node each time and print it
        while (temp != NULL) { // While loop to traverse the node of the list
            printf("%d ", temp->value); // Print the value
            temp = temp->next; // Move on to the next node
        }
        printf("\n"); // Fix missing semicolon
    }
}

// Function to check if my list is empty, using a pointer to it
int Empty(DoubleLink* List) {

    return (List == NULL || List->Head == NULL); // Checking the Head of the List
}

// Function to get the size of the list
int Size(DoubleLink* List) {

    int length = 0; // Initialize a counter for the size of the list

    ListNode* current = List->Head;
    if (current == NULL) {
        fprintf(stderr, "Please modify this pointer\n");
        return 0; // Return 0 if the list is empty
    } else {

        while (current != NULL) { // A loop to traverse the list nodes
            length++; // Increase the length counter
            current = current->next; // Move the pointer to the next node
        }
    }
    return length; // Return the length
}

// Function to remove a node from the list
void Remove(DoubleLink* List, int i) {

    if (List == NULL || List->Head == NULL) {
        fprintf(stderr, "Function termination\n");
        return;
    }

    ListNode* current = List->Head; // Declare a pointer to the Head initially in order to hold the node each time

    while (current != NULL) {
        if (current->value == i) {

            if (current->prev) current->prev->next = current->next;
            else List->Head = current->next;

            if (current->next) current->next->prev = current->prev;
            else List->Tail = current->prev;

            ListNode* Deleted = current;
            current = current->next;
            free(Deleted);
        } else {
            current = current->next;
        }
    }
    return;
}

// Function to get the element of the first node
int GetFirtst(DoubleLink* List) {

    if (List == NULL || List->Head == NULL) {
        fprintf(stderr, "Attempt to access an empty list\n"); 
        return -1; // Return an error flag 
    } else {

        return List->Head->value; // Returns the value of the Head
    }
}

// Function to get the element of the last node
int GetLast(DoubleLink* List) {

    if (List == NULL || List->Tail == NULL) {
        fprintf(stderr, "Attempt to access an empty list\n"); 
        return -1; // Return an error flag 
    } else {

        return List->Tail->value; // Returns the value of the Tail
    }
}

// Function to get the previous node's value
int GetPrev(ListNode* Node) {

    if (Node == NULL || Node->prev == NULL) {
        fprintf(stderr, "No valid previous element detected\n");
        return -1; // Return an error flag 
    } else {

        return Node->prev->value; // Returns the value of the previous node
    }
}

// Function to get the next node's value
int GetNext(ListNode* Node) {

    if (Node == NULL || Node->next == NULL) {
        fprintf(stderr, "No valid next element detected\n");
        return -1; // Return an error flag 
    } else {

        return Node->next->value; //Returns the value of the next node
    }
}

// Function to get a node at a specific index
ListNode* GetNode(DoubleLink* List, int index) {

    if (List == NULL || List->Head == NULL || index < 0) {
        fprintf(stderr, "Invalid list or index\n");
        return NULL; // If the list or the index are invalid, the function terminates and outputs a message
    } else {

        ListNode*temp=List->Head; // Initialize a pointer to List, which points to the Head
        int i=0; // Variable to traverse the nodes of the list

        do {

            if(i==index) {
                return temp; // If the comparison succeeds, the prefered node is returned
            }
            temp=temp->next; // The pointer moves on
            i++; // The variable grows
        } while(temp!=NULL) // Necessary to execute the loop
    }

    return NULL;
}

// Function to add an element at the beginning of the list
void AddFirst(DoubleLink*List, int data) {

    ListNode*new_node=(ListNode*)malloc(sizeof(ListNode)); // Memory allocation to create a new node
    if(new_node==NULL) {
        fprintf(stderr, "Failed to allocate memory\n");
        return NULL; // Checking the outcome of malloc
    }

    new_node->value; 
    new_node->next=List->Head; // The new node's next node is the Head
    new_node->prev=NULL; // The new node's previous node is NULL

    if(List->Head!=NULL) {

        List->Head->prev=new_node;
    }

    List->Head=new_node; // The new node now becomes the new Head
    
}

void AddLast(DoubleLink*List, int data) {

    ListNode*new_node=(ListNode*)malloc(sizeof(ListNode)); // Memory allocation for the creation of a new node
    if(new_node==NULL) {
        fprintf(stderr, "Failed to allocate memory\n");
        return NULL; // Checking the malloc outcome
    }

    new_node->value=data;
    new_node->next=NULL; // The new node's next node is NULL
    new_node->prev=List->Tail; // The new node's previous node is the Tail
    
    if(List->Tail!=NULL) {
        
        List->Tail->next=new_node
    }

    List->Tail=new_node; // The new node is the new Tail of the list

}

// Adding nodes
void AddBefore(DoubleLink* List, ListNode* Node, int data) {
    
    if (List == NULL || Node == NULL) {
        fprintf(stderr, "Function termination\n");
        return; // Initial checks for the function
    }
    ListNode* new_node = (ListNode*)malloc(sizeof(ListNode)); // Memory allocation using malloc
    if(new_node==NULL) {
        fprintf(stderr, "Failed to allocate memory\n");
        return NULL; // Malloc outcome check
    }
    new_node->value = data;
    new_node->prev = Node->prev; // The new node's previous node is the previous node of Node
    new_node->next = Node; // The Node is the new's node next node
    
    if (node->prev != NULL) node->prev->next = new_node;
    
    node->prev = new_node;
}

void AddAfter(DoubleLink* List, ListNode* Node, int data) {
    
    if (List == NULL || Node == NULL) {
        fprintf(stderr, "Function termination\n");
        return; // Initial function checks
    }
    
    ListNode* new_node = (ListNode*)malloc(sizeof(ListNode)); // Memory allocation
    if(new_node==NULL) {
        fprintf(stderr, "Failed to allocate memory\n");
        return NULL;
    }
    
    new_node->value = data;
    new_node->next = Node->next; // The new nodes's next node is the next node of Node
    new_node->prev = Node; // The previous node of the new node is the Node
    
    if (Node->next != NULL) Node->next->prev = new_node;
    
    node->next = new_node;
}

