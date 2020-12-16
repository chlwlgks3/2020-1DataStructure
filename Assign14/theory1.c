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
	array[0] = 0; //배열의 0번째 위치는 공백으로 하고 1번째요소부터 이용
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