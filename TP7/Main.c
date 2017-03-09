#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "graph.h"
#include "matrice.h"


int main() {
	/* test +&* matrix
	int** m = createMatrix(3);
	int** m2 = createMatrix(3);
	m[0][0] = 1;m[0][1] = 2;m[0][2] = 3;
	m[1][0] = 3;m[1][1] = 2;m[1][2] = 1;
	m[2][0] = 2;m[2][1] = 1;m[2][2] = 3;

	m2[0][0] = 2;m2[0][1] = 2;m2[0][2] = 2;
	m2[1][0] = 2;m2[1][1] = 1;m2[1][2] = 3;
	m2[2][0] = 3;m2[2][1] = 2;m2[2][2] = 2;

	printMatrix(m,3);
	printMatrix(m2, 3);
	int** res = addition(m, m2, 3);
	printMatrix(res, 3);
	int** res2 = multiplication(m, m2, 3);
	printMatrix(res2, 3);
	*/
	Graph graph = NULL;

	readGraph(&graph);

	char* end;
	char* buffer = malloc(17 * sizeof(char));
	int newValueN = 0;
	int newNode = 0, newValueL = 0;
	int nodeA = 0;
	int nodeD = 0;

	do {
		switch (menu())
		{
		case 1:
			do
			{
				printf("Saisir la valeur du noeud :\n> ");
				fgets(buffer, 10, stdin);

				buffer[strlen(buffer) - 1] = '\0';

				newValueN = strtol(buffer, &end, 10);
			} while (buffer == end);

			addNode(&graph, createNode(newValueN));
			break;
		case 2:
			do
			{
				printf("Saisir l'id du noeud :\n> ");
				fgets(buffer, 10, stdin);

				buffer[strlen(buffer) - 1] = '\0';

				nodeA = strtol(buffer, &end, 10);
			} while (buffer == end);
			do
			{
				printf("Saisir l'id du noeud destinataire :\n> ");
				fgets(buffer, 10, stdin);

				buffer[strlen(buffer) - 1] = '\0';

				newNode = strtol(buffer, &end, 10);
			} while (buffer == end);
			do
			{
				printf("Saisir la valeur du lien :\n> ");
				fgets(buffer, 10, stdin);

				buffer[strlen(buffer) - 1] = '\0';

				newValueL = strtol(buffer, &end, 10);
			} while (buffer == end);

			addLink(&graph, createLink(newNode, newValueL), nodeA);
			break;
		case 3:
			do
			{
				printf("Saisir l'id du noeud :\n> ");
				fgets(buffer, 10, stdin);

				buffer[strlen(buffer) - 1] = '\0';

				nodeD = strtol(buffer, &end, 10);
			} while (buffer == end);
			delNode(&graph, nodeD);
			break;
		case 4:
			displayGraph(graph);
			displayMatrice(graph);

			break;
		case 5:
			writeGraph(&graph);
			break;
		case 0:
			return 0;
		default:
			printf("Saisir un nombre entre 0 et 4\n");
			break;
		}
	} while (1);

	system("pause");
	return 0;
}

int menu(void);

int menu(void) {
	char* buffer = malloc(10 * sizeof(char));
	char* end;
	int choix = 0;
	do {
		printf("1- Nouveau Noeud\n");
		printf("2- Nouveau Lien\n");
		printf("3- Supprimer Noeud\n");
		printf("4- Afficher Graph\n");
		printf("5- Sauver Graph\n");

		printf("0- Quitter\n");
		printf("Tapez votre choix :\n> ");
		fgets(buffer, 10, stdin);

		buffer[strlen(buffer) - 1] = '\0';

		choix = strtol(buffer, &end, 10);
	} while (buffer == end);
	return choix;
}
