# 2020-1DataStructure

2020년 1학기 임경식 교수님의 자료구조 / 자료구조응용(컴퓨터공학부 개설)의 과제를 정리한것입니다.

각 Assign 폴더의 theory.c는 자료구조의 과제코드이고 traning.c는 자료구조응용의 과제입니다.

# index
### [Assign1](https://github.com/MinkiJo/2020_1_DataStructure/tree/main/DS01)
-theory1.c  
임의의 수의 제곱승을 구하는 함수 square()와 세제곱승을 구하는 함수 cube()를 구현하여 임의의 수의 
다섯제곱승 구하는 프로그램  
-theory2.c  
정수 n을 입력받아 1 + 1! + 2! + 3! + ... + (n-1)! + n! 을 구하는 프로그램  
long factsum(int n) 과 long fact(int n)를 이용  
-theory3.c  
void sorting(int arr[], int arrSize);을 사용하여 정수형 1차원 배열 arr[]에 임의의 정수 5개를  
차례대로 입력받아 저장한 후, 오름차순으로 정렬하여 출력하는 프로그램(배열을 오름차순으로 정렬할 때 포인터를사용)
-traing1.c  
-traing2.c  

### [Assign2](https://github.com/MinkiJo/2020_1_DataStructure/tree/main/DS01)
-theory1.c  
다음과 같이 3x2와 2x3의 두 행렬에서, 행렬의 곱을 구하는 프로그램을 작성하시오. 단, scanf 함수를 사용하여 배열의 값을 입력한다.  
다음에 주어진 함수를 이용하시오.   
void display (int x[][3])  행렬의 곱을 출력해주는 함수  
void multply (int x[][3], int a[][2], int b[][3])  두 행렬을 곱해주는 함수  

-theory2.c  
5만원, 1만원, 5천원, 1천원, 500원, 100원짜리 각 화폐의 수를 저장할 수 있는  
각 변수를 멤버로 하는 구조체 wallet의 변수를 2개 선언하고, 표준입력으로 적당한  
값을 입력받은 후 더 큰 돈이 들어있는 지갑의 금액을 출력하는 프로그램을 작성하시오.  

-theory3.c  
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
