#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "header.h"

void zapisivanjeFormule(char* file, int n) {
	int i;
	FILE* pFile = fopen("formula.bin", "wb+");
	if (pFile == NULL) {
		perror("Ne radi");
		exit(EXIT_FAILURE);
	}
	FORMULA* temp = (FORMULA*)calloc(n, sizeof(FORMULA));
	if (temp == NULL) {
		perror("Ne radi");
		exit(EXIT_FAILURE);
	}
	for (i = 0; i < n; i++) {
		printf("Unesi ime vozaca: ");
		scanf("% 50[^ \n]", temp[i].ime);
		getchar();
		printf("Unesi prezime vozaca: ");
		scanf(" % 50[^ \n]", temp[i].prezime);
		getchar();
		printf("Unesi broj bolida: ");
		scanf("%d", &temp[i].bolid_broj);
		getchar();
		printf("Unesi vrijeme: ");
		scanf("%d:%d:%d", &temp[i].vrijeme.min, &temp[i].vrijeme.sec, &temp[i].vrijeme.stot);
		getchar();
	}
	fwrite(temp, sizeof(FORMULA), n, pFile);
	fwrite(&n, sizeof(int),1, pFile);
	fclose(pFile);
	free(temp);
}

FORMULA* citajFormule(char* file, int n) {
	//int i;
	FILE* pFile = fopen("formula.bin", "wb+");
	if (pFile == NULL) {
		perror("Ne radi");
		exit(EXIT_FAILURE);
	}
	FORMULA* temp = (FORMULA*)calloc(n, sizeof(FORMULA));
	if (temp == NULL) {
		perror("Ne radi");
		exit(EXIT_FAILURE);
	}
	
	printf("Dodane formule su:\n");
	fread(temp, sizeof(FORMULA), n, pFile);
	fclose(pFile);
	return temp;
}

FORMULA* sloboda(FORMULA* F) {
	free(F);
	return NULL;
}