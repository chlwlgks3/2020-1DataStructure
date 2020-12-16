#include <stdio.h>
#include <stdlib.h>

struct Node {
	int data;
	struct Node* next;
};

int main(void) {
	struct Node* head = NULL;

	struct Node* node1 = (struct Node*)malloc(sizeof(struct Node));
	node1->data = 10;
	head = node1;

	struct Node* node2 = (struct Node*)malloc(sizeof(struct Node));
	node2->data = 20;
	node1->next = node2;
	node2->next = NULL;

	printf("%d->%d", node1->data, node1->next->data);
	free(node1);
	free(node2);

	return 0;
}