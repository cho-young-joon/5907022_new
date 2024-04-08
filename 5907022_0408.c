//1�� ����
#include <stdio.h>

#define MAX_DEGREE 100

// ���׽��� ǥ���ϴ� ����ü
typedef struct {
    int degree;         // ���׽��� �ְ� ����
    double coefficient[MAX_DEGREE + 1]; // ���׽��� ��� �迭
} Polynomial;

// �� ���׽��� ���� ����ϴ� �Լ�
Polynomial multiplyPolynomials(Polynomial poly1, Polynomial poly2) {
    Polynomial result;
    int i, j;

    // ��� ���׽� �ʱ�ȭ
    result.degree = poly1.degree + poly2.degree;
    for (i = 0; i <= result.degree; i++)
        result.coefficient[i] = 0.0;

    // ���׽� ���� ���
    for (i = 0; i <= poly1.degree; i++) {
        for (j = 0; j <= poly2.degree; j++) {
            result.coefficient[i + j] += poly1.coefficient[i] * poly2.coefficient[j];
        }
    }

    return result;
}

// ���׽��� ����ϴ� �Լ�
void printPolynomial(Polynomial poly) {
    int i;
    int hasPrinted = 0; // ���� ��µǾ����� ���θ� ��Ÿ���� �÷���

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

    if (!hasPrinted) // ��µ� ���� ���� ��� ����� 0 ���
        printf("0");

    printf("\n");
}

int main() {
    Polynomial poly1 = { 3, {1, 2, 3, 4} };  // ���׽� 1: 4x^3 + 3x^2 + 2x + 1
    Polynomial poly2 = { 2, {8, 2, 3} };     // ���׽� 2: 3x^2 + 2x + 8

    Polynomial result = multiplyPolynomials(poly1, poly2);

    printf("���׽� 1: ");
    printPolynomial(poly1);
    printf("���׽� 2: ");
    printPolynomial(poly2);
    printf("���� ���: ");
    printPolynomial(result);

    return 0;
}










//2�� ����

//#include <stdio.h>
//
//#define MAX_DEGREE 100
//
//// ���׽��� ǥ���ϴ� ����ü
//typedef struct {
//    int degree;         // ���׽��� �ְ� ����
//    double coefficient[MAX_DEGREE + 1]; // ���׽��� ��� �迭
//} Polynomial;
//
//// �� ���׽��� ���� ����ϴ� �Լ�
//Polynomial multiplyPolynomials(Polynomial poly1, Polynomial poly2) {
//    Polynomial result;
//    int i, j;
//
//    // ��� ���׽� �ʱ�ȭ
//    result.degree = poly1.degree + poly2.degree;
//    for (i = 0; i <= result.degree; i++)
//        result.coefficient[i] = 0.0;
//
//    // ���׽� ���� ���
//    for (i = 0; i <= poly1.degree; i++) {
//        for (j = 0; j <= poly2.degree; j++) {
//            result.coefficient[i + j] += poly1.coefficient[i] * poly2.coefficient[j];
//        }
//    }
//
//    return result;
//}
//
//// ���׽��� ����ϴ� �Լ�
//void printPolynomial(Polynomial poly) {
//    int i;
//    int hasPrinted = 0; // ���� ��µǾ����� ���θ� ��Ÿ���� �÷���
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
//    if (!hasPrinted) // ��µ� ���� ���� ��� ����� 0 ���
//        printf("0");
//
//    printf("\n");
//}
//
//int main() {
//    Polynomial poly1 = { 6, {1, 0, 9, 5, 0, 0, 7} };  // ���׽� 1: 4x^3 + 3x^2 + 2x + 1
//    Polynomial poly2 = { 3, {10, 1, 2, 5} };     // ���׽� 2: 3x^2 + 2x + 8
//
//    Polynomial result = multiplyPolynomials(poly1, poly2);
//
//    printf("���׽� 1: ");
//    printPolynomial(poly1);
//    printf("���׽� 2: ");
//    printPolynomial(poly2);
//    printf("���� ���: ");
//    printPolynomial(result);
//
//    return 0;
//}