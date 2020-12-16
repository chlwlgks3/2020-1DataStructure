#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)
#define MAX_TREE_SIZE 20

typedef struct type {
	char data;
	int index;
}type;

// arr배열에서 target문자의 인덱스를 찾아서 반환하는 함수
int FIND(char* arr, char target) {
	char temp = 0;
	int index, i = 1;
	while (temp != target) {
		if (arr[i++] == target) {
			index = i;
			break;
		}
	}
	return index;
}

int main(void) {
	FILE* stream = fopen("input.txt", "r");
	FILE* stream2 = fopen("output.txt", "w");
	char pre[MAX_TREE_SIZE];
	char in[MAX_TREE_SIZE];
	char tree[100];
	int input = 0;
	int count_pre = 1; // pre배열과 in배열의 인덱스1부터 사용
	int count_in = 1;

	while (1) {
		input = fgetc(stream);
		if (input != '\n') //다음 줄로 이동하기전까지 pre배열의 인덱스를 하나씩 증가시키면서 문자를 넣음
			pre[count_pre++] = input;
		else
			break;
	}
	while (1) {
		input = fgetc(stream);
		if (input != EOF) //파일의 끝에 도달하기전까지 in배열의 인덱스를 하나씩 증가시키며 문자를 넣음
			in[count_in++] = input;
		else
			break;
	}
	int count = count_pre;
	count_pre = 1; //다시 pre배열의 첫번째인덱스로 초기화
	count_in = 1;

	for (int i = 0; i < 100; i++)
		tree[i] = -1;

	type parent;
	tree[1] = pre[count_pre++]; //tree의 루트노드는 preinorder배열의 첫번째 문자
	parent.data = tree[1];
	parent.index = 1;
	char find_pre = pre[count_pre++];
	char find_in = in[count_in++];
	while (count_pre <= count && count_in <= count) {
		while (find_in != parent.data) {
			tree[parent.index * 2] = find_pre;
			find_pre = pre[count_pre++];
			if (find_pre == find_in)
				find_in = in[count_in++];
			else {
				parent.data = tree[parent.index * 2];
				parent.index *= 2;
			}
		}
		find_in = in[count_in++];
		while (find_pre == find_in) {
			tree[parent.index * 2 + 1] = find_pre;
			find_pre = pre[count_pre++];
			find_in = in[count_in++];
			parent.data = tree[parent.index * 2 + 1];
			parent.index = parent.index * 2 + 1;
		}
		parent.data = find_in;
		find_in = in[count_in++];
		tree[parent.index * 2 + 1] = find_pre;
		find_pre = pre[count_pre++];
	}
	for (int i = 1; i < 100; i++)
		if (tree[i] > 0)
			fprintf(stream2,"%c", tree[i], i);
	fclose(stream);
	fclose(stream2);
	return 0;
}