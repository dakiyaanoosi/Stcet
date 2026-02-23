#include<stdio.h>
#define MAX 5

struct Queue {
    int front, rear;
    int items[MAX];
};

void initialize(struct Queue *q) {
    q->front=0;
    q->rear=0;
}

int isEmpty(struct Queue *q) {
    return (q->front == q->rear);
}

int isFull(struct Queue *q) {
    return ((q->rear + 1) % MAX == q->front);
}

void enqueue(struct Queue *q, int value) {
    if(isFull(q)) {
        printf("Queue Overflow\n");
        return;
    }
    q->items[q->rear] = value;
    q->rear = (q->rear + 1) % MAX;
}

int dequeue(struct Queue *q) {
    if(isEmpty(q)) {
        printf("Queue Underflow\n");
        return -1;
    }
    int value = q->items[q->front];
    q->front = (q->front+1) % MAX;
    return value;
}

int getFront(struct Queue *q) {
    if(isEmpty(q)) {
        printf("Queue is Empty\n");
        return;
    }
    return q->items[q->front];
}

void display(struct Queue *q) {
    if(isEmpty(q)) {
        printf("Queue is Empty\n");
        return -1;
    }

    printf("Queue: ");
    for(int i=q->front; i!=q->rear; i=(i+1)%MAX) {
        printf("%d ", q->items[i]);
    }
    printf("\n");
}