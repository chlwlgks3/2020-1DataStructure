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
	int n; //�����ǰ���
	GraphNode* ajd_list[MAX_VERTICES];
}GraphType;

void graph_init(GraphType* g) {
	int v;
	g->n = 0;
	for (v = 0; v < MAX_VERTICES; v++)
		g->ajd_list[v] = NULL;
}

//�������� ����
void insert_vertex(GraphType* g) {
	if (((g->n) + 1) > MAX_VERTICES) {
		fprintf(stderr, "�׷��������� ���� �ʰ�");
		return;
	}
	g->n++;
}

//�������� ����, v�� u�� ��������Ʈ�� ����
void insert_edge(GraphType* g, int u, int v) {
	GraphNode* node;
	if (u >= g->n || v >= g->n) {
		fprintf(stderr, "�׷������� ��ȣ����");
		return;
	}
	node = (GraphNode*)malloc(sizeof(GraphNode));
	node->vertex = v;
	node->link = g->ajd_list[u];
	g->ajd_list[u] = node;
}

void dfs_list(GraphType* g,int v,FILE* stream) {
	GraphNode* w;
	visited[v] = TRUE; //����v�� �湮ǥ��
	fprintf(stream,"%d ", v); //�湮�� �������
	for (w = g->ajd_list[v]; w; w = w->link) //�������� Ž��
		if (!visited[w->vertex])
			dfs_list(g, w->vertex,stream); //����w->vertex���� DFS �ٽý���
}

int main(void) {
	FILE* stream = fopen("input.txt", "r");
	FILE* stream2 = fopen("output.txt", "w");
	int n, m, node1, node2;
	GraphType graph;
	graph_init(&graph); //graph �ʱ�ȭ
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