#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)
#define KEY_SIZE 10
#define equal(e1,e2) ( !strcmp(e1.name,e2.name) )

typedef struct {
	char name[KEY_SIZE];
	int kor, math, eng;
}element;

typedef struct ListNode {
	element item;
	struct ListNode* link;
}ListNode;

int stringToInt(char* key) {
	int number = 0;
	while (*key)
		number += *key++;
	if (number < 0) //���ڿ��� �� ���ڸ� ���Ѱ��� �������(�ѱ۷� �������ִٸ�)
		return -1 * number;
	else
		return number;
}

//divide(�����Լ�)�� �̿��� �ؽ��Լ�
int hash_function(char* key, int bucketSize) {
	return stringToInt(key) % bucketSize;
}

void hash_chain_add(element item, ListNode *ht[],int bucketSize) {
	int hash_value = hash_function(item.name, bucketSize);
	ListNode* ptr; //���ο� ���
	ListNode* node_before = NULL; //�������
	ListNode* node = ht[hash_value]; //������
	for (; node; node_before = node, node = node->link) {
		if (equal(node->item, item)) {
			fprintf(stderr, "�̹� Ž��Ű�� ���������\n");
			return;
		}
	}
	ptr = (ListNode*)malloc(sizeof(*ptr));
	ptr->item = item;
	ptr->link = NULL;
	if (node_before)
		node_before->link = ptr;
	else
		ht[hash_value] = ptr;
}

void hash_chain_find(char* name, ListNode *ht[], int bucketSize) {
	ListNode* node;

	int hash_value = hash_function(name, bucketSize);
	for (node = ht[hash_value]; node; node = node->link) {
		if (!strcmp(node->item.name,name)) {
			printf("%s %d %d %d\n",node->item.name,node->item.kor,node->item.math,node->item.eng);
			return;
		}
	}
	printf("Ű�������ϴ�\n");
}

int main(void) {
	FILE* stream = fopen("input.txt", "r");
	FILE* stream2 = fopen("output.txt", "w");
	int b, n, m, kor, math, eng;
	char name[KEY_SIZE];
	element temp;
	ListNode** hash_table;
	fscanf(stream, "%d %d", &b, &n);
	hash_table = (ListNode**)malloc(b * sizeof(*hash_table));
	for (int i = 0; i < b; i++) {
		hash_table[i] = (ListNode*)malloc(sizeof(*hash_table[i]));
		hash_table[i] = NULL;
	}
	
	for (int i = 0; i < n; i++) {
		fscanf(stream, "%s %d %d %d", name, &kor, &math, &eng);
		strcpy(temp.name, name);
		temp.kor = kor;
		temp.math = math;
		temp.eng = eng;
		hash_chain_add(temp, hash_table, b);
	}
	fscanf(stream, "%d", &m);
	for (int i = 0; i < m; i++) {
		fscanf(stream, "%s", &name);
		hash_chain_find(name, hash_table, b);
	}

	free(hash_table);
	for (int i = 0; i < b; i++)
		free(hash_table[i]);
	fclose(stream);
	fclose(stream2);
	return 0;
}