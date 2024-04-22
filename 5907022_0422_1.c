#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

// Stack structure definition
typedef struct Stack {
    int top;
    int data[100];
} Stack;

// Stack initialization function
void initializeStack(Stack* s) {
    s->top = -1;
}

// Check if stack is empty
int isEmptyStack(Stack* s) {
    return (s->top == -1);
}

// Check if stack is full
int isFullStack(Stack* s) {
    return (s->top == 99);
}

// Push element onto stack
void pushStack(Stack* s, int value) {
    if (isFullStack(s)) {
        printf("Stack Overflow\n");
        exit(EXIT_FAILURE);
    }
    else {
        s->data[++(s->top)] = value;
    }
}

// Pop element from stack
int popStack(Stack* s) {
    if (isEmptyStack(s)) {
        printf("Stack Underflow\n");
        exit(EXIT_FAILURE);
    }
    else {
        return s->data[(s->top)--];
    }
}

// Evaluate postfix expression
int evaluatePostfix(char* expr) {
    Stack s;
    initializeStack(&s);
    int i, operand1, operand2, result;

    for (i = 0; ; i++) {
        if (expr[i] == '\0' || expr[i] == '\n') // 수정된 부분: 후위 표기식의 끝에 도달하면 종료
            break;
        if (isdigit(expr[i])) {
            pushStack(&s, expr[i] - '0');
        }
        else if (expr[i] == ' ') {
            continue;
        }
        else {
            operand2 = popStack(&s);
            operand1 = popStack(&s);

            switch (expr[i]) {
            case '+':
                pushStack(&s, operand1 + operand2);
                break;
            case '-':
                pushStack(&s, operand1 - operand2);
                break;
            case '*':
                pushStack(&s, operand1 * operand2);
                break;
            case '/':
                if (operand2 != 0) {
                    pushStack(&s, operand1 / operand2);
                }
                else {
                    printf("Error: Division by zero\n");
                    exit(EXIT_FAILURE);
                }
                break;
            default:
                printf("Error: Invalid operator\n");
                exit(EXIT_FAILURE);
            }
        }
    }

    result = popStack(&s);
    if (!isEmptyStack(&s)) {
        printf("Error: Too many operands\n");
        exit(EXIT_FAILURE);
    }

    return result;
}

int main() {
    char postfixExpr[100];
    int result;

    printf("Enter postfix expression: ");
    fgets(postfixExpr, sizeof(postfixExpr), stdin);

    result = evaluatePostfix(postfixExpr);

    printf("Result: %d\n", result);

    return 0;
}