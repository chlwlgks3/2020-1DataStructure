#include <stdio.h>

void sorting(int arr[], int arrSize);

int main(void) {
	int iArr[5] = { 0, };
	printf("정수 5개를 입력하시오. -> ");
	scanf("%d %d %d %d %d", &iArr[0], &iArr[1], &iArr[2], &iArr[3], &iArr[4]);
	sorting(iArr, 5);
}

void sorting(int arr[], int arrSize) {
	int i, j, temp;

	for (i = arrSize - 1; i > 0; i--) {
		for (j = 0; j < i; j++) {
			if (*(arr + j) > *(arr + j + 1)) {
				temp = *(arr + j);
				*(arr + j) = *(arr + j + 1);
				*(arr + j + 1) = temp;
			}
		}
	}
	printf("\n정렬결과 : ");
	for (int i = 0; i < arrSize; i++) {
		printf("%d ", *(arr++));
	}
}