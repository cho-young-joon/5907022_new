//1) 0부터 100까지의 숫자 중에서 소수들 만의 합을 구하는 프로그램을 작성한다.
#include <stdio.h>
#include <time.h>
int main(void) {
    int sum = 0;

    int i = 2; // 자기 자신 밖에 나누지 못하는 수 라서  0,1 을 제외 한다.

    while (i <= 100) {
        int isPrime = 1; // 소수 여부를 판단하는 변수 (1: 소수, 0: 소수 아님)

        // 2부터 i-1까지 i로 나누어 떨어지는지 검사
        for (int j = 2; j <= i / 2; j++) {
            if (i % j == 0) {
                isPrime = 0; // i가 소수가 아니면 isPrime을 0으로 변경
                break;
            }
        }

        // i가 소수라면 sum에 더하기
        if (isPrime) {
            sum += i;
            
        }

        i++; // 다음 숫자로 이동
    }
    clock_t start, end;
    start = clock();
    // 결과 출력
    printf("0부터 100까지의 소수들의 합은 %d입니다.\n", sum);
    end = clock();
    printf("[time : %f]\n", (float)(end - start) / CLOCKS_PER_SEC);

    return 0;
}
