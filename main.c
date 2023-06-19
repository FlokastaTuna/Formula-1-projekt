#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "header.h"

int main(void) {
	int n, a;
	FORMULA *F;
	printf("Za koliko bolida zelite unositi podatke? ");
	scanf("%d", &n);
	getchar();
	zapisivanjeFormule("formula.bin", n);
	F = citajFormule("formula.bin", n);
	printf("Zelis li pretraziti unesene bolide pomocu jednog od unesenog podatka? 1 za da, 2 za ne :");
	scanf("%d", &a);
	if (a == 1) {
		pretrazivanjeFormule(F,n);//ovdje dodajem funkciju po kojoj pretrazujem datoteku
	}
	else {
		printf("Tvoj izbor");
	}
	
	F = sloboda(F);
	return 0;
}



