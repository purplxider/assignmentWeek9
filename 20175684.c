#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

struct node {
	int value;
	struct node *next;
};
typedef struct node node;

void createNode(node *head, int *count);
void printList(node *head);
void printMiddle(node *head, int count);
void reversePrint(node *head, int count);
void deleteOdd(node *head, node *first, int count);

int main() {
	node *first = (node *)malloc(sizeof(node));
	node *head = first;
	int count = 0;

	createNode(head, &count);
	printf("By Order: ");
	printList(head);
	printf("Count: %d\n", count);
	printMiddle(head, count);
	reversePrint(head, count);
	deleteOdd(head, first, count);

	return 0;
}

void createNode(node *head, int *count) {
	while (1) {
		char ch = 0;
		ch = getchar();
		if (ch == EOF) { break; }
		if (ch != '\n') {
			int input = ch - 48;
			node *newNode = (node *)malloc(sizeof(node));
			head->value = input;
			head->next = newNode;
			newNode->next = NULL;
			head = head->next;
			(*count)++;
		}
	}
}

void printList(node *head) {
	while (head->next != NULL) {
		printf("%d ", head->value);
		head = head->next;
	} 
	printf("\n");
}

void printMiddle(node *head, int count) {
	if (count % 2 == 0)
		printf("Middle: No Middle Value (Even Number Of Values)\n");
	else {
		for (int i = 0; i < count / 2; i++)
			head = head->next;

		printf("Middle: %d\n", head->value);
	}
}

void reversePrint(node *head, int count) {
	printf("Reverse: ");
	int *reverse = (int *)malloc(sizeof(int) * count);
	
	for (int i = 0; i < count; i++) {
		reverse[count - i - 1] = head->value;
		head = head->next;
	}

	for (int i = 0; i < count; i++)
		printf("%d ", reverse[i]);

	printf("\n");
}

void deleteOdd(node *head, node *first, int count) {
	printf("Delete Odd: ");
	if (count % 2 == 1) {
		if (count == 1)
			printf("No Nodes\n");
		else {
			if (head->next->next->next != NULL) {
				node *even1 = head->next;
				node *even2 = even1->next->next;

				while (1) {
					even1->next = even2;
					if (even2->next != NULL) {
						even1 = even2;
						even2 = even2->next->next;
					}
					else
						break;
				}
			}
		}
	}
	else {
		if (head->next->next != NULL) {
			node *even1 = head->next;
			node *even2 = even1->next->next;

			while (1) {
				even1->next = even2;
				if (even2->next != NULL && even2->next->next != NULL) {
					even1 = even2;
					even2 = even2->next->next;
				}
				else
					break;
			}
		}
	}

	head = first->next;
	while (head->next != NULL) {
		printf("%d ", head->value);
		head = head->next;
	}
	printf("\n");
}