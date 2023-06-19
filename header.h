#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#define _CRT_SECURE_NO_WARNINGS

typedef struct vrijeme {
	int min;
	int sec;
	int stot;
}VRIJEME;

typedef struct formula {
	char ime[70];
	char prezime[70];
	int bolid_broj;
	VRIJEME vrijeme;
}FORMULA;

FORMULA* sloboda(FORMULA* F);
FORMULA* citajFormule(char* file, int n);
void zapisivanjeFormule(char* file, int n);
// ovdje ide funkcija za pretrazivanje

#endif