#pragma once
#define MAX 10
void transformerFichier(char *srcFic, char *destFic);
void obtenirIndex(char *srcFic, char *destFic);
void accesDirect(char *nomIndex, char *nomUnFic, int ordre);

typedef struct Line Line;
struct Line
{
	int id;
	int pos;
};
typedef struct Index Index;
struct Index
{
	Line tab[MAX];
	int nb;
};
