#include <stdio.h>
#include <string.h> // Για την strcpy, strlen, strcmp, strcat, strtok

// Δηλώσεις συναρτήσεων
int mystrlen(char *str);
char *mystrcat(char *s1, char *s2);
void strtok_example(void);

int main() {
    // Δημιουργία των δύο συμβολοσειρών
    char strA[80];
    char strB[80];

    // Αντιγραφή συμβολοσειρών
    strcpy(strA, "This is a string.");
    strcpy(strB, "This is another string.");

    // Εκτύπωση των συμβολοσειρών και του μήκους τους
    printf("strA: %s\n", strA);
    printf("Μήκος strA (με mystrlen): %d\n", mystrlen(strA));
    printf("strB: %s\n", strB);
    printf("Μήκος strB (με strlen): %zu\n", strlen(strB));

    // Σύγκριση των δύο συμβολοσειρών
    int cmp_result = strcmp(strA, strB);
    if (cmp_result == 0) {
        printf("Οι συμβολοσειρές είναι ίδιες.\n");
    } else if (cmp_result > 0) {
        printf("Η strA είναι μεγαλύτερη από τη strB.\n");
    } else {
        printf("Η strA είναι μικρότερη από τη strB.\n");
    }

    // Προσάρτηση strB στην strA
    mystrcat(strA, strB);
    printf("Νέα τιμή strA μετά την προσάρτηση strB: %s\n", strA);

    // Προσάρτηση strA στην strB
    strcat(strB, strA);
    printf("Νέα τιμή strB μετά την προσάρτηση strA: %s\n", strB);

    // Χρήση της strtok για να εκτυπώσουμε τις λέξεις από την strB
    strtok_example();

    return 0;
}

void strtok_example() {
    char str[] = "Little by little, one Little travels far.";
    char *p = strtok(str, " ,.");
    
    while (p != NULL) {
        printf("%s\n", p);
        p = strtok(NULL, " ,.");
    }
}
