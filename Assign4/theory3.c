#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

// ���� �Է��ϴٰ� -1�� �Է��ϸ� �������� ����� ���� ��� ����մϴ�

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
	printf("�Է� : ");
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
