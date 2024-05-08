#include <stdio.h>
#include <stdlib.h>
#include <ctype.h> // for tolower

#define MAX_QUEUE_SIZE 100
#define MAX_STACK_SIZE 100

typedef int element;
typedef struct {
    element data[MAX_QUEUE_SIZE];
    int front, rear;
} QueueType;

typedef struct {
    int data[MAX_STACK_SIZE];
    int top;
} Stack;

void init_queue(QueueType* q) {
    q->front = q->rear = 0;
}

int is_queue_empty(QueueType* q) {
    return (q->front == q->rear);
}

void enqueue(QueueType* q, element item) {
    if ((q->rear + 1) % MAX_QUEUE_SIZE == q->front) {
        fprintf(stderr, "Queue is full\n");
        exit(EXIT_FAILURE);
    }
    q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
    q->data[q->rear] = item;
}

element dequeue(QueueType* q) {
    if (is_queue_empty(q)) {
        fprintf(stderr, "Queue is empty\n");
        exit(EXIT_FAILURE);
    }
    q->front = (q->front + 1) % MAX_QUEUE_SIZE;
    return q->data[q->front];
}

void init_stack(Stack* s) {
    s->top = -1;
}

int is_stack_empty(Stack* s) {
    return (s->top == -1);
}

void push(Stack* s, int item) {
    if (s->top >= MAX_STACK_SIZE - 1) {
        fprintf(stderr, "Stack overflow\n");
        exit(EXIT_FAILURE);
    }
    s->data[++(s->top)] = item;
}

int pop(Stack* s) {
    if (is_stack_empty(s)) {
        fprintf(stderr, "Stack underflow\n");
        exit(EXIT_FAILURE);
    }
    return s->data[(s->top)--];
}

int main() {
    int choice;
    char str[MAX_QUEUE_SIZE];
    QueueType q;
    Stack s;

    init_queue(&q);
    init_stack(&s);

    while (1) {
        printf("1. 회문 입력\n");
        printf("2. 회문 검사\n");
        printf("3. 종료\n");
        printf("메뉴를 선택하세요: ");
        scanf_s("%d", &choice);

        while (getchar() != '\n'); // Clear input buffer

        switch (choice) {
        case 1:
            printf("회문을 입력하세요: ");
            fgets(str, MAX_QUEUE_SIZE, stdin);
            break;
        case 2:
            // Check for palindrome
        {
            int i, j;
            // Preprocessing: Remove non-alphabetic characters and convert to lowercase
            for (i = 0, j = 0; str[i] != '\0'; i++) {
                if (isalpha(str[i])) {
                    str[j++] = tolower(str[i]);
                }
            }
            str[j] = '\0'; // Null terminate the string

            // Enqueue characters into the queue and push them into the stack
            for (i = 0; str[i] != '\0'; i++) {
                enqueue(&q, str[i]);
                push(&s, str[i]);
            }

            // Dequeue from the queue and pop from the stack, compare
            int is_palindrome = 1;
            while (!is_queue_empty(&q)) {
                if (dequeue(&q) != pop(&s)) {
                    is_palindrome = 0;
                    break;
                }
            }

            if (is_palindrome)
                printf("입력한 문자열은 회문입니다.\n");
            else
                printf("입력한 문자열은 회문이 아닙니다.\n");
        }
        break;
        case 3:
            exit(EXIT_SUCCESS);
        default:
            printf("잘못된 메뉴 선택\n");
            break;
        }
    }

    return 0;
}