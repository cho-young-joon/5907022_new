//1) 0���� 100������ ���� �߿��� �Ҽ��� ���� ���� ���ϴ� ���α׷��� �ۼ��Ѵ�.
#include <stdio.h>
#include <time.h>
int main(void) {
    int sum = 0;

    int i = 2; // �ڱ� �ڽ� �ۿ� ������ ���ϴ� �� ��  0,1 �� ���� �Ѵ�.

    while (i <= 100) {
        int isPrime = 1; // �Ҽ� ���θ� �Ǵ��ϴ� ���� (1: �Ҽ�, 0: �Ҽ� �ƴ�)

        // 2���� i-1���� i�� ������ ���������� �˻�
        for (int j = 2; j <= i / 2; j++) {
            if (i % j == 0) {
                isPrime = 0; // i�� �Ҽ��� �ƴϸ� isPrime�� 0���� ����
                break;
            }
        }

        // i�� �Ҽ���� sum�� ���ϱ�
        if (isPrime) {
            sum += i;
            
        }

        i++; // ���� ���ڷ� �̵�
    }
    clock_t start, end;
    start = clock();
    // ��� ���
    printf("0���� 100������ �Ҽ����� ���� %d�Դϴ�.\n", sum);
    end = clock();
    printf("[time : %f]\n", (float)(end - start) / CLOCKS_PER_SEC);

    return 0;
}
