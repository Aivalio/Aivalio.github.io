/*This is the list.c file*/
#include <stdio.h>
#include <stdlib.h>
#include "list.h"

// Συνάρτηση που προσθέτει έναν νέο κόμβο στην αρχή της λίστας
List *list_prepend(List *l, int data) {
    List *new_node = (List *)malloc(sizeof(List));
    if (new_node == NULL) {
        fprintf(stderr, "Failed to allocate memory\n");
        return NULL;
    }

    new_node->data = data;
    new_node->next = l;
    return new_node;
}

// Συνάρτηση που προσθέτει έναν νέο κόμβο μετά τον πρώτο κόμβο
List *list_add_after_first(List *l, int data) {
    if (l == NULL) {
        fprintf(stderr, "Termination\n");
        return l;
    }

    List *new_node = (List *)malloc(sizeof(List));
    if (new_node == NULL) {
        fprintf(stderr, "Failed to allocate memory\n");
        return NULL;
    }

    new_node->data = data;
    new_node->next = l->next;
    l->next = new_node;

    return l;
}

// Συνάρτηση που ενώνει δύο λίστες
List *list_merge(List *l1, List *l2) {
    if (l1 == NULL) return l2;
    if (l2 == NULL) return l1;

    List *temp = l1;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = l2;
    return l1;
}

// Συνάρτηση για εκτύπωση της λίστας
void list_print(List *l) {
    List *cur = l;
    printf("[");
    while (cur != NULL) {
        if (cur->next != NULL) {
            printf("%d, ", cur->data);
        } else {
            printf("%d", cur->data);
        }
        cur = cur->next;
    }
    printf("]\n");
}

// Συνάρτηση για απελευθέρωση μνήμης της λίστας
void list_free(List *l) {
    List *cur = NULL;
    while (l != NULL) {
        cur = l->next;
        free(l);
        l = cur;
    }
}

// Συνάρτηση που επιστρέφει το μέγεθος της λίστας
int list_size(List *l) {
    int count = 0;
    List *cur = l;
    while (cur != NULL) {
        count++;
        cur = cur->next;
    }
    return count;
}

// Συνάρτηση που επιστρέφει τα δεδομένα του κόμβου
int list_get_data(List *l) {
    return l->data;
}

// Συνάρτηση που επιστρέφει τον επόμενο κόμβο
List *list_get_next(List *l) {
    return l->next;
}

// Συνάρτηση για τον πρώτο κόμβο
List *list_first(List *l) {
    return l;
}

// Συνάρτηση για τον τελευταίο κόμβο
List *list_last(List *l) {
    while (l != NULL && l->next != NULL) {
        l = l->next;
    }
    return l;
}
