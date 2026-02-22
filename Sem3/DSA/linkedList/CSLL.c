#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *head=NULL;
int size=0;

struct Node* createNode(int value) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data=value;
    newNode->next=NULL;
    return newNode;
}

void insertFirst(int value) {
    struct Node *newNode=createNode(value);
    if(head==NULL) {
        head=newNode;
        newNode->next=head;
    }
    else {
        struct Node *temp=head;
        while(temp->next!=head) {
            temp=temp->next;
        }
        newNode->next=head;
        head=newNode;
        temp->next=newNode;
    }
    size++;
}

void insertLast(int value) {
    struct Node *newNode=createNode(value);
    if(head==NULL) {
        head=newNode;
        newNode->next=head;
    }
    else {
        struct Node *temp=head;
        while(temp->next!=head) {
            temp=temp->next;
        }
        temp->next=newNode;
        newNode->next=head;
    }
    size++;
}

void printList() {
    struct Node *temp=head;
    for(int i=0;i<size;i++) {
        printf("%d -->", temp->data);
        temp=temp->next;
    }
    printf("\n|");
    for(int i=0;i<size;i++) {
        if(i==size-1) {
            printf("___");
            break;
        }
        printf("_____");
    }
    printf("|\n");
}
