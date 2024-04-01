// 문제 1번 입니다
#include <stdio.h>

#define MAX_DEGREE 100

// 다항식을 표현하는 구조체 정의
typedef struct {
    int degree;         // 다항식의 차수
    float coef[MAX_DEGREE]; // 각 항의 계수를 저장하는 배열
} polynomial;

// 다항식의 곱셈을 계산하는 함수
polynomial mult(polynomial A, polynomial B);

int main() {
    polynomial a = { 3, {4,3,2,1} }; // 7x^6 + 5x^3 + 9x^2 + 1
    polynomial b = { 2, {3,2,8} };       // 5x^3 + 2x^2 + x + 10
    polynomial c;

    // 다항식 곱셈 수행
    c = mult(a, b);

    // 결과 출력
    printf("%d차 ", c.degree);
    for (int i = 0; i < c.degree + 1; i++) {
        if (c.coef[i] != 0) {
            printf("%.1fx^%d ", c.coef[i], c.degree - i);
            if (i < c.degree) {
                printf("+ ");
            }
        }
    }

    printf("\n");

    return 0;
}

// 다항식의 곱셈을 계산하는 함수
polynomial mult(polynomial A, polynomial B) {
    polynomial C;
    int i, j;

    // 결과 다항식의 계수를 0으로 초기화
    for (i = 0; i < A.degree + B.degree + 1; i++)
        C.coef[i] = 0;
    // 결과 다항식의 차수 설정
    C.degree = A.degree + B.degree;

    // 다항식 곱셈 수행
    for (i = 0; i < A.degree + 1; i++)
        for (j = 0; j < B.degree + 1; j++)
            C.coef[i + j] += A.coef[i] * B.coef[j];

    return C; // 결과 다항식 반환
}


//---------------------------------------------------------------------------------------------------------







// 문제 2번 입니다.





//#include <stdio.h>
//
//#define MAX_DEGREE 100
//
//// 다항식을 표현하는 구조체 정의
//typedef struct {
//    int degree;         // 다항식의 차수
//    float coef[MAX_DEGREE]; // 각 항의 계수를 저장하는 배열
//} polynomial;
//
//// 다항식의 곱셈을 계산하는 함수
//polynomial mult(polynomial A, polynomial B);
//
//int main() {
//    polynomial a = { 6, {7, 0, 0, 5, 9, 0, 1} }; // 7x^6 + 5x^3 + 9x^2 + 1
//    polynomial b = { 3, {5, 2, 1, 10} };       // 5x^3 + 2x^2 + x + 10
//    polynomial c;
//
//    // 다항식 곱셈 수행
//    c = mult(a, b);
//
//    // 결과 출력
//    printf("%d차 ", c.degree);
//    for (int i = 0; i < c.degree + 1; i++) {
//        if (c.coef[i] != 0) {
//            printf("%.1fx^%d ", c.coef[i], c.degree - i);
//            if (i < c.degree) {
//                printf("+ ");
//            }
//        }
//    }
//
//    printf("\n");
//
//    return 0;
//}
//
//// 다항식의 곱셈을 계산하는 함수
//polynomial mult(polynomial A, polynomial B) {
//    polynomial C;
//    int i, j;
//
//    // 결과 다항식의 계수를 0으로 초기화
//    for (i = 0; i < A.degree + B.degree + 1; i++)
//        C.coef[i] = 0;
//    // 결과 다항식의 차수 설정
//    C.degree = A.degree + B.degree;
//
//    // 다항식 곱셈 수행
//    for (i = 0; i < A.degree + 1; i++)
//        for (j = 0; j < B.degree + 1; j++)
//            C.coef[i + j] += A.coef[i] * B.coef[j];
//
//    return C; // 결과 다항식 반환
//}