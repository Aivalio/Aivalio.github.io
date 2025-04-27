/*This is the implementation file for the Point.h*/
#include <stdio.h>
#include <stdlib.h>
#include "Point.h"

// Initialization function
Point*init(double x, double y) {

    Point*t=(Point*)malloc(sizeof(Point)); // Memory allocation to create a new point
    if(t==NULL) {
        fprintf(stderr, "Memory exhaustion detected!Terminating...");
        exit(EXIT_FAILURE);
    }
    // The coordinates of the point
    t->x=x;
    t->y=y;

    return t; // Return the point
}

// X comparison
int point_compare_x(const void*a, const void*b) {
    
    // We use pointer to pointer for the qsort that will be used afterwards
    Point*t1=(Point**)a;
    Point*t2=(Point**)b;
    
    // The comparrisons
    if(t1->x == t2->x) return 0;
    else if(t1->x > t2->x) return 1;
    else return -1;
}

// Y omparison
int point_compare_y(const void*a, const void*b) {
    
    // We use pointer to pointer for the qsort that will be used afterwards
    Point*t1=(Point**)a;
    Point*t2=(Point**)b;
    
    // The comparrisons
    if(t1->y == t2->y) return 0;
    else if(t1->y > t2->y) return 1;
    else return -1;
}

