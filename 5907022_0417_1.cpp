//1������
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define MAX_SIZE 5

// ������ �����ϴ� ����ü ����
typedef struct {
    int items[MAX_SIZE];
    int top; // ������ �ֻ��� �׸��� �ε����� ��Ÿ���� ����
} Stack;

// ������ �ʱ�ȭ�ϴ� �Լ�
void initialize(Stack* s) {
    s->top = -1; // ������ ��������� ��Ÿ���� ���� ����
}

// ������ ����ִ��� Ȯ���ϴ� �Լ�
bool isEmpty(Stack* s) {
    return s->top == -1;
}

// ������ ���� ���ִ��� Ȯ���ϴ� �Լ�
bool isFull(Stack* s) {
    return s->top == MAX_SIZE - 1;
}

// ���ÿ� ���Ҹ� �߰��ϴ� �Լ� (push)
void push(Stack* s, int value) {
    if (isFull(s)) {
        printf("Stack full! Cannot push %d.\n", value);
    }
    else {
        s->top++;
        s->items[s->top] = value;
        printf("Pushed: %d\n", value);
    }
}

// ���ÿ��� ���Ҹ� �����ϰ� ��ȯ�ϴ� �Լ� (pop)
int pop(Stack* s) {
    if (isEmpty(s)) {
        printf("Stack empty! Cannot pop.\n");
        return -1; // ������ �� ��ȯ (������ ����ִ� ���)
    }
    else {
        int popped = s->items[s->top];
        s->top--;
        printf("Popped: %d\n", popped);
        return popped;
    }
}

int main() {
    srand(time(NULL)); // ���� ������ �ʱ�ȭ

    Stack stack;
    initialize(&stack); // ���� �ʱ�ȭ

    for (int i = 0; i < 30; i++) {
        int random_number = rand() % 100 + 1; // 1���� 100 ������ ���� ����
        if (random_number % 2 == 0) { // ¦���� ��� push
            push(&stack, random_number);
        }
        else { // Ȧ���� ��� pop
            pop(&stack);
        }
    }

    return 0;
}




