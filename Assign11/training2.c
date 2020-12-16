#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)

typedef struct listNode* listPointer;
typedef struct listNode {
	int data;
	listPointer link;
}listNode;

listPointer concatenate(listPointer ptr1, listPointer ptr2) {
	listPointer temp;
	if (!ptr1) return ptr2;
	if (!ptr2) return ptr1;

	for (temp = ptr1; temp->link; temp = temp->link);
	temp->link = ptr2;
	return ptr1;
}

int main(void) {
	listPointer ptr1 = NULL;
	listPointer last1 = NULL;
	listPointer ptr2 = NULL;
	listPointer last2 = NULL;
	listPointer temp;

	FILE* stream = fopen("input.txt", "r");
	FILE* stream2 = fopen("output.txt", "w");
	char lineTemp[128];
	fgets(lineTemp, 128, stream);
	if (!strcmp(lineTemp, "\n"))  // input�� ù��° �ٿ� �ƹ������͵� ���� ��� �� ���๮�ڸ� �ִ°�� 
		ptr1 = NULL;
	else {
		char* tok = strtok(lineTemp, " ");
		while (tok != NULL) {
			int data = atoi(tok);
			temp = (listPointer)malloc(sizeof(*temp));
			temp->data = data;
			temp->link = NULL;
			if (!ptr1)
				ptr1 = last1 = temp;
			else
				last1 = last1->link = temp;
			tok = strtok(NULL, " ");
		}
	}

	if (!fgets(lineTemp, 128, stream)) // input�� �ι�° �ٿ� �ƹ������͵� ���� ��� fgets()�� �ƹ��͵� �������� �����Ƿ� NULL��ȯ
		ptr2 = NULL;
	else {
		char* tok = strtok(lineTemp, " "); //lineTemp������ �а���" "���� ������ tok�� ���� 
		while (tok != NULL) {
			int data = atoi(tok); // tok�� ����ִ� ����(askii)�� int�� ��ȯ
			temp = (listPointer)malloc(sizeof(*temp));
			temp->data = data;
			temp->link = NULL;
			if (!ptr2)
				ptr2 = last2 = temp;
			else
				last2 = last2->link = temp;
			tok = strtok(NULL, " ");
		}
	}

	fprintf(stream2, "ptr1 : ");
	if (ptr1 != NULL) {
		for (temp = ptr1; temp; temp = temp->link)
			fprintf(stream2, "%d ", temp->data);
	}
	fprintf(stream2, "\nptr2 : ");
	if (ptr2 != NULL) {
		for (temp = ptr2; temp; temp = temp->link)
			fprintf(stream2, "%d ", temp->data);
	}
	fprintf(stream2, "\nconcatenation ��� : ");
	for (temp = concatenate(ptr1, ptr2); temp; temp = temp->link)
		fprintf(stream2, "%d ", temp->data);

	fclose(stream);
	fclose(stream2);
	return 0;
}