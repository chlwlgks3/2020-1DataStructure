#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void sumcolrow(int x[][5], int row, int col);
void print(int x[][5], int row, int col);

int main(void) {
	int ary[5][5];
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			scanf("%d", ary[i] + j);
		}
	}
	printf("���� ǥ�� ���ο� ������, �׸��� ��� ���� ���մϴ�.\n\n");
	printf("-------------------------------------------------\n");
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			printf(":  %d  ", ary[i][j]);
		}
		printf(":\n");
	}
	printf("-------------------------------------------------\n");
	printf("\n�� ǥ�� ���ο� ������, �׸��� ��� ����\n���� ��� ���� �������� ���մϴ�.\n");
	sumcolrow(ary, 4, 4);
	print(ary, 4, 4);
	return 0;
}

void sumcolrow(int x[][5], int row, int col) {
	for (int i = 0; i < row; i++) {
		x[i][col] = 0;
		for (int j = 0; j < col; j++) {
			x[i][col] += x[i][j];
		}
	}
	for (int i = 0; i < row; i++) {
		x[row][i] = 0;
		for (int j = 0; j < col; j++) {
			x[row][i] += x[j][i];
		}
	}
	x[row][col] = 0;
	for (int i = 0; i < row; i++) {
		x[row][col] += x[i][col];
	}
}

void print(int x[][5], int row, int col) {
	printf("-------------------------------------------------\n");
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			if (i == 4 || j == 4) {
				printf(": %d  ", x[i][j]);
			}
			else {
				printf(":  %d  ", x[i][j]);
			}
		}
		printf(":\n");
	}
	printf("-------------------------------------------------\n");
}