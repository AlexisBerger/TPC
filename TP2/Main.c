#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<ctype.h>

#include"tableau.h"



int main(void) {
	
	
	Tableau tab;
	int* tabconc;
	char* buffer = malloc(10 * sizeof(char));
	tab.taille = 0;
	char* end;
	int tab1[] = {0,1,5,7,8,6};
	int tab2[] = { 6,7,5,7,4,10,16,15 };



	tabconc = concatTab(tab1, 6, tab2, 8);
	printf("tableau concat [ ");
	for (size_t i = 0; i < 6 + 8; i++)
	{
		printf("%d ", tabconc[i]);
	}
	printf("]\n\n");

	do {
		//addEnd(&tab, atoi(buffer));
		//addFirst(&tab, atoi(buffer));
		int nombre = 0;
		do
		{
			printf("Saisir un nombre :\n> ");
			fgets(buffer, 10, stdin);
		
			buffer[strlen(buffer) - 1] = '\0';
			
			//nombre = atoi(buffer);
			nombre = strtol(buffer, &end, 10);
		} while (buffer == end);

		addInOrder(&tab, nombre);
		
		
		dispayTab(tab);

	} while (tab.taille < MAX);



	system("pause");
	return 0;
}

