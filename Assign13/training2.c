#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)

typedef struct node* nodePointer;
typedef struct node {
	int data;
	nodePointer llink;
	nodePointer rlink;
}node;

typedef struct dequeType {
	nodePointer head;
	nodePointer tail;
}dequeType;

//llink, rlink, data의 정보를 가진 node를 함수안에서 생성 후 반환
nodePointer create_node(nodePointer llink, nodePointer rlink, int data) {
	nodePointer node = (nodePointer)malloc(sizeof(*node));
	node->llink = llink;
	node->rlink = rlink;
	node->data = data;
	return node;
}

int empty(dequeType* dq) {
	return (dq->head == NULL && dq->tail == NULL);
}

void push_front(dequeType* dq, int data) {
	nodePointer new_node = create_node(NULL, dq->head, data); //왼쪽링크가 NULL, 오른쪽링크가 dq->head, data = data인 new_node생성
	if (empty(dq))
		dq->tail = new_node;
	else
		dq->head->llink = new_node;
	dq->head = new_node;
}

void push_back(dequeType* dq, int data) {
	nodePointer new_node = create_node(dq->tail, NULL, data);
	if (empty(dq))
		dq->head = new_node;
	else
		dq->tail->rlink = new_node;
	dq->tail = new_node;
}

int pop_front(dequeType* dq) {
	int result;
	nodePointer removed_node;
	if (empty(dq)) return -1;
	else {
		removed_node = dq->head;
		result = removed_node->data;
		dq->head = dq->head->rlink;
		free(removed_node);
		if (dq->head == NULL)
			dq->tail = NULL;
		else
			dq->head->llink = NULL;
	}
	return result;
}

int pop_back(dequeType* dq) {
	int result;
	nodePointer removed_node;
	if (empty(dq)) return -1;
	else {
		removed_node = dq->tail;
		result = removed_node->data;
		dq->tail = dq->tail->llink;
		free(removed_node);
		if (dq->tail == NULL)
			dq->head = NULL;
		else
			dq->tail->rlink = NULL;
	}
	return result;
}

int size(dequeType* dq) {
	int count = 0;
	nodePointer temp;
	for (temp = dq->head; temp; temp = temp->rlink)
		count++;
	return count;
}

int front(dequeType* dq) {
	if (empty(dq))
		return -1;
	return dq->head->data;
}

int back(dequeType* dq) {
	if (empty(dq))
		return -1;
	return dq->tail->data;
}

int main(void) {
	dequeType dq = { NULL,NULL };
	FILE* stream = fopen("input.txt", "r");
	FILE* stream2 = fopen("output.txt", "w");
	char buffer[128];
	int data, n;
	fscanf(stream, "%d", &n);
	for (int i = 0; i < n; i++) {
		fscanf(stream, "%s", buffer);
		if (!strcmp(buffer, "push_back")) {
			fscanf(stream, "%d", &data);
			push_back(&dq, data);
		}
		else if (!strcmp(buffer, "push_front")) {
			fscanf(stream, "%d", &data);
			push_front(&dq, data);
		}
		else if (!strcmp(buffer, "front"))
			fprintf(stream2, "\n%d", front(&dq));
		else if (!strcmp(buffer, "back"))
			fprintf(stream2, "\n%d", back(&dq));
		else if (!strcmp(buffer, "size"))
			fprintf(stream2, "\n%d", size(&dq));
		else if (!strcmp(buffer, "empty"))
			fprintf(stream2, "\n%d", empty(&dq));
		else if (!strcmp(buffer, "pop_front"))
			fprintf(stream2, "\n%d", pop_front(&dq));
		else if (!strcmp(buffer, "pop_back"))
			fprintf(stream2, "\n%d", pop_back(&dq));
	}
	fclose(stream);
	fclose(stream2);
	
	return 0;
}