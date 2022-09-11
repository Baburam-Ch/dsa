#include<stdio.h>
#include<stdlib.h>

typedef struct BinarySearchTree {
    int data;
    struct BinarySearchTree *left;
    struct BinarySearchTree *right;
}BinarySearchTree;

BinarySearchTree *newNode(int data) {
    BinarySearchTree *node = (BinarySearchTree*)malloc(sizeof(BinarySearchTree));
    node->data = data;
    node->left = NULL;
    node->right = NULL;

    return node;
}

BinarySearchTree *insertNode(BinarySearchTree *root, int data) {
    if (root == NULL) {
        return newNode(data);
    } else if (data < root->data) {
        root->left = insertNode(root->left, data);
    } else
        root->right = insertNode(root->right, data);
    return root;
}

void displayBST(BinarySearchTree *root) {
    if (root != NULL) {
        displayBST(root->left);
        printf("%d ", root->data);
        displayBST(root->right);
    }     
}

int main() 
{
    BinarySearchTree *bst = NULL;
    bst = insertNode(bst, 18);
    insertNode(bst, 10);
    insertNode(bst, 26);
    insertNode(bst, 5);
    insertNode(bst, 20);
    insertNode(bst, 30);
    insertNode(bst, 4);
    insertNode(bst, 6);
    insertNode(bst, 25);
    

    printf("\nInorder Tree Traversal: ");
    displayBST(bst);

    return 0;
}