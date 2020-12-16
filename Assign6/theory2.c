#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct _POLY{
	int coef;
	int expo;
}POLY;

int main(void){
	FILE* stream;
	POLY polyA[101] = { 0, };
	POLY polyB[101] = { 0, };
	POLY polyC[101] = { 0, };
	int len_A, len_B;
	stream = fopen("input.txt", "r");
	fscanf(stream, "%d", &len_A);

	for (int i = 0; i < len_A; i++) {
		int a, b;
		fscanf(stream, "%d %d", &a, &b);
		polyA[b].coef = a;
		polyA[b].expo = b;
	}

	fscanf(stream, "%d", &len_B);
	for (int i = 0; i < len_B; i++) {
		int a, b;
		fscanf(stream, "%d %d", &a, &b);
		polyB[b].coef = a;
		polyB[b].expo = b;
	}
	fclose(stream);
	stream = fopen("output.txt", "w");
	for (int i = 100; i >= 0; i--) {
		polyC[i].coef = polyA[i].coef + polyB[i].coef;
		polyC[i].expo = i;
		fprintf(stream, "%d,%d ", polyC[i].coef, polyC[i].expo);
	}
	fclose(stream);

	return 0;
}
