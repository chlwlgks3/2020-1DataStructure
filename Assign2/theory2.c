// 5만원, 1만원, 5천원, 1천원, 500원, 100원짜리 각 화폐의 수를 저장할 수 있는
// 각 변수를 멤버로 하는 구조체 wallet의 변수를 2개 선언하고, 표준입력으로 적당한
// 값을 입력받은 후 더 큰 돈이 들어있는 지갑의 금액을 출력하는 프로그램을 작성하시오.

/*
typedef struct wallet{
int n50000;
int n10000;
int n5000;
int n1000;
int n500;
int n100;
} wallet;
int Calc (wallet w1, wallet w2);
*/

//두 지갑의 금액을 비교하기 위해 다음 Calc 함수를 이용해야하며, 최종 출력하는
//지갑의 금액은 main 함수에서 출력해야한다.

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

typedef struct _wallet {
	int n50000;
	int n10000;
	int n5000;
	int n1000;
	int n500;
	int n100;
}wallet;

int Calc(wallet w1, wallet w2);

int main(void) {
	
	wallet w1, w2;
	
	printf("지갑1의 각 화폐의 수를 입력하세요.\n");
	scanf("%d %d %d %d %d %d", &w1.n50000, &w1.n10000, &w1.n5000, &w1.n1000, &w1.n500, &w1.n100);
	printf("\n지갑2의 각 화폐의 수를 입력하세요.\n");
	scanf("%d %d %d %d %d %d", &w2.n50000, &w2.n10000, &w2.n5000, &w2.n1000, &w2.n500, &w2.n100);
	
	printf("\n둘 중 더 큰 금액은 %d원 입니다.\n", Calc(w1, w2));
}

int Calc(wallet w1, wallet w2) {
	int iTotal_1 = 0;
	int iTotal_2 = 0;

	iTotal_1 = 50000 * w1.n50000 + 10000 * w1.n10000 + 5000 * w1.n5000 + 1000 * w1.n1000 + 500 * w1.n500 + 100 * w1.n100;
	iTotal_2 = 50000 * w2.n50000 + 10000 * w2.n10000 + 5000 * w2.n5000 + 1000 * w2.n1000 + 500 * w2.n500 + 100 * w1.n100;
	return (iTotal_1 > iTotal_2 ? iTotal_1 : iTotal_2);
}

