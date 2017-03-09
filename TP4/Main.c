
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<ctype.h>

#include"liste.h"

int menu(void);

int main(void) {
	Patient* patient = NULL;
	initFile();
	char* buffer = malloc(17*sizeof(char));
	do {
		switch (menu())
		{
		case 1:
			patient = malloc(sizeof(Patient));
			saisiePatient(patient);
			arriveePatient(patient);
			break;
		case 2:
			departPatient();
			break;
		case 3:
			printf("Saisir numero secu :\n> ");
			fgets(buffer, 17, stdin);

			buffer[strlen(buffer) - 1] = '\0';

			abandonPatient(buffer);
			break;
		case 4:
			afficherFile();
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