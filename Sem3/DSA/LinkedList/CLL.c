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

struct Node *TAIL=NULL;

int isEmpty() {
    return (TAIL==NULL);
}

void insertFirst(int value) {
    struct Node *newNode = createNode(value);
    if(isEmpty()) {
        TAIL=newNode;
        newNode->next=TAIL;
        return;
    }

    newNode->next=TAIL->next;
    TAIL->next = newNode;
}

void insertLast(int value) {
    struct Node *newNode = createNode(value);
    if(isEmpty()) {
        TAIL=newNode;
        newNode->next=TAIL;
        return;
    }

    newNode->next=TAIL->next;
    TAIL->next=newNode;
    TAIL=newNode;
}

void insertAfter(int data, int value) {
    if(isEmpty()) {
        printf("List is Empty\n");
        return;
    }

    struct Node *temp=TAIL->next;
    while(temp->next != TAIL->next && temp->data!=data) {
        temp=temp->next;
    }

    if(temp->data == data) {
        struct Node *newNode = createNode(value);
        newNode->next=temp->next;
        temp->next=newNode;
        if(temp==TAIL) {
            TAIL=newNode;
        }
        return;
    }

    printf("%d not found in the List\n", data);
}

void deleteFirst() {
    if(isEmpty()) {
        printf("List is Empty\n");
        return;
    }

    if(TAIL->next==TAIL) {
        free(TAIL);
        TAIL=NULL;
        return;
    }

    struct Node *temp=TAIL->next;
    TAIL->next=temp->next;
    free(temp);
}

void deleteLast() {
    if(isEmpty()) {
        printf("List is Empty\n");
        return;
    }

    if(TAIL->next==TAIL) {
        free(TAIL);
        TAIL=NULL;
        return;
    }

    struct Node *temp=TAIL->next;
    while(temp->next!=TAIL) {
        temp=temp->next;
    }
    
    struct Node *toDelete=temp->next;
    temp->next=toDelete->next;
    TAIL=temp;
    free(toDelete);
}

void deleteAfter(int data) {
    if(isEmpty()) {
        printf("List is Empty\n");
        return;
    }

    if(TAIL->next==TAIL) {
        if(TAIL->data == data) {
            free(TAIL);
            TAIL=NULL;
            return;
        }
        printf("%d, not found in the List\n", data);
        return;
    }

    if(TAIL->data==data) {
        deleteFirst();
        return;
    }

    struct Node *temp=TAIL->next;
    while(temp!=TAIL && temp->data!=data) {
        temp=temp->next;
    }

    if(temp->data==data) {
        struct Node *toDelete=temp->next;
        if(toDelete==TAIL) {
            deleteLast();
            return;
        }
        temp->next=toDelete->next;
        free(toDelete);
        return;
    }

    printf("%d not foudnd in the List\n", data);
}

void display() {
    if(isEmpty()) {
        printf("List is Empty\n");
        return;
    }

    struct Node *temp=TAIL->next;
    printf("List: ");
    while(temp != TAIL) {
        printf("%d --> ", temp->data);
        temp=temp->next;
    }
    printf("%d --> HEAD\n", TAIL->data);
}