#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)

typedef struct node* nodePointer;
typedef struct node {
	nodePointer llink;
	int data;
	nodePointer rlink;
}node;

nodePointer create(nodePointer head,int data) {
	nodePointer newNode = (nodePointer)malloc(sizeof(*newNode));
	newNode->data = data;
	newNode->llink = head;
	newNode->rlink = head;
	head->llink = newNode;
	head->rlink = newNode;
	return newNode;
}

//node�ڿ� newnode����
void insert(nodePointer node, nodePointer newnode,int data) {
	newnode->data = data;
	newnode->llink = node;
	newnode->rlink = node->rlink;
	node->rlink->llink = newnode;
	node->rlink = newnode;
}

void delete(nodePointer head, nodePointer deleted) {
	if (head == deleted) {
		printf("empty");
		exit(EXIT_FAILURE);
	}
	else {
		deleted->llink->rlink = deleted->rlink;
		deleted->rlink->llink = deleted->llink;
		free(deleted);
	}
}

void invers(nodePointer head,int index,FILE* stream) {
	nodePointer temp;
	temp = head;
	nodePointer node = (nodePointer)malloc(sizeof(*node));
	for (int i = 0; i < index; i++) {
		temp = temp->rlink;
		node = temp;
	}
	temp = node;
	for (int i = 0; i < 5; i++) {
		fprintf(stream, "%d ", temp->data);
		temp = temp->llink;
		if (temp == head)
			temp = temp->llink;
	}
	fprintf(stream, "\n");
}

void print(nodePointer head,FILE* stream) {
	nodePointer temp;
	temp = head->rlink;
	for (int i = 0; i < 5; i++) {
			fprintf(stream, "%d ", temp->data);
			temp = temp->rlink;
			if (temp == head) //temp �� head�� data�� �����Ƿ� �� �����ʳ��� ��ĭ �� �̵�
				temp = temp->rlink;
	}
	fprintf(stream, "\n");
}

int main(void) {
	FILE* stream = fopen("input.txt", "r");
	FILE* stream2 = fopen("output.txt", "w");
	nodePointer head = (nodePointer)malloc(sizeof(*head));
	head->llink = head; head->rlink = head;
	int n, x, y; //n: ����Ƚ��  x:�Լ����� ù��° ����   y:�Լ����� �ι�°����
	char buffer[10];
	fscanf(stream, "%d", &n);
	for (int i = 0; i < n; i++) {
		fscanf(stream, "%s", buffer);
		if (!strcmp(buffer, "create")){
			fscanf(stream, "%d", &x);
			create(head, x);
			print(head, stream2);
		}
		else if(!strcmp(buffer, "insert")) {
			fscanf(stream, "%d %d", &x, &y);
			nodePointer newnode = (nodePointer)malloc(sizeof(*newnode));
			nodePointer node = (nodePointer)malloc(sizeof(*node));
			nodePointer temp;
			temp = head;
			for (int i = 0; i < x; i++) { //x��° ������ ������ ���̹Ƿ� x��° ��带 ã�´�
				temp = temp->rlink;
				node = temp;
			}
			insert(node, newnode, y);
			print(head, stream2);
		}
		else if (!strcmp(buffer, "delete")) {
			fscanf(stream, "%d", &x);
			nodePointer node = (nodePointer)malloc(sizeof(*node));
			nodePointer temp;
			temp = head;
			for (int i = 0; i < x; i++) {
				temp = temp->rlink;
				node = temp;
			}
			delete(head, node);
			print(head, stream2);
		}
		else if (!strcmp(buffer, "invers")) {
			fscanf(stream, "%d", &x);
			invers(head, x, stream2);
		}
	}

	fclose(stream);
	fclose(stream2);
	
	return 0;
}