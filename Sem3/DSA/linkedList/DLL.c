#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node *prev;
    struct Node *next;
};

struct Node* createNode(int value) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data=value;
    newNode->prev=NULL;
    newNode->next=NULL;
}

struct Node *HEAD=NULL;

void insertFirst(int value) {
    struct Node *newNode=createNode(value);
    if(HEAD==NULL) {
        HEAD=newNode;
        return;
    }
    HEAD->prev=newNode;
    newNode->next=HEAD;
    HEAD=newNode;
}

void insertLast(int value) {
    struct Node *newNode = createNode(value);
    if(HEAD==NULL) {
        HEAD=newNode;
        return;
    }
    struct Node *temp=HEAD;
    while(temp->next!=NULL)
    temp=temp->next;

    temp->next=newNode;
    newNode->prev=temp;
}

void insertAfter(int data, int value) {
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

    struct Node *newNode=createNode(value);
    newNode->prev=temp;
    newNode->next=temp->next;

    if(temp->next!=NULL)
    (temp->next)->prev=newNode;

    temp->next=newNode;
}

void deleteFirst() {
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
    HEAD=HEAD->next;
    HEAD->prev=NULL;
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
    while(temp->next!=NULL)
    temp=temp->next;

    (temp->prev)->next=NULL;
    free(temp);
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
    temp->next=temp2->next;
    if(temp2->next!=NULL)
    temp2->next->prev=temp;

    free(temp2);
}

void printList() {
    if(HEAD==NULL) return;
    struct Node *temp=HEAD;
    while(temp->next!=NULL) {
        printf("%d --> ", temp->data);
        temp=temp->next;
    }
    printf("%d", temp->data);
}