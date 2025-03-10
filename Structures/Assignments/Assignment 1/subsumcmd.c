/* File: subsum.c */
// Code author: Nikos Aivaliotis (modified for readability)

#include <stdio.h>
#include <stdlib.h>

// Αναδρομική συνάρτηση για τον έλεγχο ύπαρξης μη κενού υποσυνόλου με άθροισμα 0
int hasZeroSubsetSum(int *numbers, int size, int sum, int count) {
    if (sum == 0 && count > 0) // Αν βρήκαμε μη κενό υποσύνολο με άθροισμα 0
        return 1;
    if (size == 0) // Αν εξαντλήσαμε τα στοιχεία χωρίς επιτυχία
        return 0;

    // Δοκιμάζουμε είτε να αγνοήσουμε είτε να συμπεριλάβουμε το τελευταίο στοιχείο
    int exclude = hasZeroSubsetSum(numbers, size - 1, sum, count);
    int include = hasZeroSubsetSum(numbers, size - 1, sum - numbers[size - 1], count + 1);

    return exclude || include;
}

int main(void) {
    int size;
    int *numbers;

    // Ζητάμε από τον χρήστη το μέγεθος του πίνακα
    printf("Δώστε τον αριθμό των στοιχείων: ");
    scanf("%d", &size);

    if (size <= 0) {
        printf("Μη έγκυρος αριθμός στοιχείων.\n");
        return 1;
    }

    // Δέσμευση μνήμης για τον πίνακα ακεραίων
    numbers = (int *)malloc(size * sizeof(int));
    if (numbers == NULL) {
        printf("Σφάλμα: Αποτυχία δέσμευσης μνήμης!\n");
        return 1;
    }

    // Εισαγωγή στοιχείων από τον χρήστη
    printf("Εισάγετε %d ακέραιους αριθμούς:\n", size);
    for (int i = 0; i < size; i++) {
        scanf("%d", &numbers[i]);
    }

    // Εκτέλεση ελέγχου για ύπαρξη υποσυνόλου με άθροισμα 0
    printf("Εκτελείται ο έλεγχος υποσυνόλου...\n");
    int found = hasZeroSubsetSum(numbers, size, 0, 0);

    // Εμφάνιση αποτελέσματος
    if (found)
        printf("Υπάρχει τουλάχιστον ένα υποσύνολο με άθροισμα 0!\n");
    else
        printf("Δεν βρέθηκε υποσύνολο με άθροισμα 0.\n");

    // Αποδέσμευση μνήμης
    free(numbers);
    return 0; // Επιτυχής έξοδος
}
