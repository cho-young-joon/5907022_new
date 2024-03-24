#include <stdio.h>
#include <stdio.h>
#include <time.h>
clock_t start_iter, end_iter, start_rec, end_rec; // 시간 체크 변수 선언
// start_iter , end_iter  반복함수 측정
// start_rec , end_rec 재귀함수 측정

int main(int argc, char* argv[]) {
    

    long result_iter = fact_iter(20);       // result_iter 측정시간 fact_iter(20) 매게변수에 20을 입력
    long result_rec = factorial_rec(20);    // result_rec 측정시간 factorial_rec(20) 매게변수 20을 입력



    start_iter = clock(); //반복함수 측정 시작
    printf("20! = %ld\n", result_iter);
    end_iter = clock(); // 반복함수 측정 종료

    start_rec = clock(); //재귀함수 측정 
    printf("20! = %ld\n", result_rec);
    end_rec = clock(); // 재귀함수 종료
    printf("걸린시간: %f \n", (float)(end_iter - start_iter) / CLOCKS_PER_SEC); // 반복함수 시작 - 반복함수 종료 / 1000
    printf("걸린시간: %f \n", (float)(end_rec - start_rec) / CLOCKS_PER_SEC); // 재귀함수 시작 - 재귀함수 종료 / 1000

}
long fact_iter(int n) { // 반복함수 구현
    int result = 1;
    for (int i = 1; i <= n; ++i) {
        result *= i;
    }
    return result;
}

long factorial_rec(int n) { // 재귀함수 구현
    if (n == 1) {
        return 1;
    }
    else {
        return n * factorial_rec(n - 1);
    }
}