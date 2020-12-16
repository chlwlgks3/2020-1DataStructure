#include <stdio.h>
#include <stdlib.h>
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)

typedef struct node* ptr;
typedef struct node {
	int data;
	ptr prev;
	ptr next;
}node ;
ptr head = NULL;
ptr tail = NULL;

int main(void) {
	FILE* stream = fopen("input.txt", "r");
	FILE* stream2 = fopen("output.txt","w");
	int data;
	while (fscanf(stream, "%d", &data) != EOF) {
		ptr temp = (ptr)malloc(sizeof(*temp));
		temp->data = data;
		temp->next = NULL;
		temp->prev = NULL;
		if (!head)
			head = tail = temp;
		else {
			temp->prev = tail;
			tail->next = temp;
			tail = temp;
		}
	}
	
	//역순으로 리스트 출력
	ptr p = (ptr)malloc(sizeof(*p));
	for (p = tail; p; p = p->prev)
		fprintf(stream2,"%d ", p->data);
	free(p);
	
	fclose(stream);
	fclose(stream2);
	return 0;
}