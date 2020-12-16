#include <stdio.h>
#include <stdlib.h>
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)

void insertion_sort(int* list, int n);

int main(void) {
	FILE* stream = fopen("input.txt","r");
	FILE* stream2 = fopen("output.txt", "w");
	int n, data;
	int* list;
	fscanf(stream, "%d", &n);
	list = (int*)malloc(n*sizeof(*list));
	for (int i = 0; i < n; i++) {
		fscanf(stream, "%d", &data);
		list[i] = data;
	}
	insertion_sort(list, n);
	for (int i = 0; i < n; i++)
		fprintf(stream2,"%d ", list[i]);

	free(list);
	fclose(stream);
	fclose(stream2);

	return 0;
}

void insertion_sort(int* list, int n) {
	int i,j,key;
	for (i = 1; i < n; i++) {
		key = list[i];
		for (j = i - 1; j >= 0 && list[j] > key; j--)
			list[j + 1] = list[j];
		list[j + 1] = key;
	}
}
