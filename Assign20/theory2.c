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
	treePointer p, t; // p는 부모노드,t는 현재노드
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

	//key노드를 갖는 노드 t를 탐색, p는 t의 부모노드
	p = NULL;
	t = *root;
	//key를 갖는 노드 t탐색한다
	while (t != NULL && t->data.key != key) {
		p = t;
		t = (key < p->data.key) ? p->leftChild : p->rightChild;
	}
	//탐색이 종료된 시점에 t가 NULL이면 트리안에 key가 없는것이다
	if (t == NULL) 	
		return;
	
	//첫번째 경우: 단말노드인 경우
	if ((t->leftChild == NULL) && (t->rightChild == NULL)) {
		if (p != NULL) {
			//부모노드의 자식필드를 NULL로 만든다.
			if (p->leftChild == t)
				p->leftChild = NULL;
			else
				p->rightChild = NULL;
		}
		else
			*root = NULL;
	}
	//두번째 경우: 하나의 자식만 가지는 경우
	else if ((t->leftChild == NULL) || (t->rightChild == NULL)) {
		child = (t->leftChild != NULL) ? t->leftChild : t->rightChild;
		if (p != NULL) {
			if (p->leftChild == t) //부모를 자식과 연결
				p->leftChild = child;
			else
				p->rightChild = child;
		}
		else // 만약 부모노드가 NULL이면 삭제되는 노드가 루트가된다.
			*root = child;
	}
	//세번째 경우: 두개의 자식을 가지는 경우
	else {
		//왼쪽 서브 트리에서 후계자 찾는다.
		succ_p = t;
		succ = t->leftChild;
		//후계자를 찾아서 계속 오른쪽으로 이동
		while (succ->rightChild != NULL) {
			succ_p = succ;
			succ = succ->rightChild;
		}
		//후속자의 부모와 자식을 연결
		if (succ_p->rightChild == succ)
			succ_p->rightChild = succ->leftChild;
		else
			succ_p->leftChild = succ->leftChild;
		//후속자가 가진 키 값을 현재노드에 복사
		t->data.key = succ->data.key;
		//원래의 후속자 삭제
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
	count = 0; // count 다시 0으로 초기화

	for (int i = 0; i < m; i++) {
		fscanf(stream, "%d", &data);
		if (search(root, data) == NULL) //data가 트리에 없다면 -1출력
			fprintf(stream2, "-1\n");
		else {
			delete_node(&root, data);
			count = 0; // count 다시 0으로 초기화
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