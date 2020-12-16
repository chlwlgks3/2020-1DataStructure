#include <stdio.h>
#include <stdlib.h>
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)
#define MAX_ELEMENT 100

typedef struct {
	int u, v;
	int cost;
}element;

typedef struct {
	element heap[MAX_ELEMENT];
	int heap_size;
}HeapType;

void init(HeapType* h) {
	h->heap_size = 0;
}

void insert_min_heap(HeapType* h, element item) {
	int i;
	i = ++(h->heap_size);

	while ((i != 1) && (item.cost < h->heap[i / 2].cost)) {
		h->heap[i] = h->heap[i / 2];
		i /= 2;
	}
	h->heap[i] = item;
}

element delete_min_heap(HeapType* h) {
	int parent, child;
	element item, temp;

	item = h->heap[1];
	temp = h->heap[(h->heap_size)--];
	parent = 1;
	child = 2;
	while (child <= h->heap_size) {
		if ((child < h->heap_size) && (h->heap[child].cost) > h->heap[child + 1].cost)
			child++;
		if (temp.cost <= h->heap[child].cost) break;
		h->heap[parent] = h->heap[child];
		parent = child;
		child *= 2;
	}
	h->heap[parent] = temp;
	return item;
}

void heap_sort(element a[], int n) {
	int i;
	HeapType h;

	init(&h);
	for (i = 0; i < n; i++) 
		insert_min_heap(&h, a[i]);
	for (i = 0; i < n; i++)
		a[i] = delete_min_heap(&h);
}

int main(void) {
	FILE* stream = fopen("input.txt", "r");
	FILE* stream2 = fopen("output.txt", "w");
	int n,m,u,v,cost;
	element* arr;
	element temp;
	fscanf(stream, "%d %d", &n, &m);
	arr = (element*)malloc(m*sizeof(*arr)); //index1부터 사용
	for (int i = 0; i < m; i++) {
		fscanf(stream, "%d %d %d", &u, &v, &cost);
		temp.u = u;
		temp.v = v;
		temp.cost = cost;
		arr[i] = temp;
	}
	heap_sort(arr, m);
	for (int i = 0; i < m; i++) {
		fprintf(stream2,"%d %d %d\n", arr[i].u, arr[i].v, arr[i].cost);
		fprintf(stream2,"%d %d %d\n", arr[i].v, arr[i].u, arr[i].cost);
	}

	free(arr);
	fclose(stream);
	fclose(stream2);

	return 0;
}
