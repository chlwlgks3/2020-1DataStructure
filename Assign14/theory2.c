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

int main(void) {
	FILE* stream = fopen("input.txt", "r");
	FILE* stream2 = fopen("output.txt", "w");
	int n, m, data, index;
	fscanf(stream, "%d", &n);
	node* arr[128];
	for (int i = 0; i < 128; i++) {
		arr[i] = (node*)malloc(sizeof(node));
		arr[i]->data = -1;
	}
	for (int i = 1; i <= n; i++) {
		fscanf(stream, "%d", &data);
		arr[i]->data = data;
		arr[i]->left = arr[2 * i];
		arr[i]->right = arr[2 * i + 1];
	}
	fscanf(stream, "%d", &m);
	for (int i = 0; i < m; i++) {
		fscanf(stream, "%d", &index);
		fprintf(stream2, "\n%d %d", arr[index]->left->data, arr[index]->right->data);
		}
	fclose(stream);
	fclose(stream2);
	for (int i = 0; i < 128; i++) {
		free(arr[i]);
	}
	
	return 0;
}