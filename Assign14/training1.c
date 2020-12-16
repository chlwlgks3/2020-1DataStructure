#include <stdio.h>
#include <stdlib.h>
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)

//
void inorder(int* arr,int i,int n,FILE* stream) {
	if (i <=n && arr[i] != -1) {
		inorder(arr, 2*i,n,stream);
		fprintf(stream, "%d ", arr[i]);
		inorder(arr, 2*i+1,n, stream);
	}
}

void preorder(int* arr, int i, int n, FILE* stream) {
	if (i <= n && arr[i] != -1) {
		fprintf(stream, "%d ", arr[i]);
		preorder(arr, 2 * i, n, stream);
		preorder(arr, 2 * i + 1, n, stream);
	}
}

void postorder(int* arr, int i, int n, FILE* stream) {
	if (i <= n && arr[i] != -1) {
		postorder(arr, 2 * i, n, stream);
		postorder(arr, 2 * i + 1, n, stream);
		fprintf(stream, "%d ", arr[i]);
	}
}


int main(void) {
	FILE* stream = fopen("input.txt", "r");
	FILE* stream2 = fopen("output.txt", "w");

	int n,data;
	int* arr;
	fscanf(stream, "%d", &n);
	arr = (int*)malloc((n + 1) * sizeof(*arr));
	arr[0] = 0;

	for (int i = 1; i <= n; i++) {
		fscanf(stream, "%d", &data);
		arr[i] = data;
	}
	inorder(arr, 1,n,stream2);
	fprintf(stream2, "\n");
	preorder(arr, 1, n, stream2);
	fprintf(stream2, "\n");
	postorder(arr, 1, n, stream2);

	fclose(stream);
	fclose(stream2);
	free(arr);

	return 0;
}