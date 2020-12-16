#include <stdio.h>
#include <stdlib.h>
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)

typedef struct listNode* listPointer;
typedef struct listNode {
	int data;
	listPointer link;
}listNode;

listPointer invert(listPointer lead,FILE* stream) {
	listPointer middle, trail;
	middle = NULL;
	int count = 1;
	while (lead) {
		trail = middle;
		middle = lead;
		lead = lead->link;
		middle->link = trail;
		fprintf(stream, "\n\n-while %dȸ-\n", count);
		if (!trail)
			fprintf(stream, "trail->data : NULL\n");
		else
			fprintf(stream, "trail->data : %d\n",trail->data);
		fprintf(stream, "middle->data : %d\n", middle->data);
		if (!lead)
			fprintf(stream, "lead->data : NULL\n");
		else
			fprintf(stream, "lead->data : %d\n", lead->data);
		if (!middle->link)
			fprintf(stream, "(middle->link)->data : NULL\n");
		else
			fprintf(stream, "(middle->link)->data : %d\n", (middle->link)->data);
		count++;
	}
	return middle;
}

int main(void) {
	FILE* stream = fopen("input.txt", "r");
	FILE* stream2 = fopen("output.txt", "w");
	int data;
	listPointer lead = NULL;
	listPointer last = NULL;
	listPointer temp;

	//������ ������ input.txt���� ���ڸ� �ϳ��� �о������ head��尡 lead�� ����Ʈ�� ����
	while (fscanf(stream, "%d", &data) != EOF) {
		temp = (listPointer)malloc(sizeof(*temp));
		temp->data = data;
		temp->link = NULL;
		if (!lead)
			lead = last = temp;
		else
			last = last->link = temp;
	}

	fprintf(stream2, "ó�� Linked list ���: ");
	for (temp = lead; temp; temp = temp->link)
		fprintf(stream2, "%d ", temp->data);

	int num = 0; //�ٷ� �Ʒ��� for�� ���� "invert ���� ��� : "�� ó�� �ݺ����� ����ϱ� ���� 0���� ����
	for (temp = invert(lead, stream2); temp; temp = temp->link) {
		if(num == 0)
		fprintf(stream2, "\n\ninvert ���� ��� : "); 
		fprintf(stream2, " %d", temp->data);
		num++; //for���ȿ��� ù �ݺ��� �϶���"invert ���� ��� : " �������ϰ� ������ �ݺ������� ���������ʱ� ���� num �ϳ����� 
	}
	fclose(stream);
	fclose(stream2);
	return 0;
}