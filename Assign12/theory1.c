#include <stdio.h>
#include <stdlib.h>
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)
#define COMPARE(A,B) ((A>B) ? 1 : (A<B) ? -1 : 0)

typedef struct polyNode* polyPointer;
typedef struct polyNode {
	int coef;
	int expon;
	polyPointer link;
}polyNode;

void attach(int coefficient, int exponenet, polyPointer* ptr) {
	//coef = coefficient �̰� expo = exponent�� ���ο� ��带 �����ϰ�, 
	//�װ��� ptr�� ���� �����Ǵ� ��忡÷�� �� ptr�� �����Ͽ� ���ο��� ����Ű�����Ѵ�
	polyPointer temp;
	temp = (polyPointer)malloc(sizeof(*temp));
	temp->coef = coefficient;
	temp->expon = exponenet;
	(*ptr)->link = temp;
	*ptr = temp;
}

polyPointer padd(polyPointer a, polyPointer b) {
	polyPointer c, rear, temp;
	int sum;
	rear = (polyPointer)malloc(sizeof(*rear));
	c = rear;
	while (a&&b) {
		switch (COMPARE(a->expon, b->expon)) {
		case -1: //a->expon < b->expon
			attach(b->coef, b->expon, &rear);
			b = b->link;
			break;
		case 0: //a->expon == b->expon
			sum = a->coef + b->coef;
			if(sum) attach(sum, a->expon, &rear);
			a = a->link; b = b->link;
			break;
		case 1: //a->expon > b->expon
			attach(a->coef, a->expon, &rear);
			a = a->link;
		}
		//����Ʈa�� ����Ʈb�� �������� ����
	}
		for(; a; a = a->link) attach(a->coef, a->expon, &rear);
		for (; b; b = b->link) attach(b->coef, b->expon, &rear);
		rear->link = NULL;
		//�ʿ���� �ʱ��带 ����
		temp = c; c = c->link; free(temp);
		return c;
}

int main(void) {
	FILE* stream = fopen("input.txt", "r");
	FILE* stream2 = fopen("output.txt", "w");
	int n1, n2;
	polyPointer a = NULL;
	polyPointer b = NULL; 
	polyPointer temp;
	polyPointer a_last = NULL; 
	polyPointer b_last = NULL;
	fscanf(stream, "%d", &n1);
	for (int i = 0; i < n1; i++) {
		temp = (polyPointer)malloc(sizeof(*temp));
		fscanf(stream, "%d %d", &temp->coef, &temp->expon);
		temp->link = NULL;
		if (!a)
			a = a_last = temp;
		else
			a_last=a_last->link=temp;
	}

	fscanf(stream, "%d", &n2);
	for (int i = 0; i < n2; i++) {
		temp = (polyPointer)malloc(sizeof(*temp));
		fscanf(stream, "%d %d", &temp->coef, &temp->expon);
		temp->link = NULL;
		if (!b)
			b = b_last = temp;
		else
			b_last = b_last->link = temp;
	}
	
	for (temp = padd(a, b); temp; temp = temp->link)
		fprintf(stream2, "%d %d\n", temp->coef, temp->expon);

	free(temp);
	fclose(stream);
	fclose(stream2);

	return 0;
}