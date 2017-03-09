#pragma once
#include"graph.h"
#include<stdlib.h>

typedef struct Cell {
	struct Vertor {
		int x;
		int y;
	}key;
	int value;
}Cell;
typedef struct Array {
	Cell* first;
	int size;
}Array;



void quicksort(Array* tab, int lo, int hi);
Array* setByGraph(Graph graph);
void displayArray(Array tab);