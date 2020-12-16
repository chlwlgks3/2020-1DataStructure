#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	int data;
	struct Node* next;
}Node;

int main(void) {
	Node* head = NULL;
	Node* tail = NULL;
	Node* node1 = (Node*)malloc(sizeof(Node));
	Node* node2 = (Node*)malloc(sizeof(Node));
	Node* node3 = (Node*)malloc(sizeof(Node));

	head = node1;
	node1->next = node2;
	node2->next = node3;
	node3->next = NULL;
	tail = node3;

	printf("입력 : ");
	scanf("%d", &node1->data);
	printf("입력 : ");
	scanf("%d", &node2->data);
	printf("입력 : ");
	scanf("%d", &node3->data);

	printf("%d -> %d -> %d", node1->data, node1->next->data,node1->next->next->data );

	free(node1);
	free(node2);
	free(node3);
	return 0;
}