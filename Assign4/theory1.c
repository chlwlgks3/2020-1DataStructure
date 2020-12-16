/*
아래 설명을 참고하여 포인터를 사용해 node1, node2...nodeN 이 연결되게 하고, 이를 차례대로 출력하는 프로그램을 작성하시오.

struct Node {
 int data;
 struct Node *next;
};
struct Node* head = NULL;

-정수를 저장하는 data 변수와, 다음 Node의 주소를 저장하는 포인터 변수 next를 멤버로 하는 구조체 Node를 정의
-구조체 Node의 주소를 저장할 수 있는 포인터변수 head를 선언
-node1을 동적으로 할당 받은 후 data에 10 저장
-head에 node1의 주소 저장
-node2를 동적으로 할당 받은 후 data에 20 저장
-node1 Node의 next에 node2의 주소 저장
*/

/////////////////////////////////////////////////////////////////////////////////
#include <stdio.h>
#include <stdlib.h>

struct Node {
	int data;
	struct Node* next;
};

int main(void) {
	struct Node* head = NULL;

	struct Node* node1 = (struct Node*)malloc(sizeof(struct Node));
	node1->data = 10;
	head = node1;

	struct Node* node2 = (struct Node*)malloc(sizeof(struct Node));
	node2->data = 20;
	node1->next = node2;
	node2->next = NULL;

	printf("%d->%d", node1->data, node1->next->data);
	free(node1);
	free(node2);

	return 0;
}
