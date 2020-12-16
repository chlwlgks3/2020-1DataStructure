#include <stdio.h>
#include <stdlib.h>
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)
#define SWAP(x,y,t) ( t=x,x=y,y=t )

void sort(int array[], int num);
int main(void) {
	FILE* stream;
	int iNum;
	stream = fopen("input.txt", "r");
	fscanf(stream, "%d", &iNum);
	int* ip = (int*)malloc(sizeof(int) * iNum);
	for (int i = 0; i < iNum; i++) {
		fscanf(stream, "%d", ip+i);
	}
	sort(ip, iNum);
	fclose(stream);
	stream = fopen("output.txt", "w");
	for (int i = 0; i < 5; i++) {
		fprintf(stream,"%d\n",ip[i]);
	}
	fclose(stream);
	free(ip);
	ip = NULL;

	return 0;
}

void sort(int array[],int num) {
	int min = 0, temp =0;
	for (int i = 0; i < 4; i++) {
		min = i;
		for (int j = i + 1; j < 5; j++) {
			if (array[j] < array[min])
				min = j;
		}
		SWAP(array[i], array[min], temp);
	}
}