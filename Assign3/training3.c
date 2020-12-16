#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
	srand(time(NULL));
	int i, j;
	int num[10];
	int A[5] = { 0, };
	int** B = (int**)malloc(sizeof(int*) * 5);
	int c[5] = { 0, };
	int sum;
	printf("뽑힌 난수\n");
	for (i = 0; i < 10; ++i)
	{
		num[i] = rand() % 50;
		printf("%d ", num[i]);
		++A[num[i] / 10];
	}
	printf("\n");
	for (i = 0; i < 5; ++i)
		printf("10의 자리가 %d인 수 : %d개\n", i, A[i]);
	for (i = 0; i < 5; ++i)
		if (A[i])
			B[i] = (int*)malloc(sizeof(int) * A[i]);
		else
			B[i] = (int*)malloc(sizeof(int));
	for (i = 0; i < 10; ++i)
	{
		B[num[i] / 10][c[num[i] / 10]] = num[i];
		++c[num[i] / 10];
	}
	for (i = 0; i < 5; ++i)
		if (!c[i])
			B[i][0] = -1;
	for (i = 0; i < 5; ++i)
	{
		j = 0;
		sum = 0;
		if (B[i][0] != -1)
		{
			printf("arr[%d] = %d", i, B[i][j]);
			sum += B[i][0];
			for (j = 1; j < A[i]; ++j)
			{
				printf(" + %d", B[i][j]);
				sum += B[i][j];
			}
			printf(" = %d\n", sum);
		}
	}
	return 0;
}