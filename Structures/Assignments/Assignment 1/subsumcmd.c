/* File: subsum.c */
// Code author: Nikos Aivaliotis

#include <stdio.h>
#include <stdlib.h>

// Αναδρομική συνάρτηση για τον έλεγχο ύπαρξης μη κενού υποσυνόλου με άθροισμα 0
int subsetSum(int *array, int n, int sum, int count) {
    if (sum == 0 && count > 0) // Βρήκαμε υποσύνολο με άθροισμα 0 (μη κενό)
        return 1;
    if (n == 0) // Αν εξαντλήσαμε τα στοιχεία και δεν βρήκαμε λύση
        return 0;

    // Εξετάζουμε δύο περιπτώσεις: να συμπεριλάβουμε ή να αγνοήσουμε το τελευταίο στοιχείο
    return subsetSum(array, n - 1, sum, count) || subsetSum(array, n - 1, sum - array[n - 1], count + 1);
}

int main(void) {
    int terms;
    int *array;

    // Ζητάμε από τον χρήστη το μέγεθος του πίνακα
    printf("Δώστε τον αριθμό των στοιχείων: ");
    scanf("%d", &terms);

    if (terms <= 0) {
        fprintf(stderr, "Μη έγκυρος αριθμός στοιχείων.\n");
        return 1;
    }

    // Δέσμευση μνήμης για τον πίνακα ακεραίων
    array = (int *)malloc(terms * sizeof(int));
    if (array == NULL) {
        fprintf(stderr, "Αποτυχία δέσμευσης μνήμης\n");
        return 1;
    }

    // Εισαγωγή στοιχείων από τον χρήστη
    printf("Εισάγετε %d ακέραιους αριθμούς:\n", terms);
    for (int i = 0; i < terms; i++) {
        scanf("%d", &array[i]);
    }

    // Κλήση της αναδρομικής συνάρτησης
    if (subsetSum(array, terms, 0, 0))
        printf("Υπάρχει υποσύνολο με άθροισμα 0\n");
    else
        printf("Δεν υπάρχει υποσύνολο με άθροισμα 0\n");

    // Αποδέσμευση μνήμης
    free(array);
    return 0; // Επιτυχής τερματισμός προγράμματος
}
