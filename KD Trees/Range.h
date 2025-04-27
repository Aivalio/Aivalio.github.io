/*This is the interace file for the range*/

#ifndef RANGE_H
#define RANGE_H

#include "Point.h"

typedef struct {

    double xmin, xmax;
    double ymin, ymax;
} Range;

// THE FUNCTIONS TO HANDLE THE RANGE

// Function to initialize a new Range 
Range *range_init(double xmin,double xmax,double ymin,double ymax); 

// Function to check if a point p is inside a square R 
int point_in_range(Point *p, Range *R); 

// Function to check if two squares intersect 
int range_intersect(Range *r1, Range *r2); 

// Four symmetrical functions. Very useful for   calculating the region of a child of a node i.e region(lc(v)) or region(rc(v)) 
Range *intersect_square_on_y_up(Range *square, double x); 
Range *intersect_square_on_y_down(Range *square, double x); 
Range *intersect_square_on_x_left(Range *square, double y); 
Range *intersect_square_on_x_right(Range *square, double y); 

// Function to check if square 'outer' completely contains square 'inner' 
int range_contains(Range *outer, Range *inner);

#endif //RANGE_H
