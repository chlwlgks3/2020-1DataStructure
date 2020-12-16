#include <stdio.h>
#include <stdlib.h>
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)
#define MAX_STACK_SIZE 100

typedef struct element {
	int key;
}element;
typedef struct node* treePointer;
typedef struct node {
	element data;
	treePointer leftChild, rightChild;
}node;

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

element* iterSearch(treePointer tree, int k) {
	while (tree) {
		if (k == tree->data.key)
			return &(tree->data);
		if (k < tree->data.key)
			tree = tree->leftChild;
		else
			tree = tree->rightChild;
	}
	return NULL;
}

int main(void) {
	FILE* stream = fopen("input.txt", "r");
	FILE* stream2 = fopen("output.txt", "w");
	treePointer arr[128];
	for (int i = 0; i < 128; i++) {
		arr[i] = (treePointer)malloc(sizeof(node));
		arr[i] = NULL;
	}
	int n, m, data;
	fscanf(stream, "%d %d", &n, &m);
	for (int i = 1; i <= n; i++) {
		fscanf(stream, "%d", &data);
		insert_node(&arr[1], data);
	}

	for (int i = 0; i < m; i++) {
		fscanf(stream, "%d", &data);
		if (iterSearch(arr[1], data) == NULL)
			fprintf(stream2,"-1\n");
		else
			fprintf(stream2,"1\n");
	}

	for (int i = 0; i < 128; i++)
		free(arr[i]);
	fclose(stream);
	fclose(stream2);
	return 0;
}
