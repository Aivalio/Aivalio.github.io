/*File:triangle.c*/
//Code author: Nikos Aivaliotis

#include <stdio.h>
#include <stdlib.h>

// Definition of struct Point
typedef struct point {
    int x;
    int y;
} Point;

// Definition of struct Triangle
typedef struct triangle {
    Point points[3];
} Triangle;

void point_print(Point p) 
{
    printf("(%d, %d)", p.x, p.y);
}

// Define a pointer to change the value of x
void point_move_horizontally(Point* p, int units) 
{
    p->x += units;
}

void triangle_print(Triangle* t) 
{
    for (int i = 0; i < 3; i++) { // Corrected loop
        point_print(t->points[i]);
        printf(" ");
    }
}

void triangle_move_horizontally(Triangle* t, int units) 
{
    for (int i = 0; i < 3; i++) { // Corrected loop
        t->points[i].x += units;
    }
}

int main(void)
{
    // Dynamic memory allocation 
    Point* a = malloc(sizeof(Point));
    if (a == NULL) {
        fprintf(stderr, "Memory allocation failed!\n");
        return 1;
    }
    
    a->x = 0;
    a->y = 0;

    point_print(*a);
    printf("\n");

    // Call with a pointer
    point_move_horizontally(a, 5);

    point_print(*a);
    printf("\n");

    free(a); // Memory deallocation

    // Dynamic memory allocation for Triangle
    Triangle* t = malloc(sizeof(Triangle));
    if (t == NULL) {
        fprintf(stderr, "Memory allocation failed!\n");
        return 1;
    }
    
    t->points[0].x = 0;
    t->points[0].y = 0;
    t->points[1].x = 1;
    t->points[1].y = 0;
    t->points[2].x = 0;
    t->points[2].y = 1;

    triangle_print(t);
    printf("\n");

    triangle_move_horizontally(t, 5);

    triangle_print(t);
    printf("\n");

    free(t); // Memory deallocation

    return 0; // Successful program termination
}
