#include <stdio.h>
#define MAX_VERTICES 100
#define MAX_ELEMENT 100
#define INF 1000	
#define _CRT_SECURE_NO_WARNINGS
#define TRUE 1
#define FALSE 0
#include <stdlib.h>
#pragma warning(disable:4996)

int parent[MAX_VERTICES];
int num[MAX_VERTICES];
typedef struct {
	int key;
	int u;
	int v;
}element;

typedef struct {
	element heap[MAX_ELEMENT];
	int heap_size;
}HeapType;

void set_init(int n) {
	int i;
	for (i = 0; i < n; i++) {
		parent[i] = -1;
		num[i] = 1;
	}
}

int set_find(int vertex) {
	int p, s, i = -1;
	for (i = vertex; (p = parent[i]) >= 0; i = p)
		;
	s = i;
	for (i = vertex; (p = parent[i]) >= 0; i = p)
		parent[i] = s;
	return s;
}

void set_union(int s1, int s2) {
	if (num[s1] < num[s2]) {
		parent[s1] = s2;
		num[s2] += num[s1];
	}
	else {
		parent[s2] = s1;
		num[s1] += num[s2];
	}
}

void insert_min_heap(HeapType* h, element item) {
	int i;
	i = ++(h->heap_size);
	while ((i != 1) && (item.key < h->heap[i / 2].key)) {
		h->heap[i] = h->heap[i / 2];
		i /= 2;
	}
	h->heap[i] = item;
}

void init(HeapType* h) {
	h->heap_size = 0;
}

int is_empty(HeapType* h) {
	if (h->heap_size == 0)
		return TRUE;
	else
		return FALSE;
}

element delete_min_heap(HeapType* h) {
	int parent, child;
	element item, temp;

	item = h->heap[1];
	temp = h->heap[(h->heap_size)--];
	parent = 1;
	child = 2;
	while (child <= h->heap_size) {
		if ((child < h->heap_size) && (h->heap[child].key) > h->heap[child + 1].key)
			child++;
		if (temp.key <= h->heap[child].key) break;
		h->heap[parent] = h->heap[child];
		parent = child;
		child *= 2;
	}
	h->heap[parent] = temp;
	return item;
}
void insert_heap_edge(HeapType* h, int u, int v, int weight) {
	element e;
	e.u = u;
	e.v = v;
	e.key = weight;
	insert_min_heap(h, e);
}

int main(void) {
	FILE* stream = fopen("input.txt", "r");
	FILE* stream2 = fopen("output.txt", "w");
	int n, m, node1, node2, weight;
	int edge_accepted = 0;
	HeapType h;
	int uset, vset;
	element e;
	init(&h);
	fscanf(stream, "%d %d", &n, &m);
	for (int i = 0; i < m; i++) {
		fscanf(stream, "%d %d %d", &node1, &node2, &weight);
		insert_heap_edge(&h, node1, node2, weight);
	}
	set_init(n);
	while (edge_accepted < (n - 1)) {
		e = delete_min_heap(&h);
		uset = set_find(e.u);
		vset = set_find(e.v);
		if (uset != vset) {
			fprintf(stream2,"%d %d\n", e.u, e.v);
			edge_accepted++;
			set_union(uset, vset);
		}
	}

	fclose(stream);
	fclose(stream2);

	return 0;
}
