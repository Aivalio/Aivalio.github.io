#include "acutest.h"
#include "subsum.h" // Υποθέτοντας ότι η subsum.c έχει αντίστοιχο header file

void test_subsetSum() {
    int array1[] = {3, 34, 4, 12, 5, 2};
    int size1 = sizeof(array1) / sizeof(array1[0]);
    TEST_CHECK(subsetSum(array1, size1, 9) == 1); // Πρέπει να υπάρχει υποσύνολο με άθροισμα 9
    TEST_CHECK(subsetSum(array1, size1, 30) == 0); // Δεν πρέπει να υπάρχει υποσύνολο με άθροισμα 30

    int array2[] = {-76, 90, 108, 45, 76, 87};
    int size2 = sizeof(array2) / sizeof(array2[0]);
    TEST_CHECK(subsetSum(array2, size2, 0) == 1); // Υπάρχει υποσύνολο με άθροισμα 0 (το κενό σύνολο)
}

TEST_LIST = {
    {"test_subsetSum", test_subsetSum},
    {NULL, NULL}
};
