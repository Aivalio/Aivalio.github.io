#ifndef KDTREE_H
#define KDTREE_H

#include "point.h"
#include "range.h"

// Διεπαφή NodeType
typedef enum node_type {
    VERTICAL_LINE, HORIZONTAL_LINE, LEAF_NODE
} NodeType;

// Διεπαφή KDNode
typedef struct kdnode {
    Point *point;
    int *line;
    NodeType type;
    struct kdnode *left;
    struct kdnode *right;
} KDNode;

// Συναρτήσεις
KDNode* kdnode_init(Point *p, int *line, NodeType type);
KDNode* buildKDTree(Point **points, int n, int depth);
List* searchKDTree(KDNode *root, Range *range, Range *region, List *l);
void destroyKDTree(KDNode *root);

#endif

#include <stdlib.h>
#include <limits.h>
#include "kdtree.h"
#include "list.h"  // χρειάζεται να έχεις έναν απλό dynamic list τύπου List

KDNode* kdnode_init(Point *p, int *line, NodeType type) {
    KDNode *node = (KDNode*)malloc(sizeof(KDNode));
    node->point = p;
    node->line = line;
    node->type = type;
    node->left = NULL;
    node->right = NULL;
    return node;
}

KDNode* buildKDTree(Point **points, int n, int depth) {
    if (n <= 0) return NULL;

    int axis = depth % 2;  // 0 για x, 1 για y
    if (axis == 0) {
        qsort(points, n, sizeof(Point*), point_compare_x);
    } else {
        qsort(points, n, sizeof(Point*), point_compare_y);
    }

    int median = n / 2;
    KDNode *node = NULL;

    if (n == 1) {
        node = kdnode_init(points[0], NULL, LEAF_NODE);
    } else {
        int *line = (int*)malloc(sizeof(int));
        if (axis == 0)
            *line = points[median]->x;
        else
            *line = points[median]->y;

        node = kdnode_init(NULL, line, axis == 0 ? VERTICAL_LINE : HORIZONTAL_LINE);
        node->left = buildKDTree(points, median, depth + 1);
        node->right = buildKDTree(points + median, n - median, depth + 1);
    }
    return node;
}

List* searchKDTree(KDNode *root, Range *range, Range *region, List *l) {
    if (!root) return l;

    if (root->type == LEAF_NODE) {
        if (point_in_range(root->point, range)) {
            list_add(l, root->point); // Προσθήκη στο αποτέλεσμα
        }
        return l;
    }

    Range *left_region = NULL;
    Range *right_region = NULL;

    if (root->type == VERTICAL_LINE) {
        left_region = intersect_square_on_y_down(region, *(root->line));
        right_region = intersect_square_on_y_up(region, *(root->line));
    } else if (root->type == HORIZONTAL_LINE) {
        left_region = intersect_square_on_x_left(region, *(root->line));
        right_region = intersect_square_on_x_right(region, *(root->line));
    }

    if (range_intersect(range, left_region)) {
        l = searchKDTree(root->left, range, left_region, l);
    }
    if (range_intersect(range, right_region)) {
        l = searchKDTree(root->right, range, right_region, l);
    }

    free(left_region);
    free(right_region);

    return l;
}

void destroyKDTree(KDNode *root) {
    if (!root) return;

    destroyKDTree(root->left);
    destroyKDTree(root->right);
    if (root->line) free(root->line);
    free(root);
}

