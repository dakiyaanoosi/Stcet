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

int search(struct Node *ROOT, int key) {
    if(ROOT==NULL) return 0;
    if(ROOT->data == key) return 1;
    if(key < ROOT->data) return search(ROOT->left, key);
    else return search(ROOT->right, key);
}

struct Node* delete(struct Node *ROOT, int key) {
    if(ROOT==NULL) return NULL;

    if(key < ROOT->data) ROOT->left = delete(ROOT->left, key);

    else if(key > ROOT->data) ROOT->right = delete(ROOT->right, key);

    else {
        if(ROOT->left == NULL && ROOT->right == NULL) {
            free(ROOT);
            return NULL;
        }
        else if(ROOT->right == NULL) {
            struct Node *temp = ROOT->left;
            free(ROOT);
            return temp;
        }
        else if(ROOT->left==NULL) {
            struct Node *temp = ROOT->right;
            free(ROOT);
            return temp;
        }
        else {
            struct Node *temp = ROOT->right;
            while(temp->left!=NULL) {
                temp=temp->left;
            }
            ROOT->data = temp->data;
            ROOT->right=delete(ROOT->right, temp->data);
        }
    }
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
    printf("\n");

    ROOT=delete(ROOT, 5);

    inorder(ROOT);
    printf("\n");

    return 0;
}