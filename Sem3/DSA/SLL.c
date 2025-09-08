#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *head = NULL;
int size = 0;

struct Node* createNode(int value) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data=value;
    newNode->next=NULL;
    return newNode;
}

void insertFirst(int value) {
    struct Node *newNode = createNode(value);
    newNode->next=head;
    head=newNode;
    size++;
}

void insertLast(int value) {
    struct Node *newNode = createNode(value);

    size++;
    if(head==NULL) {
        head=newNode;
        return;
    }

    struct Node *temp = head;
    while(temp->next!=NULL) {
        temp=temp->next;
    }
    temp->next=newNode;
}

void insertAt(int index, int value) {
    if(index<0 || index>size) {
        printf("Invaid Index!\n");
        return;
    }
    if(index==0) {
        insertFirst(value);
        return;
    }

    struct Node *temp = head;
    for(int i=0; i<index-1; i++)
    temp=temp->next;

    struct Node *newNode = createNode(value);
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

    size--;
    if(head->next==NULL) {
        free(head);
        head=NULL;
        return;
    }

    struct Node *temp=head;
    while(temp->next->next!=NULL) {
        temp=temp->next;
    }
    free(temp->next);
    temp->next=NULL;
}

void deleteAt(int index) {
    if(index<0 || index>=size) {
        printf("Invalid Index!!\n");
        return;
    }
    if(index==0) {
        deleteFirst();
        return;
    }

    struct Node *temp=head;
    for(int i=0;i<index-1;i++) {
        temp=temp->next;
    }
    struct Node *toDelete=temp->next;
    temp->next=temp->next->next;
    free(toDelete);
    size--;
}

int search(int value) {
    int index=0;
    struct Node *temp = head;
    while(temp!=NULL) {
        if(temp->data==value) {
            return index;
        }
        temp=temp->next;
        index++;
    }
    return -1;
}

int getSize() {
    return size;
}

void printList() {
    struct Node *temp = head;
    printf("List: ");
    while(temp!=NULL) {
        printf("%d --> ",temp->data);
        temp=temp->next;
    }
    printf("NULL\n");
    printf("Size: %d\n", size);
}

void clearList() {
    struct Node *temp=head;
    while(temp!=NULL) {
        struct Node *f=temp;
        temp=temp->next;
        free(f);
    }
    size=0;
    head=NULL;
}
