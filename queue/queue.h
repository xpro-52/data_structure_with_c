#ifndef QUEUE_H
#define QUEUE_H

#include "../linked_list/linked_list.h"

typedef struct queue Queue;

Queue *newQueue();

void enq(Queue *q, int data);
int deq(Queue *q);

int sizeQueue(Queue *q);
void printQueue(Queue *q);

#endif