#include <stdio.h>
#include <stdlib.h>
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)

typedef struct adj* ptr;
typedef struct adj {
	int data;
	ptr link;
}adj;

int main(void) {
	FILE* stream = fopen("input.txt", "r");
	FILE* stream2 = fopen("output.txt", "w");
	int n, m, node1, node2;
	ptr* adjLists; // adjLists[i]는 정점i에 대한 인접리스트의 첫번째 노드에 대한 포인터
	ptr* chain; 
	int* index;
	fscanf(stream, "%d %d", &n, &m);
	index = (int*)malloc(n * sizeof(*index)); //chain배열의 인덱스를 가리킬배열 동적할당
	adjLists = (ptr*)malloc(n * sizeof(*adjLists)); //노드의 개수가 n
	chain = (ptr*)malloc(n * sizeof(*chain)); //노드의 개수가 n이므로 총n개의 체인이필요
	for (int i = 0; i < n; i++)
		chain[i] = (ptr)malloc((n-1) * sizeof(*chain[i])); //각각의 체인은 자신을 제외한 나머지 노드와 연결된 edge를 가질수있으므로 (n-1)
	for (int i = 0; i < n; i++)
		adjLists[i] = &chain[i][0]; // adjLists[i]는 정점i에 대한 인접리스트의 첫번째 노드를 가리키도록한다.
	for (int i = 0; i < n; i++) 
		index[i] = 0;
	
	for (int i = 0; i < m; i++) {
		fscanf(stream, "%d %d", &node1, &node2);
		chain[node1][index[node1]].data = node2;
		chain[node2][index[node2]].data = node1;
		if (index[node1] < n - 1) {
			chain[node1][index[node1]].link = &chain[node1][index[node1] + 1];
			chain[node2][index[node2]].link = &chain[node2][index[node2] + 1];
		}
		index[node1]++;
		index[node2]++;
	}
	for (int i = 0; i < n; i++) {
		chain[i][index[i]-1].link = NULL;
	}

	for (int i = 0; i < n; i++) {
		ptr temp = NULL;
		for(temp = adjLists[i];temp;temp = temp->link)
			fprintf(stream2,"%d ", temp->data);
		fprintf(stream2,"\n");
	}
	
	for (int i = 0; i < n; i++)
		free(chain[i]);
	free(index);
	free(adjLists);

	fclose(stream);
	fclose(stream2);

	




	return 0;
}