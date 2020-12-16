/*
다음에 주어진 세 구조체를 이용하여 학생 2명과 교수 2명을 각각 구조체 배열로
선언하고, 표준입력으로부터 적절한 값을 입력 받아 student의 멤버 값을 출력하는
프로그램을 작성하시오.

typedef struct person{
 char name[20];
 int age;
} person;

typedef struct student{
 person p;
 int id;
 char major[20];
 professor *pf;
} student;

typedef struct professor{
 person p;
 char major[20];
} professor;

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

typedef struct person {
	char name[20];
	int age;
}person;

typedef struct professor {
	person p;
	char major[20];
}professor;

typedef struct student {
	person p;
	int id;
	char major[20];
	professor *pf;
}student;

요구사항
구조체 student의 멤버 중 professor 관련 항목의 값은 직접 입력되어서는 안되고, 값이 입력된 교수와 학생의 전공을 비교하여 일치하는 경우 해당 교수의 구조체 변수를 가리키
도록 해야 한다. 또한 학생의 지도교수 정보를 출력할 때 반드시 student의 멤버 변수 pf를 이
용하여 출력해야한다.
*/

////////////////////////////////////////////////////////////////////////////
int main(void) {
	student ST[2];
	professor PF[2];

	for (int i = 0; i < 2; i++) {
		printf("학생%d의 정보를 입력하시오.\n", i+1);
		printf("이름 : ");
		scanf("%s", &ST[i].p.name);
		printf("나이 : ");
		scanf("%d", &ST[i].p.age);
		printf("학번: ");
		scanf("%d", &ST[i].id);
		printf("전공: ");
		scanf("%s", &ST[i].major);
		printf("\n\n");
	}

	for (int i = 0; i < 2; i++) {
		printf("교수%d의 정보를 입력하시오.\n", i + 1);
		printf("이름 : ");
		scanf("%s", &PF[i].p.name);
		printf("나이 : ");
		scanf("%d", &PF[i].p.age);
		printf("전공 : ");
		scanf("%s", &PF[i].major);
		printf("\n\n");
	}

	ST[0].pf = strcmp(ST[0].major, PF[0].major) == 0 ? &PF[0] : &PF[1];
	ST[1].pf = strcmp(ST[1].major, PF[1].major) == 0 ? &PF[1] : &PF[0];

	for (int i = 0; i < 2; i++) {
		printf("%s / %d세 / %d / %s / 지도교수(%s)\n", ST[i].p.name, ST[i].p.age, ST[i].id, ST[i].major, ST[i].pf->p.name);
	}
}
