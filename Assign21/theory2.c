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
	ptr* adjLists; // adjLists[i]�� ����i�� ���� ��������Ʈ�� ù��° ��忡 ���� ������
	ptr* chain; 
	int* index;
	fscanf(stream, "%d %d", &n, &m);
	index = (int*)malloc(n * sizeof(*index)); //chain�迭�� �ε����� ����ų�迭 �����Ҵ�
	adjLists = (ptr*)malloc(n * sizeof(*adjLists)); //����� ������ n
	chain = (ptr*)malloc(n * sizeof(*chain)); //����� ������ n�̹Ƿ� ��n���� ü�����ʿ�
	for (int i = 0; i < n; i++)
		chain[i] = (ptr)malloc((n-1) * sizeof(*chain[i])); //������ ü���� �ڽ��� ������ ������ ���� ����� edge�� �����������Ƿ� (n-1)
	for (int i = 0; i < n; i++)
		adjLists[i] = &chain[i][0]; // adjLists[i]�� ����i�� ���� ��������Ʈ�� ù��° ��带 ����Ű�����Ѵ�.
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