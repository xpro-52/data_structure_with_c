#include <stdio.h>
#include <stdlib.h>

#include "linked_list.h"
#include "../string_builder.h"


typedef struct node {
    int v;
    struct node *next;
    struct node *prev;
} Node;

Node *newNode(int value, Node *prev, Node *next) {
    Node *new = (Node *)malloc(sizeof(Node));
    new->next = next;
    new->prev = prev;
    new->v = value;
    return new;
}


typedef struct linkedList {
    Node *first;
    Node *last;
    int size;
} LinkedList;

LinkedList *newLinkedList() {
    LinkedList *list = (LinkedList *)malloc(sizeof(LinkedList));
    list->first = NULL;
    list->last = NULL;
    list->size = 0;
    return list;
}

void delLinkedList(LinkedList *list) {
    for (Node *iter = list->first; iter != NULL;) {
        Node *curr = iter;
        iter = iter->next;
        free(curr);
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

char *toStringLinkedList(LinkedList *list) {
    StringBuilder *sb = newStringBuilder();
    appendSB(sb, "[");
    appendSB(sb, " ");
    for (Node *iter = list->first; iter != NULL; iter = iter->next) {
        char v_str[256];
        sprintf(v_str, "%d", iter->v);
        appendSB(sb, v_str);
        appendSB(sb, " ");
    }
    appendSB(sb, "]");
    return toString(sb);
}