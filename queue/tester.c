#include <stdio.h>

#include "queue.h"


int test() {
    Queue *q = newQueue();
    int data[] = {1, 2, 3, 4, 5};

    for (int i = 0; i < 5; i++)
        enq(q, data[i]);

    for (int i = 0; i < 5; i++) {
        if (deq(q) != data[i]) {
            printf("%d\n", i);
            return 0;
        }
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
gcc -o tester tester.c queue.c ..\linked_list\linked_list.c; .\tester.exe
*/