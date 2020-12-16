#include <stdio.h>
#include <stdlib.h>
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)

int main(void) {
	FILE* stream = fopen("input.txt", "r");
	FILE* stream2 = fopen("output.txt", "w");
	int n, m, node1, node2;
	int** arr;
	fscanf(stream, "%d %d", &n, &m);
	arr = (int**)malloc(n * sizeof(*arr));
	for (int i = 0; i < n; i++)
		arr[i] = (int*)malloc(n * sizeof(*arr[i]));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			arr[i][j] = 0;
	}
	
	for (int i = 0; i < m; i++) {
		fscanf(stream, "%d %d", &node1, &node2);
		arr[node1][node2] = 1;
		arr[node2][node1] = 1;
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (arr[i][j] == 1)
				fprintf(stream2,"%d ", j);
		}
		fprintf(stream2,"\n");
	}

	for (int i = 0; i < n; i++)
		free(arr[i]);
	free(arr);
	
	fclose(stream);
	fclose(stream2);

	return 0;
}