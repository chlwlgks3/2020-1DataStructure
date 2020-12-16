#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

struct personscore {
	int number;
	char name[40];
	int mid;
	int final;
	int quiz;
};

typedef struct personscore pscore;

void searchscore(pscore* p, int cnt);

int main(void) {
	int num = 0;
	pscore st[4] = { {1, "�Ǵپ�", 87, 98, 25},
					 {2, "�����", 89, 78, 30},
					 {3, "�纸��", 76, 87, 30},
					 {4, "ȫ�浿", 94, 75, 21} };
	
	printf("������ ���� ������ >>\n");
	printf("-------------------------------------------\n");
	printf("��ȣ\t  �̸�\t�߰�\t�⸻\t����\n");
	printf("-------------------------------------------\n");
	for (int i = 0; i < 4; i++) {
		printf("  %d\t  %s  %d     %d      %d\n", st[i].number, st[i].name, st[i].mid, st[i].final, st[i].quiz);
	}
	printf("\n���� ū ��ȣ�� �л��� 4�� �Դϴ�. >>\n");
	printf("ã�� �л� ��ȣ�� �Է��ϼ���. >>");
	scanf("%d", &num);
	printf("\n%ã�� �л� ������ >>\n\n");
	searchscore(&st[num-1], num);
	return 0;
}

void searchscore(pscore* p, int cnt) {
	printf("  %d\t  %s  %d     %d      %d",p->number, p->name, p->mid, p->final, p->quiz);
}
