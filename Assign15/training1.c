#include <stdio.h>
#include <stdlib.h>
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)
#define MAX_QUEUE_SIZE 100

typedef struct node* treePointer;
typedef struct node {
	int data;
	treePointer left;
	treePointer right;
}node;

typedef struct {
	treePointer queue[MAX_QUEUE_SIZE];
	int front, rear;
}QueueType;

treePointer copy(treePointer original) {
	treePointer temp;
	if (original) {
		temp = (treePointer)malloc(sizeof(*temp));
		temp->left = copy(original->left);
		temp->right = copy(original->right);
		temp->data = original->data;
		return temp;
	}
	return NULL;
}
int is_empty(QueueType* q) {
	return (q->front == q->rear);
}

int is_full(QueueType* q) {
	return ((q->rear + 1)%MAX_QUEUE_SIZE == q->front);
}

void enquque(QueueType* q, treePointer item) {
	if (is_full(q)) {
		fprintf(stderr, "큐가가득찬상태입니다.");
		exit(EXIT_FAILURE);
	}
	q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
	q->queue[q->rear] = item;
}

treePointer dequeue(QueueType* q) {
	if (is_empty(q)) {
		fprintf(stderr, "큐가공백상태입니다.");
		exit(EXIT_FAILURE);
	}
	q->front = (q->front + 1) % MAX_QUEUE_SIZE;
	return q->queue[q->front];
}

void init(QueueType* q) {
	q->front = q->rear = 0;
}

void level_order(treePointer ptr,FILE* stream) {
	QueueType q;
	init(&q);
	if (ptr == NULL) return;
	enquque(&q, ptr);
	while (!is_empty(&q)) {
		ptr = dequeue(&q);
		fprintf(stream,"%d ", ptr->data);
		if (ptr->left)
			enquque(&q, ptr->left);
		if (ptr->right)
			enquque(&q, ptr->right);
	}
}

int main(void) {
	FILE* stream = fopen("input.txt", "r");
	FILE* stream2 = fopen("output.txt", "w");
	int n, data;
	treePointer arr[128];
	fscanf(stream, "%d", &n);
	for (int i = 0; i < 128; i++) {
		arr[i] = (node*)malloc(sizeof(node));
		arr[i]->data = -1;
		arr[i]->left = NULL;
		arr[i]->right = NULL;
	}
	for (int i = 1; i <= n; i++) {
		fscanf(stream, "%d", &data);
		arr[i]->data = data;
		if (2 * i <= n)
			arr[i]->left = arr[2 * i];
		else
			arr[i]->left = NULL;
		if (2 * i + 1 <= n)
			arr[i]->right = arr[2 * i + 1];
		else
			arr[i]->right = NULL;
	}
	treePointer COPY;
	COPY = copy(arr[1]);
	level_order(COPY,stream2);
	for (int i = 0; i < 128; i++)
		free(arr[i]);
	fclose(stream);
	fclose(stream2);


	return 0;
}