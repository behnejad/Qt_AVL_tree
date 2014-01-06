#include "struct.h"
#include <qDebug>
#include "node.h"

Struct::Struct()
{
    this->root = new Node();
}

Struct::~Struct()
{
}

int Struct::max(int a, int b)
{
    return (a > b)? a : b;
}

int Struct::heightfunc(Node* N)
{
    if (N == 0)
        return 0;
    return N->getHeight();
}

Node* Struct::newNode(int key)
{
    Node* node = new Node();
    node->setValue(key);
    node->left   = 0;
    node->right  = 0;
    node->setHeight(1);
    // new node is initially added at leaf
    return node;
}

Node* Struct::rightRotate(Node* y)
{
    Node* x = y->left;
    Node* T2 = x->right;

    // Perform rotation
    x->right = y;
    y->left = T2;

    // Update heights
    y->setHeight(max(heightfunc(y->left), heightfunc(y->right))+1);
    x->setHeight(max(heightfunc(x->left), heightfunc(x->right))+1);

    // Return new root
    return x;
}

Node* Struct::leftRotate(Node* x)
{
    Node* y = x->right;
    Node* T2 = y->left;

    // Perform rotation
    y->left = x;
    x->right = T2;

    //  Update heights
    x->setHeight(max(heightfunc(x->left), heightfunc(x->right))+1);
    y->setHeight(max(heightfunc(y->left), heightfunc(y->right))+1);

    // Return new root
    return y;
}

int Struct::getBalance(Node* N)
{
    if (N == 0)
        return 0;
    return this->heightfunc(N->left) - this->heightfunc(N->right);
}

Node* Struct::insert(Node* node, int key)
{
    /* 1.  Perform the normal BST rotation */
    if (node == 0)
        return(this->newNode(key));

    if (key < node->getValue())
        node->left  = this->insert(node->left, key);
    else
        node->right = this->insert(node->right, key);

    /* 2. Update height of this ancestor node */
    node->setHeight(this->max(this->heightfunc(node->left), this->heightfunc(node->right)) + 1);

    /* 3. Get the balance factor of this ancestor node to check whether
       this node became unbalanced */
    int balance = this->getBalance(node);

    // If this node becomes unbalanced, then there are 4 cases

    // Left Left Case
    if (balance > 1 && key < node->left->getValue())
        return this->rightRotate(node);

    // Right Right Case
    if (balance < -1 && key > node->right->getValue())
        return this->leftRotate(node);

    // Left Right Case
    if (balance > 1 && key > node->left->getValue())
    {
        node->left =  leftRotate(node->left);
        return this->rightRotate(node);
    }

    // Right Left Case
    if (balance < -1 && key < node->right->getValue())
    {
        node->right = rightRotate(node->right);
        return this->leftRotate(node);
    }

    /* return the (unchanged) node pointer */
    return node;
    }

    Node* Struct::minValueNode(Node* node)
    {
    Node* current = node;

    /* loop down to find the leftmost leaf */
    while (current->left != 0)
        current = current->left;

//    return current;
}

Node* Struct::deleteNode(Node* root, int key)
{
// STEP 1: PERFORM STANDARD BST DELETE

    if (root == 0)
        return root;

    // If the key to be deleted is smaller than the root's key,
    // then it lies in left subtree
    if ( key < root->getValue())
        root->left = this->deleteNode(root->left, key);

    // If the key to be deleted is greater than the root's key,
    // then it lies in left subtree
    else if( key > root->getValue())
        root->right = this->deleteNode(root->right, key);

    // if key is same as root's key, then This is the node
    // to be deleted
    else
    {
        // node with only one child or no child
        if( (root->left == 0) || (root->right == 0) )
        {
            Node* temp = root->left ? root->left : root->right;

            // No child case
            if(temp == 0)
            {
                temp = root;
                root = 0;
            }
            else // One child case
             *root = *temp; // Copy the contents of the non-empty child

            delete temp;
        }
        else
        {
            // node with two children: Get the inorder successor (smallest
            // in the right subtree)
            Node* temp = this->minValueNode(root->right);

            // Copy the inorder successor's data to this node
            root->setValue(temp->getValue());

            // Delete the inorder successor
            root->right = this->deleteNode(root->right, temp->getValue());
        }
    }

    // If the tree had only one node then return
    if (root == 0)
      return root;

    // STEP 2: UPDATE HEIGHT OF THE CURRENT NODE
    root->setHeight(this->max(heightfunc(root->left), heightfunc(root->right)) + 1);

    // STEP 3: GET THE BALANCE FACTOR OF THIS NODE (to check whether
    //  this node became unbalanced)
    int balance = this->getBalance(root);

    // If this node becomes unbalanced, then there are 4 cases

    // Left Left Case
    if (balance > 1 && this->getBalance(root->left) >= 0)
        return rightRotate(root);

    // Left Right Case
    if (balance > 1 && getBalance(root->left) < 0)
    {
        root->left =  leftRotate(root->left);
        return this->rightRotate(root);
    }

    // Right Right Case
    if (balance < -1 && getBalance(root->right) <= 0)
        return this->leftRotate(root);

    // Right Left Case
    if (balance < -1 && getBalance(root->right) > 0)
    {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

void Struct::preOrder(Node* node)
{
    if(node != 0)
    {
        printf("%d ",node->getValue());
        preOrder(node->left);
        preOrder(node->right);
    }
}
