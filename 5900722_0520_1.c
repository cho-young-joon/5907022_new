//#include <stdio.h>
//#include <stdlib.h>
//
//#define MAX_SIZE 100
//
//typedef int element;
//typedef struct {
//    element array[MAX_SIZE];
//    int size;
//} ArrayListType;
//
//void error(char* message) {
//    fprintf(stderr, "%s\n", message);
//}
//
//void init(ArrayListType* L) {
//    L->size = 0;
//}
//
//void print_list(ArrayListType* L) {
//    printf("[LIST]");
//    for (int i = 0; i < L->size; i++)
//        printf("<%2d> ", L->array[i]);
//    printf("\n");
//}
//
//int insert(ArrayListType* L, int pos, element item) {
//    if ((pos >= 0) && (pos <= L->size)) {
//        if (L->size < MAX_SIZE) {
//            int move_count = 0;
//            for (int i = L->size - 1; i >= pos; i--) {
//                L->array[i + 1] = L->array[i];
//                move_count++;
//            }
//            L->array[pos] = item;
//            L->size++;
//            return move_count;
//        }
//        else {
//            error("리스트 오버플로우");
//        }
//    }
//    else {
//        error("잘못된 위치");
//    }
//    return 0;
//}
//
//void delete(ArrayListType* L, int pos) {
//    if (pos < 0 || pos >= L->size) {
//        error("위치 오류");
//    }
//    else {
//        int move_count = 0;
//        for (int i = pos; i < L->size - 1; i++) {
//            L->array[i] = L->array[i + 1];
//            move_count++;
//        }
//        L->size--;
//        printf("데이터 이동 횟수: %d\n", move_count);
//    }
//}
//
//int is_empty(ArrayListType* L) {
//    return (L->size == 0);
//}
//
//int is_full(ArrayListType* L) {
//    return (L->size == MAX_SIZE);
//}
//
//int main() {
//    ArrayListType list;
//    int choice;
//
//    init(&list);
//
//    while (1) {
//        printf("\n메뉴: \n");
//        printf("(1) 리스트에 추가하는 숫자와 위치를 입력 받아서 삽입\n");
//        printf("(2) 리스트에서 삭제할 위치를 입력 받아서 삭제\n");
//        printf("(3) 리스트를 차례로 출력\n");
//        printf("(0) 프로그램 종료\n");
//        printf("선택: ");
//        scanf_s("%d", &choice);
//
//        switch (choice) {
//        case 1:
//            if (is_full(&list)) {
//                printf("리스트가 꽉 찼습니다.\n");
//            }
//            else {
//                int pos, item;
//                printf("삽입할 위치와 숫자를 입력하세요: ");
//                scanf_s("%d %d", &pos, &item);
//                int move_count = insert(&list, pos - 1, item); // 내부적으로는 0부터 시작하도록 변경
//                printf("데이터 이동 횟수: %d\n", move_count);
//            }
//            break;
//
//        case 2:
//            if (is_empty(&list)) {
//                printf("리스트가 비어 있습니다.\n");
//            }
//            else {
//                int pos;
//                printf("삭제할 위치를 입력하세요: ");
//                scanf_s("%d", &pos);
//                delete(&list, pos - 1); // 내부적으로는 0부터 시작하도록 변경
//            }
//            break;
//
//        case 3:
//            print_list(&list);
//            break;
//
//        case 0:
//            printf("프로그램 종료\n");
//            return 0;
//
//        default:
//            printf("잘못된 선택입니다. 다시 시도하세요.\n");
//        }
//    }
//
//    return 0;
//}