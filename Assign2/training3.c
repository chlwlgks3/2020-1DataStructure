#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

typedef struct food {
	char foodName[20];
	int calories;
}food;

void PrintInfo(food* foods, int nFood, int calories);

int main(void) {
	int cal = 0;
	food foods[5] = { {"�ܹ���",900}, {"�Ұ��", 500}, {"�ʹ�",300}, {"���",400}, {"���",0} };
	printf("Į�θ� ���� �Է��ϼ��� : ");
	scanf("%d", &cal);
	printf("\n");
	PrintInfo(foods, 5, cal);

}

void PrintInfo(food* foods, int nFood, int calories) {
	printf("%dĮ�θ� �̻� : ", calories);
	for (int i = 0; i < nFood; i++) {
		printf("%s", (foods + i)->calories >= calories ? (foods+i)->foodName : "");
		if ((foods + i)->calories >= calories) {
			printf(" ");
		}
	}
	
	printf("\n%dĮ�θ� �̸� : ", calories);
	for (int i = 0; i < nFood; i++) {
		printf("%s", (foods + i)->calories < calories ? (foods+i)->foodName : "");
		if ((foods + i)->calories < calories) {
			printf(" ");
		}
	}
}
	

