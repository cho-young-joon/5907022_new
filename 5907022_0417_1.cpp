////1������
//#include <stdio.h>
//#include <stdlib.h>
//#include <stdbool.h>
//#include <time.h>
//
//#define MAX_SIZE 5
//
//// ������ �����ϴ� ����ü ����
//typedef struct {
//    int items[MAX_SIZE];
//    int top; // ������ �ֻ��� �׸��� �ε����� ��Ÿ���� ����
//} Stack;
//
//// ������ �ʱ�ȭ�ϴ� �Լ�
//void initialize(Stack* s) {
//    s->top = -1; // ������ ��������� ��Ÿ���� ���� ����
//}
//
//// ������ ����ִ��� Ȯ���ϴ� �Լ�
//bool isEmpty(Stack* s) {
//    return s->top == -1;
//}
//
//// ������ ���� ���ִ��� Ȯ���ϴ� �Լ�
//bool isFull(Stack* s) {
//    return s->top == MAX_SIZE - 1;
//}
//
//// ���ÿ� ���Ҹ� �߰��ϴ� �Լ� (push)
//void push(Stack* s, int value) {
//    if (isFull(s)) {
//        printf("Stack full! Cannot push %d.\n", value);
//    }
//    else {
//        s->top++;
//        s->items[s->top] = value;
//        printf("Pushed: %d\n", value);
//    }
//}
//
//// ���ÿ��� ���Ҹ� �����ϰ� ��ȯ�ϴ� �Լ� (pop)
//int pop(Stack* s) {
//    if (isEmpty(s)) {
//        printf("Stack empty! Cannot pop.\n");
//        return -1; // ������ �� ��ȯ (������ ����ִ� ���)
//    }
//    else {
//        int popped = s->items[s->top];
//        s->top--;
//        printf("Popped: %d\n", popped);
//        return popped;
//    }
//}
//
//int main() {
//    srand(time(NULL)); // ���� ������ �ʱ�ȭ
//
//    Stack stack;
//    initialize(&stack); // ���� �ʱ�ȭ
//
//    for (int i = 0; i < 30; i++) {
//        int random_number = rand() % 100 + 1; // 1���� 100 ������ ���� ����
//        if (random_number % 2 == 0) { // ¦���� ��� push
//            push(&stack, random_number);
//        }
//        else { // Ȧ���� ��� pop
//            pop(&stack);
//        }
//    }
//
//    return 0;
//}


//2��

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define INITIAL_CAPACITY 5

// ������ �����ϴ� ����ü ����
typedef struct Stack {
    int* items;
    int top;
    int capacity;
} Stack;

// ������ �ʱ�ȭ�ϴ� �Լ�
void initialize(Stack* s) {
    s->top = -1;
    s->capacity = INITIAL_CAPACITY;
    s->items = (int*)malloc(s->capacity * sizeof(int));
    if (s->items == NULL) {
        printf("Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }
}

// ������ ����ִ��� Ȯ���ϴ� �Լ�
bool isEmpty(Stack* s) {
    return s->top == -1;
}

// ������ ���� ���ִ��� Ȯ���ϴ� �Լ�
bool isFull(Stack* s) {
    return s->top == s->capacity - 1;
}

// ���ÿ� ���Ҹ� �߰��ϴ� �Լ� (push)
void push(Stack* s, int value) {
    if (isFull(s)) {
        int* new_items = (int*)malloc(s->capacity * 2 * sizeof(int));
        if (new_items == NULL) {
            printf("Memory allocation failed.\n");
            exit(EXIT_FAILURE);
        }

        // ���� �׸��� �� �޸𸮷� ����
        for (int i = 0; i <= s->top; i++) {
            new_items[i] = s->items[i];
        }

        // ���� �޸� ���� �� ������ ������Ʈ
        free(s->items);
        s->items = new_items;
        s->capacity *= 2;
    }

    s->top++;
    s->items[s->top] = value;
    printf("Pushed: %d\n", value);
}

// ���ÿ��� ���Ҹ� �����ϰ� ��ȯ�ϴ� �Լ� (pop)
int pop(Stack* s) {
    if (isEmpty(s)) {
        // ����ִ� ���� ó�� (��: ���� �߻�)
        return -1; // ������ �� ��ȯ (������ ����ִ� ���)
    }

    int popped = s->items[s->top];
    s->top--;
    printf("Popped: %d\n", popped);
    return popped;
}

// ���ÿ��� Ư�� ���� �ε����� �˻��ϴ� �Լ�
int search(Stack* s, int value) {
    for (int i = s->top; i >= 0; i--) {
        if (s->items[i] == value) {
            return i; // �ε��� ��ȯ
        }
    }
    return -1; // ���� ã�� ���� ���
}

int main() {
    srand((unsigned int)time(NULL)); // ���� ������ �ʱ�ȭ

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

    // ���ÿ��� 30�� �˻�
    int search_result = search(&stack, 30);
    if (search_result == -1) {
        printf("30�� ���ÿ� �������� �ʽ��ϴ�.\n");
    }
    else {
        printf("30�� ������ %d��° ��ġ�� �ֽ��ϴ�.\n", search_result + 1);
    }

    free(stack.items); // �������� �Ҵ�� �޸� ����

    return 0;
}