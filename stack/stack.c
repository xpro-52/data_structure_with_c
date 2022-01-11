#include <stdio.h>
#include <stdlib.h>

#include "stack.h"


typedef struct stack {
    LinkedList *linkedList;
} Stack;

Stack *newStack() {
    Stack *s = (Stack *)malloc(sizeof(Stack));
    s->linkedList = newLinkedList();
    return s;
}

void push(Stack *s, int value) {
    addLinkNode(s->linkedList, value);
}

int pop(Stack *s) {
    return removeLinkedLast(s->linkedList);
}

int sizeStack(Stack *s) {
    return sizeLinkedList(s->linkedList);
}

char *toStringStack(Stack *s) {
    return toStringLinkedList(s->linkedList);
}