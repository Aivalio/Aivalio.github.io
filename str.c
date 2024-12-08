#include <stdio.h>

char *mystrcat(char *s1, char *s2) {
    int i = 0, j = 0;

    // Βρίσκουμε το τέλος της s1
    while (s1[i] != '\0') {
        i++;
    }

    // Προσθέτουμε τους χαρακτήρες της s2 στην s1
    while (s2[j] != '\0') {
        s1[i] = s2[j];
        i++;
        j++;
    }

    // Τερματισμός της συμβολοσειράς s1 με '\0'
    s1[i] = '\0';

    return s1;
}
