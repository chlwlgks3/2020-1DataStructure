#include <stdio.h>
#include <stdlib.h>
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)
#define MAX_QUEUE_SIZE 100

int result[128];
int count = 0;
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

void init(QueueType* q) {
	q->front = q->rear = 0;
}

void print(QueueType* q,FILE* stream) {
	if (q->front == q->rear) {
		fprintf(stream,"-1");
	}
	else {
		if (q->front <= q->rear) {
			for (int i = q->front + 1; i <= q->rear; i++) {
				fprintf(stream,"%d ", q->queue[i]->data);
			}
		}
		else {
			for (int i = q->front + 1; i < MAX_QUEUE_SIZE; i++) {
				fprintf(stream,"%d ", q->queue[i]->data);
			}
			for (int i = 0; i <= q->rear; i++) {
				fprintf(stream,"%d ", q->queue[i]->data);
			}
		}
	}
	fprintf(stream,"\n");
}

int is_empty(QueueType* q) {
	return (q->front == q->rear);
}

int is_full(QueueType* q) {
	return ((q->rear + 1) % MAX_QUEUE_SIZE == q->front);
}

void enquque(QueueType* q, treePointer item,FILE* stream) {
	if (is_full(q)) {
		fprintf(stderr, "큐가가득찬상태입니다.");
		exit(EXIT_FAILURE);
	}
	if (item->data == -1) return;
	q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
	q->queue[q->rear] = item;
	print(q,stream);
}

treePointer dequeue(QueueType* q,FILE* stream) {
	if (is_empty(q)) {
		fprintf(stderr, "큐가공백상태입니다.");
		exit(EXIT_FAILURE);
	}
	q->front = (q->front + 1) % MAX_QUEUE_SIZE;
	print(q,stream);
	return q->queue[q->front];
}

void level_order(treePointer ptr, int* result, FILE* stream) {
	QueueType q;
	int i = 0;
	init(&q);
	if (ptr == NULL) return;
	fprintf(stream, "-queue-\n");
	enquque(&q, ptr, stream);
	while (!is_empty(&q)) {
		ptr = dequeue(&q, stream);
		if (ptr->data != -1) {
			result[i++] = ptr->data;
			count++;
		}
		if (ptr->left)
			enquque(&q, ptr->left, stream);
		if (ptr->right)
			enquque(&q, ptr->right, stream);
	}
}

int main(void) {
	FILE* stream = fopen("input.txt", "r");
	FILE* stream2 = fopen("output.txt", "w");
	int n, data;
	treePointer arr[128];
	for (int i = 0; i < 128; i++) {
		arr[i] = (treePointer)malloc(sizeof(node));
		arr[i]->data = -1;
		arr[i]->left = NULL;
		arr[i]->right = NULL;
	}
	fscanf(stream, "%d", &n);
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
	level_order(arr[1], result, stream2);
	fprintf(stream2, "\n\n-level order traversal-\n");
	for(int i=0;i<count;i++)
		fprintf(stream2, "%d ", result[i]);

	fclose(stream);
	fclose(stream2);
	for (int i = 0; i < 128; i++)
		free(arr[i]);
	
	return 0;
}