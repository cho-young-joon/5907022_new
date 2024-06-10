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
//// ����Ʈ ó���� ��� �߰�
//void insert_at_head(DListNode* head, element data) {
//	DListNode* newNode = (DListNode*)malloc(sizeof(DListNode));
//	newNode->data = data;
//	newNode->link = head->link;
//	head->link = newNode;
//}
//
//// ����Ʈ �������� ��� �߰�
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
//// ����Ʈ ó�� ��� ����
//void delete_first_node(ListNode* head) {
//	if (head->link == head) {
//		printf("����Ʈ�� ����ֽ��ϴ�.\n");
//		return;
//	}
//
//	ListNode* removed = head->link;
//	head->link = removed->link;
//	free(removed);
//}
//
//// ����Ʈ ������ ��� ����
//void delete_last_node(ListNode* head) {
//	if (head->link == head) {
//		printf("����Ʈ�� ����ֽ��ϴ�.\n");
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
//		printf("\n===== �޴� =====\n");
//		printf("1. ���� �Է� �޾Ƽ� ����Ʈ ó���� �߰�\n");
//		printf("2. ���� �Է� �޾Ƽ� ����Ʈ �������� �߰�\n");
//		printf("3. ����Ʈ ó�� ��� ����\n");
//		printf("4. ����Ʈ ������ ��� ����\n");
//		printf("5. ����Ʈ ����Ʈ\n");
//		printf("6. ����\n");
//		printf("���� : ");
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
//			printf("���α׷� ���� \n");
//			return 0;
//		default:
//			printf("�߸��� �����Դϴ�. �ٽ� �Է����ּ���. \n");
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
//        printf("����Ʈ�� ����ֽ��ϴ�.\n");
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
//// ����Ʈ�� ó���� ��� �߰�
//void insert_at_head(DListNode* head, element data) {
//    DListNode* newNode = (DListNode*)malloc(sizeof(DListNode));
//    newNode->data = data;
//    newNode->rlink = head->rlink;
//    newNode->llink = head;
//    head->rlink->llink = newNode;
//    head->rlink = newNode;
//}
//
//// ����Ʈ�� �������� ��� �߰�
//void insert_at_tail(DListNode* head, element data) {
//    DListNode* newNode = (DListNode*)malloc(sizeof(DListNode));
//    newNode->data = data;
//    newNode->rlink = head;
//    newNode->llink = head->llink;
//    head->llink->rlink = newNode;
//    head->llink = newNode;
//}
//
//// ����Ʈ�� ù ��° ��� ����
//void delete_first_node(DListNode* head) {
//    if (head->rlink == head) {
//        printf("����Ʈ�� ����ֽ��ϴ�.\n");
//        return;
//    }
//
//    DListNode* removed = head->rlink;
//    head->rlink = removed->rlink;
//    removed->rlink->llink = head;
//    free(removed);
//}
//
//// ����Ʈ�� ������ ��� ����
//void delete_last_node(DListNode* head) {
//    if (head->rlink == head) {
//        printf("����Ʈ�� ����ֽ��ϴ�.\n");
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
//        printf("\n===== �޴� =====\n");
//        printf("1. ���� �Է� �޾Ƽ� ����Ʈ ó���� �߰�\n");
//        printf("2. ���� �Է� �޾Ƽ� ����Ʈ �������� �߰�\n");
//        printf("3. ����Ʈ ó�� ��� ����\n");
//        printf("4. ����Ʈ ������ ��� ����\n");
//        printf("5. ����Ʈ ���\n");
//        printf("6. ����\n");
//        printf("����: ");
//        scanf_s("%d", &choice);
//
//        switch (choice) {
//        case 1:
//            printf("����Ʈ ó���� �߰��� ���ڸ� �Է��ϼ���: ");
//            scanf_s("%d", &data);
//            insert_at_head(&head, data);
//            break;
//        case 2:
//            printf("����Ʈ �������� �߰��� ���ڸ� �Է��ϼ���: ");
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
//            printf("���α׷� ����\n");
//            return 0;
//        default:
//            printf("�߸��� �����Դϴ�. �ٽ� �Է����ּ���.\n");
//        }
//    }
//    return 0;
//}