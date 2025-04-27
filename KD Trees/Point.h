/*This is the interface file for the points of my KD-Tree*/
#ifndef POINT_H
#define POINT_H

// Definition of the coordinates of a point 
typedef struct point {

    double x;
    double y;
} Point; // A variable of type sturct point

Point*init(double x, double y); // Function to initialize a point
int point_compare_x(const void*a, const void*b); // Comparison baed on x coordinate
int point_compare_y(const void*a, const void*b); // Comparison based on y coordinate

#endif // POINT_H
