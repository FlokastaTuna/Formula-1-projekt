#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "header.h"

//RADI
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
		temp[i] = unesiJednuFormulu(temp, i);
	}
	fwrite(temp, sizeof(FORMULA), n, pFile);
	fwrite(&n, sizeof(int), 1, pFile);
	fclose(pFile);
	free(temp);
}

//RADI
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

//RADI
void pretrazivanjeFormule(FORMULA* formule, int n) {
	int opcija;
	char trazeno_ime[50];
	char trazeno_prezime[50];
	int trazeni_broj_bolida;
	int trazena_sec, trazena_stot, trazena_min;
	int i;
	int pronaden = 0;
	FILE* pFile = fopen("formula.bin", "rb");
	if (pFile == NULL) {
		perror("Ne radi");
		exit(EXIT_FAILURE);
	}
	fread(formule, sizeof(FORMULA), n, pFile);
	fclose(pFile);
	printf("Odaberi po kojem podatku hocete traziti formulu:\n");
	printf("Za pretragu po imenu vozaca izaberite 1\n");
	printf("Za pretragu po prezimenu vozaca izaberite 2\n");
	printf("Za pretragu po broju bolida izaberite 3\n");
	printf("Za pretragu po ostvarenom vremenu izaberite 4\n");
	printf("Unesite svoju opciju:");
	scanf("%d", &opcija);
	getchar();

	switch (opcija) {
	case 1: {

		do {
			printf("Unesi ime vozaca za pretragu: ");
			scanf("%50[^\n]", trazeno_ime);
			getchar();
			printf("\n");
			pronaden = 0;

			for (i = 0; i < n; i++) {
				if (strcmp(formule[i].ime, trazeno_ime) == 0) {
					pronaden = 1;
					printf("Pronadena formula:\n");
					printf("Ime: %s\n", formule[i].ime);
					printf("Prezime: %s\n", formule[i].prezime);
					printf("Broj bolida: %d\n", formule[i].bolid_broj);
					printf("Vrijeme: %02d:%02d:%02d\n", formule[i].vrijeme.min, formule[i].vrijeme.sec, formule[i].vrijeme.stot);
					printf("--------------------\n");
				}
			}

			if (!pronaden) {
				printf("Nema formule sa unesenim imenom vozaca. Molimo unesite ponovno: \n");
			}
		} while (!pronaden);
		break;
	}
	case 2: {
		do {
			printf("Unesi prezime vozaca za pretragu: ");
			scanf("%50[^\n]", trazeno_prezime);
			getchar();
			printf("\n");
			for (i = 0; i < n; i++) {
				if (strcmp(formule[i].prezime, trazeno_prezime) == 0) {
					pronaden = 1;
					printf("Pronadena formula:\n");
					printf("Ime: %s\n", formule[i].ime);
					printf("Prezime: %s\n", formule[i].prezime);
					printf("Broj bolida: %d\n", formule[i].bolid_broj);
					printf("Vrijeme: %02d:%02d:%02d\n", formule[i].vrijeme.min, formule[i].vrijeme.sec, formule[i].vrijeme.stot);
					printf("--------------------\n");
				}
			}
			if (!pronaden) {
				printf("Nema formule sa unesenim prezimenom vozaca. Molim unesite ponovno: \n");
			}
		} while (!pronaden);
		break;
	}
	case 3: {
		do {
			printf("Unesi broj bolida za pretragu: ");
			scanf("%d", &trazeni_broj_bolida);
			getchar();
			printf("\n");

			for (i = 0; i < n; i++) {
				if (formule[i].bolid_broj == trazeni_broj_bolida) {
					pronaden = 1;
					printf("Pronadena formula:\n");
					printf("Ime: %s\n", formule[i].ime);
					printf("Prezime: %s\n", formule[i].prezime);
					printf("Broj bolida: %d\n", formule[i].bolid_broj);
					printf("Vrijeme: %02d:%02d:%02d\n", formule[i].vrijeme.min, formule[i].vrijeme.sec, formule[i].vrijeme.stot);
					printf("--------------------\n");

				}
			}
			if (!pronaden) {
				printf("Nema formule sa unesenim brojem bolida. Molim unesite ponovno: \n");
			}
		} while (!pronaden);
		break;
	}
	case 4: {
		do {
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
					pronaden = 1;
					printf("Pronadena formula:\n");
					printf("Ime: %s\n", formule[i].ime);
					printf("Prezime: %s\n", formule[i].prezime);
					printf("Broj bolida: %d\n", formule[i].bolid_broj);
					printf("Vrijeme: %02d:%02d:%02d\n", formule[i].vrijeme.min, formule[i].vrijeme.sec, formule[i].vrijeme.stot);
					printf("--------------------\n");

				}
			}
			if (!pronaden) {
				printf("Nema formule sa unesenim vremenom. Molim unesite ponovno: \n");
			}
		} while (!pronaden);

		break;
	}
	default:
		printf("Nepoznata opcija!\n");
	}

}

//RADI
void obrisiDatoteku(const char* file) {
	printf("Ako hocete izbrisati datoteku unesi \"da\", ako ne onda \"ne\"!\n ");
	char potvrda[3] = { '\0' };
	scanf("%2s", potvrda);
	if (!strcmp("da", potvrda)) {
		remove(file) == 0 ? printf("Uspjesno obrisana datoteka %s!\n",
			file) : printf("Neuspjesno brisanje datoteke %s!\n", file);
	}


}

//RADI
void preimenujDatoteku(const char* staroIme) {
	char novoIme[20] = { '\0' };
	printf("Unesi novo ime datoteke: ");
	getchar();
	scanf("%19[^\n]", novoIme);
	printf("Potvrdite promjenu imena datoteke sa \"da\" , ako zelite odustati unesite \"ne\"!\n");
	char potvrda[3] = { '\0' };
	scanf("%2s", potvrda);
	if (!strcmp("da", potvrda)) {
		rename(staroIme, novoIme) == 0 ?
			printf("Uspjesno promijenjeno ime datoteci!\n") :
			printf("Neuspjesno promijenjeno ime datoteci!\n");
	}
}

//RADI
void azuriranjeFormule(char* file, int n) {
	FILE* pFile = fopen("formula.bin", "r+b");
	if (pFile == NULL) {
		perror("Ne radi");
		exit(EXIT_FAILURE);
	}

	FORMULA novaFormula;
	FORMULA* formule = (FORMULA*)malloc(n * sizeof(FORMULA));
	if (formule == NULL) {
		fclose(pFile);
		perror("Ne radi");
		exit(EXIT_FAILURE);
	}

	fread(formule, sizeof(FORMULA), n, pFile);

	int bolidBroj;
	printf("Unesi broj bolida za azuriranje: ");
	scanf("%d", &bolidBroj);
	getchar();

	int i;
	int found = 0;
	for (i = 0; i < n; i++) {
		if (formule[i].bolid_broj == bolidBroj) {
			printf("Pronadena formula:\n");
			printf("Ime: %s\n", formule[i].ime);
			printf("Prezime: %s\n", formule[i].prezime);
			printf("Broj bolida: %d\n", formule[i].bolid_broj);
			printf("Vrijeme: %02d:%02d:%02d\n", formule[i].vrijeme.min, formule[i].vrijeme.sec, formule[i].vrijeme.stot);
			printf("--------------------\n");

			printf("Unesi nove podatke za azuriranje:\n");

			formule[i] = unesiJednuFormulu(formule, i);
			found = 1;
			break;
		}
	}

	if (found) {
		fseek(pFile, 0, SEEK_SET);
		fwrite(formule, sizeof(FORMULA), n, pFile);
		printf("Formula je azurirana.\n");
	}
	else {
		printf("Formula s brojem bolida %d nije pronadena.\n", bolidBroj);
	}

	fclose(pFile);
	free(formule);
}

//RADI
void kopirajDatoteku(char* pocetna, char* nova) {
	FILE* source = fopen(pocetna, "rb");
	if (source == NULL) {
		perror("Ne radi");
		exit(EXIT_FAILURE);
	}

	FILE* destination = fopen(nova, "wb");
	if (destination == NULL) {
		fclose(source);
		perror("Ne radi");
		exit(EXIT_FAILURE);
	}

	int bufferSize = 1024;
	char* buffer = (char*)malloc(bufferSize);
	if (buffer == NULL) {
		fclose(source);
		fclose(destination);
		perror("Ne radi");
		exit(EXIT_FAILURE);
	}

	size_t bytesRead;
	while ((bytesRead = fread(buffer, 1, bufferSize, source)) > 0) {
		fwrite(buffer, 1, bytesRead, destination);
	}
	printf("Uspjesno kopiranje datoteke, kopirana datoteka se zove nova_formula.bin \n");
	free(buffer);
	fclose(source);
	fclose(destination);


}

//RADI
FORMULA* obrisiFormulu(FORMULA* formula, int n, char* file) {
	int bolidToDelete;
	printf("Unesite broj bolida za brisanje: ");
	scanf("%d", &bolidToDelete);

	FILE* originalFile = fopen(file, "rb");
	if (originalFile == NULL) {
		printf("Greka prilikom otvaranja datoteke.\n");
		return formula;
	}

	FILE* tempFile = fopen("temp.bin", "wb");
	if (tempFile == NULL) {
		printf("Greka prilikom otvaranja privremene datoteke.\n");
		fclose(originalFile);
		return formula;
	}

	int formulasWritten = 0;
	for (int i = 0; i < n; i++) {
		if (formula[i].bolid_broj == bolidToDelete) {
			printf("Formula kojoj je bolid broj %d je obrisana.\n", formula[i].bolid_broj);
		}
		else {
			fwrite(&formula[i], sizeof(FORMULA), 1, tempFile);
			formulasWritten++;
		}
	}

	fclose(originalFile);
	fclose(tempFile);

	remove(file);
	rename("temp.bin", "formula.bin");

	FORMULA* updatedFormula = citajFormule(file, formulasWritten);
	return updatedFormula;
}

//RADI
void sortirajFormule(char* file) {
	FILE* dat = fopen(file, "rb");
	if (dat == NULL) {
		printf("Greska pri otvaranju datoteke.\n");
		return;
	}

	fseek(dat, 0, SEEK_END);
	long fileSize = ftell(dat);
	int numFormulas = fileSize / sizeof(FORMULA);

	FORMULA* formule = malloc(sizeof(FORMULA) * numFormulas);
	if (formule == NULL) {
		printf("Greska pri alociranju memorije.\n");
		fclose(dat);
		return;
	}

	rewind(dat);
	if (fread(formule, sizeof(FORMULA), numFormulas, dat) != numFormulas) {
		printf("Greska pri citanju formule iz datoteke.\n");
		fclose(dat);
		free(formule);
		return;
	}

	fclose(dat);

	for (int i = 0; i < numFormulas - 1; i++) {
		for (int j = 0; j < numFormulas - i - 1; j++) {
			if (formule[j].vrijeme.min > formule[j + 1].vrijeme.min ||
				(formule[j].vrijeme.min == formule[j + 1].vrijeme.min &&
					formule[j].vrijeme.sec > formule[j + 1].vrijeme.sec) ||
				(formule[j].vrijeme.min == formule[j + 1].vrijeme.min &&
					formule[j].vrijeme.sec == formule[j + 1].vrijeme.sec &&
					formule[j].vrijeme.stot > formule[j + 1].vrijeme.stot)) {
				FORMULA temp = formule[j];
				formule[j] = formule[j + 1];
				formule[j + 1] = temp;
			}
		}
	}

	printf("Formule sortirane po ostvarenom vremenu:\n");

	for (int i = 0; i < numFormulas; i++) {
		printf("Ime: %s\n", formule[i].ime);
		printf("Prezime: %s\n", formule[i].prezime);
		printf("Bolid broj: %d\n", formule[i].bolid_broj);
		printf("Vrijeme: %02d:%02d:%02d\n", formule[i].vrijeme.min, formule[i].vrijeme.sec, formule[i].vrijeme.stot);
		printf("--------------------\n");
	}

	free(formule);
}

//RADI
FORMULA* sloboda(FORMULA* F) {
	free(F);
	return NULL;
}

//RADI
int provjeriJednakostImena(FORMULA* temp, char* ime, int i) {
	for (int j = 0; j < i; j++) {
		if (strcmp(ime, temp[j].ime) == 0) {
			printf("Unos imena vec postoji. Unesi drugo ime.\n");
			i--;
			return 1;
		}
	}
	return 0;
}

//RADI
int provjeriJednakostPrezimena(FORMULA* temp, char* ime, int i) {
	for (int j = 0; j < i; j++) {
		if (strcmp(ime, temp[j].prezime) == 0) {
			printf("Unos prezimena vec postoji. Unesi drugo prezime.\n");
			i--;
			return 1;
		}
	}
	return 0;
}

//RADI
int provjeriJednakostBroja(FORMULA* temp, int bolid_broj, int i) {
	for (int j = 0; j < i; j++) {
		if (bolid_broj == temp[j].bolid_broj) {
			printf("Unos broja bolida vec postoji. Unesite drugi broj.\n");
			i--;
			return 1;
		}
		return 0;
	}
}

//RADI
FORMULA unesiJednuFormulu(FORMULA* temp, int i) {
	FORMULA novaFormula;
	do {
		printf("Unesi ime vozaca: ");
		scanf("%50[^\n]", novaFormula.ime);
		getchar();

	} while (provjeriJednakostImena(temp, novaFormula.ime, i));

	do {
		printf("Unesi prezime vozaca: ");
		scanf("%50[^\n]", novaFormula.prezime);
		getchar();

	} while (provjeriJednakostPrezimena(temp, novaFormula.prezime, i));

	do {
		printf("Unesi broj bolida: ");
		scanf("%d", &novaFormula.bolid_broj);
		getchar();

	} while (provjeriJednakostBroja(temp, novaFormula.bolid_broj, i));


	printf("Unesi vrijeme kruga:\n");
	do {
		printf("Prvo unesi minute: ");
		scanf("%d", &novaFormula.vrijeme.min);
		getchar();
		printf("Zatim sekunde: ");
		scanf("%d", &novaFormula.vrijeme.sec);
		getchar();
		printf("I na poslijetku, stotinke:");
		scanf("%d", &novaFormula.vrijeme.stot);
		getchar();
		if (novaFormula.vrijeme.min == 1 && novaFormula.vrijeme.sec < 60 && novaFormula.vrijeme.stot < 100) {
			break;
		}
		else {
			printf("Unos je netocan, zapamti, u formuli 1, krug staze ne traje duze ili ispod jedne minute! Takoder valjda znas koliko sekundi je jedna minuta i koliko je stotinki jedna sekunda.\n");
		}

	} while (1);
	printf("\n");
	printf("Dodani poadci o formulama su:\n");
	printf("Ime: %s\n", novaFormula.ime);
	printf("Prezime: %s\n", novaFormula.prezime);
	printf("Broj bolida: %d\n", novaFormula.bolid_broj);
	printf("Vrijeme: %d:%d:%d\n", novaFormula.vrijeme.min, novaFormula.vrijeme.sec, novaFormula.vrijeme.stot);
	printf("-------------------------\n");

	return novaFormula;
}


//RADI DONEKLE
void dodavanjeFormule(char* file) {
	int n, i;
	printf("Unesi broj novih formula: ");
	scanf("%d", &n);
	getchar();
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
	//printf("Broj novih elemenata: %d\n", last_element);
	//printf("Novi totalni broj elemenata: %d\n", last_element + n);
	fclose(pFile);

	FORMULA* trenutneFormule = (FORMULA*)calloc(n, sizeof(FORMULA));
	if (trenutneFormule == NULL) {
		perror("Ne radi");
		exit(EXIT_FAILURE);
	}
	trenutneFormule = citajFormule(file, last_element);

	FORMULA* temp = (FORMULA*)calloc((last_element + n), sizeof(FORMULA));
	if (temp == NULL) {
		perror("Ne radi");
		exit(EXIT_FAILURE);
	}

	for (i = 0; i < last_element; i++) {
		temp[i] = trenutneFormule[i];
	}

	//FILE* pFile = fopen(file, "ab");
	remove(file);
	pFile = fopen(file, "wb");
	if (pFile == NULL) {
		perror("Ne radi");
		exit(EXIT_FAILURE);
	}

	for (int i = last_element; i < last_element + n; i++) {
		temp[i] = unesiJednuFormulu(temp, i);
	}
	//for (int i = 0; i < last_element + n; i++) {
	//	printf("%s\n", temp[i].ime);
	//}

	int totalNum = last_element + n;
	fwrite(temp, sizeof(FORMULA), totalNum, pFile);
	fwrite(&totalNum, sizeof(int), 1, pFile);
	fclose(pFile);
	free(temp);
	free(trenutneFormule);
}
