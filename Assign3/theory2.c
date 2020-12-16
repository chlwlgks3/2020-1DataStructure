/*
다음 내용을 참고로 구조체 person을 정의하고, 구조체 변수 p1과 p2를 선언하여
input.txt 파일에서 읽어온 값으로 초기화 한 후 두 구조체의 값을 변경해 주는 swap 함수를 구
현하여 변경한 값을 output.txt에 출력하는 프로그램을 작성하시오.

struct person
{
 char name[20];
 char phone[20];
 char address[40];
};

void swap(struct person* p1, struct person* p2); // 두 구조체의 값을 변경하는 함수
void print(struct person* p1, struct person* p2); // 두 구조체의 값을 출력하는 함수

요구사항
swap 함수와 print 함수를 구현하여 사용하시오. output.txt에 결과를 출력하시오.
<input.txt>
홍길동 010-1111-1111 서울시 구로구 고적동
조명호 017-1234-5678 경기도 안양시 비산동

<output.txt>
조명호 017-1234-5678 경기도 안양시 비산동
홍길동 010-1111-1111 서울시 구로구 고적동
*/

//////////////////////////////////////////////////////////////////////////////////////////
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

struct person {
	char name[20];
	char phone[20];
	char address[40];
};

void swap(struct person* p1, struct person* p2);
void print(struct person* p1, struct person* p2);

int main(void) {
	FILE* stream1;

	struct person p1;
	struct person p2;

	stream1 = fopen("input.txt", "r");

	fscanf(stream1, "%s %s", p1.name, p1.phone);
	fgets(p1.address, sizeof(p1.address), stream1);

	fscanf(stream1, "%s %s", p2.name, p2.phone);
	fgets(p2.address, sizeof(p2.address), stream1);

	print(&p1, &p2);
	printf("\n");
	swap(&p1, &p2);
	print(&p1, &p2);

	return 0;
}

void swap(struct person* p1, struct person* p2) {
	struct person temp = *p1;
	*p1 = *p2;
	*p2 = temp;
}

void print(struct person* p1, struct person* p2) {
	fprintf(stdout, "	  이름            전화번호           주소\n");
	fprintf(stdout, "사람1 :  %s		 %s	  %s", p1->name, p1->phone, p1->address);
	fprintf(stdout, "사람2 :  %s		 %s	  %s", p2->name, p2->phone, p2->address);

	FILE* stream2;
	stream2 = fopen("output.txt", "w");

	fprintf(stream2, "%s %s	%s", p1->name, p1->phone, p1->address);
	fprintf(stream2, "%s %s %s", p2->name, p2->phone, p2->address);
}
