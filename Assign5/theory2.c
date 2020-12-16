#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>

int binarysearch(int list[], int searchnum, int left, int right);
int main(void) {
	FILE* stream;
	int left, right, searchnum, length;
	stream = fopen("input.txt", "r");
	fscanf(stream, "%d %d", &length, &searchnum);
	left = 0; 
	right = length - 1;
	int* ip = (int*)malloc(sizeof(int) * length);
	for (int i = 0; i < length; i++) {
		fscanf(stream, "%d", ip + i);
	}
	fclose(stream);
	stream = fopen("output.txt", "w");
	fprintf(stream, "%d", binarysearch(ip, searchnum, left, right));
	
	fclose(stream);
	free(ip);
	return 0;
}
int binarysearch(int list[], int searchnum, int left, int right) {
	int middle;
	while (left <= right) {
		middle = (left + right) / 2;
		if (searchnum < list[middle])
			right = middle - 1;
		else if (searchnum == list[middle])
			return middle+1;
		else left = middle + 1;
	}
	return -1;
}