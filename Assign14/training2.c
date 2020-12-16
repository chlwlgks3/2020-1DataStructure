#include <stdio.h>
#include <stdlib.h>
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)

typedef struct node* ptr;
typedef struct node {
	int data;
	ptr left;
	ptr right;
}node;

void inorder(node** arr, int i, int n,FILE* stream) {
	if (i<=n && arr[i]->data != -1) {
		inorder(arr, 2 * i, n, stream);
		fprintf(stream, "%d ", arr[i]->data);
		inorder(arr, 2 * i + 1, n, stream);
	}
}


void preorder(node** arr, int i, int n, FILE* stream) {
	if (i <= n && arr[i]->data != -1) {
		fprintf(stream, "%d ", arr[i]->data);
		preorder(arr, 2 * i, n, stream);
		preorder(arr, 2 * i + 1, n, stream);
	}
}

void postorder(node** arr, int i, int n, FILE* stream) {
	if (i <= n && arr[i]->data != -1) {
		postorder(arr, 2 * i, n, stream);
		postorder(arr, 2 * i + 1, n, stream);
		fprintf(stream, "%d ", arr[i]->data);
	}
}

int main(void) {
	FILE* stream = fopen("input.txt", "r");
	FILE* stream2 = fopen("output.txt", "w");
	int n, data;
	fscanf(stream, "%d", &n);
	node* arr[128];
	for (int i = 0; i < 128; i++) {
		arr[i] = (node*)malloc(sizeof(node));
		arr[i]->data = -1;
		arr[i]->left = NULL;
		arr[i]->right = NULL;
	}
	for (int i = 1; i <= n; i++) {
		fscanf(stream, "%d", &data);
		arr[i]->data = data;
		arr[i]->left = arr[2 * i];
		arr[i]->right = arr[2 * i + 1];
	}
	inorder(arr, 1, n, stream2);
	fprintf(stream2, "\n");
	preorder(arr, 1, n, stream2);
	fprintf(stream2, "\n");
	postorder(arr, 1, n, stream2);

	fclose(stream);
	fclose(stream2);
	for (int i = 0; i < 128; i++)
		free(arr[i]);

	return 0;
}