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
	int rows,cols,num =0 ,count = 0;
	stream = fopen("input.txt", "r");
	fscanf(stream, "%d %d", &rows, &cols);
	term* p = NULL;
	p = (term*)malloc(rows*cols*sizeof(term));

	for (int i = 0; i < rows*cols; i++) {
		fscanf(stream, "%d", &p[i].value);
		p[i].row = num / cols;
		p[i].col = num % cols;
		num++;
		if (p[i].value != 0)
			count++;
	}
	fclose(stream);
	stream = fopen("output.txt", "w");

	fprintf(stream, "%d %d %d\n",rows,cols,count);
	for (int i = 0; i < rows*cols; i++) {
		if(p[i].value !=0)
		fprintf(stream, "%d %d %d\n", p[i].row, p[i].col, p[i].value);
	}
	fclose(stream);
	free(p);
	p = NULL;

	return 0;
}