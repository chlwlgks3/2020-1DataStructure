#include <stdio.h>
#include <stdlib.h>
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)
#define MAX_ELEMENTS 200
#define SWAP(x,y,t) ((t)=(x), (x)=(y),(y)=(t))

typedef struct element {
	int key;
}element;
element heap[MAX_ELEMENTS];

typedef struct node* treePointer;
typedef struct node {
	int data;
	treePointer leftChild, rightChild;
}node;

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

void inorder(treePointer ptr, FILE* stream) {
	if (ptr) {
		inorder(ptr->leftChild, stream);
		fprintf(stream, "%d ", ptr->data);
		inorder(ptr->rightChild, stream);
	}
}

int main(void) {
	FILE* stream = fopen("input.txt", "r");
	FILE* stream2 = fopen("output.txt", "w");
	int n, data;
	element temp;
	treePointer arr[MAX_ELEMENTS];
	for (int i = 0; i < MAX_ELEMENTS; i++)
		arr[i] = (treePointer)malloc(sizeof(node));

	fscanf(stream, "%d", &n);
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

	for (int i = 1; i <= n; i++)
		printf("%d ", heap[i].key);
	for (int i = 1; i <= n; i++)
		arr[i]->data = heap[i].key;
	for (int i = 1; i <= n; i++) {
		if (2 * i <= n)
			arr[i]->leftChild = arr[2 * i];
		else
			arr[i]->leftChild = NULL;
		if (2 * i + 1 <= n)
			arr[i]->rightChild = arr[2 * i + 1];
		else
			arr[i]->rightChild = NULL;
	}
	inorder(arr[1], stream2);

	for (int i = 0; i < MAX_ELEMENTS; i++)
		free(arr[i]);
	fclose(stream);
	fclose(stream2);

	return 0;
}