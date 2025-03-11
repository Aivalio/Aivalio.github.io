/*File:list.c*/
//Code author: Nikos Aivaliotis
 #include <stdio.h>
 #include <stdlib.h>
 
 typedef struct listnode {
 
     int value;
     struct listnode*next;
 }*List; //Pointer to struct listnode data
 
 //Fucntion to find the max element of a list
 List maxsearch(List head) {
 
     if(head==NULL) {
         fprintf(stderr, "This is list is void\n");
         exit(EXIT_FAILURE);
     } //The function initially checks if the head NULL, in which the function terminates with an error message
     
     List max=head;//Initialization of a variable to hold the max element each time
     do {
         if(head->value > max->value && head!=NULL) {
             max=head; //I make the appropriate comparison each time
         }
         head=head->next; //I move in to the next node of the list
     } while(head!=NULL); //Necessary prerequisite to execute the loop
 
     return max; //The index of the max is returned
 }