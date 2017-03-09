#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<ctype.h>

#include"fichier.h"


int main(void) {
	char src[] = "Prix_Nobel.txt";
	char dst[] = "Un_Prix_Nobel.txt";
	char index[] = "Index.dat";
	transformerFichier(src, dst);
	obtenirIndex(src, index);
	accesDirect(index, dst, 3);
	accesDirect(index, dst, 2);
	accesDirect(index, dst, 1);
	accesDirect(index, dst, 0);
	system("pause");
	return 0;
}

