#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int row;
	int col;
	int value;
}term;
void transpose(term a[], term b[]);

int main(void) {
	FILE* stream;
	term* p = NULL;
	term* p2 = NULL;
	term* p2Trans = NULL;
	int rows, cols, num = 0, count = 0;
	stream = fopen("input.txt", "r");
	fscanf(stream, "%d %d", &rows, &cols);
	p = (term*)malloc(rows*cols * sizeof(term));
	
	for (int i = 0; i < rows*cols; i++) {
		fscanf(stream, "%d", &p[i].value);
		p[i].row = num / cols;
		p[i].col = num % cols;
		num++;
		if (p[i].value != 0)
			count++;
	}
	p2 = (term*)malloc((count+1) * sizeof(term));
	p2Trans = (term*)malloc((count + 1) * sizeof(term));

	p2[0].row = rows;
	p2[0].col = cols;
	p2[0].value = count;
	p2Trans[0].row = p2[0].col;
	p2Trans[0].col = p2[0].row;
	p2Trans[0].value = p2[0].value;

	int index = 1;
	for (int i = 0; i < rows*cols; i++) {
		if (p[i].value != 0) {
			p2[index].row = p[i].row;
			p2[index].col = p[i].col;
			p2[index].value = p[i].value;
			index++;
		}
	}
	transpose(p2, p2Trans);
	fclose(stream);

	stream = fopen("output.txt", "w");
	for (int i = 0; i <=p2Trans[0].value; i++) {
		fprintf(stream, "%d %d %d\n", p2Trans[i].row, p2Trans[i].col, p2Trans[i].value);
	}
	fclose(stream);
	free(p);
	free(p2);
	free(p2Trans);
	p = NULL;
	p2 = NULL;
	p2Trans = NULL;

	return 0;
}

void transpose(term a[], term b[]) {
	int currentb = 1;

	for (int i = 0; i < a[0].col; i++) {
		for (int j = 1; j <= a[0].value; j++) {
			if (a[j].col == i) {
				b[currentb].row = a[j].col;
				b[currentb].col = a[j].row;
				b[currentb].value = a[j].value;
				currentb++;
			}
		}
	}
}