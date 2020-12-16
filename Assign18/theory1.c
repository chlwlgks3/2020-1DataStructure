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

element* search(treePointer root, int key) {
	if (!root) return NULL;
	if (key == root->data.key) return &(root->data);
	if (key < root->data.key)
		return search(root->leftChild, key);
	return search(root->rightChild, key);
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
		if (search(arr[1], data) == NULL)
			fprintf(stream2,"-1\n");
		else
			fprintf(stream2,"1\n");
	}
	return 0;

	for (int i = 0; i < 128; i++)
		free(arr[i]);
	fclose(stream);
	fclose(stream2);

}
