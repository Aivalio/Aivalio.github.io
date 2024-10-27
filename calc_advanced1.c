/* File: calc_advanced1.c */
#include <stdio.h>
int main() {
long long int in1, in2, sum;

printf("Εισάγετε έναν ακέραιο αριθμό:");
scanf("%lld, &in1");

printf("Εισάγετε ένα δεύτερο ακέραιο αριθμό:");
scanf("%lld , &in2");

sum= in1 + in2;
 printf("Η πρόσθεσξ δίνει: %lld\n" , sum);

return 0;
}
