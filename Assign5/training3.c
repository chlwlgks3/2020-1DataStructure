#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define SWAP(x,y,t) ( t=x,x=y,y=t)

void sort(int array[],int length);
int binsearch(int array[], int left, int right, int searchnum);
int main(void) {
	FILE* stream;
	int* ip;
	int length, searchnum,left,right;
	stream = fopen("input.txt", "r");
	fscanf(stream, "%d %d",&length,&searchnum);
	left = 0;
	right = length - 1;
	ip = (int*)malloc(sizeof(int)*length);
	
	for (int i = 0; i < length; i++)
		fscanf(stream, "%d", ip + i);
	sort(ip, length);
	fclose(stream);
	stream = fopen("output.txt", "w");

	for (int i = 0; i < length; i++)
		fprintf(stream, "%d ", *(ip + i));
	fprintf(stream,"\n%d",binsearch(ip, left, right, searchnum));

	fclose(stream);
	free(ip);
}

void sort(int array[], int length) {
	int max = 0;
	int temp = 0;
	for (int i = 0; i < length - 1; i++) {
		max = i;
		for (int j = i + 1; j < length; j++) {
			if (array[j] > array[max])
				max = j;
		}
		SWAP(array[i], array[max], temp);
	}
}

int binsearch(int array[], int left, int right, int searchnum) {
	int middle = 0;
	while (left <= right) {
		middle = (left + right) / 2;
		if (searchnum > array[middle])
			right = middle -1;
		else if (searchnum == array[middle])
			return middle+1;
		else left = middle + 1;
	}
	return -1;
}