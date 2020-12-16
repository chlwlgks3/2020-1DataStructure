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
		fprintf(stream, "\n\n-while %d회-\n", count);
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

	//파일의 끝까지 input.txt에서 숫자를 하나씩 읽어들인후 head노드가 lead인 리스트에 저장
	while (fscanf(stream, "%d", &data) != EOF) {
		temp = (listPointer)malloc(sizeof(*temp));
		temp->data = data;
		temp->link = NULL;
		if (!lead)
			lead = last = temp;
		else
			last = last->link = temp;
	}

	fprintf(stream2, "처음 Linked list 결과: ");
	for (temp = lead; temp; temp = temp->link)
		fprintf(stream2, "%d ", temp->data);

	int num = 0; //바로 아래의 for문 에서 "invert 최종 결과 : "를 처음 반복때만 출력하기 위해 0으로 지정
	for (temp = invert(lead, stream2); temp; temp = temp->link) {
		if(num == 0)
		fprintf(stream2, "\n\ninvert 최종 결과 : "); 
		fprintf(stream2, " %d", temp->data);
		num++; //for문안에서 첫 반복문 일때만"invert 최종 결과 : " 를실행하고 나머지 반복에서는 실행하지않기 위해 num 하나증가 
	}
	fclose(stream);
	fclose(stream2);
	return 0;
}