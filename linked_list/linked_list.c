#include <stdio.h>
#include <stdlib.h>

#include "linked_list.h"


typedef struct node {
    int v;
    struct node *next;
    struct node *prev;
} Node;

Node *newNode(int value, Node *prev, Node *next) {
    Node *new = malloc(sizeof(Node));
    new->next = next;
    new->prev = prev;
    new->v = value;
}


typedef struct linkedList {
    Node *first;
    Node *last;
    int size;
} LinkedList;

LinkedList *newLinkedList() {
    LinkedList *list = malloc(sizeof(LinkedList));
    list->first = NULL;
    list->last = NULL;
    list->size = 0;
    return list;
}

void delLinkedList(LinkedList *list) {
    for (Node *iter = list->first; iter != NULL;) {
        Node *next = iter->next;
        free(iter);
        iter = next;
    }
    free(list);
}

void addLinkNode(LinkedList *list, int value) {
    Node *last = list->last;
    Node *new = newNode(value, last, NULL);
    list->last = new;
    if (last == NULL)
        list->first = new;
    else
        last->next = new;
    list->size++; 
}

int deleteNode(LinkedList *list, Node *x);
int removeLinkedNode(LinkedList *list, int value) {
    int delv;
    for (Node *iter = list->first; iter != NULL; iter = iter->next) {
        if (iter->v == value) {
            return deleteNode(list, iter);
        }
    }
    printf("no such element.\n");
    exit(-1);
}

int removeLinkedFirst(LinkedList *list) {
    Node *first = list->first;
    int v = first->v;
    list->first = list->first->next;
    free(first);
    list->size--;
    return v;
}

int removeLinkedLast(LinkedList *list) {
    Node *last = list->last;
    int v = last->v;
    list->last = list->last->prev;
    free(last);
    list->size--;
    return v;
}

int deleteNode(LinkedList *list, Node *x) {
    int v = x->v;
    Node *next = x->next;
    Node *prev = x->prev;

    if (prev == NULL)
        list->first = next;
    else
        prev->next = next;

    if (next == NULL)
        list->last = prev;
    else
        next->prev = prev;
    
    free(x);
    list->size--;
    return v;
}

int sizeLinkedList(LinkedList *list) {
    return list->size;
}

void printLinkedList(LinkedList *list) {
    if (list->size == 0) {
        printf("[]\n");
        return;
    }
    printf("[");
    for (Node *iter = list->first; ; iter = iter->next) {
        printf("%d", iter->v);
        if (iter->next == NULL) {
            printf("]\n");
            return;
        }
        printf(", ");
    }
}

// char *toString(LinkedList *list) {
//     char *string;
// }