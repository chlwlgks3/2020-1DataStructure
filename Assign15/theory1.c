#include <stdio.h>
#include <stdlib.h>
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)
#define MAX_STACK_SIZE 100

typedef struct node* treePointer;
typedef struct node {
	int data;
	treePointer left;
	treePointer right;
}node;

treePointer stack[MAX_STACK_SIZE];
int result[MAX_STACK_SIZE];
int top = -1;
int count = 0;

void print() {
	for (int i = 0; i <= top; i++) {
		if (stack[i]->data != -1) {
			printf("%d ", stack[i]->data);
		}
	}
	printf("\n");
}

void push(treePointer item) {
	if (top >= MAX_STACK_SIZE - 1) {
		printf("stackFull\n");
		return;
	}
	stack[++top]= item;
	print();
}

treePointer pop() {
	if (top == -1) {
		printf("-1\n");
		return NULL;
	}
	print();
	return stack[top--];
}


void iterInorder(treePointer node) {
	int i = 1;
	for (; ;) {
		for (; node; node = node->left)
			push(node);
		node = pop();
		if (!node) break;
		if (node->data != -1) {
			result[i++] = node->data;
			count++;
		}
		node = node->right;
	}
}

int main(void) {
	FILE* stream = fopen("input.txt", "r");
	FILE* stream2 = fopen("output.txt", "w");
	treePointer arr[128];
	for (int i = 0; i < 128; i++) {
		arr[i] = (treePointer)malloc(sizeof(node));
		arr[i]->data = -1;
		arr[i]->left = NULL;
		arr[i]->right = NULL;
	}
	int n, data;
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
	iterInorder(arr[1]);
	printf("-inorder traversal-\n");
	for (int i = 1; i <= count; i++)
		printf("%d ", result[i]);

	return 0;
}