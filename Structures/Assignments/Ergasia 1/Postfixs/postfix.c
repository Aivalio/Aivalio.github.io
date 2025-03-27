/*This is the postfix.c file*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "StackInterface.h"

#define MAX_EXPR_SIZE 100

int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

void infixToPostfix(char* infix, char* postfix) {
    
    Stack operators;
    Initialize(&operators);
    int j = 0;

    for (int i = 0; infix[i] != '\0'; i++) {
        if (isdigit(infix[i])) {
            postfix[j++] = infix[i];
        } else if (infix[i] == '(') {
            Push(infix[i], &operators);
        } else if (infix[i] == ')') {
            while (!Empty(&operators)) {
                char topOp;
                Pop(&operators, &topOp);
                if (topOp == '(') break;
                postfix[j++] = topOp;
            }
        } else { 
            while (!Empty(&operators)) {
                char topOp;
                Pop(&operators, &topOp);
                if (precedence(topOp) < precedence(infix[i])) {
                    Push(topOp, &operators);
                    break;
                }
                postfix[j++] = topOp;
            }
            Push(infix[i], &operators);
        }
    }

    while (!Empty(&operators)) {
        char topOp;
        Pop(&operators, &topOp);
        postfix[j++] = topOp;
    }
    postfix[j] = '\0';
}

float evaluatePostfix(char* postfix) {
    Stack values;
    Initialize(&values);
    
    for (int i = 0; postfix[i] != '\0'; i++) {
        if (isdigit(postfix[i])) {
            Push(postfix[i] - '0', &values);
        } else {
            float val1, val2;
            Pop(&values, &val2);
            Pop(&values, &val1);
            
            switch (postfix[i]) {
                case '+': Push(val1 + val2, &values); break;
                case '-': Push(val1 - val2, &values); break;
                case '*': Push(val1 * val2, &values); break;
                case '/': Push(val1 / val2, &values); break;
            }
        }
    }
    float result;
    Pop(&values, &result);
    return result;
}