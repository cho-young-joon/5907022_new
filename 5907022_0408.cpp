#include <stdio.h>
#include <stdlib.h>

// 다항식의 각 항을 표현하는 구조체
typedef struct {
    float coefficient; // 계수
    int exponent;     // 지수
} Term;

// 다항식을 표현하는 구조체
typedef struct {
    int total_terms;  // 총 항의 수
    Term* terms;      // 항들의 배열을 가리키는 포인터
} Polynomial;

// 다항식을 입력하는 함수
void input_polynomial(Polynomial* poly) {
    printf("다항식의 총 항의 수를 입력하시오: ");
    scanf_s("%d", &poly->total_terms);

    // 메모리 동적 할당
    poly->terms = (Term*)malloc(poly->total_terms * sizeof(Term));

    printf("고차항부터 차례로 계수와 지수를 입력하시오:\n");
    for (int i = 0; i < poly->total_terms; i++) {
        printf("[계수, 차수] ");
        scanf_s("%f %d", &poly->terms[i].coefficient, &poly->terms[i].exponent);
    }
}

// 다항식을 출력하는 함수
void print_polynomial(Polynomial* poly) {
    printf("입력된 다항식은 다음과 같습니다: ");
    for (int i = 0; i < poly->total_terms; i++) {
        printf("%.1fx^%d", poly->terms[i].coefficient, poly->terms[i].exponent);
        if (i != poly->total_terms - 1)
            printf(" + ");
    }
    printf("\n");
}

int main() {
    Polynomial poly;

    // 다항식 입력
    input_polynomial(&poly);

    // 입력된 다항식 출력
    print_polynomial(&poly);

    // 메모리 해제
    free(poly.terms);

    return 0;
}
