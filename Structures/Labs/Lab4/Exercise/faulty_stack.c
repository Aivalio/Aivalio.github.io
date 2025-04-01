#include <stdlib.h>
#include <limits.h>
#include "faulty_stack.h"
#include <stdio.h>

struct node{
    int data;
    Node *next;
};

struct stack{
    Node *list;
    int count;
};

//Function to create a new stack node
Node* create_stack_node(int data){
    Node *node = malloc(sizeof(Node));
    node->next = NULL;
    node->data = data;
    return node;
}

//Function to initialize a stack
// ERROR HERE - INITIALIZATION ERROR
Stack *stack_init(){
    
    Stack *s;
    s=malloc(sizeof(Stack));
    if(s==NULL) {
        fprintf(stderr, "Failed to allocate memory\n");
        return NULL;
    }

    s->list = NULL;
    s->count = 0;
    return s;
}

//Function to check if a stack is empty
int stack_empty(Stack *s){
    return s->count==0;
}

//Function to return the stack size
int stack_size(Stack *s){
    return s->count;
}

//Function to pop the top element of the stack and return it
//ERROR HERE - MEMORY LEAK
int stack_pop(Stack *s) { 
    // If the stack is empty, return INT_MIN
    if (stack_empty(s)) {
        return INT_MIN;
    }

    // Traverse to the last node in the stack
    Node *cur = s->list, *prev = NULL; 
    while (cur->next != NULL) { 
        prev = cur; 
        cur = cur->next; 
    } 

    // Save the data of the last node
    int result = cur->data; 

    // Free the memory of the last node
    free(cur); 

    // Update the stack's list pointer
    if (prev) {
        prev->next = NULL;
    } else {
        s->list = NULL; // If there was only one node, the stack is now empty
    }

    // Decrease the element count in the stack
    s->count--; 

    return result; 
}

//Function to return the value of the top element of the stack without removing it
//ERROR HERE - INVALID READ
int stack_peek(Stack *s){

    //check if the stack is empty
    if(stack_empty(s))
        return INT_MIN;

    Node *cur = s->list;

    while(cur->next!=NULL){
        cur = cur->next;
    }

    return cur->data;
}

//Function to insert a new element to a stack
//ERROR HERE - INVALID READ/WRITE
//TIP: the condition of the while loop
Stack* stack_push(Stack *s, int data) { 
    // Create a new node with the given data
    Node *node = create_stack_node(data); 
     
    // If the stack is empty, make the new node the first element
    if (!s->list) { 
        s->list = node; 
    } else { 
        // Traverse to the last node of the stack
        Node *cur = s->list; 
        while(cur->next != NULL) { // Traverse until the last element
            cur = cur->next; 
        } 
        // Add the new node after the last node
        cur->next = node; // Correctly adding the new node
    } 
     
    // Increment the stack's element count
    s->count++; 
    
    return s; // Return the updated stack
}


//Function to merge two stacks. The memory of the two stacks must be freed
//ERROR HERE - MEMORY LEAKS
Stack* stack_merge(Stack *s1,Stack *s2){
    Stack *newStack = stack_init();

    Node *cur = s1->list;
    while(cur!=NULL){
        newStack = stack_push(newStack,cur->data);
        cur = cur->next;
    }

    cur = s2->list;
    while(cur!=NULL){
        newStack = stack_push(newStack,cur->data);
        cur = cur->next;
    }
    
    stack_destroy(s1);
    stack_destroy(s2);

    return newStack;
}

//Function to destroy a stack
//ERROR HERE - MEMORY LEAKS
void stack_destroy(Stack *s){

    Node *cur = s->list;
    Node* next = NULL;

    while(cur!=NULL) {
        next=cur->next;
        free(cur);
        cur=next;
    }
    
    free(s);
}
