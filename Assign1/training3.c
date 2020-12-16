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

	char student[] = "재학생";
	char staff[] = "교직원";
	char normal[] = "일반인";
	
	do {
		print();
		printf("\n메뉴를 선택하세요: ");
		scanf("%d", &menu);
		if (menu == 4) { 
			printf("프로그램을 종료합니다.");  break; 
		}
		printf("강습기간을 입력하세요: ");
		scanf("%d", &term);
		printf("\n\n\n");
		
		switch (menu){
		case 1: fee = 5; strcpy(type, student); break;
		case 2: fee = 6; strcpy(type, staff); break;
		case 3: fee = 8; strcpy(type, normal); break;
		}
		printf("회원유형: %s\n", type);
		printf("강습료: %d만원\n", fee);
		printf("강습기간: %d개월\n", term);
		printf("총금액: %d만원\n", math(menu, term));
		printf("\n\n\n");
	} while (menu != 4);
}

void print() {
	for (int i = 0; i < 41; i++) 
		printf("*");
	printf("\n*\t\t1. 재학생\t\t*");
	printf("\n*\t\t2. 교직원\t\t*");
	printf("\n*\t\t3. 일반인\t\t*");
	printf("\n*\t\t4. 종료  \t\t*\n");
	for (int i = 0; i < 41; i++) 
		printf("*");
}

int math(int menu, int term) {
	int cost = 0;
	switch (menu) {
	case 1: cost = STUDENT * term; break;
	case 2: cost = STAFF * term; break;
	case 3: cost = NORMAL * term; break;
	case 4: printf("프로그램을 종료합니다."); break;
	}
	return cost;
}
