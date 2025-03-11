/* File: triangle.c */
// Code author: Nikos Aivaliotis

#include <stdio.h>
#include <stdlib.h>

// Δομή για ένα σημείο με δύο συντεταγμένες (x, y)
typedef struct point {
    int x;
    int y;
} Point;

// Δομή τριγώνου που αποτελείται από τρία σημεία
typedef struct triangle {
    Point points[3];
} Triangle;

// Συνάρτηση για εκτύπωση σημείου
void point_print(Point p) 
{
    printf("(%d, %d)", p.x, p.y);
}

// Συνάρτηση που μετακινεί ένα σημείο οριζόντια
void point_move_horizontally(Point* p, int units) 
{
    if (p != NULL) {
        p->x += units;
    }
}

// Συνάρτηση για εκτύπωση τριγώνου
void triangle_print(Triangle* t) 
{
    if (t == NULL) return;
    for (int i = 0; i < 3; i++) { 
        point_print(t->points[i]);
    }
    printf("\n"); // Για καλύτερη μορφοποίηση
}

// Συνάρτηση που μετακινεί οριζόντια ένα τρίγωνο
void triangle_move_horizontally(Triangle* t, int units) 
{
    if (t == NULL) return;
    for (int i = 0; i < 3; i++) { 
        t->points[i].x += units;
    }
}

int main(void)
{
    // Δυναμική δημιουργία ενός σημείου
    Point* a = (Point*)malloc(sizeof(Point));
    if (a == NULL) {
        fprintf(stderr, "Failed to allocate memory\n");
        return 1;
    }
    
    a->x = 0;
    a->y = 0;

    point_print(*a);
    printf("\n");

    point_move_horizontally(a, 5); // Σωστή κλήση της συνάρτησης

    point_print(*a);
    printf("\n");

    free(a); // Αποδέσμευση μνήμης

    // Δυναμική δημιουργία τριγώνου
    Triangle* t = (Triangle*)malloc(sizeof(Triangle));
    if (t == NULL) {
        fprintf(stderr, "Failed to allocate memory\n");
        return 1;
    }

    t->points[0].x = 0;
    t->points[0].y = 0;
    t->points[1].x = 1;
    t->points[1].y = 0;
    t->points[2].x = 0;
    t->points[2].y = 1;

    triangle_print(t);

    triangle_move_horizontally(t, 5);

    triangle_print(t);

    free(t); // Αποδέσμευση μνήμης

    return 0;
}
