#include<stdio.h>
#include<stdlib.h>

typedef struct TreeNode {
    int data;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;

// Create tree node
TreeNode *createNode(int item) 
{
    TreeNode *root = malloc(sizeof(TreeNode));
    if (root != NULL) {        
        root->data = item;
        root->left = NULL;
        root->right = NULL;
    }
    return root;
}

void displayTabs(int tabNumbers) {
    for (int i = 0; i < tabNumbers; i++) {
        printf("\t");
    }
}

void displayTree_recursion(TreeNode *root, int level) {
    if (root == NULL) {
        displayTabs(level);
        printf("---<empty>---\n");
        return;
    }
    displayTabs(level);
    printf("%d\n", root->data);

    displayTabs(level);
    printf("Left Node\n");
    displayTree_recursion(root->left, level+1);

    displayTabs(level);
    printf("Right Node\n");
    displayTree_recursion(root->right, level+1);
    
    displayTabs(level);
    printf("done\n");
}

void displayTree(TreeNode *root) {
    displayTree_recursion(root, 0);
}

/* Tree Traversal */
// 1. Preorder
void preorderTraversal(TreeNode *root) {
    if (root == NULL) return; // base condition
    printf("%d ", root->data);
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

// 2. Inorder
void inorderTraversal(TreeNode *root) {
    if (root != NULL) return;
    inorderTraversal(root->left);
    printf("%d ", root->data);
    inorderTraversal(root->right);
}

// 3. Postorder
void postorderTraversal(TreeNode *root) {
    if (root != NULL) return;
    postorderTraversal(root->left);
    postorderTraversal(root->right);
    printf("%d ", root->data);
}

int main() 
{
    TreeNode *n1 = createNode(8);
    TreeNode *n2 = createNode(5);
    TreeNode *n3 = createNode(4);
    TreeNode *n4 = createNode(9);
    TreeNode *n5 = createNode(7);
    TreeNode *n6 = createNode(11);
    TreeNode *n7 = createNode(1);
    TreeNode *n8 = createNode(12);
    TreeNode *n9 = createNode(3);
    TreeNode *n10 = createNode(2);

    // Tree creation
    n1->left = n2;
    n1->right = n3;
    n2->left = n4;
    n2->right = n5;
    n3->right = n6;
    n5->left = n7;
    n5->right = n8;
    n6->left = n9;
    n8->left = n10;

    // displayTree(n1);  

    // Tree Traversal
    // 1. Preorder
    printf("Preorder Traversal:\t");
    preorderTraversal(n1);
    
    // 2. Inorder
    printf("\nInorder Traversal:\t");
    inorderTraversal(n1);
    
    // 3. Postorder
    printf("\nPostorder Traversal:\t");
    postorderTraversal(n1);   

    free(n1); free(n2); free(n3); free(n4); free(n5);
    free(n6); free(n7); free(n8); free(n9); free(n10);

    return 0;
}