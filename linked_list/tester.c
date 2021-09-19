#include <stdio.h>
#include "linked_list.h"



int test() {
    LinkedList *l = newLinkedList();
    int data[] = {1, 2, 3, 4, 5};
    for (int i = 0; i < 5; i++)
        addLinkNode(l, data[i]);

    for (int i = 0; i < 5; i++) {
        if (removeLinkedNode(l, data[i]) != data[i])
            return 0;
    }

    return 1;
}

int main(void) {
    
    if (test())
        printf("Success");
    else
        printf("Failure");
    
    return 0;
}

/*
gcc -o tester tester.c .\linked_list.c; .\tester.exe
*/