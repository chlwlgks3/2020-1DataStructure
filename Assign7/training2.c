#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> 
#include <stdlib.h>
#define MAX 101
typedef struct{
	int row;
	int col;
	int value;
}TERM;
typedef struct {
	TERM term[MAX]; 
	int rows; 
	int cols; 
	int tSize; //0이 아닌 원소갯수
}MAT;

int valueAt(MAT m, int r, int c);
void mulMatrix(MAT m1, MAT m2, MAT* mul);

int main(void)
{
	FILE* stream;
	MAT A, B, C;
	int numA = 0, numB = 0;
	A.tSize = 0;
	B.tSize = 0;
	stream = fopen("input.txt", "r");
	fscanf(stream, "%d %d", &A.rows, &A.cols);
	for (int i = 0; i < A.rows*A.cols; i++) {
		fscanf(stream, "%d", &A.term[i].value);
		A.term[i].row = numA / A.cols;
		A.term[i].col = numA % A.cols;
		numA++;
		if (A.term[i].value != 0)
			A.tSize++;
	}
	fscanf(stream, "%d %d", &B.rows, &B.cols);
	for (int i = 0; i < B.rows*B.cols; i++) {
		fscanf(stream, "%d", &B.term[i].value);
		B.term[i].row = numB / B.cols;
		B.term[i].col = numB % B.cols;
		numB++;
		if (B.term[i].value != 0)
			B.tSize++;
	}
	mulMatrix(A, B, &C);
	fclose(stream);
	stream = fopen("output.txt", "w");
	for (int i = 0; i < C.tSize; i++) {
		fprintf(stream, "%d %d %d\n", C.term[i].row, C.term[i].col, C.term[i].value);
	}
	fclose(stream);

	return 0;
}

int valueAt(MAT m, int r, int c)
{
	int i;
	for (i = 0; i < sizeof(m.term)/sizeof(TERM); i++)
	{
		if (m.term[i].row == r && m.term[i].col == c)
		{
			return m.term[i].value;
		}
	}
	return 0; 
}

void mulMatrix(MAT m1, MAT m2, MAT* mul)
{
	int sum;
	int i, j, k;

	if (m1.cols != m2.rows) {
		printf("-1");
		exit(EXIT_FAILURE);
	}

	mul->rows = m1.rows;
	mul->cols = m2.cols;
	mul->tSize = 0;
	for (i = 0; i < mul->rows; i++)
	{
		for (j = 0; j < mul->cols; j++)
		{
			sum = 0;
			for (k = 0; k < m1.cols; k++)
			{
				sum += valueAt(m1, i, k)*valueAt(m2, k, j);
			}
			if (sum != 0)
			{
				mul->term[mul->tSize].row = i;
				mul->term[mul->tSize].col = j;
				mul->term[mul->tSize].value = sum;
				mul->tSize++;
			}
		}
	}
}

