#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<Windows.h>

int elimineDoublon(int tab[], int taille);
void afficheTab(int tab[], int taille);
void main() {

//	int tab[100] = { 1,2,2,3,5,8,9,9,10,14,14,14,15,16,16 };
//	int taille = 15, tailleFin = 15;
	
//	int tab2[100] = { 1,2,2,3,5,8,9,9,10,14,14,14,15,16,16 };
//	int taille2 = 15, tailleFin2 = 15;
#define MAX_END 10000//000
	int MAX = 10;
	int *tabl;
	int *tabl2;
	LARGE_INTEGER start, end, freq;
	LARGE_INTEGER start2, end2;
	QueryPerformanceFrequency(&freq);


	FILE* fichier = NULL;

	fichier = fopen("stat.csv", "w");
	fclose(fichier);

	do {

		tabl = malloc(MAX * sizeof(int));
		tabl2 = malloc(MAX * sizeof(int));

		for (int i = 0; i < MAX; i++)
		{
			tabl[i] = rand() % 99999;
		}
		memcpy(tabl2, tabl, MAX * sizeof(int));

	
	
		QueryPerformanceCounter(&start);
		delDoubloun(tabl, MAX);
		QueryPerformanceCounter(&end);
	

		//afficheTab(tabl, );
	//	printf("tick : %lld time : %lld\n", (end.QuadPart - start.QuadPart), (end.QuadPart - start.QuadPart)/freq.QuadPart);

	
		QueryPerformanceCounter(&start2);
		elimineDoublon(tabl2, MAX);
		QueryPerformanceCounter(&end2);

		//afficheTab(tabl2, 10);
	//	printf("time : %lld\n", (end.QuadPart - start.QuadPart));


		fichier = fopen("stat.csv", "a+");
		fprintf(fichier, "%d;%lld;%lld;%lld;%lld\n", MAX, (end.QuadPart - start.QuadPart), (end.QuadPart - start.QuadPart) / freq.QuadPart, (end2.QuadPart - start2.QuadPart), (end2.QuadPart - start2.QuadPart) / freq.QuadPart);
		fclose(fichier);

		free(tabl);
		free(tabl2);
		MAX = MAX * 2;
	} while (MAX<MAX_END);

	system("pause");
}

int delDoubloun(int tab[], int taille) {
	int tailleFin = taille;
	for (int i = 1, j = 1; i < taille; i++)
	{
		if (tab[i] == tab[i - j]) {
			tailleFin--;
			j++;
		}
		else if (j>1) {
			tab[i - j + 1] = tab[i];
		}
	}
	return tailleFin;
}

int elimineDoublon(int tab[], int taille) {
	int elimine = 0;
	for (int i = 0; i<taille - elimine; i++) {
		if (i>0 && tab[i - 1] == tab[i]) {
			elimine++;
			i--;
			for (int j = i; j<taille - elimine; j++) {
				tab[j] = tab[j + 1];
			}
		}
	}
	return elimine;
}

void afficheTab(int tab[], int taille) {
	for (int i = 0; i < taille; i++)
	{
		printf("%d\n", tab[i]);
	}
}