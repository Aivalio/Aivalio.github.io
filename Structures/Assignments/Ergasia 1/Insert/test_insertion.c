/* Unit Test for insertion.c */
#include "acutest.h"
#include <stdlib.h>

void test_insert_front() {
    List head = NULL;
    insert_front(&head, 10);
    insert_front(&head, 20);
    insert_front(&head, 30);
    
    TEST_CHECK(head != NULL);
    TEST_CHECK(head->value == 30);
    TEST_CHECK(head->next->value == 20);
    TEST_CHECK(head->next->next->value == 10);
    
    // Free allocated memory
    while (head) {
        List temp = head;
        head = head->next;
        free(temp);
    }
}

void test_mysortlist() {
    List head = NULL;
    insert_front(&head, 10);
    insert_front(&head, 5);
    insert_front(&head, 20);
    insert_front(&head, 15);
    
    head = mysortlist(head);
    
    TEST_CHECK(head != NULL);
    TEST_CHECK(head->value == 5);
    TEST_CHECK(head->next->value == 10);
    TEST_CHECK(head->next->next->value == 15);
    TEST_CHECK(head->next->next->next->value == 20);
    TEST_CHECK(head->next->next->next->next == NULL);
    
    // Free allocated memory
    while (head) {
        List temp = head;
        head = head->next;
        free(temp);
    }
}

TEST_LIST = {
    {"test_insert_front", test_insert_front},
    {"test_mysortlist", test_mysortlist},
    {NULL, NULL}
};
