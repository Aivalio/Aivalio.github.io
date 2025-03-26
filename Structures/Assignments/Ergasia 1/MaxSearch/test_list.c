/*This is the test_list.c*/
#include "acutest.h"
#include <stdlib.h>


void test_maxsearch() {
    List head = (List)malloc(sizeof(struct listnode));
    List second = (List)malloc(sizeof(struct listnode));
    List third = (List)malloc(sizeof(struct listnode));
    
    if (!head || !second || !third) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    
    head->value = 10;
    head->next = second;
    
    second->value = 25;
    second->next = third;
    
    third->value = 15;
    third->next = NULL;
    
    TEST_CHECK(maxsearch(head) == second);
    
    free(third);
    free(second);
    free(head);
}

TEST_LIST = {
    {"test_maxsearch", test_maxsearch},
    {NULL, NULL}
};