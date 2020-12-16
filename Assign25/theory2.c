#include <stdio.h>
#include <stdlib.h>
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)
#define MAX_SIZE 50

int sorted[MAX_SIZE];

void merge(int list[], int left, int mid, int right) {
	int i, j, k, l;
	i = left; j = mid + 1; k = left;
	while (i <= mid && j <= right) {
		if (list[i] <= list[j])
			sorted[k++] = list[i++];
		else
			sorted[k++] = list[j++];
	}
	if (i > mid)
		for (l = j; l <= right; l++)
			sorted[k++] = list[l];
	else
		for (l = i; l <= mid; l++)
			sorted[k++] = list[i];
	for (l = left; l <= right; l++)
		list[l] = sorted[l];
}

void merge_sort(int list[], int left, int right) {
	int mid;
	if (left < right) {
		mid = (right + left) / 2;
		merge_sort(list, left, mid);
		merge_sort(list, mid + 1, right);
		merge(list, left, mid, right);
	}
}

int main(void) {
	FILE* stream = fopen("input.txt", "r");
	FILE* stream2 = fopen("output.txt", "w");
	int n, data;
	int* arr;
	fscanf(stream, "%d", &n);
	arr = (int*)malloc((n + 1) * sizeof(*arr)); //index1부터 사용
	for (int i = 1; i <= n; i++) {
		fscanf(stream, "%d", &data);
		arr[i] = data;
	}
	merge_sort(arr, 0, n);
	for (int i = 1; i <= n; i++)
		fprintf(stream2,"%d ", arr[i]);

	free(arr);
	fclose(stream);
	fclose(stream2);

	return 0;
}