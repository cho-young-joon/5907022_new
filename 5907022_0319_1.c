#include <stdio.h>
#include <stdio.h>
#include <time.h>
clock_t start_iter, end_iter, start_rec, end_rec; // �ð� üũ ���� ����
// start_iter , end_iter  �ݺ��Լ� ����
// start_rec , end_rec ����Լ� ����

int main(int argc, char* argv[]) {
    

    long result_iter = fact_iter(20);       // result_iter �����ð� fact_iter(20) �ŰԺ����� 20�� �Է�
    long result_rec = factorial_rec(20);    // result_rec �����ð� factorial_rec(20) �ŰԺ��� 20�� �Է�



    start_iter = clock(); //�ݺ��Լ� ���� ����
    printf("20! = %ld\n", result_iter);
    end_iter = clock(); // �ݺ��Լ� ���� ����

    start_rec = clock(); //����Լ� ���� 
    printf("20! = %ld\n", result_rec);
    end_rec = clock(); // ����Լ� ����
    printf("�ɸ��ð�: %f \n", (float)(end_iter - start_iter) / CLOCKS_PER_SEC); // �ݺ��Լ� ���� - �ݺ��Լ� ���� / 1000
    printf("�ɸ��ð�: %f \n", (float)(end_rec - start_rec) / CLOCKS_PER_SEC); // ����Լ� ���� - ����Լ� ���� / 1000

}
long fact_iter(int n) { // �ݺ��Լ� ����
    int result = 1;
    for (int i = 1; i <= n; ++i) {
        result *= i;
    }
    return result;
}

long factorial_rec(int n) { // ����Լ� ����
    if (n == 1) {
        return 1;
    }
    else {
        return n * factorial_rec(n - 1);
    }
}