#include <stdio.h>
#include <assert.h>
#include "list.h"

void test_list_prepend() {
    List *list = NULL;
    list = list_prepend(list, 10);
    assert(list_size(list) == 1);
    assert(list_get_data(list) == 10);
    printf("[OK] test_list_prepend passed\n");
}

void test_list_add_after_first() {
    List *list = NULL;
    list = list_prepend(list, 10);
    list = list_add_after_first(list, 20);
    assert(list_size(list) == 2);
    assert(list_get_data(list->next) == 20);
    printf("[OK] test_list_add_after_first passed\n");
}

void test_list_merge() {
    List *list1 = NULL, *list2 = NULL;
    list1 = list_prepend(list1, 10);
    list2 = list_prepend(list2, 20);
    list1 = list_merge(list1, list2);
    assert(list_size(list1) == 2);
    assert(list_get_data(list1->next) == 20);
    printf("[OK] test_list_merge passed\n");
}

int main() {
    test_list_prepend();
    test_list_add_after_first();
    test_list_merge();
    return 0;
}
