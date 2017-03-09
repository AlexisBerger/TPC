#pragma once
#define MAX 10



typedef struct Patient Patient;
struct Patient
{
	char nom[50];
	char prenom[50];
	int age;
	char nbSec[16];
};

typedef struct FileAttente FileAttente;
struct FileAttente {
	Patient tab[MAX];
	Patient* premier;
	Patient* dernier;
};


int fileVide(FileAttente file);
int filePleine(FileAttente file);
void initFile();

void saisiePatient(Patient* patient);
void arriveePatient(Patient *patient);
void departPatient();
void copiePatient(Patient *dest, Patient *source);
int estPresent(char *numSec);
void abandonPatient(char *numSec);
void afficherFile();
void afficherPatient(Patient);