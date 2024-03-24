//#include <stdio.h>
//#include <stdio.h>
//#include <time.h>
//#include <math.h>
//
//clock_t start_iter, end_iter;
//long long power_iter(int n, int a) {  //power_iter 함수에 매게변수(파라미터) 값에 int n = 13 을 의미함 int a = 21 을 의미함  13^21제곱 의미
//    long long result = n;
//    for (int i = 1; i < a; ++i) {  // 반복함수
//        result *= n;
//
//
//    }
//    return result;
//}
//
//
//int main(int argc, char* argv[]) {
//    
//
//    long long result_iter = power_iter(13, 21);
//
//
//
//    start_iter = clock(); // 반복함수 측정시작
//    printf("13^21 = %i \n", result_iter);
//    end_iter = clock();  // 반복함수 측정종료
//    printf("반복문 걸린시간: %f \n", (float)(end_iter - start_iter) / CLOCKS_PER_SEC); //반복함수 시작 - 반복함수 종료 / 1000
//
//
//
//}



//#include <stdio.h>
//#include <stdio.h>
//#include <time.h>
//#include <math.h>
//
//clock_t start_rec, end_rec;
//
//
//long long power_rec(int n, int a) {  //power_rec 함수에 매게변수(파라미터) 값에 int n = 13 을 의미함 int a = 21 을 의미함  13^21제곱 의미
//    if (a == 0) { // 재귀함수
//
//        return 1;
//
//    }
//    else {
//        return n * power_rec(n, a - 1);
//
//    }
//}
//
//int main(int argc, char* argv[]) {
//
//
//    long long result_rec = power_rec(13, 21);
//
//
//    start_rec = clock(); // 재귀함수 측정시작
//    printf("13^21 = %i \n", result_rec);
//    end_rec = clock(); // 재귀함수 측정종료
//    printf("걸린시간: %f \n", (float)(end_rec - start_rec) / CLOCKS_PER_SEC); //재귀함수 시작 - 재귀함수 종료 / 1000
//
//
//}