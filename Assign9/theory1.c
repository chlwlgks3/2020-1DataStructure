#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)

int stack[20];
int top_stack = -1;

int empty() {
	if (top_stack == -1)
		return 1;
	else
		return 0;
}

int top(int* stack) {
	if (empty())
		return -1;
	else
		return stack[top_stack];
}

int size() {
	return top_stack + 1;
}

int pop(int* stack) {
	if (empty())
		return -1;
	else 
		return stack[top_stack--];
}

int push(int x) {
	if (top_stack >= 19)
		return -1;
	else
		stack[++top_stack] = x;
}

int main(void) {
	FILE* stream1;
	FILE* stream2;
	stream1 = fopen("input.txt", "r");
	stream2 = fopen("output.txt", "w");
	int count,x;
	char buffer[10];
	fscanf(stream1, "%d", &count);
	for (int i = 0; i < count; i++) {
		fscanf(stream1, "%s",buffer);
		if (!strcmp(buffer, "push")) {
			fscanf(stream1, "%d", &x);
			if (top_stack >= 19)
				fprintf(stream2, "\n%d", push(x));
			else
				push(x);
		}
		else if (!strcmp(buffer, "top")) {
			fprintf(stream2, "\n%d", top(stack));
		}
		else if (!strcmp(buffer, "size")) {
			fprintf(stream2, "\n%d", size());
		}
		else if (!strcmp(buffer, "empty")) {
			fprintf(stream2, "\n%d", empty());
		}
		else if (!strcmp(buffer, "pop")) {
			fprintf(stream2, "\n%d", pop(stack));
		}
	}
	fclose(stream1);
	fclose(stream2);

	return 0;
}

