#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MIN_COST -1000000000000000000LL
#define MAX_COST 1000000000000000000LL

// Function to check if the input cost is valid (within the predefined range)
int is_valid_cost(long long cost) {
    return cost >= MIN_COST && cost <= MAX_COST;
}

// Function to clear the input buffer (handles tabs, spaces, and newlines)
void clear_input_buffer() {
    while (getchar() != '\n'); // Clear the input buffer until a newline is encountered
}

// Function to read a long long value and validate its correctness
int read_cost(long long* cost) {
    int trolley_result;
    while (1) {
        trolley_result = scanf("%lld", cost);
        if (trolley_result == EOF) {
            printf("Terminating.\n");
            return 0;  // Return 0 to indicate program termination
        }
        if (trolley_result == 1 && is_valid_cost(*cost)) {
            return 1;  // Valid input, return success
        }
        printf("Invalid input. Please enter a valid cost: ");
        clear_input_buffer();  // Clear any remaining input (like spaces, tabs, etc.)
    }
}

int main() {
    long long left_cost, right_cost;
    int trolley_result;

    while (1) {
        printf("Please enter the cost of going left: ");
        trolley_result = read_cost(&left_cost);
        if (trolley_result == 0) return 0;  // If EOF encountered, terminate the program

        printf("Please enter the cost of going right: ");
        trolley_result = read_cost(&right_cost);
        if (trolley_result == 0) return 0;  // If EOF encountered, terminate the program

        // Decision based on the costs
        if (left_cost > right_cost) {
            printf("Go left.\n");
        } else if (left_cost < right_cost) {
            printf("Go right.\n");
        } else {
            printf("Go left.\n");  // If costs are equal, we default to going left
        }

        break;  // Exit the loop after one round of inputs
    }

    return 0;
}
