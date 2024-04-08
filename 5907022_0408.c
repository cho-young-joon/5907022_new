//1번 문제
#include <stdio.h>

#define MAX_DEGREE 100

// 다항식을 표현하는 구조체
typedef struct {
    int degree;         // 다항식의 최고 차수
    double coefficient[MAX_DEGREE + 1]; // 다항식의 계수 배열
} Polynomial;

// 두 다항식의 곱을 계산하는 함수
Polynomial multiplyPolynomials(Polynomial poly1, Polynomial poly2) {
    Polynomial result;
    int i, j;

    // 결과 다항식 초기화
    result.degree = poly1.degree + poly2.degree;
    for (i = 0; i <= result.degree; i++)
        result.coefficient[i] = 0.0;

    // 다항식 곱셈 계산
    for (i = 0; i <= poly1.degree; i++) {
        for (j = 0; j <= poly2.degree; j++) {
            result.coefficient[i + j] += poly1.coefficient[i] * poly2.coefficient[j];
        }
    }

    return result;
}

// 다항식을 출력하는 함수
void printPolynomial(Polynomial poly) {
    int i;
    int hasPrinted = 0; // 항이 출력되었는지 여부를 나타내는 플래그

    for (i = poly.degree; i >= 0; i--) {
        if (poly.coefficient[i] != 0.0) {
            if (!hasPrinted) {
                printf("%.1fx^%d", poly.coefficient[i], i);
                hasPrinted = 1;
            }
            else {
                printf(" + ");
                printf("%.1fx^%d", poly.coefficient[i], i);
            }
        }
    }

    if (!hasPrinted) // 출력된 항이 없는 경우 상수항 0 출력
        printf("0");

    printf("\n");
}

int main() {
    Polynomial poly1 = { 3, {1, 2, 3, 4} };  // 다항식 1: 4x^3 + 3x^2 + 2x + 1
    Polynomial poly2 = { 2, {8, 2, 3} };     // 다항식 2: 3x^2 + 2x + 8

    Polynomial result = multiplyPolynomials(poly1, poly2);

    printf("다항식 1: ");
    printPolynomial(poly1);
    printf("다항식 2: ");
    printPolynomial(poly2);
    printf("곱셈 결과: ");
    printPolynomial(result);

    return 0;
}










//2번 문제

//#include <stdio.h>
//
//#define MAX_DEGREE 100
//
//// 다항식을 표현하는 구조체
//typedef struct {
//    int degree;         // 다항식의 최고 차수
//    double coefficient[MAX_DEGREE + 1]; // 다항식의 계수 배열
//} Polynomial;
//
//// 두 다항식의 곱을 계산하는 함수
//Polynomial multiplyPolynomials(Polynomial poly1, Polynomial poly2) {
//    Polynomial result;
//    int i, j;
//
//    // 결과 다항식 초기화
//    result.degree = poly1.degree + poly2.degree;
//    for (i = 0; i <= result.degree; i++)
//        result.coefficient[i] = 0.0;
//
//    // 다항식 곱셈 계산
//    for (i = 0; i <= poly1.degree; i++) {
//        for (j = 0; j <= poly2.degree; j++) {
//            result.coefficient[i + j] += poly1.coefficient[i] * poly2.coefficient[j];
//        }
//    }
//
//    return result;
//}
//
//// 다항식을 출력하는 함수
//void printPolynomial(Polynomial poly) {
//    int i;
//    int hasPrinted = 0; // 항이 출력되었는지 여부를 나타내는 플래그
//
//    for (i = poly.degree; i >= 0; i--) {
//        if (poly.coefficient[i] != 0.0) {
//            if (!hasPrinted) {
//                printf("%.1fx^%d", poly.coefficient[i], i);
//                hasPrinted = 1;
//            }
//            else {
//                printf(" + ");
//                printf("%.1fx^%d", poly.coefficient[i], i);
//            }
//        }
//    }
//
//    if (!hasPrinted) // 출력된 항이 없는 경우 상수항 0 출력
//        printf("0");
//
//    printf("\n");
//}
//
//int main() {
//    Polynomial poly1 = { 6, {1, 0, 9, 5, 0, 0, 7} };  // 다항식 1: 4x^3 + 3x^2 + 2x + 1
//    Polynomial poly2 = { 3, {10, 1, 2, 5} };     // 다항식 2: 3x^2 + 2x + 8
//
//    Polynomial result = multiplyPolynomials(poly1, poly2);
//
//    printf("다항식 1: ");
//    printPolynomial(poly1);
//    printf("다항식 2: ");
//    printPolynomial(poly2);
//    printf("곱셈 결과: ");
//    printPolynomial(result);
//
//    return 0;
//}