#include"matrice.h"

void displayMatrice(Graph graph) {
	if (graph == NULL) return;
	int size = lengthGraph(graph);
	if (size == 0) return;
	printf("M^ : \n");
	
	printMatrix(mchapeau(graph), size);

	Graph* opti = kruskal(graph);
	displayGraph(*opti);

	Graph* dj = dijkstra(graph, 1);
	//displayGraph(*dj);
}

int** getAdjacence(Graph graph) {
	int size = lengthGraph(graph);

	int ** m1 = createMatrix(size);
	initM1(graph, m1, size);
	//printf("M1 :\n");
	//printMatrix(m1, size);
	return m1;

}

int** createMatrix(int size) {
	int ** m = malloc(sizeof(int*)*size);
	for (int i = 0; i < size; i++)
	{
		m[i] = calloc(sizeof(int*), size);
	}
	return m;
}

void initM0(int** m, int size) {
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			m[i][j] = i == j ? 1 : 0;
		}
	}
}

void initM1(Graph graph, int** m, int size) {
	int* listNode = getListNode(graph, size);

	for (Graph i = graph; i != NULL; i = i->next) {
		int k;
		for (k = 0; k < size && i->value != listNode[k]; k++);
		if (i->array != NULL) {
			for (Link* j = i->array; j != NULL; j = j->next) {
				int l;
				for (l = 0; l < size && j->node != listNode[l]; l++);
				m[k][l] = 1;
				m[l][k] = 1;
			}
		}
	}
}

void printMatrix(int** m, int size) {
	if (m != NULL) {
		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < size; j++)
			{
				printf("%d ", m[i][j]);
			}
			printf("\n");

		}
		printf("\n");
	}
}



int** addition(int** m, int** m2, int size) {
	int** res = createMatrix(size);
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			res[i][j] = m[i][j] + m2[i][j];
		}

	}
	return res;
}

int** produit(int** m, int** m2, int size) {
	int** res = createMatrix(size);
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			int somme = 0;
			for (int k = 0; k < size; k++)
			{
				somme += m[i][k] * m2[k][j];
			}
			res[i][j] = somme;
		}

	}
	return res;
}

int** produitBool(int** m, int** m2, int size) {
	int** res = createMatrix(size);
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			int somme = 0;
			for (int k = 0; k < size; k++)
			{
				somme |= m[i][k] && m2[k][j];
			}
			res[i][j] = somme;
		}

	}
	return res;
}
int** additionBool(int** m, int** m2, int size) {
	int** res = createMatrix(size);
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			res[i][j] = m[i][j] || m2[i][j];
		}

	}
	return res;
}

int isEqual(int** m, int** m2, int size) {

	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (m[i][j] != m2[i][j]) return 0;
		}

	}
	return 1;

}

int** mchapeau(Graph graph) {
	int size = lengthGraph(graph);

	int ** m0 = createMatrix(size);
	initM0(m0, size);
	//printf("M0 :\n");
	//printMatrix(m0, size);

	int** m1 = getAdjacence(graph);

	int** mchapeau = m0;

	int** j = m0;
	int** k = NULL;
	for (int** i = m1; !isEqual(i, j, size) && (k == NULL || !isEqual(i, k, size));i = produitBool(i, m1, size))
	{

		mchapeau = additionBool(i, mchapeau, size);
		k = j;
		j = i;

	}

	return mchapeau;

}

void freeMatrix(int** m, int size) {
	if (m == NULL) return;
	for (int i = 0; i < size; i++)
	{
		free(m[i]);
	}
	free(m);
}

Graph* kruskal(Graph graph) {
	Array* lien = setByGraph(graph);

	quicksort(lien, 0, lien->size - 1);
	displayArray(*lien);
	int size = lengthGraph(graph);


	Graph res = NULL;
	for (Graph i = graph; i != NULL; i = i->next) {
		addNode(&res, createNode(i->value));
	}

	for (int i = 0; i < lien->size; i++)
	{
		Graph j;
		for (j = res; (j != NULL) && (j->value != lien->first[i].key.x); j = j->next);
		Graph k;
		for (k = res; k != NULL && k->value != lien->first[i].key.y; k = k->next);
		if (j->component != k->component) {
			int comp = k->component;
			for (Graph l = res; l != NULL; l = l->next) {
				if (comp == l->component) {
					l->component = j->component;
				}
			}

			addLink(&res, createLink(k->value, lien->first[i].value), j->value);
		}
	}

	return &res;
}

void adjacente(Graph graph, int** m, int size) {
	int* listNode = getListNode(graph, size);

	for (Graph i = graph; i != NULL; i = i->next) {
		int k;
		for (k = 0; k < size && i->value != listNode[k]; k++);
		if (i->array != NULL) {
			for (Link* j = i->array; j != NULL; j = j->next) {
				int l;
				for (l = 0; l < size && j->node != listNode[l]; l++);
				m[k][l] = j->value;
				m[l][k] = j->value;
			}
		}
	}
}

Graph dijkstra(Graph graph, int start) {
	Graph res = NULL;
	Array tab;

	if (graph == NULL) return;

	int size = lengthGraph(graph);
	if (size == 0) return;
	Cell* chemin = malloc(size*sizeof(Cell));

	chemin[0].key.x = start;
	chemin[0].key.y = 0;
	chemin[0].value = 0;
	int ** m = createMatrix(size);
	adjacente(graph, m, size);

	//printMatrix(m, size);

	int* listNode = getListNode(graph, size);

	int posStart;
	for (posStart = 0; posStart < size && start != listNode[posStart]; posStart++);

	tab.first = malloc(sizeof(Cell)*(size - 1));
	tab.size = size - 1;

	int j = 0;
	for (Graph i = graph; (i != NULL); i = i->next) {
		if (i->value != start) {
			tab.first[j].key.x = i->value;
			int l;
			for (l = 0; l < size && i->value != listNode[l]; l++);
			if (m[posStart][l] > 0) {
				tab.first[j].value = m[posStart][l];
				tab.first[j].key.y = start;
			}
			else {
				tab.first[j].value = -1;
			}
			j++;
		}

	}
	int sizeD = size - 1;
	int i = 1;
	Cell* ntab;
	Cell* tmp = tab.first;
	while (sizeD > 0)
	{
		
		ntab = malloc(sizeof(Cell)*(sizeD - 1));
		int min = -1;
		for (int k = 0; k < sizeD;k++)
		{	//select min
			
			//printf("%d < %d\n", tmp[k].value, min);

			if (min == -1 || tmp[k].value < min) {	//maj s
				chemin[i].key.x = tmp[k].key.x;
				chemin[i].key.y = 0;
				chemin[i].value = tmp[k].value;
				min = tmp[k].value;
			}
		}

		int l;
		for (l = 0; l < size && chemin[i].key.x != listNode[l]; l++);

		int k2 = 0;
		for (int k = 0; k < sizeD;k++)
		{	//maj sbar
			if (tmp[k].key.x != chemin[i].key.x) {
				int o;
				for (o = 0; o < size && ntab[k].key.x != listNode[o]; o++);
				ntab[k2].key.x = tmp[k].key.x;
				ntab[k2].key.y = tmp[k].key.y;
				ntab[k2].value = tmp[k].value;

				k2++;
			}
		}
		sizeD--;


		for (int k = 0; k < sizeD; k++)
		{
			int o;
			for (o = 0; o < size && ntab[k].key.x != listNode[o]; o++);
			if (m[l][o] > 0 && ntab[k].value > chemin[i].value + m[l][o]) {
				ntab[k].value = chemin[i].value + m[l][o];
				ntab[k].key.y = chemin[i].key.y;
			}

			
		}
		i++;
		tmp = ntab;
		
	}
	printf("\n");
	Array soluce;
	soluce.first = chemin;
	soluce.size = size;
	displayArray(soluce);
	return res;
}
