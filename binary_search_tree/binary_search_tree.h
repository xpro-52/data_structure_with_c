#ifndef BINARY_TREE_H
#define BINARY_TREE_H

#include "../linked_list/linked_list.h"

typedef struct entry Entry;

Entry *newEntry(int key, int value);


typedef struct bst BST;

BST *newBST();

int get(BST *tree, int key);

void put(BST *tree, int key, int value);

void inorder(Entry *root, LinkedList *list);

int treesize(BST *tree);

void printTree(BST *tree);

void removeEntry(BST *tree, int key);

#endif