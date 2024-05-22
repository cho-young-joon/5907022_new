#include <stdio.h>
#include <stdlib.h>
//����
// ��� ����ü ����
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// ����Ʈ ����ü ����
typedef struct {
    Node* head;
} LinkedList;

// �Լ� ����
void insertNode(LinkedList* list, int data, int position);
void deleteNode(LinkedList* list, int position);
void printList(LinkedList* list);
void freeList(LinkedList* list);

// ���� �Լ�
int main() {
    LinkedList list;
    list.head = NULL;
    int choice, data, position;

    while (1) {
        printf("\n�޴�:\n");
        printf("1. ����Ʈ�� ���� ����\n");
        printf("2. ����Ʈ���� ���� ����\n");
        printf("3. ����Ʈ ���\n");
        printf("0. ���α׷� ����\n");
        printf("����: ");
        scanf_s("%d", &choice);

        switch (choice) {
        case 1:
            printf("������ ����: ");
            scanf_s("%d", &data);
            printf("������ ��ġ: ");
            scanf_s("%d", &position);
            insertNode(&list, data, position);
            break;
        case 2:
            printf("������ ��ġ: ");
            scanf_s("%d", &position);
            deleteNode(&list, position);
            break;
        case 3:
            printList(&list);
            break;
        case 0:
            freeList(&list);
            printf("���α׷��� �����մϴ�.\n");
            return 0;
        default:
            printf("�߸��� �����Դϴ�. �ٽ� ������ �ּ���.\n");
        }
    }

    return 0;
}

// ��� ���� �Լ�
void insertNode(LinkedList* list, int data, int position) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if (position == 0) {
        newNode->next = list->head;
        list->head = newNode;
        printf("���� �Ϸ�: ��ũ �̵� Ƚ�� = 0\n");
        return;
    }

    Node* temp = list->head;
    int count = 0;

    while (temp != NULL && count < position - 1) {
        temp = temp->next;
        count++;
    }

    if (temp == NULL) {
        printf("�߸��� ��ġ�Դϴ�. ���� ����.\n");
        free(newNode);
    }
    else {
        newNode->next = temp->next;
        temp->next = newNode;
        printf("���� �Ϸ�: ��ũ �̵� Ƚ�� = %d\n", count + 1);
    }
}

// ��� ���� �Լ�
void deleteNode(LinkedList* list, int position) {
    if (list->head == NULL) {
        printf("����Ʈ�� ��� �ֽ��ϴ�.\n");
        return;
    }

    Node* temp = list->head;
    int count = 0;

    if (position == 0) {
        list->head = temp->next;
        free(temp);
        printf("���� �Ϸ�: ��ũ �̵� Ƚ�� = 0\n");
        return;
    }

    Node* prev = NULL;

    while (temp != NULL && count < position) {
        prev = temp;
        temp = temp->next;
        count++;
    }

    if (temp == NULL) {
        printf("�߸��� ��ġ�Դϴ�. ���� ����.\n");
    }
    else {
        prev->next = temp->next;
        free(temp);
        printf("���� �Ϸ�: ��ũ �̵� Ƚ�� = %d\n", count);
    }
}

// ����Ʈ ��� �Լ�
void printList(LinkedList* list) {
    Node* temp = list->head;
    printf("����Ʈ: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// �޸� ���� �Լ�
void freeList(LinkedList* list) {
    Node* temp = list->head;
    while (temp != NULL) {
        Node* next = temp->next;
        free(temp);
        temp = next;
    }
    list->head = NULL;
}