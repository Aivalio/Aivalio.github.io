#include <stdio.h>
#include "acutest.h"
#include "PQInterface.h"

void test_initialize_queue(void) {
    PriorityQueue pq = InitializeQueue();
    TEST_CHECK(pq != NULL);
    TEST_CHECK(Empty(pq) == 1);
}

void test_insert_and_remove(void) {
    PriorityQueue pq = InitializeQueue();
    TEST_CHECK(Empty(pq));
    
    Insert(5, pq);
    Insert(3, pq);
    Insert(8, pq);
    
    TEST_CHECK(!Empty(pq));
    TEST_CHECK(Remove(pq) == 8);
    TEST_CHECK(Remove(pq) == 5);
    TEST_CHECK(Remove(pq) == 3);
    TEST_CHECK(Empty(pq));
}

void test_full_queue(void) {
    PriorityQueue pq = InitializeQueue();
    
    for (int i = 0; i < MAXCOUNT; i++) {
        Insert(i, pq);
    }
    
    TEST_CHECK(Full(pq));
}

TEST_LIST = {
    {"Initialize Queue", test_initialize_queue},
    {"Insert and Remove", test_insert_and_remove},
    {"Full Queue", test_full_queue},
    {NULL, NULL} 
};