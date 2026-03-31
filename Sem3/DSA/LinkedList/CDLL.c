#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node *next;
    struct Node *prev;
};

struct Node *createNode(int value) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data=value;
    newNode->next=newNode->prev=NULL;
    return newNode;
}

struct Node *TAIL=NULL;

void insertFirst(int value) {
    struct Node *newNode = createNode(value);
    if(TAIL==NULL) {
        TAIL=newNode;
        newNode->next=newNode->prev=TAIL;
        return;
    }

    TAIL->next->prev=newNode;
    newNode->prev=TAIL;
    newNode->next=TAIL->next;
    TAIL->next=newNode;
}

void insertLast(int value) {
    struct Node *newNode = createNode(value);
    if(TAIL==NULL) {
        TAIL=newNode;
        newNode->next=newNode->prev=TAIL;
        return;
    }

    TAIL->next->prev=newNode;
    newNode->prev=TAIL;
    newNode->next=TAIL->next;
    TAIL->next=newNode;
    TAIL=newNode;
}

void insertAfter(int data, int value) {
    if(TAIL==NULL) {
        printf("List is Empty\n");
        return;
    }
    struct Node *temp = TAIL->next;
    while(temp->data!=data) {
        if(temp->next==TAIL->next) {
            printf("%d, not found in the List\n", data);
            return;
        }
        temp=temp->next;
    }

    struct Node *newNode = createNode(value);

    temp->next->prev=newNode;
    newNode->prev=temp;
    newNode->next=temp->next;
    temp->next=newNode;
    if(temp==TAIL) TAIL= newNode;
}

void insertbefore(int data, int value) {
    if(TAIL==NULL) {
        printf("List is Empty\n");
        return;
    }
    struct Node *temp = TAIL->next;
    while(temp->data!=data) {
        if(temp->next==TAIL->next) {
            printf("%d, not found in the List\n", data);
            return;
        }
        temp=temp->next;
    }

    struct Node *newNode = createNode(value);

    newNode->prev=temp->prev;
    newNode->next=temp;
    temp->prev->next=newNode;
    temp->prev=newNode;
}

void deleteFirst() {
    if(TAIL==NULL) {
        printf("List is Empty\n");
        return;
    }

    if(TAIL->next==TAIL) {
        free(TAIL);
        TAIL=NULL;
        return;
    }

    struct Node *toDelete = TAIL->next;
    toDelete->next->prev=TAIL;
    TAIL->next=toDelete->next;
    free(toDelete);
}

void deletelast() {
    if(TAIL==NULL) {
        printf("List is Empty\n");
        return;
    }

    if(TAIL->next==TAIL) {
        free(TAIL);
        TAIL=NULL;
        return;
    }

    struct Node *toDelete = TAIL; 
    TAIL->prev->next=TAIL->next;
    TAIL->next->prev=TAIL->prev;
    TAIL=TAIL->prev;
    free(toDelete);
}

void delete(int data) {
    if(TAIL==NULL) {
        printf("List is Empty\n");
        return;
    }

    if(TAIL->next==TAIL) {
        if(TAIL->data==data) {
            free(TAIL);
            TAIL=NULL;
            return;
        }
        printf("%d, not found in the List\n", data);
        return;
    }

    struct Node *temp=TAIL->next;
    while(temp->data!=data) {
        temp=temp->next;
        if(temp==TAIL->next) {
            printf("%d, not found in the List\n", data);
            return;
        }
    }

    temp->prev->next=temp->next;
    temp->next->prev=temp->prev;
    if(temp==TAIL) TAIL=temp->prev;
    free(temp);
}

void display() {
    if(TAIL==NULL) {
        printf("List is Empty\n");
        return;
    }

    struct Node *temp=TAIL->next;
    printf("List: ");
    while(temp != TAIL) {
        printf("%d <--> ", temp->data);
        temp=temp->next;
    }
    printf("%d <--> HEAD\n", TAIL->data);
}