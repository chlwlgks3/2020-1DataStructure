#define _CRT_SECURE_NO_WARNINGS
#define MAX 50
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int size = 0;
int count = 0;

typedef struct food {
	char name[20];
	int price;
}FOOD;

int find_index(struct food* foods, char* name);
void insert(struct food* foods);
void print(struct food* foods);
void delete(struct food* foods);
void update(struct food* foods);
void file_save(struct food* foods);
void file_load(struct food* foods);

int main(void) {

	FOOD* food = (FOOD*)malloc(MAX * sizeof(FOOD));
	int choice = 0;
	while (choice != 7) {
		printf("<<1.�߰� 2.���� 3.���� 4.��� 5.���Ϸε� 6.���� 7.����>>\n");
		printf("==>�޴����� : ");
		scanf("%d", &choice);

		switch (choice) {
		case 1: insert(food); break;
		case 2: delete(food); break;
		case 3: update(food); break;
		case 4: print(food); break;
		case 5: file_load(food); break;
		case 6: file_save(food); break;
		case 7: break;
		}
	}
	return 0;
}

int find_index(struct food* foods, char* name) {
	int index = 0;
	for (int i = 0; i < size; i++) {
		if (strcmp(foods[i].name, name) == 0) {
			index = i;
			break;
		}
	}
	return index;
}

void insert(struct food* foods) {
	printf("\n���� �̸��� �Է��ϼ��� : ");
	scanf("%s", &foods[size].name);
	printf("���� ������ �Է��ϼ��� : ");
	scanf("%d", &foods[size].price);
	++size;
}

void print(struct food* foods) {
	printf("				<<���� ���� ���>>   \n\n");
	if (count == 0) {
		for (int i = 0; i < size; i++) {
			printf(" �̸� : %s, ���� : %d\n", foods[i].name, foods[i].price);
		}
	}
	else {
		for (int i = 0; i < count; i++) {
			printf(" �̸� : %s, ���� : %d\n", foods[i].name, foods[i].price);
		}
	}
}

void delete(struct food* foods) {
	--size;
	FOOD del_food;
	int index = 0;
	printf("\n������ ���� ������ �Է��ϼ���. ");
	scanf("%s", &del_food.name);
	index = find_index(foods, del_food.name);

	for (int i = index; i < size; i++) {
		strcpy(foods[i].name, foods[i + 1].name);
		foods[i].price = foods[i + 1].price;
	}
	printf("\n%s�� ������ ���� �Ͽ����ϴ�.\n", del_food.name);
}

void update(struct food* foods) {
	FOOD adv_food;
	int index = 0;
	printf("\n������ ���� ������ �Է��ϼ��� : ");
	scanf("%s", &adv_food.name);
	printf("������ ������ �Է��ϼ��� : ");
	scanf("%d", &adv_food.price);
	index = find_index(foods, adv_food.name);

	foods[index].price = adv_food.price;
}

void file_save(struct food* foods) {
	FILE* stream = fopen("food.txt", "w");
	for (int i = 0; i < size; i++) {
		fprintf(stream, "%s %d", foods[i].name, foods[i].price);
	}
	fclose(stream);
}

void file_load(struct food* foods) {
	FILE* stream = fopen("food.txt", "r");
	int ch =0;
	while (ch != EOF) {
		ch = fgetc(stream);
		if (ch == ' ')
			++count;
	}
	fclose(stream);
	stream = fopen("food.txt", "r");
	for (int i = 0; i < count ; i++) {
		fscanf(stream, "%s %d", &foods[i].name, &foods[i].price);
	}
	printf("���Ϸε�\n");
}