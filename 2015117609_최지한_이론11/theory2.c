#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)

typedef struct queue* queuePointer;
typedef struct queue {
	int data;
	queuePointer link;
}queue;
queuePointer front;
queuePointer rear;

void addq(int item) {
	queuePointer temp;
	temp = (queuePointer)malloc(sizeof(*temp));
	temp->data = item;
	temp->link = NULL;
	if (front)
		rear->link = temp;
	else
		front = temp;
	rear = temp;
}

int deleteq() {
	queuePointer temp = front;
	int item;
	if (!temp)
		return -1;
	item = temp->data;
	front = temp->link;
	free(temp);
	return item;
}

int main(void) {
	front = NULL;
	rear = NULL;
	FILE* stream = fopen("input.txt", "r");
	FILE* stream2 = fopen("output.txt", "w");
	int count, x;
	char buffer[10];
	fscanf(stream, "%d", &count);
	for (int i = 0; i < count; i++) {
		fscanf(stream, "%s", buffer);
		if (!strcmp(buffer, "addq")) {
			fscanf(stream, "%d", &x);
			addq(x);
		}
		if (!strcmp(buffer, "deleteq"))
			fprintf(stream2, "%d\n", deleteq());
	}
	fclose(stream);
	fclose(stream2);

	return 0;
}