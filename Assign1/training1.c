#include <stdio.h>

void average(int* parr, double* average_value, int n);
void sum(int* parr, int* sum_value, int n);

int main(void) {
	int iSum = 0;
	double iAverage = 0;
	int* iArrSum = &iSum;
	double* iArrAverage = &iAverage;

	int iArr[5] = { 32,54,98,234,27 };
	printf("배열 원소의 개수 : 5\n");
	sum(iArr, iArrSum, 5);
	printf("배열의 총합 : %d\n", *iArrSum);
	average(iArr, iArrAverage, 5);
	printf("배열의 평균 : %f\n", *iArrAverage);
}

void sum(int* parr, int* sum_value, int n) {
	for (int i = 0; i < n; i++) {
		*sum_value += parr[i];
	}
}

void average(int* parr, double* average_value, int n) {
	int Sum = 0;
	for (int i = 0; i < n; i++) {
		Sum += *(parr+i);
	}
	*average_value = (double)Sum / n;
}
