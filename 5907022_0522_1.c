#include <stdio.h>
#include <stdlib.h>
//과제
// 노드 구조체 정의
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// 리스트 구조체 정의
typedef struct {
    Node* head;
} LinkedList;

// 함수 선언
void insertNode(LinkedList* list, int data, int position);
void deleteNode(LinkedList* list, int position);
void printList(LinkedList* list);
void freeList(LinkedList* list);

// 메인 함수
int main() {
    LinkedList list;
    list.head = NULL;
    int choice, data, position;

    while (1) {
        printf("\n메뉴:\n");
        printf("1. 리스트에 숫자 삽입\n");
        printf("2. 리스트에서 숫자 삭제\n");
        printf("3. 리스트 출력\n");
        printf("0. 프로그램 종료\n");
        printf("선택: ");
        scanf_s("%d", &choice);

        switch (choice) {
        case 1:
            printf("삽입할 숫자: ");
            scanf_s("%d", &data);
            printf("삽입할 위치: ");
            scanf_s("%d", &position);
            insertNode(&list, data, position);
            break;
        case 2:
            printf("삭제할 위치: ");
            scanf_s("%d", &position);
            deleteNode(&list, position);
            break;
        case 3:
            printList(&list);
            break;
        case 0:
            freeList(&list);
            printf("프로그램을 종료합니다.\n");
            return 0;
        default:
            printf("잘못된 선택입니다. 다시 선택해 주세요.\n");
        }
    }

    return 0;
}

// 노드 삽입 함수
void insertNode(LinkedList* list, int data, int position) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if (position == 0) {
        newNode->next = list->head;
        list->head = newNode;
        printf("삽입 완료: 링크 이동 횟수 = 0\n");
        return;
    }

    Node* temp = list->head;
    int count = 0;

    while (temp != NULL && count < position - 1) {
        temp = temp->next;
        count++;
    }

    if (temp == NULL) {
        printf("잘못된 위치입니다. 삽입 실패.\n");
        free(newNode);
    }
    else {
        newNode->next = temp->next;
        temp->next = newNode;
        printf("삽입 완료: 링크 이동 횟수 = %d\n", count + 1);
    }
}

// 노드 삭제 함수
void deleteNode(LinkedList* list, int position) {
    if (list->head == NULL) {
        printf("리스트가 비어 있습니다.\n");
        return;
    }

    Node* temp = list->head;
    int count = 0;

    if (position == 0) {
        list->head = temp->next;
        free(temp);
        printf("삭제 완료: 링크 이동 횟수 = 0\n");
        return;
    }

    Node* prev = NULL;

    while (temp != NULL && count < position) {
        prev = temp;
        temp = temp->next;
        count++;
    }

    if (temp == NULL) {
        printf("잘못된 위치입니다. 삭제 실패.\n");
    }
    else {
        prev->next = temp->next;
        free(temp);
        printf("삭제 완료: 링크 이동 횟수 = %d\n", count);
    }
}

// 리스트 출력 함수
void printList(LinkedList* list) {
    Node* temp = list->head;
    printf("리스트: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// 메모리 해제 함수
void freeList(LinkedList* list) {
    Node* temp = list->head;
    while (temp != NULL) {
        Node* next = temp->next;
        free(temp);
        temp = next;
    }
    list->head = NULL;
}