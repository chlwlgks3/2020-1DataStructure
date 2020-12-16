#include <stdio.h>
#include <string.h>
#define STUDENT 5
#define STAFF 6
#define NORMAL 8

void print();
int math(int menu, int term);

int main(void) {
	int menu = 0;
	int term = 0;
	int fee = 0;
	char type[7];

	char student[] = "���л�";
	char staff[] = "������";
	char normal[] = "�Ϲ���";
	
	do {
		print();
		printf("\n�޴��� �����ϼ���: ");
		scanf("%d", &menu);
		if (menu == 4) { 
			printf("���α׷��� �����մϴ�.");  break; 
		}
		printf("�����Ⱓ�� �Է��ϼ���: ");
		scanf("%d", &term);
		printf("\n\n\n");
		
		switch (menu){
		case 1: fee = 5; strcpy(type, student); break;
		case 2: fee = 6; strcpy(type, staff); break;
		case 3: fee = 8; strcpy(type, normal); break;
		}
		printf("ȸ������: %s\n", type);
		printf("������: %d����\n", fee);
		printf("�����Ⱓ: %d����\n", term);
		printf("�ѱݾ�: %d����\n", math(menu, term));
		printf("\n\n\n");
	} while (menu != 4);
}

void print() {
	for (int i = 0; i < 41; i++) 
		printf("*");
	printf("\n*\t\t1. ���л�\t\t*");
	printf("\n*\t\t2. ������\t\t*");
	printf("\n*\t\t3. �Ϲ���\t\t*");
	printf("\n*\t\t4. ����  \t\t*\n");
	for (int i = 0; i < 41; i++) 
		printf("*");
}

int math(int menu, int term) {
	int cost = 0;
	switch (menu) {
	case 1: cost = STUDENT * term; break;
	case 2: cost = STAFF * term; break;
	case 3: cost = NORMAL * term; break;
	case 4: printf("���α׷��� �����մϴ�."); break;
	}
	return cost;
}
