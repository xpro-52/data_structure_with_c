#ifndef LINKED_LIST_H
#define LINKED_LIST_H

typedef struct node Node;

Node *newNode(int value, Node *prev, Node *next);


typedef struct linkedList LinkedList;

LinkedList *newLinkedList();

void delLinkedList(LinkedList *list);

void addLinkNode(LinkedList *list, int value);

int removeLinkedNode(LinkedList *list, int value);
int removeLinkedFirst(LinkedList *list);
int removeLinkedLast(LinkedList *list);

int sizeLinkedList(LinkedList *list);

char *toStringLinkedList(LinkedList *list);

#endif