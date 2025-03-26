/*This is the test_list.c file*/
#include "DLLInterface.h"
#include "acutest.h"
#include <stdlib.h>

void test_create() {
    
    DoubleLink* list = Create();
    
    TEST_CHECK(list != NULL);
    TEST_CHECK(list->Head == NULL);
    TEST_CHECK(list->Tail == NULL);
    
    free(list);
}

void test_add_first() {
    
    DoubleLink* list = Create();
    
    AddFirst(list, 25);
    
    TEST_CHECK(list->Head != NULL);
    TEST_CHECK(list->Head->value == 25);
    TEST_CHECK(list->Tail == list->Head);
    
    free(list->Head);
    free(list);
}

void test_add_last() {
    
    DoubleLink* list = Create();
    
    AddLast(list, 35);
    
    TEST_CHECK(list->Tail != NULL);
    TEST_CHECK(list->Tail->value == 35);
    TEST_CHECK(list->Head == list->Tail);
    
    free(list->Tail);
    free(list);
}

void test_remove() {
    
    DoubleLink* list = Create();
    
    AddFirst(list, 10);
    AddFirst(list, 30);
    
    Remove(list, 10);
    
    TEST_CHECK(list->Head != NULL);
    TEST_CHECK(list->Head->value == 30);
    
    free(list->Head);
    free(list);
}

void test_get_first() {
    
    DoubleLink* list = Create();
    
    AddFirst(list, 40);
    
    TEST_CHECK(GetFirst(list) == 40);
    free(list->Head);
    free(list);
}

void test_get_last() {
    
    DoubleLink* list = Create();
    
    AddLast(list, 40);
    
    TEST_CHECK(GetLast(list) == 40);
    free(list->Tail);
    free(list);
}

void test_size() {
    
    DoubleLink* list = Create();
    
    TEST_CHECK(Size(list) == 0);
    AddFirst(list, 50);
    TEST_CHECK(Size(list) == 1);
    AddLast(list, 60);
    TEST_CHECK(Size(list) == 2);
    free(list->Head->next);
    free(list->Head);
    free(list);
}

TEST_LIST = {
    {"test_create", test_create},
    {"test_add_first", test_add_first},
    {"test_add_last", test_add_last},
    {"test_remove", test_remove},
    {"test_get_first", test_get_first},
    {"test_get_last", test_get_last},
    {"test_size", test_size},
    {NULL, NULL}
};
