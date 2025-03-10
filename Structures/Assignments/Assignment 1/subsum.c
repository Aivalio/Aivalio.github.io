/*File:subsum.c*/
//Code author: Nikos Aivaliotis

#include <stdio.h>
#include <stdlib.h>

// Συνάρτηση για την έυρεση υποσυνόλου ενός συνόλου ακεραίων
int subsetSum(int *array, int value, int sum) {
    if (sum == 0) // Αν δε βρω κανένα υποσύνολο, επιστρέφω ως default τιμή το 0
        return 1;
    if (value == 0) // Αν εξέτασα όλα τα στοιχεία και πάλι δε βρήκα υποσύνολο
        return 0;

    // Δυναμική επιλογή: να συμπεριλάβω το τελευταίο στοιχείο ή όχι
    return subsetSum(array, value - 1, sum) || subsetSum(array, value - 1, sum - array[value - 1]);
}

// Κύρια συνάρτηση με παράδειγμα εκτέλεσης
int main(void) {
    
    int array[] = {-76, 90, 108, 45, 76, 87}; // Ορίζω έναν πίνακα ακεραίων και τον αρχικοποιώ
    int size = sizeof(array) / sizeof(array[0]);

    if (subsetSum(array, size, 0))
        printf("Υπάρχει υποσύνολο με άθροισμα 0\n");
    else
        fprintf(stderr, "Δεν υπάρχει υποσύνολο με άθροισμα 0\n");
        return 1; // Αν δε βρω υποσύνολο, το πράγραμμα τερματίζει με κδωικό εξόδου 1 και κατάλληλο μήνυμα λάθους

    return 0; // Επιτυχής τερματισμός προγράμματος
}
