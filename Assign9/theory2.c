#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)

int queue[20];
int rear_q = -1;
int front_q = -1;

int empty() {
	return rear_q == front_q;
}

int front(int* queue) {
	if (empty())
		return -1;
	else 
		return queue[front_q + 1];
}

int back(int* queue) {
	if (empty())
		return -1;
	else
		return queue[rear_q];
}

int size() {
	return rear_q - front_q;
}

int pop(int* queue) {
	if (empty())
		return -1;
	else
		return queue[++front_q];
}

int push(int x) {
	if (rear_q >= 19)
		return -1;
	else
		queue[++rear_q] = x;
}

int main(void) {
	FILE* stream1;
	FILE* stream2;
	int count, x;
	char buffer[10];

	stream1 = fopen("input.txt", "r");
	stream2 = fopen("output.txt", "w");
	fscanf(stream1, "%d", &count);
	
	for (int i = 0; i < count; i++) {
		fscanf(stream1, "%s", buffer);
		if (!strcmp(buffer, "push")) {
			fscanf(stream1, "%d", &x);
			if (rear_q >= 19) 
				fprintf(stream2, "\n%d", push(x));
			else
				push(x);
		}
		else if (!strcmp(buffer, "front")) {
			fprintf(stream2, "\n%d", front(queue));
		}
		else if (!strcmp(buffer, "back")) {
			fprintf(stream2, "\n%d", back(queue));
		}
		else if (!strcmp(buffer,"size")) {
			fprintf(stream2, "\n%d", size());
		}
		else if (!strcmp(buffer, "empty")) {
			fprintf(stream2, "\n%d", empty());
		}
		else if (!strcmp(buffer, "pop")) {
			fprintf(stream2, "\n%d", pop(queue));
		}
	}

	fclose(stream1);
	fclose(stream2);
	return 0;
}