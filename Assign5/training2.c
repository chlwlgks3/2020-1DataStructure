#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>

int binsearch(int array[], int right, int left,int searchnum);
int main(void) {
	FILE* stream;
	int len_data, len_target, right, left;
	int* pData;
	int* pTarget;
	stream = fopen("input.txt", "r");

	fscanf(stream, "%d", &len_data);
	pData = (int*)malloc(sizeof(int)*len_data);
	left = 0;
	right = len_data - 1;
	for (int i = 0; i < len_data; i++)
		fscanf(stream, "%d", pData + i);

	fscanf(stream, "%d", &len_target);
	pTarget = (int*)malloc(sizeof(int)*len_target);
	for (int i = 0; i < len_target; i++)
		fscanf(stream, "%d", pTarget + i);
	
	fclose(stream);
	stream = fopen("output.txt", "w");
	for (int i = 0; i < len_target; i++) {
		fprintf(stream, "%d ", binsearch(pData, right, left, pTarget[i]));
	}
	
	fclose(stream);
	free(pData);
	free(pTarget);
	return 0;
}

int binsearch(int array[],int right,int left,int searchnum) {
	int middle;
	while (left <= right) {
		middle = (left + right) / 2;
		if (searchnum < array[middle])
			right = middle - 1;
		else if (searchnum == array[middle])
			return middle;
		else left = middle + 1;
	}
	return -1;
}
