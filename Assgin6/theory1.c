#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)
#define SWAP(x,y,t) ( t=x,x=y,y=t )

typedef struct _PERSON {
	char name[20];
	int age;
}person;
void sort(person p[],int length);
int binsearch(person p[], int left, int right, int searchnum);

int main(void) {
	FILE* stream;
	person* ptr;
	int length, searchnum, left, right,index;
	stream = fopen("input.txt", "r");
	fscanf(stream, "%d %d", &length, &searchnum);
	left = 0;
	right = length - 1;

	ptr = (person*)malloc(length * sizeof(person));
	for (int i = 0; i < length; i++) {
		fscanf(stream, "%s %d", ptr[i].name, &ptr[i].age);
	}
	sort(ptr, length);
	index = binsearch(ptr, left, right, searchnum);
	fclose(stream);
	stream = fopen("output.txt", "w");
	fprintf(stream, "%d %s", index+1, ptr[index].name);
	
	fclose(stream);
	free(ptr);
	return 0;
}

void sort(person p[],int length) {
	int min, temp;
	char temp_name[20];
	for (int i = 0; i < length - 1; i++) {
		min = i;
		for (int j = i + 1; j < length; j++) {
			if (p[j].age < p[min].age)
				min = j;
		}
		SWAP(p[i].age, p[min].age, temp);
		strcpy(temp_name, p[min].name);
		strcpy(p[min].name, p[i].name);
		strcpy(p[i].name, temp_name);
	}
}

int binsearch(person p[],int left,int right,int searchnum) {
	int middle;
	while (left <= right) {
		middle = (left + right) / 2;
		if (searchnum < p[middle].age)
			right = middle - 1;
		else if (searchnum == p[middle].age)
			return middle;
		else
			left = middle + 1;
	}
	return -1;
}