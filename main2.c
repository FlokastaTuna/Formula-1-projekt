#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "header.h"



int main(void) {
	int n = 0;
	int a;
	int odabir = 0;
	FORMULA* F;
	char* file;
	file = "formula.bin";
	printf("Za koliko bolida zelite unositi podatke? ");
	scanf("%d", &n);
	getchar();

	zapisivanjeFormule(file, n);
	F = citajFormule(file, n);
	printf("Posto ste unijeli podatke za zeljene bolide, dobivate na izbor slijedece opcije :\n");
	while (!odabir) {
		printf("--------------------\n");
		printf("IZBORNIK: \n");
		printf("Trazi formulu: 1\n");
		printf("Azuriraj formulu: 2\n");
		printf("Dodaj novu formulu: 3\n");
		printf("Sortiraj formule po ostvarenom vremenu: 4\n");
		printf("Obrisi jednu od dodanih formula: 5\n");
		printf("Obrisi datoteku: 6\n");
		printf("Preimenuj datoteku: 7\n");
		printf("Kopiraj datoteku: 8\n");
		printf("Izlaz iz programa: 9\n");
		printf("--------------------\n");
		printf("Unesite opciju: ");
		scanf("%d", &a);

		switch (a) {
		case 1: {
			printf("--------------------\n");
			pretrazivanjeFormule(F, n);
			break; }
		case 2: {
			printf("--------------------\n");
			azuriranjeFormule(file, n);

			FILE* pFile = fopen(file, "rb");
			if (pFile == NULL) {
				return -1;
			}
			fseek(pFile, 0, SEEK_END);
			long file_size = ftell(pFile);
			long last_element_offset = file_size - sizeof(int);
			fseek(pFile, last_element_offset, SEEK_SET);
			int last_element;
			fread(&last_element, sizeof(int), 1, pFile);
			fclose(pFile);
			F = citajFormule(file, last_element);
			n = last_element;

			break; }
		case 3: {
			printf("--------------------\n");
			dodavanjeFormule(file);

			FILE* pFile = fopen(file, "rb");
			if (pFile == NULL) {
				return -1;
			}
			fseek(pFile, 0, SEEK_END);
			long file_size = ftell(pFile);
			long last_element_offset = file_size - sizeof(int);
			fseek(pFile, last_element_offset, SEEK_SET);
			int last_element;
			fread(&last_element, sizeof(int), 1, pFile);
			fclose(pFile);
			F = citajFormule(file, last_element);
			n = last_element;

			break; }
		case 4: {
			printf("--------------------\n");
			sortirajFormule(file);
			F = citajFormule(file, n);
			break; }
		case 5: {
			printf("--------------------\n");
			F = obrisiFormulu(F, n, file);
			break; }
		case 6: {
			printf("--------------------\n");
			obrisiDatoteku(file);
			break; }
		case 7: {
			printf("--------------------\n");
			preimenujDatoteku(file);
			break; }
		case 8: {
			printf("--------------------\n");
			kopirajDatoteku(file, "nova_formula.bin");
			break; }
		case 9: {
			printf("--------------------\n");
			printf("Dovidenja!");
			F = sloboda(F);
			return 0; }
		default: {
			printf("--------------------\n");
			printf("Nepoznata opcija\n");
			break; }
		}
	}
	return 0;
}

