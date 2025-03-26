/*File:sortlist.c*/
 //Code author: Nikos Aivaliotis
 #include <stdio.h>
 #include <stdlib.h>
 
 // Definition of a list node and a pointer to it
 typedef struct listnode {
     
     int value;
     struct listnode* next;
 } *List;

// Merging of two lists into a third one and return of a pointer to it
 List mergeSortedLists(List l1, List l2) {
     struct listnode dummy;
     List tail = &dummy;
     dummy.next = NULL;
 
     while (l1 && l2) {
         if (l1->value < l2->value) {
             tail->next = l1;
             l1 = l1->next;
         } else {
             tail->next = l2;
             l2 = l2->next;
         }
         tail = tail->next;
     }
     tail->next = l1 ? l1 : l2;
 
     return dummy.next;
 }
