#include <stdio.h>

int divTwo(int num);
int minusOne(int num);

int main(void) {
	int iNum = 0;
	int count = 0;
	printf("자연수 n을 입력하시오 : ");
	scanf("%d", &iNum);
	printf("%d ", iNum);
	do{
		count++;
		if (iNum % 2 == 0) {
			iNum = divTwo(iNum);
		}
		else {
			iNum= minusOne(iNum);
		}
	} while (iNum != 0);
	printf("\ncount = %d\n", count);
}

int divTwo(int num) {
	printf("%d ", num / 2);
	return num / 2;
}

int minusOne(int num) {
	printf("%d ", num - 1);
	return num - 1;
}