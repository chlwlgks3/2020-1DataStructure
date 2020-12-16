#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct MENU* mPtr;
typedef struct MENU
{
	char name[20];
	int price;
	mPtr next;
};

void insert(mPtr*);
void print(mPtr);
void save(mPtr);
void load(mPtr*);
void exits();

int main()
{
	int c;
	mPtr head = NULL;
	while (1)
	{
		printf("1.insert 2.print 3.save 4.load 5.exit\n메뉴를 선택하세요 :");
		scanf("%d", &c);
		switch (c)
		{
		case 1:
			insert(&head);
			break;
		case 2:
			printf("=====================\n");
			print(head);
			printf("=====================\n");
			break;
		case 3:
			save(head);
			break;
		case 4:
			load(&head);
			break;
		case 5:
			exits();
			break;
		}
		printf("\n\n");
	}
}
void insert(mPtr* ptr)
{
	char name[20];
	int price;
	mPtr temp = (mPtr)malloc(sizeof(struct MENU));
	temp->next = NULL;
	printf("치킨 이름 입력: ");
	scanf("%s", name);
	printf("치킨 가격 입력: ");
	scanf("%d", &price);
	strcpy(temp->name, name);
	temp->price = price;
	if (!*ptr)
	{
		*ptr = temp;
		return;
	}
	temp->next = (*ptr)->next;
	(*ptr)->next = temp;
}
void print(mPtr ptr)
{
	if (ptr)
	{
		printf("%s %d\n", ptr->name, ptr->price);
		print(ptr->next);
	}
}
void save(mPtr ptr)
{
	FILE* fp = fopen("data.txt", "w");
	mPtr temp;
	for (temp = ptr; temp; temp = temp->next)
		fprintf(fp, "%s %d\n", temp->name, temp->price);
}
void load(mPtr* ptr)
{
	char name[20];
	int price;
	mPtr temp;
	FILE* fp = fopen("data.txt", "r");
	while (~fscanf(fp, "%s %d", name, &price))
	{
		temp = (mPtr)malloc(sizeof(struct MENU));
		temp->next = NULL;
		strcpy(temp->name, name);
		temp->price = price;
		if (!*ptr)
		{
			*ptr = temp;
			return;
		}
		temp->next = (*ptr)->next;
		(*ptr)->next = temp;
	}
}
void exits()
{
	exit(EXIT_SUCCESS);
}