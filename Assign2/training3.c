#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

typedef struct food {
	char foodName[20];
	int calories;
}food;

void PrintInfo(food* foods, int nFood, int calories);

int main(void) {
	int cal = 0;
	food foods[5] = { {"햄버거",900}, {"불고기", 500}, {"초밥",300}, {"라면",400}, {"곤약",0} };
	printf("칼로리 값을 입력하세요 : ");
	scanf("%d", &cal);
	printf("\n");
	PrintInfo(foods, 5, cal);

}

void PrintInfo(food* foods, int nFood, int calories) {
	printf("%d칼로리 이상 : ", calories);
	for (int i = 0; i < nFood; i++) {
		printf("%s", (foods + i)->calories >= calories ? (foods+i)->foodName : "");
		if ((foods + i)->calories >= calories) {
			printf(" ");
		}
	}
	
	printf("\n%d칼로리 미만 : ", calories);
	for (int i = 0; i < nFood; i++) {
		printf("%s", (foods + i)->calories < calories ? (foods+i)->foodName : "");
		if ((foods + i)->calories < calories) {
			printf(" ");
		}
	}
}
	

