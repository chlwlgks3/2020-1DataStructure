#include <stdio.h>
#include <stdlib.h>
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)
#define MAX_ELEMENT 100
typedef struct {
	int heap[MAX_ELEMENT];
	int heap_size;
}HeapType;

void init(HeapType* h) {
	h->heap_size = 0;
}

void insert_min_heap(HeapType* h, int item) {
	int i;
	i = ++(h->heap_size);

	while ((i != 1) && (item < h->heap[i / 2])) {
		h->heap[i] = h->heap[i / 2];
		i /= 2;
	}
	h->heap[i] = item;
}

int delete_min_heap(HeapType* h) {
	int parent, child;
	int item, temp;

	item = h->heap[1];
	temp = h->heap[(h->heap_size)--];
	parent = 1;
	child = 2;
	while (child <= h->heap_size) {
		if ((child < h->heap_size) && (h->heap[child]) > h->heap[child + 1])
			child++;
		if (temp <= h->heap[child]) break;
		h->heap[parent] = h->heap[child];
		parent = child;
		child *= 2;
	}
	h->heap[parent] = temp;
	return item;
}

void heap_sort(int a[], int n) {
	int i;
	HeapType h;

	init(&h);
	for (i = 0; i < n; i++) {
		insert_min_heap(&h, a[i]);
	}
	for (i = n - 1; i >= 0; i--)
		a[i] = delete_min_heap(&h);
}

int main(void) {
	FILE* stream = fopen("input.txt", "r");
	FILE* stream2 = fopen("output.txt", "w");
	int n, data;
	int* arr;
	fscanf(stream, "%d", &n);
	arr = (int*)malloc(n * sizeof(*arr));
	for (int i = 0; i < n; i++) {
		fscanf(stream, "%d", &data);
		arr[i] = data;
	}
	heap_sort(arr, n);
	for (int i = n-1; i >= 0; i--)
		fprintf(stream2,"%d ", arr[i]);

	free(arr);
	fclose(stream);
	fclose(stream2);

	return 0;
}
