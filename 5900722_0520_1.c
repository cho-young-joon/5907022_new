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
//            error("����Ʈ �����÷ο�");
//        }
//    }
//    else {
//        error("�߸��� ��ġ");
//    }
//    return 0;
//}
//
//void delete(ArrayListType* L, int pos) {
//    if (pos < 0 || pos >= L->size) {
//        error("��ġ ����");
//    }
//    else {
//        int move_count = 0;
//        for (int i = pos; i < L->size - 1; i++) {
//            L->array[i] = L->array[i + 1];
//            move_count++;
//        }
//        L->size--;
//        printf("������ �̵� Ƚ��: %d\n", move_count);
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
//        printf("\n�޴�: \n");
//        printf("(1) ����Ʈ�� �߰��ϴ� ���ڿ� ��ġ�� �Է� �޾Ƽ� ����\n");
//        printf("(2) ����Ʈ���� ������ ��ġ�� �Է� �޾Ƽ� ����\n");
//        printf("(3) ����Ʈ�� ���ʷ� ���\n");
//        printf("(0) ���α׷� ����\n");
//        printf("����: ");
//        scanf_s("%d", &choice);
//
//        switch (choice) {
//        case 1:
//            if (is_full(&list)) {
//                printf("����Ʈ�� �� á���ϴ�.\n");
//            }
//            else {
//                int pos, item;
//                printf("������ ��ġ�� ���ڸ� �Է��ϼ���: ");
//                scanf_s("%d %d", &pos, &item);
//                int move_count = insert(&list, pos - 1, item); // ���������δ� 0���� �����ϵ��� ����
//                printf("������ �̵� Ƚ��: %d\n", move_count);
//            }
//            break;
//
//        case 2:
//            if (is_empty(&list)) {
//                printf("����Ʈ�� ��� �ֽ��ϴ�.\n");
//            }
//            else {
//                int pos;
//                printf("������ ��ġ�� �Է��ϼ���: ");
//                scanf_s("%d", &pos);
//                delete(&list, pos - 1); // ���������δ� 0���� �����ϵ��� ����
//            }
//            break;
//
//        case 3:
//            print_list(&list);
//            break;
//
//        case 0:
//            printf("���α׷� ����\n");
//            return 0;
//
//        default:
//            printf("�߸��� �����Դϴ�. �ٽ� �õ��ϼ���.\n");
//        }
//    }
//
//    return 0;
//}