#include <stdio.h>

long square(int x);
long cube(int x);

int main(void) {
	int iNum = 0;

	printf("정수 입력 -> ");
	scanf("%d", &iNum);
	printf("%d의 다섯 제곱은 %ld 입니다.", iNum, cube(iNum) * square(iNum));
}

long square(int x) {
	return x * x;
}

long cube(int x) {
	return square(x)*x;
}
