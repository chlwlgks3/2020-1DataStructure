#define _CRT_SECURE_NO_WARNINGS	
#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int row;
	int col;
	int value;
}term;

int main(void) {
	FILE* stream;
	term* p1 = NULL;
	term* p2 = NULL;
	term* p3 = NULL;
	int rows1, rows2, cols1, cols2, num1 = 0, num2 = 0;
	stream = fopen("input.txt", "r");
	fscanf(stream, "%d %d", &rows1, &cols1);
	p1 = (term*)malloc(rows1*cols1 * sizeof(term));
	for (int i = 0; i < rows1*cols1; i++) {
		fscanf(stream, "%d", &p1[i].value);
		p1[i].row = num1 / cols1;
		p1[i].col = num1 % cols1;
		num1++;
	}
	fscanf(stream, "%d %d", &rows2, &cols2);
	p2 = (term*)malloc(rows2*cols2 * sizeof(term));
	for (int i = 0; i < rows2*cols2; i++) {
		fscanf(stream, "%d", &p2[i].value);
		p2[i].row = num2 / cols1;
		p2[i].col = num2 % cols1;
		num2++;
	}

	int count = 0;
	for (int i = 0; i < rows1*cols1; i++) {
		if ((p1[i].value + p2[i].value) != 0)
			count++;	// 두 matrix의 각 요소를 합하였을때 0이 아닌 요소의 갯수
	}
	p3 = (term*)malloc(count * sizeof(term));
	
	int index = 0;
	for (int i = 0; i < rows1*cols1; i++) {
		if ((p1[i].value + p2[i].value) != 0) {
			p3[index].row = p1[i].row;
			p3[index].col = p1[i].col;
			p3[index].value = p1[i].value + p2[i].value;
			index++;
		}
	}

	fclose(stream);
	stream = fopen("output.txt", "w");
	for (int i = 0; i < count; i++)
		fprintf(stream, "%d %d %d\n", p3[i].row, p3[i].col, p3[i].value);

	fclose(stream);
	free(p1);
	free(p2);
	free(p3);
	p1 = NULL;
	p2 = NULL;
	p3 = NULL;
	
	return 0;
}