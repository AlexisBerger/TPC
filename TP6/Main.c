#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<ctype.h>

#include"file.h"

int menu(void);

int main(void) {
	FileAttente file;
	initFile(&file);
	char* buffer = malloc(17 * sizeof(char));
	do {
		switch (menu())
		{
		case 1:
			arriveePatient(&file, saisiePatient());
			break;
		case 2:
			departPatient(&file);
			break;
		case 3:
			printf("Saisir numero secu :\n> ");
			fgets(buffer, 17, stdin);

			buffer[strlen(buffer) - 1] = '\0';

			abandonPatient(&file, buffer);
			break;
		case 4:
			afficherFile(&file);
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
	do {
		printf("1- Arrivee Patient\n");
		printf("2- Depart Patient\n");
		printf("3- Abandon Patient\n");
		printf("4- Afficher File d'attente\n");
		printf("0- Quitter\n");
		printf("Tapez votre choix :\n> ");
		fgets(buffer, 10, stdin);

		buffer[strlen(buffer) - 1] = '\0';

		choix = strtol(buffer, &end, 10);
	} while (buffer == end);
	return choix;
}