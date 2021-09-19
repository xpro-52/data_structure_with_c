#include <stdio.h>
#include <stdlib.h>

#include "queue.h"

typedef struct queue {
    LinkedList *linkedlist;
} Queue;

Queue *newQueue() {
    Queue *q = malloc(sizeof(Queue));
    q->linkedlist = newLinkedList();
    return q;
}

void enq(Queue *q, int value) {
    addLinkNode(q->linkedlist, value);
}

int deq(Queue *q) {
    return removeLinkedFirst(q->linkedlist);
}

int sizeQueue(Queue *q) {
    return sizeLinkedList(q->linkedlist);
}

void printQueue(Queue *q) {
    printLinkedList(q->linkedlist);
}

