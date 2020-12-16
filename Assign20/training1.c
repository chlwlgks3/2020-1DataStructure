#include <stdio.h>
#include <stdlib.h>
#define _CRT_SECURE_NO_WARNINGS	
#pragma warning(disable:4996)

typedef struct node* treePointer;
typedef struct node {
	int data;
	treePointer leftChild;
	treePointer rightChild;
}node;

void inorder(treePointer root,FILE* stream) {
	if (root) {
		inorder(root->leftChild,stream);
		fprintf(stream, "%d ", root->data);
		inorder(root->rightChild, stream);
	}
}

void preorder(treePointer root,FILE* stream) {
	if (root) {
		fprintf(stream, "%d ", root->data);
		preorder(root->leftChild, stream);
		preorder(root->rightChild, stream);
	}
}

void postorder(treePointer root,FILE* stream) {
	if (root) {
		postorder(root->leftChild, stream);
		postorder(root->rightChild, stream);
		fprintf(stream, "%d ", root->data);
	}
}

int main(void) {
	FILE* stream = fopen("input.txt", "r");
	FILE* stream2 = fopen("output.txt", "w");
	int n, data;
	treePointer arr[128];
	for (int i = 0; i < 128; i++)
		arr[i] = (treePointer)malloc(sizeof(node));
	fscanf(stream, "%d", &n);
	for (int i = 1; i <= n; i++) { // arr의 index1부터 tree의 노드로 사용
		fscanf(stream, "%d", &data);
		if (data != -1)
			arr[i]->data = data;
		else
			arr[i] = NULL;
	}

	for (int i = 1; i <= n; i++) {
		if (arr[i] != NULL) {
			if (2 * i <= n)
				arr[i]->leftChild = arr[2 * i];
			else
				arr[i]->leftChild = NULL;
			if (2 * i + 1 <= n)
				arr[i]->rightChild = arr[2 * i + 1];
			else
				arr[i]->rightChild = NULL;
		}
	}
	inorder(arr[1], stream2);
	fprintf(stream2, "\n");
	preorder(arr[1], stream2);
	fprintf(stream2, "\n");
	postorder(arr[1], stream2);

	fclose(stream);
	fclose(stream2);
	for(int i=0;i<128;i++)
		free(arr[i]);

	return 0;
}