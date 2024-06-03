##include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct ListNode {
    element data;
    struct ListNode* link;
} ListNode;

// 원형 연결 리스트의 초기화
ListNode* init_list() {
    ListNode* head = (ListNode*)malloc(sizeof(ListNode));
    head->link = head;
    return head;
}

// 리스트의 처음에 노드 추가
void insert_first(ListNode* head, element data) {
    ListNode* node = (ListNode*)malloc(sizeof(ListNode));
    node->data = data;
    node->link = head->link;
    head->link = node;
}

// 리스트의 마지막에 노드 추가
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

// 리스트의 처음 노드 삭제
void delete_first(ListNode* head) {
    if (head->link == head) {
        printf("리스트가 비어있습니다.\n");
        return;
    }
    ListNode* temp = head->link;
    head->link = temp->link;
    free(temp);
}

// 리스트의 마지막 노드 삭제
void delete_last(ListNode* head) {
    if (head->link == head) {
        printf("리스트가 비어있습니다.\n");
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

// 리스트 출력
void print_list(ListNode* head) {
    if (head->link == head) {
        printf("리스트가 비어있습니다.\n");
        return;
    }
    ListNode* p = head->link;
    do {
        printf("%d -> ", p->data);
        p = p->link;
    } while (p != head);
    printf("HEAD\n");
}

// 메뉴 출력
void menu() {
    printf("\n===== 메뉴 =====\n");
    printf("1. 숫자 입력 받아서 리스트 처음에 추가\n");
    printf("2. 숫자 입력 받아서 리스트 마지막에 추가\n");
    printf("3. 리스트 처음 노드 삭제\n");
    printf("4. 리스트 마지막 노드 삭제\n");
    printf("5. 리스트 프린트\n");
    printf("6. 종료\n");
}

int main() {
    ListNode* head = init_list();
    int choice, data;

    while (1) {
        menu();
        printf("메뉴를 선택하세요: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("추가할 숫자를 입력하세요: ");
            scanf("%d", &data);
            insert_first(head, data);
            break;
        case 2:
            printf("추가할 숫자를 입력하세요: ");
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
            printf("프로그램을 종료합니다.\n");
            exit(0);
        default:
            printf("잘못된 입력입니다. 다시 선택하세요.\n");
            break;
        }
    }

    return 0;
}