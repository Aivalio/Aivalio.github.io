/*File:client.c*/

// This is the client program, containing a main function to implement the infix-postfix procedure

#include <stdio.h>
#include "StackInterface.h"

int main(void) {

    char inf[100], postf[100]; // Two arrays for each fix
    
    printf("Please enter the infix to be evaluated: ");
    scanf("%100s", inf); // Prompt the user to enter the infix expression

    InfixToPostfix(inf, postf); // Transformation
    
    printf("Postfix Expression: %s\n", postf); // Printing of the postfix expression
    printf("Evaluated Result: %f\n", EvaluatePostfix(postf)); // Evaluation
    
    return 0; // Successful program termination
}