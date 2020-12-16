#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)

typedef int element;
element queue[5];
int front_q = 0;
int rear_q = 0;

element empty() {
	return front_q == rear_q;
}

element front(element* queue) {
	if (empty())
		return -1;
	else
		return queue[front_q + 1];
}

element back(element* queue) {
	if (empty())
		return -1;
	else
		return queue[rear_q];
}

void index(FILE* stream) {
	fprintf(stream, "\n%d %d", front_q, rear_q);
}

int size() {
	return rear_q - front_q;
}

int pop(element* queue) {
	if (empty())
		return -1;
	else {
		front_q = (front_q + 1) % 5;
		return queue[front_q];
	}
}

int push(element* queue, element x) {
	if (front_q == (rear_q + 1) % 5)
		return -1;
	else {
		rear_q = (rear_q + 1) % 5;
		queue[rear_q] = x;
	}
}

int main(void) {
	FILE* stream1;
	FILE* stream2;
	stream1 = fopen("input.txt", "r");
	stream2 = fopen("output.txt", "w");
	int count, x;
	char buffer[10];
	
	fscanf(stream1, "%d", &count);
	for (int i = 0; i < count; i++) {
		fscanf(stream1, "%s", buffer);
		if (!strcmp(buffer, "push")) {
			fscanf(stream1, "%d", &x);
			if (front_q == (rear_q + 1) % 5) 
				fprintf(stream2, "\n%d", push(queue,x));
			else
				push(queue, x);
		}
		else if (!strcmp(buffer, "index")) {
			index(stream2);
		}
		else if (!strcmp(buffer, "pop")) {
			fprintf(stream2,"\n%d",pop(queue));
		}
		else if (!strcmp(buffer, "front")) {
			fprintf(stream2,"\n%d",front(queue));
		}
		else if (!strcmp(buffer, "back")) {
			fprintf(stream2,"\n%d",back(queue));
		}
		else if (!strcmp(buffer, "empty")) {
			fprintf(stream2,"\n%d",empty());
		}
		else if (!strcmp(buffer, "size")) {
			fprintf(stream2, "\n%d", size());
		}
	}

	fclose(stream1);
	fclose(stream2);
	
	return 0;
}

