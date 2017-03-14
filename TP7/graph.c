#include<stdio.h>
#include<stdlib.h>

#include "graph.h"

#ifndef _CC
#define _CC
int _cc = 0;
#endif // !1

void initNode(Node* node) {
	node->array = NULL;
	node->next = NULL;
	node->value = 0;
	node->component = _cc;
}
void initLink(Link* link) {
	link->next = NULL;
	link->node = 0;
	link->value = 0;
}


Node* createNode(int value) {
	Node* node = malloc(sizeof(Node));
	initNode(node);
	node->value = value;
	_cc++;
	return node;
}
Link* createLink(int node, int value) {
	Link* link = malloc(sizeof(Link));
	initLink(link);
	link->node = node;
	link->value = value;
	return link;
}
void addNode(Graph* graph, Node *node) {
	if (isExist(*graph, node->value)) return;
	Node* i = NULL;
	for (i = *graph; i != NULL && i->next != NULL; i = i->next);
	if(i != NULL) i->next = node;
	else *graph = node;
}
void addLink(Graph* graph, Link *link, int node) {
	Node* i = NULL;
	for (i = *graph; i != NULL && i->value != node; i = i->next);
	if (i != NULL) {
		Link* j = NULL;
		Link* k = i->array;
		for (j = i->array;j != NULL;j = j->next) { 
			k = j;
		}
		if (k != NULL) k->next = link;
		else i->array = link;
	}
}
void delLink(Graph* graph, int node, int node2) {

}

void delNode(Graph* graph, int node) {
	void* tmp = NULL;
	Node* n = *graph;
	int resetN = 0;
	for (Node *k = *graph; k != NULL; k = (resetN == 1?*graph:k->next)) {
		resetN = 0;
		tmp = NULL;
		if (k->value != node) {
			Link* i = k->array;
			int reset = 0;
			for (Link* j = k->array;
					j != NULL;
					j = (j == NULL ?
						NULL : 
						(reset == 1?k->array:j->next))) {
				reset = 0;
				if (j->node == node) {
					if (i == j) {
						tmp = j;
						k->array = j->next;
						j = k->array;
						reset = 1;
						free(tmp);
						
					}
					else {
						tmp = j;
						i->next = j->next;
						j = i;
						free(tmp);
					}
				}
				i = j;
			}
		}
		else
		{
			for (Link* j = k->array;j != NULL;tmp = j, j = j->next, free(tmp));
			if (k == *graph) {
				*graph = k->next;
				
				free(k);
				k = *graph;
				resetN = 1;
			}
			else {
				n->next = k->next;
				free(k);
				k = n;
			}
		}
		n = k;
	}
}
int lengthGraph(Graph graph) {
	int j = 0;
	for (Graph i = graph; i != NULL; i = i->next)
	{
		j++;
	}
	return j;
}

int linkCount(Graph graph) {
	int k = 0;
	for (Graph i = graph; i != NULL; i = i->next) {
		if (i->array != NULL) {
			for (Link* j = i->array; j != NULL; j = j->next) {
				k++;
			}
		}	
	}
	return k;
}

void displayGraph(Graph graph) {
	if (graph == NULL)return;
	printf("Nombre de node  : %d\n", lengthGraph(graph));
	printf("Node  : ");
	for (Graph i = graph; i != NULL; i = i->next) {
		printf("%d ", i->value);
	}
	printf("\nLiens:\n");
	for (Graph i = graph; i != NULL; i = i->next) {
		if (i->array != NULL) {
			
			for (Link* j = i->array; j != NULL; j = j->next) {
				printf("%d -> ", i->value);
				printf("%d ", j->node);
				printf(" : %d\n", j->value);
			}
		}
	}
}



int* getListNode(Graph graph, int size) {
	int* tab = malloc(sizeof(int)*size);
	Node* ptr = graph;
	for (int i = 0; i < size; i++)
	{
		tab[i] = ptr->value;
		ptr = ptr->next;
	}
	return tab;
}




void readGraph(Graph* graph) {
	FILE* file;
	int nbNode = 0;
	if (!(file = fopen("graph.dat", "r"))) {
		file = fopen("graph.dat", "a+");
	}
	else {
		file = fopen("graph.dat", "r");
	}
	
	fread(&nbNode, sizeof(int), 1, file);


	for (int i = 0; i < nbNode; i++)
	{
		int value;
		int nbLink = 0;
		
		fread(&value, sizeof(int), 1, file);
		addNode(graph, createNode(value));
		
		fread(&nbLink, sizeof(int), 1, file);
		if (nbLink) {
			for (int i = 0; i < nbLink; i++)
			{
				int lvalue;
				int lnode;
				fread(&lnode, sizeof(int), 1, file);
				fread(&lvalue, sizeof(int), 1, file);
				addLink(graph, createLink(lnode, lvalue),value);
				
			}
		}
	}

	fclose(file);
}

void writeGraph(Graph* graph) {
	FILE* file;
	file = fopen("graph.dat", "w");
	int size = lengthGraph(*graph);
	fwrite(&size, sizeof(int), 1, file);
	
	for (Graph i = *graph; i != NULL; i = i->next) {
		fwrite(&i->value, sizeof(int), 1, file);
		int nbLink = 0;
		if (i->array != NULL) {
			
			for (Link* j = i->array; j != NULL; j = j->next) nbLink++;
			fwrite(&nbLink, sizeof(int), 1, file);

			for (Link* j = i->array; j != NULL; j = j->next) {
				fwrite(&j->node, sizeof(int), 1, file);
				fwrite(&j->value, sizeof(int), 1, file);
			}
		}
		else {
			
			fwrite(&nbLink, sizeof(int), 1, file);
		}
	}
	
	fclose(file);
}

int isExist(Graph graph, int value) {
	for (Graph i = graph; i != NULL; i = i->next) {
		if (i->value == value) {
			return 1;
		}
	
	}
	return 0;

}