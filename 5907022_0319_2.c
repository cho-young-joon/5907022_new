//#include <stdio.h>
//#include <stdio.h>
//#include <time.h>
//#include <math.h>
//
//clock_t start_iter, end_iter;
//long long power_iter(int n, int a) {  //power_iter �Լ��� �ŰԺ���(�Ķ����) ���� int n = 13 �� �ǹ��� int a = 21 �� �ǹ���  13^21���� �ǹ�
//    long long result = n;
//    for (int i = 1; i < a; ++i) {  // �ݺ��Լ�
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
//    start_iter = clock(); // �ݺ��Լ� ��������
//    printf("13^21 = %i \n", result_iter);
//    end_iter = clock();  // �ݺ��Լ� ��������
//    printf("�ݺ��� �ɸ��ð�: %f \n", (float)(end_iter - start_iter) / CLOCKS_PER_SEC); //�ݺ��Լ� ���� - �ݺ��Լ� ���� / 1000
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
//long long power_rec(int n, int a) {  //power_rec �Լ��� �ŰԺ���(�Ķ����) ���� int n = 13 �� �ǹ��� int a = 21 �� �ǹ���  13^21���� �ǹ�
//    if (a == 0) { // ����Լ�
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
//    start_rec = clock(); // ����Լ� ��������
//    printf("13^21 = %i \n", result_rec);
//    end_rec = clock(); // ����Լ� ��������
//    printf("�ɸ��ð�: %f \n", (float)(end_rec - start_rec) / CLOCKS_PER_SEC); //����Լ� ���� - ����Լ� ���� / 1000
//
//
//}