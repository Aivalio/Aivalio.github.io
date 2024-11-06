#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

// Ορισμός ελάχιστου και μέγιστου κόστους
#define MIN_COST -1000000000000000000LL
#define MAX_COST 1000000000000000000LL

// Συνάρτηση για έλεγχο εγκυρότητας του κόστους
int is_valid_cost(long long cost) {
    return cost >= MIN_COST && cost <= MAX_COST;
}

int main() {
    long long left_cost, right_cost;
    int trolley_result;

    while (1) {
        // Λήψη κόστους για αριστερά
        printf("Please enter the cost of going left: ");
        trolley_result = scanf("%lld", &left_cost);

        // Έλεγχος για αποτυχία ανάγνωσης
        if (trolley_result == EOF || trolley_result != 1) {
            printf("Terminating.\n");
            return 0; 
        }

        // Έλεγχος εγκυρότητας
        if (!is_valid_cost(left_cost)) {
            printf("Invalid input for left cost. Enter again.\n");
            while (getchar() != '\n'); // Καθαρισμός του buffer
            continue;
        }

        // Λήψη κόστους για δεξιά
        printf("Please enter the cost of going right: ");
        trolley_result = scanf("%lld", &right_cost);

        // Έλεγχος για αποτυχία ανάγνωσης
        if (trolley_result == EOF || trolley_result != 1) {
            printf("No right cost provided.\n");
            return 1; 
        }

        // Έλεγχος εγκυρότητας
        if (!is_valid_cost(right_cost)) {
            printf("Invalid input for right cost. Enter again.\n");
            while (getchar() != '\n'); // Καθαρισμός του buffer
            continue;
        }

        // Απόφαση για το που θα πάει το τρολλέι
        if (left_cost > right_cost) {
            printf("Go left.\n");
        } else if (left_cost < right_cost) {
            printf("Go right.\n");
        } else {
            printf("Go left.\n");  // Αν είναι ίδια τα κόστη, προτιμάμε το αριστερό
        }
    }

    return 0;
}
