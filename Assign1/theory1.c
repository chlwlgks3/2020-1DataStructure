//임의의 수의 제곱승을 구하는 함수 square()와 세제곱승을 구하는 함수 cube()를 구현하여 임의의 수의 
//다섯제곱승 구하는 프로그램
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
