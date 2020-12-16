#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)
#define TRUE 1
#define FALSE 0

typedef enum {not,and,or,true,false} logical;
typedef enum {x,y,z} TYPE;
typedef struct node* treePointer;
typedef struct node {
	treePointer left;
	treePointer right;
	logical data;
	short int value;
}node;

typedef struct save {
	int index;
	TYPE type;
}save;

void postOrderEval(treePointer node) {
	if (node) {
		postOrderEval(node->left);
		postOrderEval(node->right);
		switch (node->data) {
		case not:
			node->value = !(node->right->value);
			break;
		case and:
			node->value = node->right->value && node->left->value;
			break;
		case or:
			node->value = node->right->value || node->left->value;
			break;
		case true:
			node->value = TRUE;
			break;
		case false:
			node->value = FALSE;
		}
	}
}

void change(treePointer* arr,save* savearr,int* choice, int count) {
	for (int i = 1; i <= count; i++) {
		switch (savearr[i].type) {
		case x: arr[savearr[i].index]->data = choice[0]; break;
		case y: arr[savearr[i].index]->data = choice[1]; break;
		case z:arr[savearr[i].index]->data = choice[2];
		}
	}
}

int main(void) {
	FILE* stream = fopen("input.txt", "r");
	FILE* stream2 = fopen("output.txt", "w");
	int n;
	int count = 1;
	save savearr[128];
	char buffer[10];
	treePointer arr[128];
	for (int i = 0; i < 128; i++)
		arr[i] = (treePointer)malloc(sizeof(node));
	fscanf(stream, "%d", &n);
	for (int i = 1; i <= n; i++) {
		fscanf(stream, "%s", buffer);
		if (!strcmp(buffer, "not"))
			arr[i]->data = not;
		else if (!strcmp(buffer, "and"))
			arr[i]->data = and;
		else if (!strcmp(buffer, "or"))
			arr[i]->data = or ;
		else if (!strcmp(buffer, "-1"))
			arr[i] = NULL;
		else if (!strcmp(buffer, "x")) {
			savearr[count].index = i;
			savearr[count++].type = x;
			arr[i]->data = 0; //data에 임의로 0 저장해놓는다 추후에 변경
		}
		else if (!strcmp(buffer, "y")) {
			savearr[count].index = i;
			savearr[count++].type = y;
			arr[i]->data = 0;
		}
		else if (!strcmp(buffer, "z")) {
			savearr[count].index = i;
			savearr[count++].type = z;
			arr[i]->data = 0; 
		}
	}
	for (int i = 1; i <= n; i++) {
		if (arr[i] != NULL) {
			arr[i]->value = 0; //임의로 모든노드의 value에 0 저장해놓는다
			if (2 * i <= n) 
				arr[i]->left = arr[2 * i];
			else
				arr[i]->left = NULL;
			if (2 * i + 1 <= n)
				arr[i]->right = arr[2 * i + 1];
			else
				arr[i]->right = NULL;
		}
	}
	fprintf(stream2,"-x y z : true or false-\n");
	int choice[3];
	choice[0] = 4; choice[1] = 4; choice[2] = 4;
	change(arr, savearr, choice, count);
	postOrderEval(arr[1]);
	fprintf(stream2,"f f f : %s\n", arr[1]->value==1 ? "true":"false");

	choice[0] = 4; choice[1] = 4; choice[2] = 3;
	change(arr, savearr, choice, count);
	postOrderEval(arr[1]);
	fprintf(stream2,"f f t : %s\n", arr[1]->value == 1 ? "true" : "false");

	choice[0] = 4; choice[1] = 3; choice[2] = 4;
	change(arr, savearr, choice, count);
	postOrderEval(arr[1]);
	fprintf(stream2,"f t f : %s\n", arr[1]->value == 1 ? "true" : "false");

	choice[0] = 3; choice[1] = 4; choice[2] = 4;
	change(arr, savearr, choice, count);
	postOrderEval(arr[1]);
	fprintf(stream2,"t f f : %s\n", arr[1]->value == 1 ? "true" : "false");

	choice[0] = 4; choice[1] = 3; choice[2] = 3;
	change(arr, savearr, choice, count);
	postOrderEval(arr[1]);
	fprintf(stream2,"f t t : %s\n", arr[1]->value == 1 ? "true" : "false");

	choice[0] = 3; choice[1] = 4; choice[2] = 3;
	change(arr, savearr, choice, count);
	postOrderEval(arr[1]);
	fprintf(stream2,"t f t : %s\n", arr[1]->value == 1 ? "true" : "false");

	choice[0] = 3; choice[1] = 3; choice[2] = 4;
	change(arr, savearr, choice, count);
	postOrderEval(arr[1]);
	fprintf(stream2,"t t f : %s\n", arr[1]->value == 1 ? "true" : "false");

	choice[0] = 3; choice[1] = 3; choice[2] = 3;
	change(arr, savearr, choice, count);
	postOrderEval(arr[1]);
	fprintf(stream2,"t t t : %s\n", arr[1]->value == 1 ? "true" : "false");

	fclose(stream);
	fclose(stream2);
	for (int i = 0; i < 128; i++)
		free(arr[i]);

	return 0;
}