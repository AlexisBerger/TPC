#pragma once

#include<stdio.h>
#include<stdlib.h>

#include "quickSort.h"
#include "graph.h"


int** getAdjacence(Graph graph);
int** createMatrix(int size);
void initM0(int** m, int size);
void initM1(Graph graph, int** m, int size);

void printMatrix(int** m, int size);

int** produit(int** m, int** m2, int size);
int** addition(int** m, int** m2, int size);

int** produitBool(int** m, int** m2, int size);
int** additionBool(int** m, int** m2, int size);

int** mchapeau(Graph graph);
int isEqual(int** m, int** m2, int size);
void freeMatrix(int** m, int size);

Graph* kruskal(Graph graph);

Graph dijkstra(Graph graph)