#include <stdio.h>
#include <stdlib.h>
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)

typedef struct node* treePointer;
typedef struct node{
	int data;
	treePointer left;
	treePointer right;
}node;

int equal(treePointer first, treePointer second) {
	return ((!first && !second) || (first&&second && (first->data == second->data) && equal(first->left, second->left) && equal(first->right, second->right)));
}
int main(void) {
	FILE* stream = fopen("input.txt", "r");
	FILE* stream2 = fopen("output.txt", "w");
	int n, data;
	treePointer first[128];
	treePointer second[128];
	for (int i = 0; i < 128; i++) {
		first[i] = (treePointer)malloc(sizeof(node));
		second[i] = (treePointer)malloc(sizeof(node));
		first[i]->data = -1;
		first[i]->left = NULL;
		first[i]->right = NULL;
		second[i]->data = -1;
		second[i]->left = NULL;
		second[i]->right = NULL;
	}
	fscanf(stream, "%d", &n);
	for (int i = 1; i <= n; i++) {
		fscanf(stream, "%d", &data);
		first[i]->data = data;
		if (2 * i <= n)
			first[i]->left = first[2 * i];
		else
			first[i]->left = NULL;
		if (2 * i + 1 <= n)
			first[i]->right = first[2 * i + 1];
		else
			first[i]->right = NULL;
	}
	for (int i = 1; i <= n; i++) {
		fscanf(stream, "%d", &data);
		second[i]->data = data;
		if (2 * i <= n)
			second[i]->left = first[2 * i];
		else
			second[i]->left = NULL;
		if (2 * i + 1 <= n)
			second[i]->right = first[2 * i + 1];
		else
			second[i]->right = NULL;
	}
	fprintf(stream2, "%d", equal(first[1], second[1]));

	fclose(stream);
	fclose(stream2);
	for (int i = 0; i < 128; i++) {
		free(first[i]);
		free(second[i]);
	}

	return 0;
}