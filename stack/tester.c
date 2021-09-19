#include <stdio.h>

#include "stack.h"


int test() {
    Stack *s = newStack();
    int data[] = {1, 2, 3, 4, 5};

    for (int i = 0; i < 5; i++)
        push(s, data[i]);

    for (int i = 4; i >= 0; i--) {
        if (pop(s) != data[i]) {
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
gcc -o tester tester.c .\stack.c ..\linked_list\linked_list.c; .\tester.exe  
*/