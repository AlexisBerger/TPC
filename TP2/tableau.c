#include<stdlib.h>
#include<stdio.h>
#include"tableau.h"

void dispayTab(Tableau tab) {
	printf("tableau [ ");
	for (int i = 0; i < tab.taille; i++)
	{
		printf("%d ", tab.tab[i]);
	}
	printf("]\n\n");
}

void addEnd(Tableau* tab, int nombre) {
	tab->tab[tab->taille] = nombre;
	tab->taille++;
}

void addIn(Tableau* tab, int nombre, int pos) {
	for (int i = tab->taille; i > pos; i--)
	{
		tab->tab[i] = tab->tab[i - 1];
	}
	tab->tab[pos] = nombre;
	tab->taille++;
}

void addFirst(Tableau* tab, int nombre) {
	addIn(tab, nombre, 0);
}


void addInOrder(Tableau* tab, int nombre) {
	int i = 0;
	if (tab->taille == 0) {
		addEnd(tab, nombre);
	}
	else {
		for (i = 0; i < tab->taille; i++)
		{
			if (tab->tab[i] >= nombre) {
				addIn(tab, nombre, i);
				break;
			}
			else if (i >= tab->taille - 1) {
				addEnd(tab, nombre);
				break;
			}
		}
	}
}

int* concatTab(int* tab1, size_t taille1, int* tab2, size_t taille2) {
	int* result = malloc((taille1+taille2)*sizeof(int));
	size_t i;
	for (i = 0; i < taille1; i++)
	{
		result[i] = tab1[i];
	}
	for (size_t j = 0; j < taille2; j++, i++)
	{
		result[i] = tab2[j];
	}
	return result;
}