/*This is the list.h file*/
#ifndef LIST_H
#define LIST_H

typedef struct list List;
struct list {
    int data;
    List *next;
};

// Δηλώσεις συναρτήσεων
List *list_prepend(List *l, int data);
List *list_add_after_first(List *l, int data);
List *list_merge(List *l1, List *l2);
void list_free(List *l);
void list_print(List *l);
int list_size(List *l);
int list_get_data(List *l);
List *list_get_next(List *l);
List *list_first(List *l);
List *list_last(List *l);

#endif
