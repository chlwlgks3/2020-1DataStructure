#include <stdio.h>
#include <stdlib.h>
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)

typedef struct {
	short int row;
	short int col;
	short int dir;
}element;

typedef struct {
	int vert;
	int horiz;
}MOVE;


element stack[20*20];
int top;

element pop(int* top) {
	return stack[(*top)--];
}

int main(void) {
	FILE* stream1;
	FILE* stream2;
	element** maze;
	int** mark;
	int row, col, nextRow, nextCol, dir, found = 0, count;
	element position;
	MOVE move[8]= { {-1,0},{-1,1},{0,1},{1,1},{1,0},{1,-1},{0,-1},{-1,-1} };
	stream1 = fopen("input.txt", "r");
	stream2 = fopen("output.txt", "w");
	int n, m;
	fscanf(stream1, "%d %d", &n, &m);
	int exit_row = n;
	int exit_col = m;
	maze = (element**)malloc(sizeof(element*)*(n+1));
	for (int i = 0; i < n + 1; i++)
		maze[i] = malloc(sizeof(element**)*(m + 1));

	mark = (int**)malloc(sizeof(int*)*(n + 1));
	for (int i = 0; i < n + 1; i++)
		mark[i] = malloc(sizeof(int**)*(m + 1));

	mark[1][1] = 1; top = 0;
	stack[0].row = 1; stack[0].col = 1; stack[0].dir = 1;
	while (top > -1 && !found) {
		position = pop(&top);
		row = position.row;
		col = position.col;
		dir = position.dir;
		while (dir < 8 && !found) {
			nextRow = row + move[dir].vert;
			nextCol = col + move[dir].horiz;
			if (nextRow == exit_row && nextCol == exit_col)
				found = 1;
			else if (! (**maze)[nextRow][nextCol] && !mark[nextRow][nextCol]) {
				mark[nextRow][nextCol] = 1;
				position.row = row; 
				position.col = col;
				position.dir = ++dir;
				push(position);
				row = nextRow; 
				col = nextCol;
				dir = 0;
			}
			else ++dir;
		}
	}
	if (found) {
		fprintf(stream2, "%d", count);
		for (int i = 0; i < count; i++) {
			fprintf(stream2, "%d %d", row, col);
		}
	}
	else {
		fprintf(stream2, "-1");
	}

	return 0;
}