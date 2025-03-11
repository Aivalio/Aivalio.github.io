/*File:insertion.c*/
 //Code author: Nikos Aivaliotis
 
 #include <stdio.h>
 #include <stdlib.h>
 
 // Definition of a list node and a pointer to it
 typedef struct listnode {
     int value;
     struct listnode* next;
 }*List;
 
 // Function to insert a node at the beginning of my list, using a pointer to pointer to traverse the list
 void insert_front(List *head, int new_value) {
     List new_node = (List)malloc(sizeof(struct listnode));
     if (new_node == NULL) {
         fprintf(stderr, "Failed to allocate memory\n");
         exit(EXIT_FAILURE); //If memory allocation fails, the program exits and gives an error message
     }
     new_node->value = new_value; //The value of the new head is that of the old one
     new_node->next = *head; //The new node points to the old head
     *head = new_node; //Now the head of the list is the new node
 }
 
 // Συνάρτηση ταξινόμησης λίστας με εισαγωγή (Insertion Sort)
 List mysortlist(List head) {
     
     if (head==NULL || head->next==NULL) {
         fprintf(stderr, "Void list\n");
         return head; //If the list has one or no node, the fucntion terminates and returns a pointer head
     }
     
     List sorted = head;
     head = head->next;
     sorted->next = NULL;
     
     while (head!=NULL) {
         
         List current = head;
         head = head->next;
         
         if (current->value < sorted->value) {
             current->next = sorted;
             sorted = current;
         } else {
             List temp = sorted;
             while (temp->next && temp->next->value < current->value) {
                 temp = temp->next;
             }
             current->next = temp->next;
             temp->next = current;
         }
     }
     
     return sorted;
 }
