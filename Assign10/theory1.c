#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define _CRT_SECURE_NO_WARNINGS

typedef struct {
	char data[10];
	int link;
}linkedList;

void insert(linkedList* list,char* array, int next) {

}
int main(void) {
	FILE* stream;
	stream = fopen("input.txt", "r");
	linkedList* list;
	char** array;
	int n, pos; 
	int index, next;

	fscanf(stream, "%d %d", &n, &pos);

	array = (char**)malloc(n * sizeof(*array));
	for (int i = 0; i < n; i++)
		array[i] = (char*)malloc(10 * sizeof(**array));
	
	list = (linkedList*)malloc(n * sizeof(*list));
	
	for (int i = 0; i < n; i++) {
		fscanf(stream, "%d", &index);
		fscanf(stream, "%s %d", &array[index - 1], &next);
		
	}
	


	

	return 0;
}

