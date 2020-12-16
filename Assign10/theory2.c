#include <stdio.h>
#include <stdlib.h>
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)

typedef	struct listNode* listPointer;
typedef struct listNode {
	int data;
	listPointer link;
}listNode;

int main(void) {
	FILE* stream;
	stream = fopen("input.txt", "r");
	int n, data;
	fscanf(stream, "%d", &n);

	listNode** list = (listNode**)malloc((n+1) * sizeof(listNode*));
	for (int i = 0; i <=n; i++)
		list[i] = (listNode*)malloc(sizeof(listNode));
	
	list[0]->link = list[1];
	for (int i=1; i<=n;i++) {
		fscanf(stream, "%d", &data);
		list[i]->data = data;
		if (i == n) {
			list[i]->link = NULL;
		}
		else
			list[i]->link = list[i + 1];
	}


	fclose(stream);
	stream = fopen("output.txt", "w");

	listPointer head = list[1];
	while (head != NULL) {
		fprintf(stream, "%d ", head->data);
		head = head->link;
	}

	fclose(stream);


	return 0;
}
