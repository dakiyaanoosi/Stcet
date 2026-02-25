#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node* createNode(int value) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data=value;
    newNode->left=newNode->right=NULL;
    return newNode;
}

struct Node* insert(struct Node *ROOT, int value) {
    if(ROOT==NULL) return createNode(value);
    if(value < ROOT->data) ROOT->left = insert(ROOT->left, value);
    else ROOT->right = insert(ROOT->right, value);
    return ROOT;
}

void inorder(struct Node *ROOT) {
    if(ROOT==NULL) return;
    inorder(ROOT->left);
    printf("%d ", ROOT->data);
    inorder(ROOT->right);
}

int main() {
    struct Node *ROOT=NULL;

    ROOT=insert(ROOT, 3);
    ROOT=insert(ROOT, 2);
    ROOT=insert(ROOT, 5);
    ROOT=insert(ROOT, 1);
    ROOT=insert(ROOT, 4);
    ROOT=insert(ROOT, 6);

    inorder(ROOT);

    return 0;
}