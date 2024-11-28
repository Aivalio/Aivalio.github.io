/*File:ladder.c*/
#include <stdio.h>

unsigned long long ladder(int n) {
    // Αν έχουμε λιγότερα από 1 σκαλιά, το μόνο που μπορούμε να κάνουμε είναι να μην κάνουμε τίποτα
    if (n == 0) return 1;
    
    // Αν έχουμε 1 ή 2 σκαλιά, οι λύσεις είναι εύκολες
    if (n == 1) return 1;
    if (n == 2) return 2;

    // Δημιουργούμε πίνακα για δυναμικό προγραμματισμό
    unsigned long long dp[n + 1];
    
    // Θέτουμε τις βάσεις
    dp[0] = 1; // 1 τρόπος για να ανέβουμε 0 σκαλιά (να μην κάνουμε τίποτα)
    dp[1] = 1; // 1 τρόπος για να ανέβουμε 1 σκαλί
    dp[2] = 2; // 2 τρόποι για να ανέβουμε 2 σκαλιά (1-1 ή 2)
    
    // Υπολογίζουμε τις υπόλοιπες τιμές για dp[3] και παρακάτω
    for (int i = 3; i <= n; i++) {
        dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
    }
    
    // Η απάντηση βρίσκεται στο dp[n]
    return dp[n];
}

int main() {
    int steps;
    printf("Please provide the number of steps: ");
    scanf("%d", &steps);
    
    unsigned long long result = ladder(steps);
    printf("There are %llu different ways to climb the ladder\n", result);
    
    return 0;
}
