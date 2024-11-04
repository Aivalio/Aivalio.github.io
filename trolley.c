/*File: trolley.c */
#include <stdio.h>
#include <stdlib.h>
//This program offers a solution written in C language for the trolley problem

int main(void) {
    long long left_trolley_cost, right_trolley_cost;

    while (1) {
        printf("Please enter the cost of going left: ");
        if (scanf("%lld", &left_trolley_cost) != 1) {
            printf("No valid input or EOF tracked. Logging out now...\n");
            break ;
        }

        printf("Enter the cost of turning right: ");
        if (scanf("%lld", &right_trolley_cost) != 1) {
            printf("No valid input or EOF tracked. Logging out now...\n");
            break;
        }

        if (left_trolley_cost < right_trolley_cost) {
            printf("Go left.\n");
        } else if(left_trolley_cost > right_trolley_cost) {
            printf("Go right.\n");
        }   else {
             printf("Go left.\n");
        }
    
    }

    return 0;
}
