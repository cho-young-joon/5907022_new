#include <stdio.h>
#include <stdio.h>
#include <time.h>

long fact_iter(int n) {
    int result = 1;
    for (int i = 1; i <= n; ++i) {
        result *= i;
    }
    return result;
}

long factorial_rec(int n) {
    if (n == 1) {
        return 1;
    }
    else {
        return n * factorial_rec(n - 1);
    }
}

int main(int argc, char* argv[]) {
    clock_t start_iter, end_iter, start_rec, end_rec;

    long result_iter = fact_iter(20);
    long result_rec = factorial_rec(20);



    start_iter = clock();
    printf("20! = %ld\n", result_iter);
    end_iter = clock();

    start_rec = clock();
    printf("20! = %ld\n", result_rec);
    end_rec = clock();
    printf("걸린시간: %f \n", (float)(end_iter - start_iter) / CLOCKS_PER_SEC);
    printf("걸린시간: %f \n", (float)(end_rec - start_rec) / CLOCKS_PER_SEC);

}