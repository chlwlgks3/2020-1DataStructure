#include <stdio.h>

long square(int x);
long cube(int x);

int main(void) {
	int iNum = 0;

	printf("���� �Է� -> ");
	scanf("%d", &iNum);
	printf("%d�� �ټ� ������ %ld �Դϴ�.", iNum, cube(iNum) * square(iNum));
}

long square(int x) {
	return x * x;
}

long cube(int x) {
	return square(x)*x;
}
