#ifndef STRUCT_H
#define STRUCT_H

#include "node.h"

class Struct
{
public:
    // An AVL tree node
    Node* root;
    Struct();
    /* Helper function that allocates a new node with the given key and
        NULL left and right pointers. */
    Node* newNode(int);
    // A utility function to right rotate subtree rooted with y
    // See the diagram given above.
    Node* rightRotate(Node*);
    // A utility function to left rotate subtree rooted with x
    // See the diagram given above.
    Node* leftRotate(Node*);
    Node* insert(Node*, int b);
    /* Given a non-empty binary search tree, return the node with minimum
       key value found in that tree. Note that the entire tree does not
       need to be searched. */
    Node* minValueNode(Node*);
    Node* deleteNode(Node*, int);
    // A utility function to print preorder traversal of the tree.
    // The function also prints height of every node
    void preOrder(Node*);
    // Get Balance factor of node N
    int getBalance(Node*);
    // A utility function to get maximum of two integers
    int max(int a, int b);
    // A utility function to get height of the tree
    int heightfunc(Node*);
    ~Struct();
};



#endif // STRUCT_H
