#include <stdio.h>

long fact(int n);
long factsum(int n);

int main(void) {
	int input = 0;

	printf("���� ���� n�� �Է��ϼ���. => ");
	scanf("%d", &input);
	printf("\n����� ���� %ld �Դϴ�.", factsum(input));
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