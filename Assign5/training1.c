#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)
#define SWAP(x,y,t) (t=x,x=y,y=t)
#include <stdio.h>
#include <stdlib.h>


int main(void) {
	FILE* stream;
	int* ip;
	int length;
	stream = fopen("input.txt", "r");
	fscanf(stream, "%d", &length);
	ip = (int*)malloc(sizeof(int)*length);
	for (int i = 0; i < length; i++) 
		fscanf(stream, "%d", ip + i);
	fclose(stream);
	stream = fopen("output.txt", "w");

	int min = 0, temp = 0;
	for (int i = 0; i < length - 1; i++) {
		min = i;
		for (int j = i + 1; j < length; j++) {
			if (ip[j] < ip[min])
				min = j;
		}
		SWAP(ip[i],ip[min],temp);
		for (int k = 0; k < length; k++) 
			fprintf(stream, "%d ", ip[k]);
		fprintf(stream, "\n");
	}
	fclose(stream);
	free(ip);
	return 0;
}

