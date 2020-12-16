#include <stdio.h>
#include <stdlib.h>
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)
#define TRUE 1
#define FALSE 0
#define MAX_VERTICES 50

int visited[MAX_VERTICES];
typedef struct GraphNode {
	int vertex;
	struct GraphNode* link;
}GraphNode;

typedef struct GraphType {
	int n; //정점의개수
	GraphNode* ajd_list[MAX_VERTICES];
}GraphType;

void graph_init(GraphType* g) {
	int v;
	g->n = 0;
	for (v = 0; v < MAX_VERTICES; v++)
		g->ajd_list[v] = NULL;
}

//정점삽입 연산
void insert_vertex(GraphType* g) {
	if (((g->n) + 1) > MAX_VERTICES) {
		fprintf(stderr, "그래프정점의 개수 초과");
		return;
	}
	g->n++;
}

//간선삽입 연산, v를 u의 인접리스트에 삽입
void insert_edge(GraphType* g, int u, int v) {
	GraphNode* node;
	if (u >= g->n || v >= g->n) {
		fprintf(stderr, "그래프정점 번호오류");
		return;
	}
	node = (GraphNode*)malloc(sizeof(GraphNode));
	node->vertex = v;
	node->link = g->ajd_list[u];
	g->ajd_list[u] = node;
}

void dfs_list(GraphType* g,int v,FILE* stream) {
	GraphNode* w;
	visited[v] = TRUE; //정점v의 방문표시
	fprintf(stream,"%d ", v); //방문한 정점출력
	for (w = g->ajd_list[v]; w; w = w->link) //인접정점 탐색
		if (!visited[w->vertex])
			dfs_list(g, w->vertex,stream); //정점w->vertex에서 DFS 다시시작
}

int main(void) {
	FILE* stream = fopen("input.txt", "r");
	FILE* stream2 = fopen("output.txt", "w");
	int n, m, node1, node2;
	GraphType graph;
	graph_init(&graph); //graph 초기화
	fscanf(stream, "%d %d", &n, &m);
	for (int i = 0; i < n; i++)
		insert_vertex(&graph);
	for (int i = 0; i < m; i++) {
		fscanf(stream, "%d %d", &node1, &node2);
		insert_edge(&graph, node1, node2);
	}
	dfs_list(&graph, 0,stream2);
	
	fclose(stream);
	fclose(stream2);

	return 0;
}