/*File:sortlist.c*/
 //Code author: Nikos Aivaliotis
 #include <stdio.h>
 #include <stdlib.h>
 
 // Definition of a list node and a pointer to it
 typedef struct listnode {
     
     int value;
     struct listnode* next;
 } *List;
 
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
 
 // Fucntion to print a list
 void printList(List head) {
     
     while (head!=NULL) {
         printf("%d -> ", head->value);
         head = head->next;
     }
     printf("NULL\n");
 }
 
 // Fucntion to sort a list with Insertion Sort
 List sortList(List head) {
     
     if (head!=NULL || head->next!=NULL) {
         return head;
     }  // If the list has one or zero elements, then it is already sorted
 
     List sorted = NULL;
     
     while (head) {
         List current = head;
         head = head->next;
 
         if (!sorted || current->value < sorted->value) { // Insert in the beginning
             current->next = sorted;
             sorted = current;
         } else { // Insert in te proper position
             List temp = sorted;
             while (temp->next && temp->next->value < current->value)
                 temp = temp->next;
             current->next = temp->next;
             temp->next = current;
         }
     }
     return sorted;
 }
 

 int main(void) {
     
     List list1 = NULL, list2 = NULL;
 
     // I create two lists
     int a, b;
 
     printf("Please give me the size of the each list to be filled: ");
     scanf("%d %d", &a , &b);
 
     for(int i = 0; i < a; i++) {
         scanf("%d", &i);
         list1 = insert(list1, i);  // Update the head after each insertion
     }
 
     for(int i = 0; i < b; i++) {  // Changed loop condition to use 'b' for list2 size
         scanf("%d", &i);
         list2 = insert(list2, i);  // Update the head after each insertion
     }
 
     printf("List 1 (unsorted): ");
     printList(list1);
     
     printf("List 2 (unsorted): ");
     printList(list2);
 
     // Sorting
     list1 = sortList(list1);
     list2 = sortList(list2);
 
     printf("Λίστα 1 (ταξινομημένη): ");
     printList(list1);
     
     printf("Λίστα 2 (ταξινομημένη): ");
     printList(list2);
 
     // Merging
     List merged = mergeSortedLists(list1, list2);
     printf("Συγχωνευμένη ταξινομημένη λίστα: ");
     printList(merged);
 
     return 0; // Successful termination of the program
 }
