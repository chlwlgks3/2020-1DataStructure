#include <stdio.h>
#include <stdlib.h>
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)
#define TRUE 1
#define FALSE 0
#define MAX_VERTICES 15
#define INF 1000L

int selected[MAX_VERTICES];
int dist[MAX_VERTICES];
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

int get_min_vertex(int n) {
	int v, i;
	for (i = 0; i < n; i++)
		if (!selected[i]) {
			v = i;
			break;
		}
	for (i = 0; i < n; i++)
		if (!selected[i] && (dist[i] < dist[v])) v = i;
	return v;
}

void prim(int s, int n, int** weight, int* arr) {
	int i, u, v, index = 0;
	for (u = 0; u < n; u++)
	{
		dist[u] = INF; selected[u] = FALSE;
	}
	dist[s] = 0;
	for (i = 0; i < n; i++) {
		u = get_min_vertex(n);
		selected[u] = TRUE;
		if (dist[u] == INF) return;
		arr[index++] = u;
		for (v = 0; v < n; v++)
			if (weight[u][v] != INF)
				if (!selected[v] && weight[u][v] < dist[v])
					dist[v] = weight[u][v];
	}
}

void dfs_list(GraphType* g, int v, FILE* stream) {
	GraphNode* w;
	visited[v] = TRUE; //����v�� �湮ǥ��
	fprintf(stream, "%d ", v); //�湮�� �������
	for (w = g->ajd_list[v]; w; w = w->link) //�������� Ž��
		if (!visited[w->vertex])
			dfs_list(g, w->vertex, stream); //����w->vertex���� DFS �ٽý���
}

int main(void) {
	FILE* stream = fopen("input.txt", "r");
	FILE* stream2 = fopen("output.txt", "w");
	int n, m, node1, node2, weight;
	int** arr_weight; // �� edge���� ����ġ�� ������ 2�����迭 ����
	int* arr;
	GraphType g; // Prim�˰����� ���� ������� MST�� ������ �׷�������
	graph_init(&g);
	fscanf(stream, "%d %d", &n, &m);
	arr_weight = (int**)malloc(n * sizeof(*arr_weight));
	for (int i = 0; i < n; i++) {
		insert_vertex(&g);
		arr_weight[i] = (int*)malloc(n * sizeof(*arr_weight[i]));
	}
	arr = (int*)malloc(n * sizeof(*arr));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i == j)
				arr_weight[i][j] = 0;
			else
				arr_weight[i][j] = INF;
		}
	}
	for (int i = 0; i < m; i++) {
		fscanf(stream, "%d %d %d", &node1, &node2, &weight);
		arr_weight[node1][node2] = weight;
		arr_weight[node2][node1] = weight;
	}

	prim(0, n, arr_weight, arr);
	int index1 = 0, index2 = 1;
	for (int i = 0; i < n - 1; i++) {
		insert_edge(&g, arr[index1], arr[index2]);
		insert_edge(&g, arr[index2++], arr[index1++]);
	}
	dfs_list(&g, 0, stream2);

	free(arr);
	for (int i = 0; i < n; i++)
		free(arr_weight[i]);
	free(arr_weight);
	fclose(stream);
	fclose(stream2);


	return 0;

}