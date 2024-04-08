#include <stdio.h>
#include <stdlib.h>

// ���׽��� �� ���� ǥ���ϴ� ����ü
typedef struct {
    float coefficient; // ���
    int exponent;     // ����
} Term;

// ���׽��� ǥ���ϴ� ����ü
typedef struct {
    int total_terms;  // �� ���� ��
    Term* terms;      // �׵��� �迭�� ����Ű�� ������
} Polynomial;

// ���׽��� �Է��ϴ� �Լ�
void input_polynomial(Polynomial* poly) {
    printf("���׽��� �� ���� ���� �Է��Ͻÿ�: ");
    scanf_s("%d", &poly->total_terms);

    // �޸� ���� �Ҵ�
    poly->terms = (Term*)malloc(poly->total_terms * sizeof(Term));

    printf("�����׺��� ���ʷ� ����� ������ �Է��Ͻÿ�:\n");
    for (int i = 0; i < poly->total_terms; i++) {
        printf("[���, ����] ");
        scanf_s("%f %d", &poly->terms[i].coefficient, &poly->terms[i].exponent);
    }
}

// ���׽��� ����ϴ� �Լ�
void print_polynomial(Polynomial* poly) {
    printf("�Էµ� ���׽��� ������ �����ϴ�: ");
    for (int i = 0; i < poly->total_terms; i++) {
        printf("%.1fx^%d", poly->terms[i].coefficient, poly->terms[i].exponent);
        if (i != poly->total_terms - 1)
            printf(" + ");
    }
    printf("\n");
}

int main() {
    Polynomial poly;

    // ���׽� �Է�
    input_polynomial(&poly);

    // �Էµ� ���׽� ���
    print_polynomial(&poly);

    // �޸� ����
    free(poly.terms);

    return 0;
}
