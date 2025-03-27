/*File:sortlist.c*/
 //Code author: Nikos Aivaliotis
#include <stdio.h>
#include <stdlib.h>

// Definition of the linked list node
typedef struct ListNode {
    int value;
    struct ListNode *next;
} List;

// Function to merge two sorted linked lists into one sorted list
List* list_merge(List *l1, List *l2) {
    // Create a dummy node to simplify the merging process
    List dummy;
    List *tail = &dummy;  // Pointer to the last element of the new list
    dummy.next = NULL;

    // While both lists have elements
    while (l1 && l2) {
        if (l1->value < l2->value) {
            tail->next = l1;  // Add the current node from l1
            l1 = l1->next;    // Move to the next node in l1
        } else {
            tail->next = l2;  // Add the current node from l2
            l2 = l2->next;    // Move to the next node in l2
        }
        tail = tail->next;  // Move the tail pointer to the last node
    }

    // If there are remaining elements in one list, append them
    tail->next = l1 ? l1 : l2;

    // Return the merged list starting from the first node after dummy
    return dummy.next;
}

// Function to create a new node
List* create_node(int value) {
    List* new_node = (List*)malloc(sizeof(List));
    new_node->value = value;
    new_node->next = NULL;
    return new_node;
}

// Function to print a linked list
void print_list(List *head) {
    while (head) {
        printf("%d -> ", head->value);
        head = head->next;
    }
    printf("NULL\n");
}

// Main function to test list_merge
int main(void) {
    // Creating first sorted linked list: 1 -> 3 -> 5
    List *l1 = create_node(1);
    l1->next = create_node(3);
    l1->next->next = create_node(5);

    // Creating second sorted linked list: 2 -> 4 -> 6
    List *l2 = create_node(2);
    l2->next = create_node(4);
    l2->next->next = create_node(6);

    // Print the original lists
    printf("List 1: ");
    print_list(l1);
    printf("List 2: ");
    print_list(l2);

    // Merge the lists
    List *merged_list = list_merge(l1, l2);

    // Print the merged list
    printf("Merged List: ");
    print_list(merged_list);

    return 0;
}
