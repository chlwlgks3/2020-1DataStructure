#include <stdio.h>
#include <stdlib.h>
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)

int* parent;
int simplefind(int i) { // 원소 i가 속한 집합(루트노드)를 찾는 함수
	for (; parent[i] >= 0; i = parent[i])
		;
	return i;
}

void weightedUnion(int i, int j) {
	int temp = parent[i] + parent[j];
	if (parent[i] > parent[j]) { // 루트가 i인 트리의 노드갯수 < 루트가 j인 트리의 노드갯수 인경우
		parent[i] = j; // j를 새로운 루트로 만든다
		parent[j] = temp; // 트리j의 노드갯수는 i의노드수 + j의 노드수
	}
	else { // 트리i와 트리j의 노드갯수가 같거나 j의 노드갯수가 더 적은경우
		parent[j] = i; 
		parent[i] = temp; 
	}
}

int main(void) {
	FILE* stream = fopen("input.txt", "r");
	FILE* stream2 = fopen("output.txt", "w");
	int n, m, data1, data2, count = 0;
	fscanf(stream, "%d %d", &n, &m);
	parent = (int*)malloc((n+1) * sizeof(*parent)); //index1부터 사용
	for (int i = 1; i <= n; i++)
		parent[i] = -1;
	for (int i = 0; i < m; i++) {
		fscanf(stream, "%d %d", &data1, &data2);
		if (simplefind(data1) != simplefind(data2))
			weightedUnion(simplefind(data1), simplefind(data2)); // weightedUnion의 인자로는 루트노드가 들어가야함
	}

	fprintf(stream2,"%d", -(parent[1]+1)); // 자신을 제외하고 감염되는 컴퓨터들의 수 이므로 +1 해주어야함
	fclose(stream);
	fclose(stream2);
	free(parent);
	return 0;
}