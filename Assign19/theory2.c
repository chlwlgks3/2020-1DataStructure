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

// arr�迭���� target������ �ε����� ã�Ƽ� ��ȯ�ϴ� �Լ�
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
	int count_pre = 1; // pre�迭�� in�迭�� �ε���1���� ���
	int count_in = 1;

	while (1) {
		input = fgetc(stream);
		if (input != '\n') //���� �ٷ� �̵��ϱ������� pre�迭�� �ε����� �ϳ��� ������Ű�鼭 ���ڸ� ����
			pre[count_pre++] = input;
		else
			break;
	}
	while (1) {
		input = fgetc(stream);
		if (input != EOF) //������ ���� �����ϱ������� in�迭�� �ε����� �ϳ��� ������Ű�� ���ڸ� ����
			in[count_in++] = input;
		else
			break;
	}
	int count = count_pre;
	count_pre = 1; //�ٽ� pre�迭�� ù��°�ε����� �ʱ�ȭ
	count_in = 1;

	for (int i = 0; i < 100; i++)
		tree[i] = -1;

	type parent;
	tree[1] = pre[count_pre++]; //tree�� ��Ʈ���� preinorder�迭�� ù��° ����
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