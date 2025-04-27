#ifndef LIST_H
#define LIST_H

#include "Point.h"

typedef struct listnode {
    Point *p;
    struct listnode *next;
} ListNode;

typedef struct list {
    ListNode *head;
} List;

List* list_init();
void list_add(List *list, Point *p);
void list_destroy(List *list);
void list_print(List *list); // για debugging

#endif
