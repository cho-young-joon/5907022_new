//#include <stdio.h>
//#include <stdlib.h>
//
//
//typedef int element;
//typedef struct DListNode {
//	element data;
//	struct DListNode* llink;
//	struct DListNode* rlink;
//}DListNode;
//
//void init(DListNode* phead) {
//	phead->llink = phead;
//	phead->rlink = phead;
//}
//
//void print_dlist(DListNode* phead) {
//	DListNode* p;
//	for (p = phead->rlink; p != phead; p = p->rlink) {
//		printf("%d -> ", p->data);
//	}
//	printf("\n");
//}
//
//
//// 리스트 처음에 노드 추가
//void insert_at_head(DListNode* head, element data) {
//	DListNode* newNode = (DListNode*)malloc(sizeof(DListNode));
//	newNode->data = data;
//	newNode->link = head->link;
//	head->link = newNode;
//}
//
//// 리스트 마지막에 노드 추가
//void insert_at_tail(ListNode* head, element data) {
//	ListNode* newNode = (ListNode*)malloc(sizeof(ListNode));
//	newNode->data = data;
//	newNode->link = head;
//
//	ListNode* p = head;
//	while (p->link != head) {
//		p = p->link;
//	}
//	p->link = newNode;
//}
//
//// 리스트 처음 노드 삭제
//void delete_first_node(ListNode* head) {
//	if (head->link == head) {
//		printf("리스트가 비어있습니다.\n");
//		return;
//	}
//
//	ListNode* removed = head->link;
//	head->link = removed->link;
//	free(removed);
//}
//
//// 리스트 마지막 노드 삭제
//void delete_last_node(ListNode* head) {
//	if (head->link == head) {
//		printf("리스트가 비어있습니다.\n");
//		return;
//	}
//
//	ListNode* p = head;
//	ListNode* prev = NULL;
//
//	while (p->link != head) {
//		prev = p;
//		p = p->link;
//	}
//
//	prev->link = head;
//	free(p);
//}
//
//
//
//
//
//
//
//int main() {
//	DListNode head;
//	init(&head);
//	int choice, data;
//
//	while (1) {
//		printf("\n===== 메뉴 =====\n");
//		printf("1. 숫자 입력 받아서 리스트 처음에 추가\n");
//		printf("2. 숫자 입력 받아서 리스트 마지막에 추가\n");
//		printf("3. 리스트 처음 노드 삭제\n");
//		printf("4. 리스트 마지막 노드 삭제\n");
//		printf("5. 리스트 프린트\n");
//		printf("6. 종료\n");
//		printf("선택 : ");
//		scanf_s("%d", &choice);
//
//		switch (choice) {
//		case 1:
//			break;
//		case 2:
//			break;
//		case 3:
//			break;
//		case 4:
//			break;
//		case 5:
//			break;
//		case 6:
//			printf("프로그램 종료 \n");
//			return 0;
//		default:
//			printf("잘못된 선택입니다. 다시 입력해주세요. \n");
//		}
//		return 0;
//	}

//#include <stdio.h>
//#include <stdlib.h>
//
//typedef int element;
//typedef struct DListNode {
//    element data;
//    struct DListNode* llink;
//    struct DListNode* rlink;
//} DListNode;
//
//void init(DListNode* phead) {
//    phead->llink = phead;
//    phead->rlink = phead;
//}
//
//void print_dlist(DListNode* phead) {
//    DListNode* p = phead->rlink;
//
//    if (p == phead) {
//        printf("리스트가 비어있습니다.\n");
//        return;
//    }
//
//    printf("%d", p->data);
//    p = p->rlink;
//
//    while (p != phead) {
//        printf(" -> %d", p->data);
//        p = p->rlink;
//    }
//
//    printf(" (head)\n");
//}
//
//// 리스트의 처음에 노드 추가
//void insert_at_head(DListNode* head, element data) {
//    DListNode* newNode = (DListNode*)malloc(sizeof(DListNode));
//    newNode->data = data;
//    newNode->rlink = head->rlink;
//    newNode->llink = head;
//    head->rlink->llink = newNode;
//    head->rlink = newNode;
//}
//
//// 리스트의 마지막에 노드 추가
//void insert_at_tail(DListNode* head, element data) {
//    DListNode* newNode = (DListNode*)malloc(sizeof(DListNode));
//    newNode->data = data;
//    newNode->rlink = head;
//    newNode->llink = head->llink;
//    head->llink->rlink = newNode;
//    head->llink = newNode;
//}
//
//// 리스트의 첫 번째 노드 삭제
//void delete_first_node(DListNode* head) {
//    if (head->rlink == head) {
//        printf("리스트가 비어있습니다.\n");
//        return;
//    }
//
//    DListNode* removed = head->rlink;
//    head->rlink = removed->rlink;
//    removed->rlink->llink = head;
//    free(removed);
//}
//
//// 리스트의 마지막 노드 삭제
//void delete_last_node(DListNode* head) {
//    if (head->rlink == head) {
//        printf("리스트가 비어있습니다.\n");
//        return;
//    }
//
//    DListNode* removed = head->llink;
//    head->llink = removed->llink;
//    removed->llink->rlink = head;
//    free(removed);
//}
//
//int main() {
//    DListNode head;
//    init(&head);
//    int choice, data;
//
//    while (1) {
//        printf("\n===== 메뉴 =====\n");
//        printf("1. 숫자 입력 받아서 리스트 처음에 추가\n");
//        printf("2. 숫자 입력 받아서 리스트 마지막에 추가\n");
//        printf("3. 리스트 처음 노드 삭제\n");
//        printf("4. 리스트 마지막 노드 삭제\n");
//        printf("5. 리스트 출력\n");
//        printf("6. 종료\n");
//        printf("선택: ");
//        scanf_s("%d", &choice);
//
//        switch (choice) {
//        case 1:
//            printf("리스트 처음에 추가할 숫자를 입력하세요: ");
//            scanf_s("%d", &data);
//            insert_at_head(&head, data);
//            break;
//        case 2:
//            printf("리스트 마지막에 추가할 숫자를 입력하세요: ");
//            scanf_s("%d", &data);
//            insert_at_tail(&head, data);
//            break;
//        case 3:
//            delete_first_node(&head);
//            break;
//        case 4:
//            delete_last_node(&head);
//            break;
//        case 5:
//            print_dlist(&head);
//            break;
//        case 6:
//            printf("프로그램 종료\n");
//            return 0;
//        default:
//            printf("잘못된 선택입니다. 다시 입력해주세요.\n");
//        }
//    }
//    return 0;
//}