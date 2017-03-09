#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<ctype.h>

#include"fichier.h"

void transformerFichier(char *srcFic, char *destFic) {
	FILE* file = fopen(srcFic, "r");
	FILE* fileOut = fopen(destFic, "w");
	char* buffer = malloc(100*sizeof(char));
	char* text = malloc(100 * sizeof(char));
	if (file == NULL) perror("Error opening file");
	else {
		fgets(buffer, 255, file);
		while (strcmp(buffer, text) != 0 && strlen(buffer) > 1)
		{

			buffer[strlen(buffer) - 1] = '\0';
			printf("%s\n", buffer);
			fputs(buffer, fileOut);
			strcpy(text, buffer);
			fgets(buffer, 255, file);
		}
					
	}
	fclose(file);
	fclose(fileOut);
}

void obtenirIndex(char *srcFic, char *destFic) {
	FILE* file = fopen(srcFic, "r");
	FILE* fileOut = fopen(destFic, "w");

	char* buffer = malloc(100 * sizeof(char));
	char* text = malloc(100 * sizeof(char));

	int current = 0;
	Index *index = malloc(sizeof(Index));
	Line line;
	index->nb = 0;

	if (file == NULL) perror("Error opening file");
	else {
		fgets(buffer, 255, file);
		while (strcmp(buffer, text) != 0 && strlen(buffer) > 1)
		{
			
			line.id = index->nb;
			line.pos = current;

			index->tab[index->nb] = line;

			printf("%d\t%d\n", line.id, line.pos);

			index->nb = index->nb + 1;
			current = current + (strlen(buffer) - 1);

			strcpy(text, buffer);
			fgets(buffer, 255, file);
		}
		fwrite(index, sizeof(Index), 1, fileOut);
	}
	fclose(file);
	fclose(fileOut);
}

void accesDirect(char *nomIndex, char *nomUnFic, int ordre) {
	FILE* file = fopen(nomUnFic, "r");
	FILE* fileIndex = fopen(nomIndex, "r");
	Index* index = malloc(sizeof(Index));
	char* result = malloc(sizeof(char) * 255);
	fread(index, sizeof(Index), 1, fileIndex);

	if (index->nb > ordre && ordre >= 0) {
		fseek(file, index->tab[ordre].pos, SEEK_SET);
		if (ordre + 1 < index->nb) {
			fgets(result, index->tab[ordre + 1].pos - index->tab[ordre].pos + 1, file);
		}
		else {
			fgets(result, 255, file);
		}
		printf("%s\n", result);
	}
	fclose(file);
	fclose(fileIndex);
}