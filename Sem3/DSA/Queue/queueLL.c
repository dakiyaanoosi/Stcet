#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *Rear=NULL;
struct Node *Front=NULL;

struct Node* createNode(int value) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data=value;
    newNode->next=NULL;
    return newNode;
}

int isEmpty() {
    return Rear==NULL;
}

void enqueue(int value) {
    struct Node *newNode = createNode(value);
    if(isEmpty()) {
        Rear=newNode;
        Front=newNode;
        return;
    }
    Rear->next=newNode;
    Rear=newNode;
}

int dequeue() {
    if(isEmpty()) {
        printf("Queue Underflow\n");
        return -1;
    }
    if(Front->next==NULL) {
        int value=Front->data;
        free(Front);
        Front=Rear=NULL;
        return value;
    }

    int value = Front->data;
    struct Node *toDelete = Front;
    Front = Front->next;
    free(toDelete);
    return value;
}

void display() {
    if(isEmpty()) {
        printf("Queue is Empty\n");
        return;
    }
    printf("Queue: ");
    struct Node *temp=Front;
    while(temp!=NULL) {
        printf("%d ", temp->data);
        temp=temp->next;
    }
    printf("\n");
}
