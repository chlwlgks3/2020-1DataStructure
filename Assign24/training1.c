#include <stdio.h>
#include <stdlib.h>
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)
#define SWAP(x,y,t) ( (t) = (x), (x) = (y) , (y) = (t) )

int partition(int* list, int left, int right);
void quick_sort(int* list, int left, int right);

int main(void) {
	FILE* stream = fopen("input.txt", "r");
	FILE* stream2 = fopen("output.txt", "w");
	int n, data;
	int* list;
	fscanf(stream, "%d", &n);
	list = (int*)malloc(n * sizeof(*list));
	for (int i = 0; i < n; i++) {
		fscanf(stream, "%d", &data);
		list[i] = data;
	}
	quick_sort(list, 0, n - 1);
	for (int i = 0; i < n; i++)
		fprintf(stream2,"%d ", list[i]);

	free(list);
	fclose(stream);
	fclose(stream2);
	return 0;
}

int partition(int* list, int left, int right) {
	int pivot, temp;
	int low, high;
	low = left;
	high = right + 1;
	pivot = list[left];
	do {
		do
			low++;
		while(low <= right && list[low] < pivot);
		do
			high--;
		while (high >= left && list[high] > pivot);
		if (low < high) SWAP(list[low], list[high], temp);
	} while (low < high);

	SWAP(list[left], list[high], temp);
	return high;
}

void quick_sort(int* list, int left, int right) {
	if (left < right) {
		int q = partition(list, left, right);
		quick_sort(list, left, q - 1);
		quick_sort(list, q + 1, right);
	}
}
