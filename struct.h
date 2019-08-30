#ifndef STRUCT1_H
#define STRUCT1_H

#include "node.h"

class Struct1
{
public:
    // An AVL tree node
    struct node* root;
    Struct1();
    /* Helper function that allocates a new node with the given key and
        NULL left and right pointers. */
    struct node* newNode(int);
    // A utility function to right rotate subtree rooted with y
    // See the diagram given above.
    struct node* rightRotate(struct node*);
    // A utility function to left rotate subtree rooted with x
    // See the diagram given above.
    struct node* leftRotate(struct node*);
    struct node* insert(struct node*, int b);
    /* Given a non-empty binary search tree, return the node with minimum
       key value found in that tree. Note that the entire tree does not
       need to be searched. */
    struct node* minValueNode(struct node*);
    struct node* deleteNode(struct node*, int);
    // A utility function to print preorder traversal of the tree.
    // The function also prints height of every node
    void preOrder(struct node*);
    // Get Balance factor of node N
    int getBalance(struct node*);
    // A utility function to get maximum of two integers
    int max(int a, int b);
    // A utility function to get height of the tree
    int heightfunc(struct node*);
    ~Struct1();
};



#endif // STRUCT_H
