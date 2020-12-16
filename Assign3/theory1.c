/*
다음을 참고하여, input.txt에서 시작시간과 종료시간을 읽어와 output.txt에
경과시간을 출력하는 프로그램을 작성하시오.

typedef struct{
 int hour;
 int min;
 int sec;
} TIME;

TIME elapsedTime(TIME start, TIME end, FILE *f);

요구사항
시, 분, 초의 정보를 저장할 수 있는 구조체 TIME을 정의해서 사용한다. 
시작시간과 종료시간으로부터 경과시간에 대한 계산은 함수로 구현해야 한다.

input.txt
18:31:50 //시작시간
19:50:01 //종료시간

output.txt
경과시간은 1:18:11입니다.
*/

////////////////////////////////////////////////////////////////

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

typedef struct {
	int hour;
	int min;
	int sec;
}TIME;

TIME elapsedTime(TIME start, TIME end, FILE* f);

int main(void) {
	FILE* stream1;
	FILE* stream2;
	
	TIME start = { 18, 31 , 50 };
	TIME end = { 19,50,1 };
	TIME elap = { 0,0,0 };

	stream1 = fopen("input.txt", "w");
	fprintf(stream1, "%d:%d:%d", start.hour, start.min, start.sec);
	fprintf(stream1, "%d:%d:%d", end.hour, end.min, end.sec);
	puts("input.txt 출력");
	fprintf(stdout, "%d:%d:%d\n", start.hour, start.min, start.sec);
	fprintf(stdout, "%d:%d:%d\n\n\n", end.hour, end.min, end.sec);
	fclose(stream1);

	stream2 = fopen("output.txt", "w");
	elapsedTime(start, end, stream2);
	fclose(stream2);
	
	return 0;
}

TIME elapsedTime(TIME start, TIME end, FILE* f) {
	TIME elap = { 0,0,0 };
	int time1 = start.hour * 10000 + start.min * 100 + start.sec;
	int time2 = end.hour * 10000 + end.min * 100 + end.sec;
	int timeGap, temp, carry;
	temp = time2 % 100 - time1 % 100;

	// 초 계산
	carry = 0;
	if (temp < 0){
		temp += 60;
		carry = 1;
	}
	timeGap = temp;

	// 분 계산
	temp = time2 % 10000 / 100 - time1 % 10000 / 100 - carry;
	carry = 0;
	if (temp < 0){
		temp += 60;
		carry = 1;
	}
	timeGap += temp * 100;
	// 시 계산
	temp = time2 % 1000000 / 10000 - time1 % 1000000 / 10000 - carry;
	if (temp < 0) {
		temp += 24;
	}
	timeGap += temp * 10000;

	elap.hour = timeGap % 1000000 / 10000;
	elap.min = timeGap % 10000 / 100;
	elap.sec = timeGap % 100;

	fprintf(f, "경과시간은 %d:%d:%d입니다.", elap.hour, elap.min, elap.sec);
	fprintf(stdout, "경과시간은 %d:%d:%d입니다.", elap.hour, elap.min, elap.sec);
	return elap;
}
