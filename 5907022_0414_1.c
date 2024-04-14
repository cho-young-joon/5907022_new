#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 5

int stack[MAX_SIZE];
int top = -1;

void push(int data) {
    if (top == MAX_SIZE - 1) {
        printf("Stack Overflow: Cannot push %d\n", data);
    }
    else {
        stack[++top] = data;
        printf("Even push: %d | Stack elements: ", data);
        for (int i = 0; i <= top; i++) {
            printf("%d ", stack[i]);
        }
        printf("\n");
    }
}

void pop() {
    if (top == -1) {
        printf("Stack Underflow: Cannot pop from empty stack\n");
    }
    else {
        int popped = stack[top--];
        printf("Pop: %d | Stack elements: ", popped);
        for (int i = 0; i <= top; i++) {
            printf("%d ", stack[i]);
        }
        printf("\n");
    }
}

int main() {
    srand(time(NULL));

    for (int i = 0; i < 30; i++) {
        int rand_num = rand() % 100 + 1;
        printf("Current rand_num: %d\n", rand_num);

        if (rand_num % 2 == 0) {
            push(rand_num);
        }
        else {
            pop();
        }
    }

    return 0;
}