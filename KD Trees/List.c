#include <stdlib.h>
#include <stdio.h>
#include "List.h"

List* list_init() {
    List *list = (List*)malloc(sizeof(List));
    list->head = NULL;
    return list;
}

void list_add(List *list, Point *p) {
    ListNode *node = (ListNode*)malloc(sizeof(ListNode));
    node->p = p;
    node->next = list->head;
    list->head = node;
}

void list_destroy(List *list) {
    ListNode *curr = list->head;
    while (curr) {
        ListNode *temp = curr;
        curr = curr->next;
        free(temp);
    }
    free(list);
}

void list_print(List *list) {
    ListNode *curr = list->head;
    while (curr) {
        printf("(%.2f, %.2f)\n", curr->p->x, curr->p->y);
        curr = curr->next;
    }
}
