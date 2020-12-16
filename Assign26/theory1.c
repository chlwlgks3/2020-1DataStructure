#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)
#define KEY_SIZE 10 //탐색 키의 최대길이
#define empty(e) ( strlen(e.name) == 0)

typedef struct {
	char name[KEY_SIZE];
	int kor, math, eng;
}element;

//hash table의 각 요소들 초기화(각 버켓들을 공백상태로 만든다.)
//문자열(학생의이름)이 탐색키 이므로 탐색키의 첫번째 문자를 NULL로 정해줌
void init_table(element ht[], int bucketSize) {
	for (int i = 0; i < bucketSize; i++)
		ht[i].name[0] = NULL;
}

//문자열(학생의 이름)을 정수로 변환해준다.
int stringToInt(char* key) {
	int number = 0;
	while (*key)
		number += *key++;
	if (number < 0) //문자열의 각 문자를 합한것이 음수라면(한글로 구성되있다면)
		return -1 * number;
	else
		return number;
}

//divide(제산함수)를 이용한 해싱함수
int hash_function(char* key, int bucketSize) {
	return stringToInt(key) % bucketSize;
}

void hash_add(element item, element ht[], int bucketSize, FILE* stream) {
	int i = hash_function(item.name, bucketSize);
	if (!empty(ht[i]))
		fprintf(stream, "%s overflow\n", item.name);
	else
		ht[i] = item;
}

void hash_search(char* name, element ht[], int bucketSize, FILE* stream) {
	int hash_value = 0;
	for (int i = 0; i < bucketSize; i++)
		if (!strcmp(name, ht[i].name)) {
			hash_value = i;
			break;
		}
	fprintf(stream, "%s %d %d %d\n", ht[hash_value].name, ht[hash_value].kor, ht[hash_value].math, ht[hash_value].eng);
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