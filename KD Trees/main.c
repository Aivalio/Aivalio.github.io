#include <stdio.h>
#include <limits.h>
#include "point.h"
#include "range.h"
#include "kdtree.h"
#include "list.h"

int main() {
    // Δημιουργία σημείων
    Point *points_arr[] = {
        point_init(3,6),
        point_init(17,15),
        point_init(13,15),
        point_init(6,12),
        point_init(9,1),
        point_init(2,7),
        point_init(10,19)
    };

    int n = sizeof(points_arr) / sizeof(points_arr[0]);

    // Κατασκευή kd-tree
    KDNode *root = buildKDTree(points_arr, n, 0);

    // Ορισμός περιοχής αναζήτησης
    Range *query = range_init(0, 10, 0, 10);
    Range *region = range_init(INT_MIN, INT_MAX, INT_MIN, INT_MAX);

    // Λίστα για τα αποτελέσματα
    List *results = list_init();

    // Αναζήτηση
    results = searchKDTree(root, query, region, results);

    // Εκτύπωση αποτελεσμάτων
    printf("Points inside range:\n");
    list_print(results);

    // Καθαρισμός μνήμης
    list_destroy(results);
    destroyKDTree(root);
    free(region);
    free(query);
    for (int i = 0; i < n; i++) {
        free(points_arr[i]);
    }

    return 0;
}
