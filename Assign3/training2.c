#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _PERSON {
	char name[20];
	char phone[20];
}PERSON;

int main(void) {
	FILE* stream;
	PERSON* p;
	stream = fopen("data.txt", "w");

	for (int i = 0; i < 12; i++) {
		p = (PERSON*)calloc(i + 1, sizeof(PERSON));
		fscanf(stdin, "%s", &p[i].name );
		if ( strcmp(p[i].name, "exit") == 0 || i == 10) break;
		fscanf(stdin, "%s", &p[i].phone );
		fprintf(stream, "%s %s\n", p[i].name, p[i].phone);
	}
	fclose(stream);
	free(p);

	return 0;
}