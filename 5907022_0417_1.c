////1번문제
//#include <stdio.h>
//#include <stdlib.h>
//#include <stdbool.h>
//#include <time.h>
//
//#define MAX_SIZE 5
//
//// 스택을 구현하는 구조체 정의
//typedef struct {
//    int items[MAX_SIZE];
//    int top; // 스택의 최상위 항목의 인덱스를 나타내는 변수
//} Stack;
//
//// 스택을 초기화하는 함수
//void initialize(Stack* s) {
//    s->top = -1; // 스택이 비어있음을 나타내는 값을 설정
//}
//
//// 스택이 비어있는지 확인하는 함수
//bool isEmpty(Stack* s) {
//    return s->top == -1;
//}
//
//// 스택이 가득 차있는지 확인하는 함수
//bool isFull(Stack* s) {
//    return s->top == MAX_SIZE - 1;
//}
//
//// 스택에 원소를 추가하는 함수 (push)
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
//// 스택에서 원소를 제거하고 반환하는 함수 (pop)
//int pop(Stack* s) {
//    if (isEmpty(s)) {
//        printf("Stack empty! Cannot pop.\n");
//        return -1; // 임의의 값 반환 (스택이 비어있는 경우)
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
//    srand(time(NULL)); // 난수 생성기 초기화
//
//    Stack stack;
//    initialize(&stack); // 스택 초기화
//
//    for (int i = 0; i < 30; i++) {
//        int random_number = rand() % 100 + 1; // 1부터 100 사이의 난수 생성
//        if (random_number % 2 == 0) { // 짝수일 경우 push
//            push(&stack, random_number);
//        }
//        else { // 홀수일 경우 pop
//            pop(&stack);
//        }
//    }
//
//    return 0;
//}


//2번

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define INITIAL_CAPACITY 5

// 스택을 구현하는 구조체 정의
typedef struct Stack {
    int* items;
    int top;
    int capacity;
} Stack;

// 스택을 초기화하는 함수
void initialize(Stack* s) {
    s->top = -1;
    s->capacity = INITIAL_CAPACITY;
    s->items = (int*)malloc(s->capacity * sizeof(int));
    if (s->items == NULL) {
        printf("Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }
}

// 스택이 비어있는지 확인하는 함수
bool isEmpty(Stack* s) {
    return s->top == -1;
}

// 스택이 가득 차있는지 확인하는 함수
bool isFull(Stack* s) {
    return s->top == s->capacity - 1;
}

// 스택에 원소를 추가하는 함수 (push)
void push(Stack* s, int value) {
    if (isFull(s)) {
        int* new_items = (int*)malloc(s->capacity * 2 * sizeof(int));
        if (new_items == NULL) {
            printf("Memory allocation failed.\n");
            exit(EXIT_FAILURE);
        }

        // 기존 항목을 새 메모리로 복사
        for (int i = 0; i <= s->top; i++) {
            new_items[i] = s->items[i];
        }

        // 이전 메모리 해제 및 포인터 업데이트
        free(s->items);
        s->items = new_items;
        s->capacity *= 2;
    }

    s->top++;
    s->items[s->top] = value;
    printf("Pushed: %d\n", value);
}

// 스택에서 원소를 제거하고 반환하는 함수 (pop)
int pop(Stack* s) {
    if (isEmpty(s)) {
        // 비어있는 스택 처리 (예: 예외 발생)
        return -1; // 임의의 값 반환 (스택이 비어있는 경우)
    }

    int popped = s->items[s->top];
    s->top--;
    printf("Popped: %d\n", popped);
    return popped;
}

// 스택에서 특정 값의 인덱스를 검색하는 함수
int search(Stack* s, int value) {
    for (int i = s->top; i >= 0; i--) {
        if (s->items[i] == value) {
            return i; // 인덱스 반환
        }
    }
    return -1; // 값을 찾지 못한 경우
}

int main() {
    srand((unsigned int)time(NULL)); // 난수 생성기 초기화

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

    // 스택에서 30을 검색
    int search_result = search(&stack, 30);
    if (search_result == -1) {
        printf("30은 스택에 존재하지 않습니다.\n");
    }
    else {
        printf("30은 스택의 %d번째 위치에 있습니다.\n", search_result + 1);
    }

    free(stack.items); // 동적으로 할당된 메모리 해제

    return 0;
}