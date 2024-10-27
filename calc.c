/* File: calc.c */
#include <stdio.h>

int main() {
    int in1, in2, sum;

   
    printf("Εισάγετε έναν ακέραιο: ");
    scanf("%d", &in1);
    
    printf("Εισάγετε έναν δεύτερο ακέραιο: ");
    scanf("%d", &in2);
    
    
    sum = in1 + in2;

    
    printf("Το αποτέλεσμα της πρόσθεσης είναι: %d\n", sum);

    return 0;
}

