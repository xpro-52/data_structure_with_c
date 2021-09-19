#ifndef STACK_H
#define STACK_H

#include "../linked_list/linked_list.h"

typedef struct stack Stack;

Stack *newStack();

void delStack(Stack *s);

void push(Stack *s, int value);

int pop(Stack *s);

int sizeStack(Stack *s);

void printStack(Stack *s);

#endif
