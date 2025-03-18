/*File:main.c*/
#include <stdio.h>
#include <stdlib.h>
#include "list.h"

// Κύρια συνάρτηση για δοκιμές
int main(void) {
    
    List *list1 = NULL;
    
    list1 = list_prepend(list1, 3);
    list1 = list_prepend(list1, 2);
    list1 = list_prepend(list1, 1);
    
    print_list(list1);
    
    list1 = list_add_after_first(list1, 4);
    print_list(list1);
    
    List *list2 = NULL;
    list2 = list_prepend(list2, 6);
    list2 = list_prepend(list2, 5);
    print_list(list2);
    
    list1 = list_merge(list1, list2);
    print_list(list1);
    
    list1 = list_append(list1, 7);
    print_list(list1);
    
    list1 = list_remove_first(list1);
    print_list(list1);
    
    list1 = list_remove_last(list1);
    print_list(list1);
    
    free_list(list1);
    return 0;
}
