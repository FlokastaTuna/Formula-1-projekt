#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "header.h"

int main(void) {
	int n;
	FORMULA *F;
	printf("Za koliko bolida zelite unositi podatke? ");
	scanf("%d", &n);
	getchar();
	zapisivanjeFormule("formula.bin", n);
	F = citajFormule("formula.bin", n);
	//ovdje dodajem funkciju po kojoj pretrazujem datoteku
	F = sloboda(F);
	return 0;
}



