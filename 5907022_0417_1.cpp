//1번문제
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define MAX_SIZE 5

// 스택을 구현하는 구조체 정의
typedef struct {
    int items[MAX_SIZE];
    int top; // 스택의 최상위 항목의 인덱스를 나타내는 변수
} Stack;

// 스택을 초기화하는 함수
void initialize(Stack* s) {
    s->top = -1; // 스택이 비어있음을 나타내는 값을 설정
}

// 스택이 비어있는지 확인하는 함수
bool isEmpty(Stack* s) {
    return s->top == -1;
}

// 스택이 가득 차있는지 확인하는 함수
bool isFull(Stack* s) {
    return s->top == MAX_SIZE - 1;
}

// 스택에 원소를 추가하는 함수 (push)
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

// 스택에서 원소를 제거하고 반환하는 함수 (pop)
int pop(Stack* s) {
    if (isEmpty(s)) {
        printf("Stack empty! Cannot pop.\n");
        return -1; // 임의의 값 반환 (스택이 비어있는 경우)
    }
    else {
        int popped = s->items[s->top];
        s->top--;
        printf("Popped: %d\n", popped);
        return popped;
    }
}

int main() {
    srand(time(NULL)); // 난수 생성기 초기화

    Stack stack;
    initialize(&stack); // 스택 초기화

    for (int i = 0; i < 30; i++) {
        int random_number = rand() % 100 + 1; // 1부터 100 사이의 난수 생성
        if (random_number % 2 == 0) { // 짝수일 경우 push
            push(&stack, random_number);
        }
        else { // 홀수일 경우 pop
            pop(&stack);
        }
    }

    return 0;
}




