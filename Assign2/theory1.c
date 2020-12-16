//다음과 같이 3x2와 2x3의 두 행렬에서, 행렬의 곱을 구하는 프로그램을 작성하시오. 단, scanf 함수를 사용하여 배열의 값을 입력한다.
//다음에 주어진 함수를 이용하시오. 
//void display (int x[][3])  행렬의 곱을 출력해주는 함수
//void multply (int x[][3], int a[][2], int b[][3])  두 행렬을 곱해주는 함수

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void display(int x[][3]);
void multply(int x[][3], int a[][2], int b[][3]);


int main(void) {
	int ary_1[3][2];
	int ary_2[2][3];
	int ary_3[3][3];
	

	printf("첫 번째 행렬 값 입력 :\n");
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 2; j++) {
			scanf("%d", &ary_1[i][j]);
		}
	}
	
	printf("\n두 번째 행렬 값 입력 :\n");
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 3; j++) {
			scanf("%d", &ary_2[i][j]);
		}
	}
	printf("\n");
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			ary_3[i][j] = 0;
		}
	}
	multply(ary_3, ary_1, ary_2);
}

void display(int x[][3]) {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			printf("%d ", x[i][j]);
		}
		printf("\n");
	}
}

void multply(int x[][3], int a[][2], int b[][3]) {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			for (int k = 0; k < 2; k++) {
				x[i][j] += a[i][k] * b[k][j];
			}
		}
	}
	display(x);
}
