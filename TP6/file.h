#pragma once

typedef struct Patient
{
	char nom[50];
	char prenom[50];
	int age;
	char nbSec[16];
}Patient;
typedef struct Node {
	Patient* patient;
	struct Node* next;
}Node;
typedef struct FileAttente {
	int nb;
	Node* premier;
	Node* dernier;
}FileAttente;



int fileVide(FileAttente file);

void initFile(FileAttente *file);

Patient *saisiePatient();
void arriveePatient(FileAttente *file, Patient *patient);
void departPatient(FileAttente *file);
void copiePatient(Patient *dest, Patient *source);
int estPresent(FileAttente *file, char *numSec);
void abandonPatient(FileAttente *file, char *numSec);
void afficherFile(FileAttente *file);
void afficherPatient(Patient);

void enregistreFileAttente(FileAttente file, char *nomFic);
void lireFileAttente(FileAttente file, char *nomFic);
