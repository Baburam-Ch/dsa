#include<stdio.h>
#define SIZE 10

int tree[SIZE] = {0};

int root(int key) {
    if (tree[0]) 
        printf("Tree is Full.\n");
    tree[0] = key;
    return 0;
}

int left_child(int key, int parent) {
    if (!tree[parent]) 
        printf("No parent for this left child.\n");
    tree[(parent*2) + 1] = key;
    return 0;
}

int right_child(int key, int parent) {
    if (!tree[parent]) 
        printf("No parent for this right child.\n");
    tree[(parent*2) + 2] = key;
    return 0;
}

void displayTree(int tree[]) {
    printf("\n");
    for (int i = 0; i < SIZE; i++) {
            if (!tree[i])
                printf("_");
            printf("%d", tree[i]);
    }
}

int main() 
{
    root(0);
    left_child(1, 0);
    right_child(2, 0);
    left_child(3, 1);
    right_child(4, 1);
    right_child(7, 2);

    return 0;
}