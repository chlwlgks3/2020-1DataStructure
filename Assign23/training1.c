#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0
#define MAX_VERTICES 50
#define MAX_STACK_SIZE 50
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)

typedef struct GraphNode {
	int vertex;
	struct GraphNode* link;
}GraphNode;

typedef struct GraphType {
	int n;
	GraphNode* adj_list[MAX_VERTICES];
}GraphType;

typedef struct {
	int stack[MAX_STACK_SIZE];
	int top;
}StackType;

void init(StackType* s) {
	s->top = -1;
}

int is_empty(StackType* s) {
	return (s->top == -1);
}

int is_full(StackType* s) {
	return (s->top == MAX_STACK_SIZE - 1);
}

void push(StackType* s, int item) {
	if (is_full(s)) {
		fprintf(stderr, "������ȭ����\n");
		return;
	}
	else s->stack[++(s->top)] = item;
}

int pop(StackType* s) {
	if (is_empty(s)) {
		fprintf(stderr, "���ð��鿡��\n");
		exit(EXIT_FAILURE);
	}
	else return s->stack[(s->top)--];
}

void graph_init(GraphType* g) {
	int v;
	g->n = 0;
	for (v = 0; v < MAX_VERTICES; v++)
		g->adj_list[v] = NULL;
}

void insert_vertex(GraphType* g, int v) {
	if (( (g->n) + 1) > MAX_VERTICES){
		fprintf(stderr, "�׷��� ���������ʰ�");
		return;
	}
	g->n++;
}

void insert_edge(GraphType* g, int u, int v) {
	GraphNode* node;
	if (u >= g->n || v >= g->n) {
		fprintf(stderr, "�׷��� ������ȣ����");
		return;
	}
	node = (GraphNode*)malloc(sizeof(GraphNode));
	node->vertex = v;
	node->link = g->adj_list[u];
	g->adj_list[u] = node;
}

void topo_sort(GraphType* g,FILE* stream) {
	int i;
	StackType s;
	GraphNode* node;

	//��������� �������� ���
	int* in_degree = (int*)malloc(g->n * sizeof(int));
	for (i = 0; i < g->n; i++) //�ʱ�ȭ
		in_degree[i] = 0; 
	for (i = 0; i < g->n; i++) {
		node = g->adj_list[i]; //����i���� ������ ������
		while (node != NULL) {
			in_degree[node->vertex]++;
			node = node->link;
		}
	}
	init(&s);
	for (i = 0; i < g->n; i++) {
		if (in_degree[i] == 0) push(&s, i);
	}

	//������� ����
	while (!is_empty(&s)) {
		int w;
		w = pop(&s);
		fprintf(stream,"%d ", w);
		node = g->adj_list[w];
		while (node != NULL) {
			int u = node->vertex;
			in_degree[u]--;
			if (in_degree[u] == 0) push(&s, u);
			node = node->link;
		}
	}
	free(in_degree);
	return;
}

int main(void) {
	FILE* stream = fopen("input.txt", "r");
	FILE* stream2 = fopen("output.txt", "w");
	int n, m, node1, node2;
	GraphType g;
	graph_init(&g);
	fscanf(stream, "%d %d", &n, &m);
	for (int i = 0; i < n; i++)
		insert_vertex(&g, i);
	for (int i = 0; i < m; i++) {
		fscanf(stream, "%d %d", &node1, &node2);
		insert_edge(&g, node1, node2);
	}
	topo_sort(&g,stream2);

	fclose(stream);
	fclose(stream2);


}