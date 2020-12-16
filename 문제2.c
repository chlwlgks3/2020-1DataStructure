#include <stdio.h>

long fact(int n);
long factsum(int n);

int main(void) {
	int input = 0;

	printf("양의 정수 n을 입력하세요. => ");
	scanf("%d", &input);
	printf("\n계산한 답은 %ld 입니다.", factsum(input));
}

long fact(int n) {
	if (n == 0 || n ==1 )
		return 1;
	else
		return n*fact(n - 1);
}

long factsum(int n) {
	int sum = 0;

	for (int i = 0; i <= n; i++) {
		sum += fact(i);
	}
	return sum;
}