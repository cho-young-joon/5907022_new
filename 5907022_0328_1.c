// ���� 1�� �Դϴ�
#include <stdio.h>

#define MAX_DEGREE 100

// ���׽��� ǥ���ϴ� ����ü ����
typedef struct {
    int degree;         // ���׽��� ����
    float coef[MAX_DEGREE]; // �� ���� ����� �����ϴ� �迭
} polynomial;

// ���׽��� ������ ����ϴ� �Լ�
polynomial mult(polynomial A, polynomial B);

int main() {
    polynomial a = { 3, {4,3,2,1} }; // 7x^6 + 5x^3 + 9x^2 + 1
    polynomial b = { 2, {3,2,8} };       // 5x^3 + 2x^2 + x + 10
    polynomial c;

    // ���׽� ���� ����
    c = mult(a, b);

    // ��� ���
    printf("%d�� ", c.degree);
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

// ���׽��� ������ ����ϴ� �Լ�
polynomial mult(polynomial A, polynomial B) {
    polynomial C;
    int i, j;

    // ��� ���׽��� ����� 0���� �ʱ�ȭ
    for (i = 0; i < A.degree + B.degree + 1; i++)
        C.coef[i] = 0;
    // ��� ���׽��� ���� ����
    C.degree = A.degree + B.degree;

    // ���׽� ���� ����
    for (i = 0; i < A.degree + 1; i++)
        for (j = 0; j < B.degree + 1; j++)
            C.coef[i + j] += A.coef[i] * B.coef[j];

    return C; // ��� ���׽� ��ȯ
}


//---------------------------------------------------------------------------------------------------------







// ���� 2�� �Դϴ�.





//#include <stdio.h>
//
//#define MAX_DEGREE 100
//
//// ���׽��� ǥ���ϴ� ����ü ����
//typedef struct {
//    int degree;         // ���׽��� ����
//    float coef[MAX_DEGREE]; // �� ���� ����� �����ϴ� �迭
//} polynomial;
//
//// ���׽��� ������ ����ϴ� �Լ�
//polynomial mult(polynomial A, polynomial B);
//
//int main() {
//    polynomial a = { 6, {7, 0, 0, 5, 9, 0, 1} }; // 7x^6 + 5x^3 + 9x^2 + 1
//    polynomial b = { 3, {5, 2, 1, 10} };       // 5x^3 + 2x^2 + x + 10
//    polynomial c;
//
//    // ���׽� ���� ����
//    c = mult(a, b);
//
//    // ��� ���
//    printf("%d�� ", c.degree);
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
//// ���׽��� ������ ����ϴ� �Լ�
//polynomial mult(polynomial A, polynomial B) {
//    polynomial C;
//    int i, j;
//
//    // ��� ���׽��� ����� 0���� �ʱ�ȭ
//    for (i = 0; i < A.degree + B.degree + 1; i++)
//        C.coef[i] = 0;
//    // ��� ���׽��� ���� ����
//    C.degree = A.degree + B.degree;
//
//    // ���׽� ���� ����
//    for (i = 0; i < A.degree + 1; i++)
//        for (j = 0; j < B.degree + 1; j++)
//            C.coef[i + j] += A.coef[i] * B.coef[j];
//
//    return C; // ��� ���׽� ��ȯ
//}