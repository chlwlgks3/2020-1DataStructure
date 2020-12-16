#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int m = 0;
	int n = 0;
	int** Array;
	
	fprintf(stdout, "m x n 이차원 배열을 생성합니다\n");
	fprintf(stdout, "m : ");
	fscanf(stdin, "%d", &m);
	fprintf(stdout, "n : ");
	fscanf(stdin, "%d", &n);
	printf("\n");

	Array = malloc(sizeof(int*) * m);

	for (int i = 0; i < m; i++) {
		Array[i] = malloc(sizeof(int) * n);
	}

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			fprintf(stdout, "arr[%d][%d] : ", i,j);
			fscanf(stdin, "%d", &Array[i][j]);
		}
	}
	printf("\n");

	printf("이차원 배열 :\n");
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			fprintf(stdout, "%d\t", Array[i][j]);
		}
			fprintf(stdout, "\n");
	}

	for (int i = 0; i < m; i++) {
		free(Array[i]);
	}
	free(Array);

	return 0;

	

}


