#include<stdlib.h>
#include<stdio.h>
#include<math.h>

void saisiePoly(int poly[]) {
	char* buffer = malloc(10 * sizeof(char));
	char* end;
	char* buffer2 = malloc(10 * sizeof(char));
	char* end2;
	int coef = 0;
	int expo = 0;
	int taille = 0;

	do {
		do {
			printf("Saisir le coefficient :\n> ");
			fgets(buffer, 10, stdin);

			buffer[strlen(buffer) - 1] = '\0';

			//nombre = atoi(buffer);
			coef = strtol(buffer, &end, 10);
		} while (buffer == end);
		do {
			printf("Saisir l'exposant :\n> ");
			fgets(buffer2, 10, stdin);

			buffer[strlen(buffer) - 1] = '\0';

			//nombre = atoi(buffer);
			expo = strtol(buffer2, &end2, 10);
		} while (buffer2 == end2);
		
		poly[taille] = coef;
		poly[taille + 1] = expo;
		taille += 2;
		
	} while (coef != 0 || expo != 0);
	
}


void affichePoly(int poly[]) {
	int coef = 0;
	int expo = 0;
	int i = 0;
	do
	{
		coef = poly[i];
		expo = poly[i + 1];
		if (coef != 0) {
			if (coef > 0 && i !=0) {
				printf("+%d", coef);
			}
			else if (coef < 0 || (coef > 0 && i == 0)) {
				printf("%d", coef);
			}
			if (expo != 0){
				if (expo == 1) {
					printf("x");
				}
				else {
					printf("x^%d", expo);
				}
			}
		}
		i += 2;
	} while (coef != 0 || expo != 0);
	printf("\n");
}

int evalPoly(int poly[], int x) {
	int result = 0;
	int coef = 0;
	int expo = 0;
	int i = 0;
	do
	{
		coef = poly[i];
		expo = poly[i + 1];
		result += coef*pow(x,expo);
		i += 2;
	} while (coef != 0 || expo != 0);
	return result;
}


void derivePoly(int poly[]) {

	int coef = 0;
	int expo = 0;
	int i = 0;
	do
	{
		
		coef = poly[i];
		expo = poly[i + 1];
		if (coef != 0 || expo != 0) {
			poly[i] = coef*expo;
			poly[i + 1] = expo - 1;
		}
		else {
			poly[i] = 0;
			poly[i + 1] = 0;
		}
		i += 2;
	} while (coef != 0 || expo != 0);
}

