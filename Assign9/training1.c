#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning(disable:4996)
#define MAX_STACK_SZIE 100

char stack[MAX_STACK_SZIE];
int top = -1;

void push(char item);
char pop();
int check_matching(char* in);

int main(void) {
	FILE* stream;
	stream = fopen("input.txt", "r");
	int count = 0;
	char blank = 0;
	char buffer[100];
	char** ps; // ��ȣ���ڿ� �迭 ps����
	fscanf(stream, "%d%c", &count, &blank);
	// ��ȣ���ڿ� �迭 �����Ҵ�
	ps = (char**)malloc(count * sizeof(*ps));
	for (int i = 0; i < count; i++) {
		ps[i] = (char*)malloc(50 * sizeof(**ps)); // ��ȣ���ڿ� �ִ���̴� 50
	}

	//input.txt�� ���� ��ȣ���ڿ��� ���پ� �о���δ�
	for (int i = 0; i < count; ++i) {
		fgets(buffer, 100, stream);
		strcpy(ps[i], buffer);
	}

	fclose(stream);
	stream = fopen("output.txt", "w");
	for (int i = 0; i < count; i++) {
		top = -1;
		fprintf(stream, "%s\n", check_matching(ps[i]) ? "YES" : "NO");
	}

	fclose(stream);
	for (int i = 0; i < count; i++)
		free(ps[i]);
	free(ps);

	return 0;
}


void push(char item) {
	if (top == MAX_STACK_SZIE - 1) {
		fprintf(stderr, "stack full\n");
		exit(EXIT_FAILURE);
	}
	else
		stack[++top] = item;
}

char pop() {
	if (top == -1) {
		fprintf(stderr, "stack empty\n");
		exit(EXIT_FAILURE);
	}
	else
		return stack[top--];
}

int check_matching(char* in) {
	char ch;
	char ch2;
	int n = strlen(in);

	for (int i = 0; i < n - 1; i++) {
		ch = in[i];
		switch (ch) {
		case '(': push(ch); break;
		case ')':
			if (top == -1) return 0;
			else {
				ch2 = pop();
				if (ch2 == '(' && ch != ')') return 0;
			}
			break;
		}
	}
	if (top != -1) return 0; // ���ÿ� ����̶� ���������� ¦�̾ȸ´°��̹Ƿ� ����!
	return 1;
}