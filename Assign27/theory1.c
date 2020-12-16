#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)
#define KEY_SIZE 10 //Ž�� Ű�� �ִ����
#define empty(e) ( strlen(e.name) == 0)

typedef struct {
	char name[KEY_SIZE];
	int kor, math, eng;
}element;

//hash table�� �� ��ҵ� �ʱ�ȭ(�� ���ϵ��� ������·� �����.)
//���ڿ�(�л����̸�)�� Ž��Ű �̹Ƿ� Ž��Ű�� ù��° ���ڸ� NULL�� ������
void init_table(element ht[], int bucketSize) {
	for (int i = 0; i < bucketSize; i++)
		ht[i].name[0] = NULL;
}

//���ڿ�(�л��� �̸�)�� ������ ��ȯ���ش�.
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

void hash_add(element item, element ht[], int bucketSize, FILE* stream) {
	int i, hash_value;
	hash_value = i = hash_function(item.name, bucketSize);
	while (!empty(ht[i])) {
		if (!strcmp(item.name, ht[i].name)) {
			fprintf(stderr, "Ž��Ű�� �ߺ��Ǿ����ϴ�.\n");
			return;
		}
		i = (i + 1) % bucketSize;
		if (i == hash_value) {
			fprintf(stream, "%s overflow\n",item.name);
			return;
		}
	}
	ht[i] = item;
	return;
}

void hash_search(char* name, element ht[], int bucketSize, FILE* stream) {
	int i, hash_value;
	hash_value = i = hash_function(name, bucketSize);
	while (!empty(ht[i])) {
		if (!strcmp(name, ht[i].name)) {
			fprintf(stream, "%s %d %d %d\n", ht[i].name, ht[i].kor, ht[i].math, ht[i].eng);
			return;
		}
		i = (i + 1) % bucketSize;
		if (i == hash_value) {
			fprintf(stream, "����\n");
			return;
		}
		fprintf(stream, "����\n");
	}
}

int main(void) {
	FILE* stream = fopen("input.txt", "r");
	FILE* stream2 = fopen("output.txt", "w");
	int b, n, kor, math, eng, search_count;
	char name[KEY_SIZE];
	element* ht;
	element temp;
	fscanf(stream, "%d %d", &b, &n);
	ht = (element*)malloc(b * sizeof(*ht));
	init_table(ht, b);
	for (int i = 0; i < n; i++) {
		fscanf(stream, "%s %d %d %d", name, &kor, &math, &eng);
		strcpy(temp.name, name);
		temp.kor = kor;
		temp.math = math;
		temp.eng = eng;
		hash_add(temp, ht, b, stream2);
	}
	fscanf(stream, "%d", &search_count);
	for (int i = 0; i < search_count; i++) {
		fscanf(stream, "%s", name);
		hash_search(name, ht, b, stream2);
	}

	free(ht);
	fclose(stream);
	fclose(stream2);
	return 0;
}