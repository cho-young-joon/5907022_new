//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//
//#define MAX_EXPRESSION_LENGTH 100
//
//typedef int element;
//typedef struct StackType {
//    element* data;
//    int capacity;
//    int top;
//} StackType;
//
//// Function prototypes
//void init(StackType* s, int capacity);
//int is_empty(StackType* s);
//int is_full(StackType* s);
//void push(StackType* s, element item);
//element pop(StackType* s);
//int eval_postfix(char expr[]);
//void infix_to_postfix(char infix[], char postfix[]);
//
//void init(StackType* s, int capacity) {
//    s->data = (element*)malloc(sizeof(element) * capacity);
//    s->capacity = capacity;
//    s->top = -1;
//}
//
//int is_empty(StackType* s) {
//    return (s->top == -1);
//}
//
//int is_full(StackType* s) {
//    return (s->top == (s->capacity - 1));
//}
//
//void push(StackType* s, element item) {
//    if (is_full(s)) {
//        printf("Stack overflow\n");
//        return;
//    }
//    s->data[++(s->top)] = item;
//}
//
//element pop(StackType* s) {
//    if (is_empty(s)) {
//        printf("Stack underflow\n");
//        exit(EXIT_FAILURE);
//    }
//    return s->data[(s->top)--];
//}
//
//int eval_postfix(char expr[]) {
//    int len;
//    StackType s;
//    init(&s, 20);
//    len = strlen(expr);
//    for (int i = 0; i < len; i++) {
//        int ch = expr[i];
//        int value;
//        int op1, op2;
//        if ((ch == '+') || (ch == '-') || (ch == '*') || (ch == '/')) {
//            op1 = pop(&s);
//            op2 = pop(&s);
//            
//            switch (ch) {
//            case '+': push(&s, op2 + op1); break;
//            case '-': push(&s, op2 - op1); break;
//            case '*': push(&s, op2 * op1); break;
//            case '/': push(&s, op2 / op1); break;
//            default:;
//            }
//        }
//        else if ((ch >= '0') && (ch <= '9')) {
//            value = ch - '0';
//            push(&s, value);
//        }
//        else {
//            printf("Abnormal character in expression\n");
//        }
//    }
//    return pop(&s);
//}
//
//void infix_to_postfix(char infix[], char postfix[]) {
//    // Function implementation goes here
//}
//
//int main(int argc, char* argv[]) {
//    char infixExpression[MAX_EXPRESSION_LENGTH];
//    char postfixExpression[MAX_EXPRESSION_LENGTH];
//
//    while (1) {
//        printf("다음과 같은 메뉴로 동작하는 프로그램입니다 : \n");
//        printf("1. 중위식을 입력 받음 \n");
//        printf("2. 중위식을 후위식으로 변환\n");
//        printf("3. 후위식을 계산 \n");
//        printf("4. 종료\n");
//        printf("메뉴를 선택하세요 : ");
//        int getchar(void);
//
//        int choice;
//        scanf_s("%d", &choice);
//         
//
//
//        switch (choice) {
//        case 1:
//            printf("중위식 입력하세요 : ");
//            getchar();
//            fgets(infixExpression, sizeof(infixExpression), stdin);
//            printf("입력된 중위식 : %s\n", infixExpression);
//            break;
//
//        case 2:
//            // Convert infix to postfix
//            infix_to_postfix(infixExpression, postfixExpression);
//            printf("후위식 변환 결과: %s\n", postfixExpression);
//            break;
//
//        case 3:
//            // Evaluate postfix expression
//            printf("계산 결과: %d\n", eval_postfix(postfixExpression));
//            break;
//
//        case 4:
//            printf("프로그램을 종료합니다 \n");
//            exit(0);
//
//        default:
//            printf("잘못된 메뉴 선택입니다. 다시 선택하세요 \n");
//            break;
//        }
//    }
//    return 0;
//}


