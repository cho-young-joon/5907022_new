#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LEN 20

typedef struct listNode {
    char data[MAX_NAME_LEN];
    struct listNode* link;
} ListNode;

ListNode* insert_last(ListNode* head, const char* value);
ListNode* delete_node(ListNode* head, const char* value, ListNode** deleted_head);
void print_list(ListNode* head);
ListNode* search_list(ListNode* head, const char* value);
void print_deleted_list(ListNode* deleted_head);

int main() {
    ListNode* head = NULL;
    ListNode* deleted_head = NULL;

    char* initial_fruits[] = { "Mango", "Orange", "Apple", "Grape", "Cherry", "Plum", "Guava", "Raspberry", "Banana", "Peach" };
    int initial_count = sizeof(initial_fruits) / sizeof(initial_fruits[0]);

    for (int i = 0; i < initial_count; i++) {
        head = insert_last(head, initial_fruits[i]);
    }

    int choice;
    char fruit[MAX_NAME_LEN];

    while (1) {
        printf("\n메뉴:\n");
        printf("1. 리스트의 마지막에 새로운 과일 추가\n");
        printf("2. 리스트에서 과일 삭제\n");
        printf("3. 삭제된 과일 목록 출력\n");
        printf("4. 리스트 출력\n");
        printf("5. 종료\n");
        printf("선택하세요: ");
        scanf_s("%d", &choice);

        switch (choice) {
        case 1:
            printf("추가할 과일 이름을 입력하세요: ");
            scanf_s("%s", fruit, (unsigned)_countof(fruit));
            if (search_list(head, fruit) == NULL) {
                head = insert_last(head, fruit);
                printf("%s이(가) 리스트에 추가되었습니다.\n", fruit);
            }
            else {
                printf("%s은(는) 이미 리스트에 있습니다.\n", fruit);
            }
            break;
        case 2:
            printf("삭제할 과일 이름을 입력하세요: ");
            scanf_s("%s", fruit, (unsigned)_countof(fruit));
            if (search_list(head, fruit) != NULL) {
                head = delete_node(head, fruit, &deleted_head);
                printf("%s이(가) 리스트에서 삭제되었습니다.\n", fruit);
            }
            else {
                printf("%s은(는) 리스트에 없습니다.\n", fruit);
            }
            break;
        case 3:
            printf("삭제된 과일 목록:\n");
            print_deleted_list(deleted_head);
            break;
        case 4:
            printf("현재 리스트:\n");
            print_list(head);
            break;

        case 5:
            exit(0);
        default:
            printf("잘못된 선택입니다. 다시 시도하세요.\n");
        }
    }
    return 0;
}

ListNode* insert_last(ListNode* head, const char* value) {
    ListNode* p = (ListNode*)malloc(sizeof(ListNode));
    strcpy_s(p->data, MAX_NAME_LEN, value);
    p->link = NULL;

    if (head == NULL) {
        return p;
    }
    else {
        ListNode* temp = head;
        while (temp->link != NULL) {
            temp = temp->link;
        }
        temp->link = p;
        return head;
    }
}

ListNode* delete_node(ListNode* head, const char* value, ListNode** deleted_head) {
    ListNode* pre = NULL;
    ListNode* cur = head;

    while (cur != NULL && strcmp(cur->data, value) != 0) {
        pre = cur;
        cur = cur->link;
    }

    if (cur == NULL) return head;

    if (pre == NULL) {
        head = cur->link;
    }
    else {
        pre->link = cur->link;
    }

    cur->link = *deleted_head;
    *deleted_head = cur;

    return head;
}

void print_list(ListNode* head) {
    while (head != NULL) {
        printf("%s ", head->data);
        head = head->link;
    }
    printf("\n");
}

ListNode* search_list(ListNode* head, const char* value) {
    ListNode* p = head;
    while (p != NULL) {
        if (strcmp(p->data, value) == 0) {
            return p;
        }
        p = p->link;
    }
    return NULL;
}

void print_deleted_list(ListNode* deleted_head) {
    if (deleted_head == NULL) {
        printf("삭제된 과일이 없습니다.\n");
        return;
    }
    ListNode* p = deleted_head;
    while (p != NULL) {
        printf("%s ", p->data);
        p = p->link;
    }
    printf("\n");
}