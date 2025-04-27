#include <stdlib.h>
#include "Range.h"

Range* range_init(double xmin, double xmax, double ymin, double ymax) {
    Range *r = (Range*)malloc(sizeof(Range));
    r->xmin = xmin;
    r->xmax = xmax;
    r->ymin = ymin;
    r->ymax = ymax;
    return r;
}

int point_in_range(Point *p, Range *r) {
    return (p->x >= r->xmin && p->x <= r->xmax && p->y >= r->ymin && p->y <= r->ymax);
}

int range_intersect(Range *r1, Range *r2) {
    return !(r1->xmax < r2->xmin || r1->xmin > r2->xmax || r1->ymax < r2->ymin || r1->ymin > r2->ymax);
}

Range* intersect_square_on_y_up(Range *square, double x) {
    return range_init(x, square->xmax, square->ymin, square->ymax);
}

Range* intersect_square_on_y_down(Range *square, double x) {
    return range_init(square->xmin, x, square->ymin, square->ymax);
}

Range* intersect_square_on_x_left(Range *square, double y) {
    return range_init(square->xmin, square->xmax, square->ymin, y);
}

Range* intersect_square_on_x_right(Range *square, double y) {
    return range_init(square->xmin, square->xmax, y, square->ymax);
}

int range_contains(Range *outer, Range *inner) {
    return (outer->xmin <= inner->xmin && outer->xmax >= inner->xmax &&
            outer->ymin <= inner->ymin && outer->ymax >= inner->ymax);
}
