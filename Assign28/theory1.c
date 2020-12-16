#include <stdio.h>
#include <stdlib.h>
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)
#include <string.h>
#define MAX(a,b) (a)>(b) ? (a) : (b)
#define MAX_QUEUE_SIZE 100

typedef struct AvlNode* nodePointer;
typedef struct AvlNode {
	char data[10];
	struct AvlNode* left_child;
	struct AvlNode* right_child;
}AvlNode;

typedef struct {
	nodePointer queue[MAX_QUEUE_SIZE];
	int front, rear;
}QueueType;

//queue 초기화 함수
void init(QueueType* q) {
	q->front = q->rear = 0;
}

int is_empty(QueueType* q) {
	return (q->front == q->rear);
}

int is_full(QueueType* q) {
	return ((q->rear + 1) % MAX_QUEUE_SIZE == q->front);
}

void enquque(QueueType* q, nodePointer item) {
	if (is_full(q)) {
		fprintf(stderr, "큐가가득찬상태입니다.");
		exit(EXIT_FAILURE);
	}
	if (item == NULL) return;
	q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
	q->queue[q->rear] = item;
}

nodePointer dequeue(QueueType* q) {
	if (is_empty(q)) {
		fprintf(stderr, "큐가공백상태입니다.");
		exit(EXIT_FAILURE);
	}
	q->front = (q->front + 1) % MAX_QUEUE_SIZE;
	return q->queue[q->front];
}

void level_order(nodePointer ptr, char* result[]) {
	QueueType q;
	int i = 0;
	init(&q);
	if (ptr == NULL) return;
	enquque(&q, ptr);
	while (!is_empty(&q)) {
		ptr = dequeue(&q);
		if (ptr->data != NULL) {
			strcpy(result[i++], ptr->data);
		}
		if (ptr->left_child)
			enquque(&q, ptr->left_child);
		if (ptr->right_child)
			enquque(&q, ptr->right_child);
	}
}

//LL회전함수
AvlNode* rotate_LL(AvlNode* parent) {
	AvlNode* child = parent->left_child;
	parent->left_child = child->right_child;
	child->right_child = parent;
	return child;
}

//RR회전함수
AvlNode* rotate_RR(AvlNode* parent) {
	AvlNode* child = parent->right_child;
	parent->right_child = child->left_child;
	child->left_child = parent;
	return child;
}

//RL회전함수
AvlNode* rotate_RL(AvlNode* parent) {
	AvlNode* child = parent->right_child;
	parent->right_child = rotate_LL(child);
	return rotate_RR(parent);
}

//LR회전함수
AvlNode* rotate_LR(AvlNode* parent) {
	AvlNode* child = parent->left_child;
	parent->left_child = rotate_RR(child);
	return rotate_LL(parent);
}

//트리의 높이반환
int get_height(AvlNode* node) {
	int height = 0;
	if (node != NULL)
		height = 1 + MAX(get_height(node->left_child), get_height(node->right_child));
	return height;
}

//노드의 왼쪽서브트리 높이와 오른쪽서브트리높이차(균형인수) 반환
int get_height_diff(AvlNode* node) {
	if (node == NULL) return 0;
	return get_height(node->left_child) - get_height(node->right_child);
}

//균형트리로 만드는 함수
AvlNode* rebalance(AvlNode** node) {
	int height_diff = get_height_diff(*node);
	if (height_diff > 1) {
		if ( get_height_diff((*node)->left_child) > 0 )
			*node = rotate_LL(*node);
		else
			*node = rotate_LR(*node);
	}
	else if (height_diff < -1) {
		if (get_height_diff((*node)->right_child) < 0)
			*node = rotate_RR(*node);
		else
			*node = rotate_RL(*node);
	}
	return *node;
}

AvlNode* avl_add(AvlNode** root, char* new_key) {
	if (*root == NULL) {
		*root = (AvlNode*)malloc(sizeof(AvlNode));
		strcpy((*root)->data, new_key);
		(*root)->left_child = (*root)->right_child = NULL;
	}
	else if (strcmp(new_key,(*root)->data) == -1) {
		(*root)->left_child = avl_add(&((*root)->left_child), new_key);
		*root = rebalance(root);
	}
	else if (strcmp(new_key, (*root)->data) == 1) {
		(*root)->right_child = avl_add(&((*root)->right_child), new_key);
		*root = rebalance(root);
	}
	else {
		fprintf(stderr, "중복된 키 에러\n");
		exit(1);
	}
	return *root;
}

int main(void) {
	FILE* stream = fopen("input.txt", "r");
	FILE* stream2 = fopen("output.txt", "w");
	int n;
	char data[5];
	char** result;		
	AvlNode* root = NULL;
	fscanf(stream, "%d", &n);
	result = (char**)malloc(n * sizeof(*result));
	for (int i = 0; i < n; i++)
		result[i] = (char*)malloc(10 * sizeof(*result[i]));
	for (int i = 0; i < n; i++) {
		fscanf(stream, "%s", data);
		avl_add(&root, data);
	}
	level_order(root, result);
	for (int i = 0; i < n; i++)
		fprintf(stream2,"%s\n", result[i]);
	
	free(result);
	fclose(stream);
	fclose(stream2);

	return 0;
}