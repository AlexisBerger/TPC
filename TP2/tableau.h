#pragma once
#define MAX 10
typedef struct Tableau Tableau;
struct Tableau
{
	int taille;
	int tab[MAX];

};

void dispayTab(Tableau);
void addEnd(Tableau* tab, int nombre);
void addFirst(Tableau* tab, int nombre);
void addInOrder(Tableau* tab, int nombre);
int* concatTab(int* tab1, size_t taille1, int* tab2, size_t taille2);