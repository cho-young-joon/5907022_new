//#include <stdio.h>
//#include <stdlib.h>
//
//typedef int element;
//typedef struct ListNode {
//    element data;
//    struct ListNode* link;
//} ListNode;
//
//
//
//// ����Ʈ ���
//void print_list(ListNode* head) {
//    ListNode* p;
//
//    if (head->link == head) return;
//    
//    p = head->link;
//    do {
//        printf("%d -> ", p->data);
//        p = p->link;
//    } while (p != head);
//    printf("%d ->\n", p->data);
//
//}
//
//// �޴� ���
//void menu() {
//    printf("\n===== �޴� =====\n");
//    printf("1. ���� �Է� �޾Ƽ� ����Ʈ ó���� �߰�\n");
//    printf("2. ���� �Է� �޾Ƽ� ����Ʈ �������� �߰�\n");
//    printf("3. ����Ʈ ó�� ��� ����\n");
//    printf("4. ����Ʈ ������ ��� ����\n");
//    printf("5. ����Ʈ ����Ʈ\n");
//    printf("6. ����\n");
//}
//
//int main() {
//    ListNode* head = init_list();
//    int choice, data;
//
//    while (1) {
//        menu();
//        printf("�޴��� �����ϼ���: ");
//        scanf_s("%d", &choice);
//
//        switch (choice) {
//        case 1:
//            break;
//        case 2:
//            
//            break;
//        case 3:
//           
//            break;
//        case 4:
//            
//            break;
//        case 5:
//            print_list(head);
//            break;
//        case 6:
//            printf("���α׷��� �����մϴ�.\n");
//            exit(0);
//        default:
//            printf("�߸��� �Է��Դϴ�. �ٽ� �����ϼ���.\n");
//            break;
//        }
//    }
//
//    return 0;
//}
#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct ListNode {
    element data;
    struct ListNode* link;
} ListNode;

// ����Ʈ �ʱ�ȭ
ListNode* init_list() {
    ListNode* head = (ListNode*)malloc(sizeof(ListNode));
    head->link = head;
    return head;
}

// ����Ʈ ���
void print_list(ListNode* head) {
    ListNode* p = head->link;

    if (p == head) {
        printf("����Ʈ�� ����ֽ��ϴ�.\n");
        return;
    }

    printf("%d", p->data);
    p = p->link;

    while (p != head) {
        printf(" -> %d", p->data);
        p = p->link;
    }

    printf(" (head)\n");
}
// �޴� ���
void menu() {
    printf("\n===== �޴� =====\n");
    printf("1. ���� �Է� �޾Ƽ� ����Ʈ ó���� �߰�\n");
    printf("2. ���� �Է� �޾Ƽ� ����Ʈ �������� �߰�\n");
    printf("3. ����Ʈ ó�� ��� ����\n");
    printf("4. ����Ʈ ������ ��� ����\n");
    printf("5. ����Ʈ ����Ʈ\n");
    printf("6. ����\n");
}

// ����Ʈ ó���� ��� �߰�
void insert_at_head(ListNode* head, element data) {
    ListNode* newNode = (ListNode*)malloc(sizeof(ListNode));
    newNode->data = data;
    newNode->link = head->link;
    head->link = newNode;
}

// ����Ʈ �������� ��� �߰�
void insert_at_tail(ListNode* head, element data) {
    ListNode* newNode = (ListNode*)malloc(sizeof(ListNode));
    newNode->data = data;
    newNode->link = head;

    ListNode* p = head;
    while (p->link != head) {
        p = p->link;
    }
    p->link = newNode;
}

// ����Ʈ ó�� ��� ����
void delete_first_node(ListNode* head) {
    if (head->link == head) {
        printf("����Ʈ�� ����ֽ��ϴ�.\n");
        return;
    }

    ListNode* removed = head->link;
    head->link = removed->link;
    free(removed);
}

// ����Ʈ ������ ��� ����
void delete_last_node(ListNode* head) {
    if (head->link == head) {
        printf("����Ʈ�� ����ֽ��ϴ�.\n");
        return;
    }

    ListNode* p = head;
    ListNode* prev = NULL;

    while (p->link != head) {
        prev = p;
        p = p->link;
    }

    prev->link = head;
    free(p);
}

int main() {
    ListNode* head = init_list();
    int choice, data;

    while (1) {
        menu();
        printf("�޴��� �����ϼ���: ");
        scanf_s("%d", &choice);

        switch (choice) {
        case 1:
            printf("�߰��� ���ڸ� �Է��ϼ���: ");
            scanf_s("%d", &data);
            insert_at_head(head, data);
            break;
        case 2:
            printf("�߰��� ���ڸ� �Է��ϼ���: ");
            scanf_s("%d", &data);
            insert_at_tail(head, data);
            break;
        case 3:
            delete_first_node(head);
            break;
        case 4:
            delete_last_node(head);
            break;
        case 5:
            print_list(head);
            break;
        case 6:
            printf("���α׷��� �����մϴ�.\n");
            exit(0);
        default:
            printf("�߸��� �Է��Դϴ�. �ٽ� �����ϼ���.\n");
            break;
        }
    }

    return 0;
}