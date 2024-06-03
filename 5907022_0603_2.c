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
//// 리스트 출력
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
//// 메뉴 출력
//void menu() {
//    printf("\n===== 메뉴 =====\n");
//    printf("1. 숫자 입력 받아서 리스트 처음에 추가\n");
//    printf("2. 숫자 입력 받아서 리스트 마지막에 추가\n");
//    printf("3. 리스트 처음 노드 삭제\n");
//    printf("4. 리스트 마지막 노드 삭제\n");
//    printf("5. 리스트 프린트\n");
//    printf("6. 종료\n");
//}
//
//int main() {
//    ListNode* head = init_list();
//    int choice, data;
//
//    while (1) {
//        menu();
//        printf("메뉴를 선택하세요: ");
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
//            printf("프로그램을 종료합니다.\n");
//            exit(0);
//        default:
//            printf("잘못된 입력입니다. 다시 선택하세요.\n");
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

// 리스트 초기화
ListNode* init_list() {
    ListNode* head = (ListNode*)malloc(sizeof(ListNode));
    head->link = head;
    return head;
}

// 리스트 출력
void print_list(ListNode* head) {
    ListNode* p = head->link;

    if (p == head) {
        printf("리스트가 비어있습니다.\n");
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

// 리스트 처음에 노드 추가
void insert_at_head(ListNode* head, element data) {
    ListNode* newNode = (ListNode*)malloc(sizeof(ListNode));
    newNode->data = data;
    newNode->link = head->link;
    head->link = newNode;
}

// 리스트 마지막에 노드 추가
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

// 리스트 처음 노드 삭제
void delete_first_node(ListNode* head) {
    if (head->link == head) {
        printf("리스트가 비어있습니다.\n");
        return;
    }

    ListNode* removed = head->link;
    head->link = removed->link;
    free(removed);
}

// 리스트 마지막 노드 삭제
void delete_last_node(ListNode* head) {
    if (head->link == head) {
        printf("리스트가 비어있습니다.\n");
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
        printf("메뉴를 선택하세요: ");
        scanf_s("%d", &choice);

        switch (choice) {
        case 1:
            printf("추가할 숫자를 입력하세요: ");
            scanf_s("%d", &data);
            insert_at_head(head, data);
            break;
        case 2:
            printf("추가할 숫자를 입력하세요: ");
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
            printf("프로그램을 종료합니다.\n");
            exit(0);
        default:
            printf("잘못된 입력입니다. 다시 선택하세요.\n");
            break;
        }
    }

    return 0;
}