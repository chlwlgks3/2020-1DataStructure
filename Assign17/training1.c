#include <stdio.h>
#include <stdlib.h>
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)
#define MAX_ELEMENTS 200
#define SWAP(x,y,t) ((t)=(x), (x)=(y),(y)=(t))
#define HEAP_EMPTY(n) (!n)
#define HEAP_FULL(n) (n == MAX_ELEMENTS-1)

typedef struct element {
	int key;
}element;
element heap[MAX_ELEMENTS];

void adjust(element a[], int root, int n) {
	int child, rootkey;
	element temp;
	temp = a[root];
	rootkey = a[root].key;
	child = 2 * root;
	while (child <= n) {
		if ((child < n) && (a[child].key < a[child + 1].key))
			child++;
		if (rootkey > a[child].key)
			break;
		else {
			a[child / 2] = a[child];
			child *= 2;
		}
		a[child / 2] = temp;
	}
}

element pop(int* n) {
	int parent, child;
	element item, temp;
	if (HEAP_EMPTY(*n)) {
		fprintf(stderr, "The heap is empty\n");
		exit(EXIT_FAILURE);
	}
	item = heap[1];
	temp = heap[(*n)--];
	parent = 1;
	child = 2;
	while (child <= *n) {
		if ((child < *n) && (heap[child].key > heap[child + 1].key))
			child++;
		if (temp.key <= heap[child].key) break;
		heap[parent] = heap[child];
		parent = child;
		child *= 2;
	}
	heap[parent] = temp;
	return item;
}

int main(void) {
	FILE* stream = fopen("input.txt", "r");
	FILE* stream2 = fopen("output.txt", "w");
	int n, count, data;
	element temp;
	fscanf(stream, "%d", &n);
	count = n;
	for (int i = 1; i <= n; i++) {
		fscanf(stream, "%d", &data);
		heap[i].key = data;
	}
	for (int i = n / 2; i > 0; i--)
		adjust(heap, i, n);
	for (int i = n - 1; i > 0; i--) {
		SWAP(heap[1], heap[i + 1], temp);
		adjust(heap, 1, i);
	}
	for(int i=0;i<count;i++)
		fprintf(stream2, "%d ", pop(&n).key);
	
	fclose(stream);
	fclose(stream2);

	return 0;
}