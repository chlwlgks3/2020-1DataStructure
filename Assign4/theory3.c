#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

// 값을 입력하다가 -1을 입력하면 이제까지 저장된 값을 모두 출력합니다

typedef struct NODE {
	int data;
	struct NODE* next;
}Node;

void addFirst(struct NODE** head, int value);
void print(struct NODE* node);

int main(void) {
	Node* head = (Node*)malloc(sizeof(Node));
	head->next = NULL;
	int val = 0;
	printf("입력 : ");
	scanf("%d", &val);
	while (val != -1)	
	{
		addFirst(&head, val);
		scanf("%d", &val);
	}
	print(head->next);

	return 0;
}
void addFirst(struct NODE** head, int value)
{
	Node* node = (Node*)malloc(sizeof(Node));
	node->next = NULL;
	node->data = value;
	node->next = (*head)->next;
	(*head)->next = node;
}
void print(struct NODE* node)
{
	if (node)
	{
		printf("%d", node->data);
		if (node->next)
			printf(" -> ");
		print(node->next);
	}
}
