/*File:ladder.c*/
#include <stdio.h>

unsigned long long ladder(int n) {
    // Αν έχουμε λιγότερα από 1 σκαλιά, το μόνο που μπορούμε να κάνουμε είναι να μην κάνουμε τίποτα
    if (n == 0) return 1;
    
    // Αν έχουμε 1 ή 2 σκαλιά, οι λύσεις είναι εύκολες
    if (n == 1) return 1;
    if (n == 2) return 2;

    // Χρησιμοποιούμε μόνο δύο μεταβλητές για να αποθηκεύσουμε τις τελευταίες τιμές
    unsigned long long a = 1, b = 1, c = 2, result;

    // Υπολογίζουμε τις τιμές για τα υπόλοιπα σκαλοπάτια
    for (int i = 3; i <= n; i++) {
        result = a + b + c;
        a = b;  // Ενημερώνουμε τις τιμές για την επόμενη επανάληψη
        b = c;
        c = result;
    }

    // Επιστρέφουμε το αποτέλεσμα για το n
    return result;
}

int main() {
    int steps;
    printf("Please provide the number of steps: ");
    scanf("%d", &steps);
    
    unsigned long long result = ladder(steps);
    printf("There are %llu different ways to climb the ladder\n", result);
    
    return 0;
}
