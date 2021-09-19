#include <stdio.h>

#include "binary_search_tree.h"


void test() {
    BST *bst = newBST();
    int data[] = {9, 5, 7, 3, 8, 2, 1};
    for (int i = 0; i < 7; i++)
        put(bst, data[i], data[i]);
    
    printf("--- init ---\n");
    printTree(bst);

    for (int i = 0; i < 7; i++) {
        printf("--- remove %d ---\n", data[i]);
        removeEntry(bst, data[i]);
        printTree(bst);
    }
    
}


int main(void) {

    test();
    
    return 0;
}

/*
gcc -o tester tester.c .\binary_search_tree.c ..\linked_list\linked_list.c; .\tester.exe
*/