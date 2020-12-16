#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct _PERSON{
	int num;
	char name[20];
	float score1;
	float score2;
}PERSON;

int main(void) {
	FILE* stream;
	stream = fopen("input.txt", "r");
	int count;
	float* total;
	PERSON* array;
	fscanf(stream, "%d", &count);
	array = (PERSON*)malloc(count * sizeof(PERSON));
	total = (float*)malloc(count * sizeof(float));
	for (int i = 0; i < count; i++) {
		fscanf(stream, "%d %s %f %f", &array[i].num, array[i].name, &array[i].score1, &array[i].score2);
		total[i] = array[i].score1 + array[i].score2;
	}
	
	fclose(stream);
	stream = fopen("output.txt", "w");
	for (int i = 0; i < count; i++) {
		fprintf(stream, "%d\t%s\t%.1f\t%.1f\t%.1f\n", array[i].num, array[i].name, array[i].score1, array[i].score2, total[i]);
	}
	fclose(stream);
	return 0;
}