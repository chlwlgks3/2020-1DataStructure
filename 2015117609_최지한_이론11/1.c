#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)

typedef struct stack* stackPointer;
typedef struct stack{
	int data;
	stackPointer link;
}stack;
stackPointer top;

void push(int item) {
	stackPointer temp;
	temp = (stackPointer)malloc(sizeof(*temp));
	temp->data = item;
	temp->link = top;
	top = temp;
}

int pop() {
	stackPointer temp = top;
	int item;
	if (!temp) {
		return -1;
	}
	item = temp->data;
	top = temp->link;
	free(temp);
	return item;
}

int main(void) {
	top = NULL;
	FILE* stream;
	FILE* stream2;
	stream = fopen("input.txt", "r");
	stream2 = fopen("output.txt", "w");
	int count;
	int x;
	char buffer[10];
	fscanf(stream, "%d", &count);
	for (int i = 0; i < count; i++) {
		fscanf(stream, "%s", buffer);
		if (!strcmp(buffer, "push")) {
			fscanf(stream, "%d", &x);
			push(x);
		}
		if (!strcmp(buffer, "pop"))
			fprintf(stream2, "%d\n", pop());
	}
	fclose(stream);
	fclose(stream2);
	return 0;
}