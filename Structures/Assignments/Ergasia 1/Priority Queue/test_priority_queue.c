#include <stdio.h>
#include <assert.h>
#include "PQInterface.h"

void test_InitializeQueue() {
    PriorityQueue PQ = InitializeQueue();
    assert(PQ != NULL); // Έλεγχος ότι η ουρά δημιουργήθηκε σωστά
    assert(Empty(PQ) == 1); // Η ουρά πρέπει να είναι κενή αρχικά
    printf("test_InitializeQueue passed\n");
}

void test_Insert() {
    PriorityQueue PQ = InitializeQueue();
    Insert(10, PQ);
    assert(Empty(PQ) == 0); // Η ουρά δεν πρέπει να είναι κενή μετά την εισαγωγή
    assert(Remove(PQ) == 10); // Το πρώτο στοιχείο που βγαίνει πρέπει να είναι 10
    printf("test_Insert passed\n");
}

void test_Remove() {
    PriorityQueue PQ = InitializeQueue();
    Insert(20, PQ);
    Insert(30, PQ);
    Insert(10, PQ);

    assert(Remove(PQ) == 30); // Η ουρά πρέπει να επιστρέψει το μεγαλύτερο στοιχείο
    assert(Remove(PQ) == 20); // Ακολουθεί το 20
    assert(Remove(PQ) == 10); // Ακολουθεί το 10
    assert(Empty(PQ) == 1); // Η ουρά πρέπει να είναι κενή μετά τη διαγραφή όλων των στοιχείων
    printf("test_Remove passed\n");
}

void test_Full() {
    PriorityQueue PQ = InitializeQueue();
    for (int i = 0; i < MAXCOUNT; i++) {
        Insert(i, PQ);
    }
    assert(Full(PQ) == 1); // Η ουρά πρέπει να είναι γεμάτη
    printf("test_Full passed\n");
}

void test_Empty() {
    PriorityQueue PQ = InitializeQueue();
    assert(Empty(PQ) == 1); // Η ουρά πρέπει να είναι κενή αρχικά
    Insert(5, PQ);
    assert(Empty(PQ) == 0); // Μετά την εισαγωγή, η ουρά δεν πρέπει να είναι κενή
    Remove(PQ);
    assert(Empty(PQ) == 1); // Αφού αφαιρεθεί το στοιχείο, η ουρά πρέπει να είναι κενή
    printf("test_Empty passed\n");
}

int main() {
    test_InitializeQueue();
    test_Insert();
    test_Remove();
    test_Full();
    test_Empty();

    printf("All tests passed!\n");
    return 0;
}
