/*
다음 구조체 account를 참고하여, input.txt 파일에서 고객 n명의 계좌정보를
입력받아 동적 할당으로 생성한 구조체 배열에 저장한 후 그 중 가장 대출금이 높은 VIP의 계좌
정보를 output.txt 파일에 저장하는 프로그램을 작성하시오.

struct account
{
 int accountNum;
 char name[30];
 int deposit;
 int loan; // 대출금
};

<주의사항>
동적 할당된 메모리의 해제를 하지 않을 경우 감점

<input.txt>
5 // 고객의 수
100 김수한무 4200 500
200 거북이 200 150300
300 두루미 13000 0
400 삼천갑자 200000 30000
500 동방삭 50 30000000

<output.txt>
500 동방삭 50 300000000

/////////////////////////////////////////////////////////////////////////////////////////////
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

struct account {
	int accountNum;
	char name[30];
	int deposit;
	int loan;
};

int main(void) {
	struct account* p;
	FILE* stream1;
	FILE* stream2;
	int n = 0;

	stream1 = fopen("input.txt", "r");
	fscanf(stream1, "%d", &n);
	p = calloc(n, sizeof(struct account));

	for (int i = 0; i < n; i++) {
		fscanf(stream1, "%d %s %d %d", &p[i].accountNum, p[i].name, &p[i].deposit, &p[i].loan);
	}
	
	int vip_loan = 0;
	int vip_index = 0;
	for (int i = 0; i < n; i++) {
		if (i == 0) vip_loan = p[i].loan;
		if (p[i].loan >= vip_loan) {
			vip_loan = p[i].loan;
			vip_index = i;
		}
	}

	fclose(stream1);
	stream2 = fopen("output.txt", "w");

	fprintf(stream2, "%d %s %d %d", p[vip_index].accountNum, p[vip_index].name, p[vip_index].deposit, p[vip_index].loan);
	fclose(stream2);

	free(p);

	return 0;
}
