#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<ctype.h>

#include"file.h"


int fileVide(FileAttente file) {
	return file.premier == NULL || file.dernier == NULL || file.nb == 0;
}

void initFile(FileAttente *file) {
	file->premier = NULL;
	file->dernier = NULL;
	file->nb = 0;
}

Patient *saisiePatient() {
	Patient *patient = malloc(sizeof(Patient));
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

	return patient;
}
Node* newNode(Patient* patient) {
	Node* new = malloc(sizeof(Node));
	new->next = NULL;
	new->patient = patient;
	return new;
}
void arriveePatient(FileAttente *file, Patient *patient) {
	Node* node = newNode(patient);
	
	file->nb = file->nb + 1;
	if (!fileVide(*file)) {
		file->dernier->next = node;
	}
	else {
		file->premier = node;
	}
	file->dernier = node;
}
void departPatient(FileAttente *file) {
	if (!fileVide(*file)) {
		void* tmp = NULL;
		file->nb = file->nb - 1;
		afficherPatient(*(file->premier->patient));
		free(file->premier->patient);
		tmp = file->premier;
		file->premier = file->premier->next;
		free(tmp);
	}
}
void copiePatient(Patient *dest, Patient *source) {
	dest->age = source->age;
	strcpy(dest->nom, source->nom);
	strcpy(dest->prenom, source->prenom);
	strcpy(dest->nbSec, source->nbSec);
}
int estPresent(FileAttente *file, char *numSec) {
	for (Node* i = file->premier; i != NULL; i = i->next)
	{
		if (strcmp(i->patient->nbSec, numSec) == 0) return 1;
	}
	return 0;
}
void abandonPatient(FileAttente *file, char *numSec) {
	if (!fileVide(*file)) {
		if (strcmp(&(file->premier->patient->nbSec), numSec) == 0) {
			void* tmp = file->premier->next;
			if (file->dernier == file->premier) file->dernier = NULL;
			free(file->premier->patient);
			free(file->premier);
			file->premier = tmp;
		}
		else if (file->premier->next != NULL)
		{
			Node* i = NULL;
			for (i = file->premier; i->next != NULL && strcmp(&(i->next->patient->nbSec), numSec) != 0; i = i->next);
			if (i->next == file->dernier) file->dernier = i;
			Node* tmp = i->next;
			i->next = i->next->next;
			free(tmp->patient);
			free(tmp);
		}
	}
	
}
void afficherFile(FileAttente *file) {
	for (Node* i = file->premier; i != NULL; i = i->next) {
		afficherPatient(*(i->patient));
	}
}
void afficherPatient(Patient p) {
	printf("%s\t%s\t%d ans\t%s\n", p.nom, p.prenom, p.age, p.nbSec);
}

void enregistreFileAttente(FileAttente file, char *nomFic) {

}
void lireFileAttente(FileAttente file, char *nomFic) {

}
