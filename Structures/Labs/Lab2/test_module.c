#include <stdlib.h>
#include <limits.h>
#include "list.h"
#include "acutest/acutest.h"

// Υλοποίηση του test για τη συνάρτηση list_prepend
void test_list_prepend(){
    List *l = NULL;
    
    // Προσθέτουμε το 10 στην αρχή της λίστας
    l = list_prepend(l, 10);
    
    // Ελέγχουμε ότι το πρώτο στοιχείο είναι το 10
    TEST_CHECK(list_size(l) == 1 && list_get_data(list_first(l)) == 10);
    
    // Προσθέτουμε το 5 στην αρχή της λίστας
    l = list_prepend(l, 5);
    
    // Ελέγχουμε ότι το πρώτο στοιχείο είναι το 5 και το μέγεθος της λίστας είναι 2
    TEST_CHECK(list_size(l) == 2 && list_get_data(list_first(l)) == 5);
    
    list_free(l);
}

// Υλοποίηση του test για τη συνάρτηση list_add_after_first
void test_list_add_after_first(){
    List *l = NULL;
    
    // Δημιουργούμε μια λίστα με δύο στοιχεία
    l = list_push(l, 10);  // Προσθέτουμε το 10 στην αρχή
    l = list_push(l, 5);   // Προσθέτουμε το 5 στην αρχή
    
    // Προσθέτουμε το 7 μετά το πρώτο κόμβο (μετά το 10)
    l = list_add_after_first(l, 7);
    
    // Ελέγχουμε ότι το μέγεθος της λίστας είναι 3 και το στοιχείο μετά το πρώτο κόμβο είναι το 7
    TEST_CHECK(list_size(l) == 3 && list_get_data(list_get_next(list_first(l))) == 7);
    
    list_free(l);
}

// Υλοποίηση του test για τη συνάρτηση list_merge
void test_list_merge(){
    List *l1 = NULL, *l2 = NULL;
    
    // Δημιουργούμε δύο λίστες
    l1 = list_push(l1, 10);
    l1 = list_push(l1, 5);
    
    l2 = list_push(l2, 20);
    
    // Συγχωνεύουμε τις δύο λίστες
    l1 = list_merge(l1, l2);
    
    // Ελέγχουμε ότι η νέα λίστα έχει σωστά στοιχεία και το τελευταίο στοιχείο είναι το 20
    TEST_CHECK(list_size(l1) == 3 && list_get_data(list_last(l1)) == 20);
    
    list_free(l1);
}

TEST_LIST = {
    { "test_list_prepend", test_list_prepend },
    { "test_list_add_after_first", test_list_add_after_first },
    { "test_list_merge", test_list_merge },
    { NULL, NULL }  /* Zeroed record marking the end of the list */
};
