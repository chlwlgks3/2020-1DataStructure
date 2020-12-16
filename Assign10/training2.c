#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)

typedef	struct listNode* listPointer;
typedef struct listNode {
	int data;
	listPointer link;
}listNode;

void delete(listPointer* head, listPointer trail, listPointer x) {
	if (trail)
		trail->link = x->link;
	else
		*head = (*head)->link;
	free(x);
}
int main(void) {
	listPointer head = NULL;
	FILE* stream1;
	FILE* stream2;
	stream1 = fopen("input.txt", "r");
	stream2 = fopen("output.txt", "w");

	int n, n2; // 정수의 개수를 저장할 변수n 선언
	int data, data2; //input으로 부터 받은 정수를 저장할 변수data 선언
	int pos;
	fscanf(stream1, "%d", &n);

	listNode** list = (listNode**)malloc((n + 1) * sizeof(listNode*));
	for (int i = 0; i <= n; i++)
		list[i] = (listNode*)malloc(sizeof(listNode));

	list[0] = list[1];
	for (int i = 1; i <= n; i++) {
		fscanf(stream1, "%d", &data);
		list[i]->data = data;
		if (i == n) {
			list[i]->link = NULL;
		}
		else
			list[i]->link = list[i + 1];
	}
	head = list[1];
	while (head != NULL) {
		fprintf(stream2, "%d ", head->data);
		head = head->link;
	}
	fprintf(stream2, "\n");

	for (int i = 0; i < n2; i++) {
		fscanf(stream1, "%d %d", &data2, &pos);
		delete(&list[0], list[pos], data2);
		listPointer p = list[1];
		while (p != NULL) {
			fprintf(stream2, "%d ", p->data);
			p = p->link;
		}
		fprintf(stream2, "\n");
	}

	return 0;
}

