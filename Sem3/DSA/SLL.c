#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *HEAD = NULL;

struct Node* createNode(int value) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data=value;
    newNode->next=NULL;
    return newNode;
}

void printList() {
    struct Node *temp=HEAD;
    printf("List: ");
    while(temp!=NULL) {
        printf("%d --> ",temp->data);
        temp=temp->next;
    }
    printf("NULL\n");
}

void insertFirst(int value) {
    struct Node *newNode = createNode(value);
    newNode->next=HEAD;
    HEAD=newNode;
}

void insertLast(int value) {
    struct Node *newNode=createNode(value);
    if(HEAD==NULL) {
        HEAD=newNode;
        return;
    }
    struct Node *temp=HEAD;
    while(temp->next!=NULL) {
        temp=temp->next;
    }
    temp->next=newNode;
}

void insertAfter(int data, int value) {
    struct Node *temp=HEAD;
    if(temp==NULL) {
        printf("Error: List is Empty!\n");
        return;
    }
    while(temp->data!=data) {
        temp=temp->next;
        if(temp==NULL) {
            printf("Error: %d NOT FOUND in the List!\n", data);
            return;
        }
    }
    struct Node *newNode=createNode(value);
    newNode->next=temp->next;
    temp->next=newNode;
}

void deleteFirst() {
    if(HEAD==NULL) {
        printf("Error: List is Empty!\n");
        return;
    }
    struct Node *temp=HEAD;
    HEAD=HEAD->next;
    free(temp);
}

void deleteLast() {
    if(HEAD==NULL) {
        printf("Error: List is Empty!\n");
        return;
    }
    if(HEAD->next==NULL) {
        free(HEAD);
        HEAD=NULL;
        return;
    }
    struct Node *temp=HEAD;
    while(temp->next->next!=NULL) {
        temp=temp->next;
    }
    free(temp->next);
    temp->next=NULL;
}

void deleteAfter(int data) {
    if(HEAD==NULL) {
        printf("Error: List is Empty!\n");
        return;
    }
    struct Node *temp=HEAD;
    while(temp->data!=data) {
        temp=temp->next;
        if(temp==NULL) {
            printf("Error: %d NOT FOUND in the List!\n", data);
            return;
        }
    }
    if(temp->next==NULL) {
        printf("Error: No value after %d!\n", data);
        return;
    }
    struct Node *temp2=temp->next;
    temp->next=temp->next->next;
    free(temp2);
}
