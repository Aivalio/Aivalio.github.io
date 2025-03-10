#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    // Ελέγχουμε αν έχουμε επαρκή ορίσματα (τουλάχιστον 4, 1 για το goal και τουλάχιστον 3 για τους υποψηφίους)
    if (argc < 5) {
        printf("Not enough candidates\n");
        return 1;
    }

    // Ο στόχος που πρέπει να πετύχουμε
    long long goal = atoll(argv[1]);

    // Αποθήκευση των υποψηφίων
    int candidates[argc - 2];
    for (int i = 2; i < argc; i++) {
        candidates[i - 2] = atoi(argv[i]);
    }

    // Εξετάζουμε όλους τους δυνατούς συνδυασμούς 3 υποψηφίων
    int found = 0; // Σημαία για να δούμε αν βρέθηκαν συνδυασμοί
    for (int i = 0; i < argc - 2; i++) {
        for (int j = i + 1; j < argc - 2; j++) {
            for (int k = j + 1; k < argc - 2; k++) {
                long long sum = candidates[i] + candidates[j] + candidates[k];
                if (sum == goal) {
                    printf("Candidates combination found: %d + %d + %d = %lld\n", 
                            candidates[i], candidates[j], candidates[k], sum);
                    found = 1;
                }
            }
        }
    }

    // Αν δεν βρεθεί κανένας συνδυασμός
    if (!found) {
        printf("No combination of candidates leads to %lld\n", goal);
    }

    return 0;
}
