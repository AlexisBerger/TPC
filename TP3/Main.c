#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<ctype.h>

#include"polynome.h"

int menu(void);

int main(void) {
	
	int tab[100] = { 0 };
	char* buffer = malloc(10 * sizeof(char));
	char* end;
	int x = 0;

	do
	{
		switch (menu())
		{
		case 1:
			saisiePoly(tab);
			break;
		case 2:
			
			printf("Saisir x = :\n> ");
			fgets(buffer, 10, stdin);

			buffer[strlen(buffer) - 1] = '\0';
			x = strtol(buffer, &end, 10);
			if (end != buffer)
				printf("valeur pour x = %d : %d\n", x, evalPoly(tab, x));
			else
				printf("Saisir un nombre\n");
			break;
		case 3:
			derivePoly(tab);
			break;
		case 4:
			affichePoly(tab);
			break;
		case 0:
			return 0;
		default:
			printf("Saisir un nombre entre 0 et 4\n");
			break;
		}
	} while (1);
	system("pause");
	return 0;
}

int menu(void) {
	char* buffer = malloc(10 * sizeof(char));
	char* end;
	int choix = 0;
	do{
		printf("1- Saisie Polynome\n");
		printf("2- Evaluer le polynome\n");
		printf("3- Deriver le polynome\n");
		printf("4- Afficher le polynome\n");
		printf("0- Quitter\n");
		printf("Tapez votre choix :\n> ");
		fgets(buffer, 10, stdin);

		buffer[strlen(buffer) - 1] = '\0';

		choix = strtol(buffer, &end, 10);
	} while (buffer == end);
	return choix;
}