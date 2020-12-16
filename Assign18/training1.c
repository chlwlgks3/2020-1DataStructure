#include <stdio.h>
#include <stdlib.h>
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)

int main(void) {
	FILE* stream = fopen("input.txt", "r");
	FILE* stream2 = fopen("output.txt", "w");
	int n, m, data, COUNT = 0;
	int** run;
	int* run_count; 
	int** tree; //tree의 노드에는 int의 주소를 저장
	int size = 1; // size는 Winner Tree의 노드갯수
	fscanf(stream, "%d %d", &n, &m);
	for (int i = 0; i <= m / n; i++)
		size *= 2;
	size -= 1; // size는 Winner Tree의 노드갯수
	tree = (int**)malloc((size+1)*sizeof(*tree)); // tree의 index는 1부터시작
	for(int i=0;i<size+1;i++)
		tree[i] = (int*)malloc(sizeof(**tree)); 
	run = (int**)malloc(n * sizeof(*run));
	for (int i = 0; i < n; i++)
		run[i] = (int*)malloc((m / n) * sizeof(*run[i]));
	run_count = (int*)malloc(n*sizeof(*run_count));
	for (int i = 0; i < n; i++)
		run_count[i] = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m / n; j++) {
			fscanf(stream, "%d", &data);
			run[i][j] = data;
		}
	}
	int index_first = 1;
	for (int i = 0; i < m / n; i++)
		index_first *= 2; // index_first는 tree의 제일높은 레벨의 첫번째 노드

	// tree의 제일높은 레벨의 노드들에 각 run배열의 첫번째 요소의 주소저장
	int count = 0;
	for (int i = index_first; i <= size; i++) {
		tree[i] = &run[count][0];
		run_count[count++]++;
	}

	for (int k = 0; k < 50; k++) {
		for (int i = size; i > 0; i -= 2) {
			if (i != 1) {
				if (*tree[i] > *tree[i - 1])
					tree[i / 2] = tree[i - 1];
				else 
					tree[i / 2] = tree[i];
			}
			else {
				if (*tree[1] > 0 && *tree[1] < 100 && COUNT < m) {
					fprintf(stream2,"%d ", *tree[1]);
					COUNT++;
				}// tree[1]의 참조값 출력
				for (int j = index_first; j <= size; j++) { // tree[1]의 참조값 출력 후 tree의 가장높은 레벨에서 tree[1]의 주소와 똑같은 주소를 가진노드에 run배열의 그다음요소 저장 
					if (tree[j] == tree[1]) {
						tree[j] = &run[j-index_first][run_count[j - index_first]++];
						break;
					}
				}
			}
		}
	}
	return 0;
}