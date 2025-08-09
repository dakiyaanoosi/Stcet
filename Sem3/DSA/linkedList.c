#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *head=NULL;
int size=0;

struct Node* createNode(int value) {
    struct Node *newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->data=value;
    newNode->next=NULL;
    return newNode;
}

void insertFirst(int value) {
    struct Node *newNode=createNode(value);
    newNode->next=head;
    head=newNode;
    size++;
}

void insertLast(int value) {
    struct Node *newNode=createNode(value);
    
    if(head==NULL) {
        head=newNode;
        size++;
        return;
    }

    struct Node *temp=head;
    while(temp->next!=NULL) {
        temp=temp->next;
    }
    temp->next=newNode;
    size++;
}

void insertAt(int index, int value) {
    if(index<0 || index>size) {
        printf("Invalid Index\n");
        return;
    }
    if(index==0) {
        insertFirst(value);
        return;
    }
    else if(index==size) {
        insertLast(value);
        return;
    }

    struct Node *newNode=createNode(value);
    struct Node *temp=head;

    for(int i=0;i<index-1;i++)
    temp=temp->next;

    newNode->next=temp->next;
    temp->next=newNode;
    size++;
}

void deleteFirst() {
    if(head==NULL) {
        printf("List is Empty!\n");
        return;
    }
    struct Node *temp=head;
    head=head->next;
    free(temp);
    size--;
}

void deleteLast() {
    if(head==NULL) {
        printf("List is Empty!\n");
        return;
    }

    if(head->next==NULL) {
        free(head);
        head=NULL;
        size--;
        return;
    }

    struct Node *temp=head;
    while(temp->next->next!=NULL) {
        temp=temp->next;
    }
    free(temp->next);
    temp->next=NULL;
    size--;
}

void deleteAt(int index) {
    if(index<0 || index>=size) {
        printf("Invalid Index\n");
        return;
    }
    if(index==0) {
        deleteFirst();
        return;
    }
    else if(index==size-1) {
        deleteLast();
        return;
    }

    struct Node *temp=head;
    for(int i=0; i<index-1; i++) {
        temp=temp->next;
    }

    struct Node *toDelete=temp->next;
    temp->next=toDelete->next;
    free(toDelete);
    size--;
}

void printList() {
    if(head==NULL) {
        printf("List is Empty!\n");
        return;
    }
    struct Node *temp=head;
    printf("List: ");
    while(temp!=NULL) {
        printf("%d --> ", temp->data);
        temp=temp->next;
    }
    printf("NULL\n");
    printf("Size: %d\n", size);
}

void freeList() {
    struct Node *temp=head;
    while(temp!=NULL) {
        struct Node* nxt=temp->next;
        free(temp);
        temp=nxt;
    }
    head=NULL;
    size=0;
}

int main() {
    insertLast(10);
    insertLast(12);
    insertLast(14);

    insertFirst(8);
    insertFirst(6);
    insertFirst(4);
    insertFirst(2);

    insertAt(2,5);
    insertAt(4,7);

    deleteFirst();
    deleteLast();
    deleteAt(2);
    deleteAt(0);

    printList();
    freeList();
    return 0;
}