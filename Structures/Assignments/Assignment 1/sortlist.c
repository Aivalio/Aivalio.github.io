/*File:sortlist.c*/
//Code author: Nikos Aivaliotis
#include <stdio.h>
#include <stdlib.h>

// Ορισμός του κόμβου της λίστας
typedef struct listnode {
    int value;
    struct listnode* next;
} *List;

// Συνάρτηση για εισαγωγή στοιχείου στην αρχή της λίστας
List insert(List head, int val) {
    List newNode = (List)malloc(sizeof(struct listnode));
    if (!newNode) {
        fprintf(stderr, "Αποτυχία δέσμευσης μνήμης\n");
        exit(1);
    }
    newNode->value = val;
    newNode->next = head;
    return newNode;
}

// Συνάρτηση εκτύπωσης λίστας
void printList(List head) {
    while (head) {
        printf("%d -> ", head->value);
        head = head->next;
    }
    printf("NULL\n");
}

// Ταξινόμηση λίστας με Insertion Sort
List sortList(List head) {
    if (!head || !head->next) return head; // Αν έχει 0 ή 1 στοιχείο, είναι ήδη ταξινομημένη

    List sorted = NULL;
    
    while (head) {
        List curr = head;
        head = head->next;

        if (!sorted || curr->value < sorted->value) { // Εισαγωγή στην αρχή
            curr->next = sorted;
            sorted = curr;
        } else { // Εισαγωγή στη σωστή θέση
            List temp = sorted;
            while (temp->next && temp->next->value < curr->value)
                temp = temp->next;
            curr->next = temp->next;
            temp->next = curr;
        }
    }
    return sorted;
}

// Συγχώνευση δύο ταξινομημένων λιστών
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

int main(void) {
    List list1 = NULL, list2 = NULL;

    // Δημιουργία δύο μη ταξινομημένων λιστών
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

    // Ταξινόμηση των δύο λιστών
    list1 = sortList(list1);
    list2 = sortList(list2);

    printf("Λίστα 1 (ταξινομημένη): ");
    printList(list1);
    
    printf("Λίστα 2 (ταξινομημένη): ");
    printList(list2);

    // Συγχώνευση ταξινομημένων λιστών
    List merged = mergeSortedLists(list1, list2);
    printf("Συγχωνευμένη ταξινομημένη λίστα: ");
    printList(merged);

    return 0;
}
