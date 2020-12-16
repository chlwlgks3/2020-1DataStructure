#include <stdio.h>
#include <stdlib.h>
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)
#define MAX_QUEUE_SIZE 100

int result[128];
int count = 0;
typedef struct node* treePointer;
typedef struct element {
	int key;
}element;
typedef struct node {
	element data;
	treePointer leftChild;
	treePointer rightChild;
}node;

typedef struct {
	treePointer queue[MAX_QUEUE_SIZE];
	int front, rear;
}QueueType;

void init(QueueType* q) {
	q->front = q->rear = 0;
}

int is_empty(QueueType* q) {
	return (q->front == q->rear);
}
int is_full(QueueType* q) {
	return ((q->rear + 1) % MAX_QUEUE_SIZE == q->front);
}

void enquque(QueueType* q, treePointer item) {
	q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
	q->queue[q->rear] = item;
}

treePointer dequeue(QueueType* q) {
	q->front = (q->front + 1) % MAX_QUEUE_SIZE;
	return q->queue[q->front];
}

void level_order(treePointer ptr, int* result) {
	QueueType q;
	int i = 0;
	init(&q);
	if (ptr == NULL) return;
	enquque(&q, ptr);
	while (!is_empty(&q)) {
		ptr = dequeue(&q);
		if (ptr->data.key != -1) {
			result[i++] = ptr->data.key;
			count++;
		}
		if (ptr->leftChild)
			enquque(&q, ptr->leftChild);
		if (ptr->rightChild)
			enquque(&q, ptr->rightChild);
	}
}

void insert_node(node** root, int key) {
	treePointer p, t; // p�� �θ���,t�� ������
	treePointer n;

	t = *root;
	p = NULL;
	while (t != NULL) {
		if (key == t->data.key) return;
		p = t;
		if (key < p->data.key) t = p->leftChild;
		else t = p->rightChild;
	}

	n = (node*)malloc(sizeof(node));
	if (n == NULL) return;
	n->data.key = key;
	n->leftChild = n->rightChild = NULL;
	if (p != NULL)
		if (key < p->data.key)
			p->leftChild = n;
		else
			p->rightChild = n;
	else
		*root = n;
}

element* search(treePointer root, int key) {
	if (!root) return NULL;
	if (key == root->data.key) return &(root->data);
	if (key < root->data.key)
		return search(root->leftChild, key);
	return search(root->rightChild, key);
}

void delete_node(node** root, int key) {
	node* p, *child, *succ, *succ_p, *t;

	//key��带 ���� ��� t�� Ž��, p�� t�� �θ���
	p = NULL;
	t = *root;
	//key�� ���� ��� tŽ���Ѵ�
	while (t != NULL && t->data.key != key) {
		p = t;
		t = (key < p->data.key) ? p->leftChild : p->rightChild;
	}
	//Ž���� ����� ������ t�� NULL�̸� Ʈ���ȿ� key�� ���°��̴�
	if (t == NULL) 	
		return;
	
	//ù��° ���: �ܸ������ ���
	if ((t->leftChild == NULL) && (t->rightChild == NULL)) {
		if (p != NULL) {
			//�θ����� �ڽ��ʵ带 NULL�� �����.
			if (p->leftChild == t)
				p->leftChild = NULL;
			else
				p->rightChild = NULL;
		}
		else
			*root = NULL;
	}
	//�ι�° ���: �ϳ��� �ڽĸ� ������ ���
	else if ((t->leftChild == NULL) || (t->rightChild == NULL)) {
		child = (t->leftChild != NULL) ? t->leftChild : t->rightChild;
		if (p != NULL) {
			if (p->leftChild == t) //�θ� �ڽİ� ����
				p->leftChild = child;
			else
				p->rightChild = child;
		}
		else // ���� �θ��尡 NULL�̸� �����Ǵ� ��尡 ��Ʈ���ȴ�.
			*root = child;
	}
	//����° ���: �ΰ��� �ڽ��� ������ ���
	else {
		//���� ���� Ʈ������ �İ��� ã�´�.
		succ_p = t;
		succ = t->leftChild;
		//�İ��ڸ� ã�Ƽ� ��� ���������� �̵�
		while (succ->rightChild != NULL) {
			succ_p = succ;
			succ = succ->rightChild;
		}
		//�ļ����� �θ�� �ڽ��� ����
		if (succ_p->rightChild == succ)
			succ_p->rightChild = succ->leftChild;
		else
			succ_p->leftChild = succ->leftChild;
		//�ļ��ڰ� ���� Ű ���� �����忡 ����
		t->data.key = succ->data.key;
		//������ �ļ��� ����
		t = succ;
	}
	free(t);
}

int main(void) {
	FILE* stream = fopen("input.txt", "r");
	FILE* stream2 = fopen("output.txt", "w");
	treePointer root = NULL;
	int n, m, data;
	fscanf(stream, "%d %d", &n, &m);
	for (int i = 1; i <= n; i++) {
		fscanf(stream, "%d", &data);
		insert_node(&root, data);
	}
	level_order(root, result);
	for (int i = 0; i < count; i++)
		fprintf(stream2,"%d ", result[i]);
	fprintf(stream2, "\n");
	count = 0; // count �ٽ� 0���� �ʱ�ȭ

	for (int i = 0; i < m; i++) {
		fscanf(stream, "%d", &data);
		if (search(root, data) == NULL) //data�� Ʈ���� ���ٸ� -1���
			fprintf(stream2, "-1\n");
		else {
			delete_node(&root, data);
			count = 0; // count �ٽ� 0���� �ʱ�ȭ
			level_order(root, result);
			for (int i = 0; i < count; i++)
				fprintf(stream2, "%d ", result[i]);
			fprintf(stream2, "\n");
		}
	}

	fclose(stream);
	fclose(stream2);
	
	return 0;
}