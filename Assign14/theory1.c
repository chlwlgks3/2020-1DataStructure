#include <stdio.h>
#include <stdlib.h>
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)

int main(void) {
	int* array;
	int n,m,data,index;
	FILE* stream = fopen("input.txt", "r");
	FILE* stream2 = fopen("output.txt", "w");
	fscanf(stream, "%d", &n);
	array = (int*)malloc((n+1) * sizeof(*array));
	array[0] = 0; //�迭�� 0��° ��ġ�� �������� �ϰ� 1��°��Һ��� �̿�
	for (int i = 1; i <= n; i++) {
		fscanf(stream, "%d", &data);
		array[i] = data;
	}
	fscanf(stream, "%d", &m);
	for (int i = 0; i < m; i++) {
		fscanf(stream, "%d", &index);
		if (2 * index > n)
			fprintf(stream2, "\n-1 -1");
		else
			fprintf(stream2, "\n%d %d", array[2 * index], array[2 * index + 1]);
	}

	fclose(stream);
	fclose(stream2);
	free(array);
	return 0;
}