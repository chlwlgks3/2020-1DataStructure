#include <stdio.h>
#include <stdlib.h>
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)
#define TRUE 1
#define FALSE 0

int save[128];
int count = 1;
int count2 = 0;
typedef struct threadedTree* treePointer;
typedef struct threadedTree{
	short int leftThread;
	short int rightThread;
	int data;
	int index;
	treePointer leftChild;
	treePointer rightChild;
}threadedTree;

void inorder(treePointer ptr) {
	if (ptr) {
		inorder(ptr->leftChild);
		save[count++] = ptr->index;
		inorder(ptr->rightChild);
	}
}

int find(int* arr,int index,int n) {
	int result;
	for (int i = 1; i <= n-count2; i++) {
		if (arr[i] == index)
			result = i;
	}
	return result;
}

treePointer insucc(treePointer tree) {
	treePointer temp;
	temp = tree->rightChild;
	if (tree->rightThread == FALSE)
		while (temp->leftThread == FALSE)
			temp = temp->leftChild;
	return temp;
}

void tinorder(treePointer tree) {
	treePointer temp = tree;
	for (;;) {
		temp = insucc(temp);
		if (temp == tree) break;
		printf("%d ", temp->data);
	}
}

int main(void) {
	FILE* stream = fopen("input.txt", "r");
	FILE* stream2 = fopen("output.txt","w");
	int n, data;
	treePointer arr[128];
	for (int i = 0; i < 128; i++)
		arr[i] = (treePointer)malloc(sizeof(threadedTree));
	fscanf(stream, "%d", &n);
	for (int i = 1; i <= n; i++) {
		fscanf(stream, "%d", &data);
		if (data == -1) {
			arr[i] = NULL;
			count2++;
		}
		else {
			arr[i]->data = data;
			arr[i]->index = i;
		}
	}

	for (int i = 1; i <= n; i++) {
		if (arr[i] != NULL) {
			if (2 * i <= n) {
				arr[i]->leftThread = FALSE;
				arr[i]->leftChild = arr[2 * i];
			}
			else 
				arr[i]->leftChild = NULL;
			if (2 * i + 1 <= n) {
				arr[i]->rightThread = FALSE;
				arr[i]->rightChild = arr[2 * i + 1];
			}
			else 
				arr[i]->rightChild = NULL;
		}
	}
	//arr[0]를 헤드노드로 사용
	arr[0]->leftThread = FALSE;
	arr[0]->rightThread = FALSE;
	arr[0]->leftChild = arr[1];
	arr[0]->rightChild = arr[0];
	inorder(arr[1]);
	for (int i = 1; i <= n - count2; i++) {
		printf("%d--- ", save[i]);
	}
	for (int i = 1; i <= n; i++) {
		if (arr[i] != NULL) {
			if (arr[i]->leftChild == NULL) {
				arr[i]->leftThread = TRUE;
				arr[i]->leftChild = arr[find(save, i, n)-1];
			}
			if (arr[i]->rightChild == NULL) {
				arr[i]->rightThread = TRUE;
				if (find(save, i, n) == 10)
					arr[i]->rightChild = arr[0];
				else
					arr[i]->rightChild = arr[find(save, i, n)+1];
			}
		}
	}
	tinorder(arr[1]);


	return 0;
}