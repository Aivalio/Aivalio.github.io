/*File:main.c*/
#include <stdio.h>
#include <stdlib.h>
#include "list.h"

int main(void) {
    List *list1 = NULL;

    // Προσθέτουμε στοιχεία στη λίστα
    list1 = list_prepend(list1, 3);
    list1 = list_prepend(list1, 2);
    list1 = list_prepend(list1, 1);

    // Εκτυπώνουμε τη λίστα
    printf("List 1: ");
    list_print(list1);

    // Προσθέτουμε νέο κόμβο μετά τον πρώτο
    list1 = list_add_after_first(list1, 4);
    printf("After adding after the first: ");
    list_print(list1);

    // Δημιουργούμε και άλλη λίστα
    List *list2 = NULL;
    list2 = list_prepend(list2, 6);
    list2 = list_prepend(list2, 5);

    // Εκτυπώνουμε τη δεύτερη λίστα
    printf("List 2: ");
    list_print(list2);

    // Ενώνουμε τις δύο λίστες
    list1 = list_merge(list1, list2);
    printf("Merged List: ");
    list_print(list1);

    // Απελευθερώνουμε τη μνήμη
    list_free(list1);
    return 0;
}

