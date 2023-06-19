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
		scanf("%50[^\n]", temp[i].ime);
		getchar();
		for (int j = 0; j < i; j++) {
			if (strcmp(temp[i].ime, temp[j].ime) == 0) {
				printf("Unos imena vec postoji. Unesite drugo ime.\n");
				i--;
				break;
			}
		}
		printf("Unesi prezime vozaca: ");
		scanf("%50[^\n]", temp[i].prezime);
		getchar();
		for (int j = 0; j < i; j++) {
			if (strcmp(temp[i].prezime, temp[j].prezime) == 0) {
				printf("Unos prezimena vec postoji. Unesite drugo prezime.\n");
				i--;
				break;
			}
		}
		printf("Unesi broj bolida: ");
		scanf("%d", &temp[i].bolid_broj);
		getchar();
		for (int j = 0; j < i; j++) {
			if (temp[i].bolid_broj == temp[j].bolid_broj) {
				printf("Unos broja bolida vec postoji. Unesite drugi broj.\n");
				i--;
				break;
			}
		}
		printf("Unesi vrijeme kruga:\n");
		do {
		printf("Prvo unesi minute: ");
		scanf("%d", &temp[i].vrijeme.min);
		getchar();
		printf("Zatim sekunde: ");
		scanf("%d", &temp[i].vrijeme.sec); 
		getchar();
		printf("I na poslijetku, stotinke:");
		scanf("%d", &temp[i].vrijeme.stot);
		getchar();
		if (temp[i].vrijeme.min == 1 && temp[i].vrijeme.sec < 60 && temp[i].vrijeme.stot < 60) {
			break;
		}
		else {
			printf("Unos je netocan, zapamti, u formuli 1, krug staze ne traje duze ili ispod jedne minute! Takoder valjda znas koliko sekundi je jedna minuta i koliko je stotinki jedna sekunda.\n");
		}

		} while (1);
		printf("\n");
		printf("Dodani poadci o formulama su:\n");
		printf("Ime: %s\n", temp[i].ime);
		printf("Prezime: %s\n", temp[i].prezime);
		printf("Broj bolida: %d\n", temp[i].bolid_broj);
		printf("Vrijeme: %d:%d:%d\n", temp[i].vrijeme.min, temp[i].vrijeme.sec, temp[i].vrijeme.stot);
		printf("-------------------------\n");
	}
	fwrite(temp, sizeof(FORMULA), n, pFile);
	fwrite(&n, sizeof(int), 1, pFile);
	fclose(pFile);
	free(temp);
}

FORMULA* citajFormule(char* file, int n) {
	FILE* pFile = fopen("formula.bin", "rb");
	if (pFile == NULL) {
		perror("Ne radi");
		exit(EXIT_FAILURE);
	}
	FORMULA* temp = (FORMULA*)calloc(n, sizeof(FORMULA));
	if (temp == NULL) {
		perror("Ne radi");
		exit(EXIT_FAILURE);
	}
    fread(temp, sizeof(FORMULA), n, pFile); 
    fclose(pFile);
	return temp;
}

void pretrazivanjeFormule(FORMULA* formule, int n) {
	int opcija;
	char trazeno_ime[50];
	char trazeno_prezime[50];
	int trazeni_broj_bolida;
	int trazena_sec, trazena_stot, trazena_min;
	int i;
	printf("Odaberi po kojem podatku hoces traziti formulu:\n");
	printf("Za pretragu po imenu vozaca izaberi 1\n");
	printf("Za pretragu po prezimenu vozaca izaberi 2\n");
	printf("Za pretragu po broju bolida izaberi 3\n");
	printf("Za pretragu po ostvarenom vremenu izaberi 4\n");
	printf("Unesi svoju opciju:\n");
	scanf("%d", &opcija);
	getchar();
	
	switch (opcija) {
	case 1: {
		printf("Unesi ime vozaca za pretragu: ");
		scanf("%50[^\n]", trazeno_ime);
		getchar();
		printf("\n");

		for (i = 0; i < n; i++) {
			if (strcmp(formule[i].ime, trazeno_ime) == 0) {
				printf("Pronadena formula:\n");
				printf("Ime: %s\n", formule[i].ime);
				printf("Prezime: %s\n", formule[i].prezime);
				printf("Broj bolida: %d\n", formule[i].bolid_broj);
				printf("Vrijeme: %02d:%02d:%02d\n", formule[i].vrijeme.min, formule[i].vrijeme.sec, formule[i].vrijeme.stot);
				printf("--------------------\n");
			}
		}
		break;
	}
	case 2: {
		printf("Unesi prezime vozaca za pretragu: ");
		scanf("%50[^\n]", trazeno_prezime);
		getchar();
		printf("\n");

		for (i = 0; i < n; i++) {
			if (strcmp(formule[i].prezime, trazeno_prezime) == 0) {
				printf("Pronadena formula:\n");
				printf("Ime: %s\n", formule[i].ime);
				printf("Prezime: %s\n", formule[i].prezime);
				printf("Broj bolida: %d\n", formule[i].bolid_broj);
				printf("Vrijeme: %02d:%02d:%02d\n", formule[i].vrijeme.min, formule[i].vrijeme.sec, formule[i].vrijeme.stot);
				printf("--------------------\n");
			}
		}
		break;

	}
	case 3: {
		printf("Unesi broj bolida za pretragu: ");
		scanf("%d", &trazeni_broj_bolida);
		getchar();
		printf("\n");

		for (i = 0; i < n; i++) {
			if (formule[i].bolid_broj == trazeni_broj_bolida){
				printf("Pronadena formula:\n");
				printf("Ime: %s\n", formule[i].ime);
				printf("Prezime: %s\n", formule[i].prezime);
				printf("Broj bolida: %d\n", formule[i].bolid_broj);
				printf("Vrijeme: %02d:%02d:%02d\n", formule[i].vrijeme.min, formule[i].vrijeme.sec, formule[i].vrijeme.stot);
				printf("--------------------\n");
	
			}
		}
		break;

	}
	case 4: {
		printf("Unesite vrijeme za pretragu (minute, sekunde, i stotinke):\n");
		printf("Minute: ");
		scanf("%d", &trazena_min);
		getchar();
		printf("Sekunde: ");
		scanf("%d", &trazena_sec);
		getchar();
		printf("Stotinke: ");
		scanf("%d", &trazena_stot);
		getchar();
		printf("\n");

		for (i = 0; i < n; i++) {
			if (formule[i].vrijeme.min == trazena_min && formule[i].vrijeme.sec == trazena_sec && formule[i].vrijeme.stot == trazena_stot) {
				printf("Pronadena formula:\n");
				printf("Ime: %s\n", formule[i].ime);
				printf("Prezime: %s\n", formule[i].prezime);
				printf("Broj bolida: %d\n", formule[i].bolid_broj);
				printf("Vrijeme: %02d:%02d:%02d\n", formule[i].vrijeme.min, formule[i].vrijeme.sec, formule[i].vrijeme.stot);
				printf("--------------------\n");
				
			}
		}
		break;
	}
	default:
		printf("Nepoznata opcija!\n");
	}

}

FORMULA* sloboda(FORMULA* F) {
	free(F);
	return NULL;
}
