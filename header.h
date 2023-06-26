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
void pretrazivanjeFormule(FORMULA* formula, int n);
void azuriranjeFormule(char* file, int n);
void obrisiDatoteku(const char* file);
void preimenujDatoteku(const char*);
//void kopirajDatoteku(char*, char*);
FORMULA* obrisiFormulu(FORMULA* formula, int n, char* file);
void sortirajFormule(char*);
//void dodavanjeFormule(char*);
#endif
