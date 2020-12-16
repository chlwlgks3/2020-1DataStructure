#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define MAX_TERMS 100

typedef struct {
	int coef;
	int expon;
}polynomial;

polynomial terms[MAX_TERMS];
int avail = 0;

void padd(int startA, int finishA, int startB, int finishB, 
								   int* startD, int* finishD);
void attach(int coefficient, int exponent);
int main(void) {
	FILE* stream;
	stream = fopen("input.txt", "r");
	int startA, finishA, startB, finishB, startD, finishD,len_A,len_B;
	startA = 0;
	fscanf(stream, "%d", &len_A);
	finishA = startA + len_A - 1;
	for (int i = 0; i <= finishA; i++) {
		fscanf(stream, "%d %d", &terms[i].coef, &terms[i].expon);
	}

	startB = finishA + 1;
	fscanf(stream, "%d", &len_B);
	finishB = startB + len_B - 1;
	for (int i = startB; i <= finishB; i++) {
		fscanf(stream, "%d %d", &terms[i].coef, &terms[i].expon);
	}
	fclose(stream);
	padd(startA, finishA, startB, finishB, &startD, &finishD);
	stream = fopen("output.txt", "w");
	for (int i = startD; i <= finishD; i++) {
		fprintf(stream, "%d,%d ",terms[i].coef,terms[i].expon );
	}

	fclose(stream);
	return 0;
}

void attach(int coefficient, int exponent) {
	if (avail >= MAX_TERMS) {
		fprintf(stderr, "다항식에 항이 너무 많다.");
		exit(EXIT_FAILURE);
	}
	terms[avail].coef = coefficient;
	terms[avail++].expon = exponent;
}

void padd(int startA, int finishA, int startB, int finishB,
	      int* startD, int* finishD) {
	int coefficient;
	avail = finishB + 1;
	*startD = avail;
	while (startA <= finishA && startB <= finishB) {
		if (terms[startA].expon < terms[startB].expon) {
			attach(terms[startB].coef, terms[startB].expon);
			startB++;
		}else if (terms[startA].expon > terms[startB].expon) {
			attach(terms[startA].coef, terms[startA].expon);
			startA++;
		}else {
			coefficient = terms[startA].coef + terms[startB].coef;
			if (coefficient)
				attach(coefficient, terms[startA].expon);
			startA++;
			startB++;
		}
	}
	for (; startA <= finishA; startA++)
		attach(terms[startA].coef, terms[startA].expon);
	for (; startB <= finishB; startB++)
		attach(terms[startB].coef, terms[startB].expon);
	*finishD = avail - 1;
}

