#include <stdio.h>
#include <stdlib.h>

#include "binary_search_tree.h"

typedef struct entry {
    int k;
    int v;
    struct entry *left;
    struct entry *right;
} Entry;

Entry *__newEntry(int key, int value) {
    Entry *e = malloc(sizeof(Entry));
    e->k = key;
    e->v = value;
    e->left = NULL;
    e->right = NULL;
    return e;
}


typedef struct bst {
    Entry *root;
    int size;
} BST;

BST *newBST() {
    BST *tree = (BST *)malloc(sizeof(BST));
    tree->root = NULL;
    tree->size = 0;
    return tree;
}

Entry *__get(Entry *e, int key);
int get(BST *tree, int key) {
    Entry *e = __get(tree->root, key);
    return e->v;
}

Entry  *__get(Entry *e, int key) {
    if (e == NULL)
        exit(-1);
    else if (key == e->k)
        return e;
    else if (key < e->k)
        return __get(e->left, key);
    else
        return __get(e->right, key);
} 

Entry *__put(Entry *e, int key, int value);
void put(BST *tree, int key, int value) {
    tree->root = __put(tree->root, key, value);
}

Entry *__put(Entry *e, int key, int value) {
    if (e == NULL)
        e = __newEntry(key, value);
    else if (key < e->k)
        e->left = __put(e->left, key, value);
    else
        e->right = __put(e->right, key, value);
    return e;
} 

Entry *__removeEntry(Entry *e, int key);
Entry *__deleteEntry(Entry *e);
Entry *__maxEntry(Entry *e);
void removeEntry(BST *tree, int key) {
    tree->root = __removeEntry(tree->root, key);
}

Entry *__removeEntry(Entry *e, int key) {
    if (e == NULL);
    else if (key == e->k)
        e = __deleteEntry(e);
    else if (key < e->k)
        e->left = __removeEntry(e->left, key);
    else
        e->right = __removeEntry(e->right, key);
    return e;
}

Entry *__maxEntry(Entry *e) {
    while (e->right != NULL) 
        e = e->right;
    return e;
}

Entry *__deleteEntry(Entry *e) {
    if (e->left != NULL) {
        
        if (e->right != NULL) {
            Entry* max = __maxEntry(e->left);
            max->right = e->right;
            free(e);
            return max;

        } else {
            Entry *left = e->left;
            free(e);
            return left;
        }

    } else {

        if (e->right != NULL) {
            Entry *right = e->right;
            free(e);
            return right;

        } else {
            free(e);
            return NULL;
        }
    }
}

void inorder(Entry *iter, LinkedList *list) {
    if (iter != NULL) {
        inorder(iter->left, list);
        addLinkNode(list, iter->v);
        inorder(iter->right, list);
    }
}

int treesize(BST *tree) {
    return tree->size;
}

char *toStringTree(BST *tree) {
    LinkedList *list = newLinkedList();
    inorder(tree->root, list);
    char *string = toStringLinkedList(list);
    delLinkedList(list);
    return string;
}


