#include <stdio.h>
#include <stdlib.h>
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)
#define MAX_SIZE 50

void merge(int initList[], int mergedList[], int i, int m, int n) {
	int j, k, t;
	j = m + 1;
	k = i;
	while (i <= m && j <= n) {
		if (initList[i] <= initList[j])
			mergedList[k++] = initList[i++];
		else
			mergedList[k++] = initList[j++];
	}
	if (i > m)
		for (t = j; t <= n; t++)
			mergedList[t] = initList[t];
	else
		for (t = i; t <= m; t++)
			mergedList[k + t - i] = initList[t];
}

void mergePass(int initList[], int mergedList[], int n, int s) {
	int i, j;
	for (i = 1; i <= n - 2 * s + 1; i += 2 * s)
		merge(initList, mergedList, i, i + s - 1, i + 2 * s - 1);
	if (i + s - 1 < n)
		merge(initList, mergedList, i, i + s - 1, n);
	else
		for (j = i; j <= n; j++)
			mergedList[j] = initList[j];
}

void mergeSort(int a[], int n) {
	int s = 1;
	int extra[MAX_SIZE];

	while (s < n) {
		mergePass(a, extra, n, s);
		s *= 2;
		mergePass(extra, a, n, s);
		s *= 2;
	}
}

int main(void) {
	FILE* stream = fopen("input.txt", "r");
	FILE* stream2 = fopen("output.txt", "w");
	int n, data;
	int* arr;
	fscanf(stream, "%d", &n);
	arr = (int*)malloc((n+1) * sizeof(*arr)); //index1���� ���
	for (int i = 1; i <= n; i++) {
		fscanf(stream, "%d", &data);
		arr[i] = data;
	}
	mergeSort(arr, n);
	for (int i = 1; i <= n; i++)
		fprintf(stream2,"%d ", arr[i]);

	free(arr);
	fclose(stream);
	fclose(stream2);
	return 0;
}