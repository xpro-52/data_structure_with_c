#include <stdio.h>
#include <stdlib.h>
#include "binary_search_tree.h"


void test() {
    BST *bst = newBST();
    int data[] = {9, 5, 7, 3, 8, 2, 1};
    for (int i = 0; i < 7; i++)
        put(bst, data[i], data[i]);
    
    printf("--- init ---\n");
    char *str = toStringTree(bst);
    printf("%s\n", str);
    free(str);

    for (int i = 0; i < 7; i++) {
        printf("--- remove %d ---\n", data[i]);
        removeEntry(bst, data[i]);
        char* str = toStringTree(bst);
        printf("%s\n", str);
        free(str);
    }
    
}


int main(void) {

    test();
    
    return 0;
}
