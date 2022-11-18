//Given an array, construct an AVL tree with helper operations (including left and right rotations)
//The tree is constructed using the bottom-up method

#include "stdio.h"
#include "stdlib.h"

//Structure to represent a node in the tree
struct node
{
    int data;
    struct node *left;
    struct node *right;
    int height;
};

//Function to get the height of a node
int height(struct node *N)
{
    if (N == NULL)
        return 0;
    return N->height;
}

//Function to get maximum of two integers
int max(int a, int b)
{
    return (a > b)? a : b;
}

//Function to create a new node
struct node* newNode(int data)
{
    struct node* node = (struct node*)
                        malloc(sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    node->height = 1; //new node is initially added at leaf
    return(node);
}

//Function to right rotate subtree rooted with y
//See the diagram given above.
struct node *rightRotate(struct node *y)
{
    struct node *x = y->left;
    struct node *T2 = x->right;

    //Perform rotation
    x->right = y;
    y->left = T2;

    //Update heights
    y->height = max(height(y->left), height(y->right))+1;
    x->height = max(height(x->left), height(x->right))+1;

    //Return new root
    return x;
}

//Function to left rotate subtree rooted with x
//See the diagram given above.
struct node *leftRotate(struct node *x)
{
    struct node *y = x->right;
    struct node *T2 = y->left;

    //Perform rotation
    y->left = x;
    x->right = T2;

    //Update heights
    x->height = max(height(x->left), height(x->right))+1;
    y->height = max(height(y->left), height(y->right))+1;

    //Return new root
    return y;
}

//Get Balance factor of node N
int getBalance(struct node *N)
{
    if (N == NULL)
        return 0;
    return height(N->left) - height(N->right);
}

//Function to insert a node in the subtree rooted with node and returns the new root of the subtree
struct node* insert(struct node* node, int data)
{
    //1. Perform the normal BST insertion
    if (node == NULL)
        return(newNode(data));

    if (data < node->data)
        node->left  = insert(node->left, data);
    else if (data > node->data)
        node->right = insert(node->right, data);
    else //Equal data values are not allowed in BST
        return node;

    //2. Update height of this ancestor node
    node->height = 1 + max(height(node->left),
                           height(node->right));

    //3. Get the balance factor of this ancestor node to check whether this node became unbalanced
    int balance = getBalance(node);

    //If this node becomes unbalanced, then there are 4 cases

    //Left Left Case
    if (balance > 1 && data < node->left->data)
        return rightRotate(node);

    //Right Right Case
    if (balance < -1 && data > node->right->data)
        return leftRotate(node);

    //Left Right Case
    if (balance > 1 && data > node->left->data)
    {
        node->left =  leftRotate(node->left);
        return rightRotate(node);
    }

    //Right Left Case
    if (balance < -1 && data < node->right->data)
    {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    /* return the (unchanged) node pointer */
    return node;
}

//Function to print the tree in inorder traversal
void printTree(struct node *root)
{
    if(root != NULL)
    {
        printTree(root->left);
        printf("%d ", root->data);
        printTree(root->right);
    }
}

//Driver program to test above functions
int main()
{
    struct node *root = NULL;

    /* Constructing tree given in the above figure */
    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 30);
    root = insert(root, 40);
    root = insert(root, 50);
    root = insert(root, 25);

    /* The constructed AVL Tree would be
            30
           /  \
         20   40
        /  \     \
       10  25    50
    */

    printf("The AVL tree is:");

    printTree(root);

    return 0;
}

