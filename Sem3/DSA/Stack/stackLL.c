#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *createNode(int value) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data=value;
    newNode->next=NULL;
    return newNode;
}

struct Node *HEAD=NULL;

int isEmpty() {
    return HEAD==NULL;
}

void push(int value) {
    struct Node *newNode = createNode(value);
    if(isEmpty()) {
        HEAD=newNode;
        return;
    }
    newNode->next=HEAD;
    HEAD=newNode;
}

int pop() {
    if(isEmpty()) {
        printf("Stack Underflow\n");
        return -1;
    }

    struct Node *toPop = HEAD;
    int toReturn = toPop->data;

    HEAD=HEAD->next;

    free(toPop);
    return toReturn;
}

int peek() {
    if(isEmpty()) {
        printf("Stack is Empty\n");
        return -1;
    }
    return HEAD->data;
}

void display() {
    if(isEmpty()) {
        printf("Stack is Empty\n");
        return;
    }
    struct Node *temp=HEAD;
    printf("Stack:\n");
    while(temp!=NULL) {
        printf("%d\n", temp->data);
        temp=temp->next;
    }
}
