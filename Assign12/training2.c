#include <stdio.h>
#include <stdlib.h>
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)

typedef struct listNode* listPointer;
typedef struct listNode {
	int data;
	listPointer link;
}listNode;

void insertRear(listPointer* last, listPointer node) {
	//list의 마지막노드가 last인 원형리스트의 뒤에 node삽입
	if (!(*last)) {
		*last = node;
		node->link = node;
	}
	else {
		node->link = (*last)->link;
		(*last)->link = node;
		*last = node;
	}
}

int length(listPointer last) {
	listPointer temp;
	int count = 0;
	if (last) {
		temp = last;
		do {
			count++;
			temp = temp->link;
		} while (temp != last);
	}
	return count;
}

int main(void) {
	FILE* stream = fopen("input.txt", "r");
	FILE* stream2 = fopen("output.txt", "w");
	int n, m, data;
	listPointer last = NULL;
	listPointer temp;
	fscanf(stream, "%d", &n);
	for (int i = 0; i < n; i++) {
		fscanf(stream, "%d", &data);
		temp = (listPointer)malloc(sizeof(*temp));
		temp->data = data;
		temp->link = NULL;
		insertRear(&last, temp);
	}
	temp = last;
	for (int i = 0; i < 2; i++) {
		do {
			fprintf(stream2, "%d ", temp->link->data);
			temp = temp->link;
		} while (temp != last);
	}
	fprintf(stream2, "\n");
	fscanf(stream, "%d", &m);
	for (int i = 0; i < m; i++) {
		fscanf(stream, "%d", &data);
		temp = (listPointer)malloc(sizeof(*temp));
		temp->data = data;
		temp->link = NULL;
		insertRear(&last, temp);
	}
	for (int i = 0; i < 2; i++) {
		do {
			fprintf(stream2, "%d ", temp->link->data);
			temp = temp->link;
		} while (temp != last);
	}
	fprintf(stream2, "\n");
	fprintf(stream2, "%d",length(last));

	fclose(stream);
	fclose(stream2);
	return 0;
}