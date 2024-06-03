##include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct ListNode {
    element data;
    struct ListNode* link;
} ListNode;

// ���� ���� ����Ʈ�� �ʱ�ȭ
ListNode* init_list() {
    ListNode* head = (ListNode*)malloc(sizeof(ListNode));
    head->link = head;
    return head;
}

// ����Ʈ�� ó���� ��� �߰�
void insert_first(ListNode* head, element data) {
    ListNode* node = (ListNode*)malloc(sizeof(ListNode));
    node->data = data;
    node->link = head->link;
    head->link = node;
}

// ����Ʈ�� �������� ��� �߰�
void insert_last(ListNode* head, element data) {
    ListNode* node = (ListNode*)malloc(sizeof(ListNode));
    node->data = data;
    if (head->link == head) {
        head->link = node;
        node->link = head;
    }
    else {
        ListNode* temp = head;
        while (temp->link != head) {
            temp = temp->link;
        }
        temp->link = node;
        node->link = head;
    }
}

// ����Ʈ�� ó�� ��� ����
void delete_first(ListNode* head) {
    if (head->link == head) {
        printf("����Ʈ�� ����ֽ��ϴ�.\n");
        return;
    }
    ListNode* temp = head->link;
    head->link = temp->link;
    free(temp);
}

// ����Ʈ�� ������ ��� ����
void delete_last(ListNode* head) {
    if (head->link == head) {
        printf("����Ʈ�� ����ֽ��ϴ�.\n");
        return;
    }
    ListNode* temp = head;
    ListNode* prev = NULL;
    while (temp->link != head) {
        prev = temp;
        temp = temp->link;
    }
    if (prev != NULL) {
        prev->link = head;
        free(temp);
    }
    else {
        head->link = head;
        free(temp);
    }
}

// ����Ʈ ���
void print_list(ListNode* head) {
    if (head->link == head) {
        printf("����Ʈ�� ����ֽ��ϴ�.\n");
        return;
    }
    ListNode* p = head->link;
    do {
        printf("%d -> ", p->data);
        p = p->link;
    } while (p != head);
    printf("HEAD\n");
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

int main() {
    ListNode* head = init_list();
    int choice, data;

    while (1) {
        menu();
        printf("�޴��� �����ϼ���: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("�߰��� ���ڸ� �Է��ϼ���: ");
            scanf("%d", &data);
            insert_first(head, data);
            break;
        case 2:
            printf("�߰��� ���ڸ� �Է��ϼ���: ");
            scanf("%d", &data);
            insert_last(head, data);
            break;
        case 3:
            delete_first(head);
            break;
        case 4:
            delete_last(head);
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