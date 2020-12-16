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
	pscore st[4] = { {1, "권다애", 87, 98, 25},
					 {2, "김근태", 89, 78, 30},
					 {3, "양보원", 76, 87, 30},
					 {4, "홍길동", 94, 75, 21} };
	
	printf("현재의 성적 내용은 >>\n");
	printf("-------------------------------------------\n");
	printf("번호\t  이름\t중간\t기말\t퀴즈\n");
	printf("-------------------------------------------\n");
	for (int i = 0; i < 4; i++) {
		printf("  %d\t  %s  %d     %d      %d\n", st[i].number, st[i].name, st[i].mid, st[i].final, st[i].quiz);
	}
	printf("\n가장 큰 번호의 학생은 4번 입니다. >>\n");
	printf("찾을 학생 번호를 입력하세요. >>");
	scanf("%d", &num);
	printf("\n%찾은 학생 정보는 >>\n\n");
	searchscore(&st[num-1], num);
	return 0;
}

void searchscore(pscore* p, int cnt) {
	printf("  %d\t  %s  %d     %d      %d",p->number, p->name, p->mid, p->final, p->quiz);
}
