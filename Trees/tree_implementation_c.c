#include<stdio.h>
#include<stdlib.h>

typedef struct TreeNode {
    int data; 
    struct TreeNode *leftNode;
    struct TreeNode *rightNode;
}TreeNode;

TreeNode *createNode(int item) {
    TreeNode *root = malloc(sizeof(TreeNode));
    if (root != NULL) {
        root->data = item;
        root->leftNode = NULL;
        root->rightNode = NULL;
    }
    return root;
}

void displayTabs(int numTabs) {
    for (int i = 0; i < numTabs; i++) {
        printf("\t");
    }
}

void displayTreeRecursive(TreeNode *root, int level) {
    if (root == NULL) {
        displayTabs(level);
        printf("---<empty>---\n");
        return;
    } 
    displayTabs(level);
    printf("value = %d\n", root->data);

    displayTabs(level);
    printf("left Nodes\n");  
    displayTreeRecursive(root->leftNode, level+1);
    
    displayTabs(level);
    printf("right Nodes\n");    
    displayTreeRecursive(root->rightNode, level+1);

    displayTabs(level);
    printf("done\n");
    
}

void displayTree(TreeNode * root) {
    displayTreeRecursive(root, 0);
}

int main() 
{
    TreeNode *n1 = createNode(10);
    TreeNode *n2 = createNode(20);
    TreeNode *n3 = createNode(15);
    TreeNode *n4 = createNode(12);
    TreeNode *n5 = createNode(19);

    n1->leftNode = n2;
    n1->rightNode = n3;
    n3->leftNode = n4;
    n3->rightNode = n5;

    displayTree(n1);
    
    free(n1);
    free(n2);
    free(n3);
    free(n4);
    free(n5);

    return 0;
}


