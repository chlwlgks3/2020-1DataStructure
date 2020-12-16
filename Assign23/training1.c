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
		fprintf(stderr, "스택포화에러\n");
		return;
	}
	else s->stack[++(s->top)] = item;
}

int pop(StackType* s) {
	if (is_empty(s)) {
		fprintf(stderr, "스택공백에러\n");
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
		fprintf(stderr, "그래프 정점개수초과");
		return;
	}
	g->n++;
}

void insert_edge(GraphType* g, int u, int v) {
	GraphNode* node;
	if (u >= g->n || v >= g->n) {
		fprintf(stderr, "그래프 정점번호오류");
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

	//모든정점의 진입차수 계산
	int* in_degree = (int*)malloc(g->n * sizeof(int));
	for (i = 0; i < g->n; i++) //초기화
		in_degree[i] = 0; 
	for (i = 0; i < g->n; i++) {
		node = g->adj_list[i]; //정점i에서 나오는 간선들
		while (node != NULL) {
			in_degree[node->vertex]++;
			node = node->link;
		}
	}
	init(&s);
	for (i = 0; i < g->n; i++) {
		if (in_degree[i] == 0) push(&s, i);
	}

	//위상순서 생성
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