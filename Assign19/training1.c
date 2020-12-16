#include <stdio.h>
#include <stdlib.h>
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)

int* parent;
int simplefind(int i) { // ���� i�� ���� ����(��Ʈ���)�� ã�� �Լ�
	for (; parent[i] >= 0; i = parent[i])
		;
	return i;
}

void weightedUnion(int i, int j) {
	int temp = parent[i] + parent[j];
	if (parent[i] > parent[j]) { // ��Ʈ�� i�� Ʈ���� ��尹�� < ��Ʈ�� j�� Ʈ���� ��尹�� �ΰ��
		parent[i] = j; // j�� ���ο� ��Ʈ�� �����
		parent[j] = temp; // Ʈ��j�� ��尹���� i�ǳ��� + j�� ����
	}
	else { // Ʈ��i�� Ʈ��j�� ��尹���� ���ų� j�� ��尹���� �� �������
		parent[j] = i; 
		parent[i] = temp; 
	}
}

int main(void) {
	FILE* stream = fopen("input.txt", "r");
	FILE* stream2 = fopen("output.txt", "w");
	int n, m, data1, data2, count = 0;
	fscanf(stream, "%d %d", &n, &m);
	parent = (int*)malloc((n+1) * sizeof(*parent)); //index1���� ���
	for (int i = 1; i <= n; i++)
		parent[i] = -1;
	for (int i = 0; i < m; i++) {
		fscanf(stream, "%d %d", &data1, &data2);
		if (simplefind(data1) != simplefind(data2))
			weightedUnion(simplefind(data1), simplefind(data2)); // weightedUnion�� ���ڷδ� ��Ʈ��尡 ������
	}

	fprintf(stream2,"%d", -(parent[1]+1)); // �ڽ��� �����ϰ� �����Ǵ� ��ǻ�͵��� �� �̹Ƿ� +1 ���־����
	fclose(stream);
	fclose(stream2);
	free(parent);
	return 0;
}