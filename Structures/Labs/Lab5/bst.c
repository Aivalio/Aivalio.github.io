/*File: bst.c*/
#include <stdio.h>
#include <stdlib.h>
#include "bst.h" // Interface file

// Creating a new BSTNode with input data
BSTNode* create_node(int data) {
    BSTNode* temp = (BSTNode*)malloc(sizeof(BSTNode));
    if (temp == NULL) {
        fprintf(stderr, "Failed to allocate memory\n");
        exit(EXIT_FAILURE);
    }
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

// Insert a new node into the binary search tree
BSTNode* insert(BSTNode* root, int data) {
    if (root == NULL) return create_node(data);

    if (data < root->data) {
        root->left = insert(root->left, data);
    } else if (data > root->data) {
        root->right = insert(root->right, data);
    }
    return root;
}

// Visit function
void visit(BSTNode* node) {
    printf("%d ", node->data);
}

// Count total nodes
int count(BSTNode* root) {
    return root ? count(root->left) + count(root->right) + 1 : 0;
}

// De-allocate memory
void destroy(BSTNode* node) {
    if (node != NULL) {
        destroy(node->left);
        destroy(node->right);
        free(node);
    }
}

/* -------------------------- */
/* FUNCTIONS FOR LAB EXERCISE */
/* -------------------------- */

// Complete implementation of delete function
BSTNode* delete(BSTNode* root, int data) {
    
    if(root==NULL) return NULL; // Root case

    if(data<root->data) {
        root->left=delete(root->left, data); // Search in the left subtree
    }
    else if(data>root->data) {
        root->right=delete(root->right, data); // Search in the right subtree
    }
    else { // Node found

        if(root->left==NULL) { // If the node has no left child
            BSTNode*temp=root->right;
            free(root);
            return temp;
        }
        else if(root->right==NULL) { // If tthe node has no right child
            BSTNode*temp=root->left;
            free(root);
            return temp;
        }
        else { // Two-childed case

            BSTNode* temp = min_value(root->right); // Find the minimum value of the right subtree
            root->data = temp->data;
            root->right = delete(root->right, temp->data);
        }
    }
    return root;
}

// Search a node
BSTNode* search(BSTNode* root, int data) {
    if (root == NULL || root->data == data) {
        return root;
    } else if (data < root->data) {
        return search(root->left, data);
    } else {
        return search(root->right, data);
    }
}

// In-order traversal
void inorder(BSTNode* root, Visit visit) {
    if (root != NULL) {
        inorder(root->left, visit);
        visit(root);
        inorder(root->right, visit);
    }
}

// Pre-order traversal
void preorder(BSTNode* root, Visit visit) {
    if (root != NULL) {
        visit(root);
        preorder(root->left, visit);
        preorder(root->right, visit);
    }
}

// Post-order traversal
void postorder(BSTNode* root, Visit visit) {
    if (root != NULL) {
        postorder(root->left, visit);
        postorder(root->right, visit);
        visit(root);
    }
}

// Find minimum value
BSTNode* min_value(BSTNode* root) {
    if (root == NULL) {
        fprintf(stderr, "The tree is empty\n");
        exit(EXIT_FAILURE);
    }

    while (root->left != NULL) {
        root = root->left;
    }
    return root;
}

// Find maximum value
BSTNode* max_value(BSTNode* root) {
    if (root == NULL) {
        fprintf(stderr, "The tree is empty\n");
        exit(EXIT_FAILURE);
    }

    while (root->right != NULL) {
        root = root->right;
    }
    return root;
}
