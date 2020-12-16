#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define _CRT_SECURE_NO_WARNINGS	
#pragma warning(disable:4996)
int* parent;

void simpleunion(int i, int j) {
	parent[i] = j;
}

int simplefind(int i) {
	for (; parent[i] >= 0; i = parent[i])
		;
	return i;
}

int main(void) {
	FILE* stream = fopen("input.txt", "r");
	FILE* stream2 = fopen("output.txt", "w");
	int n, m, data1, data2;
	char buffer[10];
	fscanf(stream, "%d %d", &n, &m);
	parent = (int*)malloc((n + 1) * sizeof(*parent)); //index 1부터사용
	for (int i = 1; i <= n; i++) 
		parent[i] = -1;
	for (int i = 0; i < m; i++) {
		fscanf(stream, "%s", buffer);
		if (!strcmp(buffer, "union")) {
			fscanf(stream, "%d %d", &data1, &data2);
			simpleunion(data1, data2);
		}
		else if (!strcmp(buffer, "find")) {
			fscanf(stream, "%d %d", &data1, &data2);
			if (simplefind(data1) == simplefind(data2))
				fprintf(stream2, "\nYES");
			else
				fprintf(stream2, "\nNO");
		}
	}

	fclose(stream);
	fclose(stream2);
	free(parent);
	return 0;
}