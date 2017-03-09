#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<ctype.h>

#include"liste.h"

FileAttente file;

int fileVide(FileAttente file) {
	return file.premier == file.dernier;
}
int filePleine(FileAttente file) {
	return (file.premier == (file.dernier - 1) && file.premier > file.dernier) || (file.dernier == &file.tab[MAX - 1] && file.premier == &file.tab[0]);
}
void initFile() {
	file.dernier = &file.tab[0];
	file.premier = &file.tab[0];
}
void saisiePatient(Patient* patient) {
	char* buffer = malloc(50 * sizeof(char));
	char* buffer2 = malloc(50 * sizeof(char));
	int age = 0;
	char* buffer3 = malloc(17 * sizeof(char));
	char* buffer4 = malloc(17 * sizeof(char));
	char* end;

	printf("Saisir nom :\n> ");
	fgets(buffer, 50, stdin);
	buffer[strlen(buffer) - 1] = '\0';
	strcpy(&(patient->nom), buffer);

	printf("Saisir prenom :\n> ");
	fgets(buffer2, 50, stdin);
	buffer2[strlen(buffer2) - 1] = '\0';
	strcpy(&(patient->prenom), buffer2);

	do
	{
		printf("Saisir age :\n> ");
		fgets(buffer3, 15, stdin);
		buffer[strlen(buffer3) - 1] = '\0';
		age = strtol(buffer3, &end, 10);
	} while (buffer3 == end);
	patient->age = age;

	printf("Saisir numero secu :\n> ");
	fgets(buffer4, 17, stdin);
	buffer4[strlen(buffer4) - 1] = '\0';
	strcpy(&(patient->nbSec), buffer4);

}
void arriveePatient(Patient* patient) {

	if (!filePleine(file)) {
		*(file.dernier) = *patient;
		if (file.dernier != &file.tab[MAX - 1]) {
			file.dernier += 1;
		}
		else
		{
			file.dernier = &file.tab[0];
		}

	}

}
void departPatient() {
	if (!fileVide(file)) {
		printf("%s\n", (*file.premier).nom);
		if ((file.premier != &file.tab[MAX - 1])) {
			file.premier += 1;
		}
		else
		{
			if (!filePleine(file))
			{
				file.premier = &file.tab[0];
			}
			
		}
	}
}
void copiePatient(Patient *dest, Patient *source) {
	dest->age = source->age;
	strcpy(dest->nom, source->nom);
	strcpy(dest->prenom, source->prenom);
	strcpy(dest->nbSec, source->nbSec);
}

int estPresent(char *numSec) {
	Patient* pointer = file.premier;
	int i = 0;
	while (pointer != file.dernier)
	{
		if (strcmp(pointer->nbSec, numSec) == 0) {
			return i;
		}
		if (pointer == &file.tab[MAX - 1]) {
			pointer = &file.tab[0];
		}
		else {
			pointer += 1;
		}
		i++;
	}
	return -1;
}
void abandonPatient(char *numSec) {
	Patient* pointer = file.premier;
	int decal = 0;
	while (pointer != file.dernier)
	{
		if (decal) {
			if (pointer == &file.tab[0]) {
				file.tab[MAX - 1] = file.tab[0];
			}
			else {
				*(pointer - 1) = *pointer;
			}
		}
		if (strcmp(pointer->nbSec, numSec) == 0) {
			decal = 1;
		}

		if (pointer == &file.tab[MAX - 1]) {
			pointer = &file.tab[0];
			if (pointer == file.dernier && decal) {
				file.dernier = &file.tab[MAX - 1];
			}
		}
		else {
			pointer += 1;
			if (pointer == file.dernier && decal) {
				file.dernier -= 1;
				break;
			}
		}
	}
}
void afficherPatient(Patient p) {
	printf("%s\t%s\t%d ans\t%s\n", p.nom, p.prenom, p.age, p.nbSec);
}
void afficherFile() {
	if (!fileVide(file))
	{
		int i = 0;
		Patient* pointer = file.premier;
		while (pointer != file.dernier)
		{
			i++;
			printf("%d- ", i);
			afficherPatient(*pointer);
			if (pointer == &file.tab[MAX - 1]) {
				pointer = &file.tab[0];
			}
			else {
				pointer += 1;
			}
		}
	}
	else
	{
		printf("File vide\n");
	}
	printf("\n");
}
