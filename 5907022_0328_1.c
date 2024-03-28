#include <stdio.h>

#define _CRT_SECURE_NO_WARNINGS
#define MAX(a,b) (((a)>(b))?(a):(b))
#define MAX_DEGREE 101

typedef struct {
	int degree;
	float coef[MAX_DEGREE];
}polynomial;

polynomial poly_add1(polynomial A, polynomial B) {
	polynomial C;
	int Apos = 0, Bpos = 0, Cpos = 0;
	int degree_a = A.degree;
	int degree_b = B.degree;
	C.degree = MAX(A.degree, B.degree);

	while (Apos <= A.degree && Bpos <= B.degree) {
		if (degree_a > degree_b) {
			printf("%d���� : C.coef[%d] = A.coef[%d] = %d \n", degree_a, Cpos, Apos, (int)A.coef[Apos]);
			C.coef[Cpos++] = A.coef[Apos++];
			degree_a--;
		}
		else if (degree_a == degree_b) {
			printf("%d���� : C.coef[%d] = A.coef[%d] + B.coef[%d] = %d \n", degree_a, Cpos, Apos, Bpos, (int)(A.coef[Apos] + B.coef[Bpos]));
			C.coef[Cpos++] = A.coef[Apos++] + B.coef[Bpos++];
			degree_a--; degree_b--;
		}
		else {
			printf("%d���� : C.coef[%d] = B.coef[%d] = %d \n", degree_b, Cpos, Bpos, (int)B.coef[Bpos]);
			C.coef[Cpos++] = B.coef[Bpos++];
			degree_b--;
		}
	}
	return C;
}

void print_poly(polynomial p) {
	for (int i = p.degree; i > 0; i--)
		printf("%3.1f x^%d + ", p.coef[p.degree - i], i);
	printf("%3.1f \n", p.coef[p.degree]);
}

int main(void) {
	/*
	polynomial a = { 5,{3,6,0,0,0,10} };
	polynomial b = { 4,{7,0,5,0,1} };
	polynomial c;
	*/

	// ���� ���׽� ���� �Է� �ޱ�

	polynomial a, b, c;
	printf("[ù��° ���׽� ���� �Է�]\n\n");
	printf("�ְ������� ���� : ");
	scanf("%d", &a.degree);
	printf("������� ������ ��� �Է� : ");
	for (int i = 0; i <= a.degree; i++)
		scanf("%f", &a.coef[i]);

	printf("\nù��° ���׽� : ");
	print_poly(a);

	printf("\n\n[�ι�° ���׽� ���� �Է�]\n\n");
	printf("�ְ������� ���� : ");
	scanf("%d", &b.degree);
	printf("������� ������ ��� �Է� : ");
	for (int i = 0; i <= b.degree; i++)
		scanf("%f", &b.coef[i]);

	printf("\n�ι�° ���׽� : ");
	print_poly(b);
	printf("\n");

	print_poly(a);
	print_poly(b);
	printf("\n");

	c = poly_add1(a, b);
	printf("----------------------------------------------------------\n");
	print_poly(c);

	return 0;
}