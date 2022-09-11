#include<stdio.h>
#define SIZE 10

char tree[SIZE];

int root(char key) {
    if (tree[0] != "\n")
        printf("Tree is full.\n");
    tree[0] = key;
    return 0;
}

int set_left_child(char key, int parent) {
    if (tree[parent] == "\n") {
        printf("No parent to insert left child.\n");
    }
    tree[(parent*2) + 1] = key;
    return 0;
}

int set_right_child(char key, int parent) {
    if (tree[parent] == "\n") {
        printf("No parent to insert right child.\n");
    }
    tree[(parent*2)+2] = key;
    return 0;
}

void displayTree(char tree[]) {
    printf("\n");
    for (int i = 0; i < SIZE; i++) {
        if (tree[i] == "\0") {
            printf("_");
        }
        printf("%c", tree[i]);
    }
}

int main() 
{
    root("A");
    set_left_child("B", 0);
    set_right_child("C", 0);
    set_left_child("D", 1);
    set_right_child("E", 1);
    set_right_child("F", 2);

    return 0;
}