#include"quickSort.h"


void swap(Array* tab, int i, int j);
int partition(Array* tab, int lo, int hi);

void swap(Array* tab, int i, int j) {
	Cell temp = tab->first[i];
	tab->first[i] = tab->first[j];
	tab->first[j] = temp;
}

int partition(Array* tab, int lo, int hi) {
	swap(tab, lo + (rand() % (hi - lo + 1)), hi);
	int i = lo - 1;
	for (int j = lo; j <= hi; j++)
	{
		if (tab->first[j].value <= tab->first[hi].value) {
			swap(tab, ++i, j);
		}
	}
	return i;
}

void quicksort(Array* tab, int lo, int hi) {
	int p = 0;
	if (lo < hi)
	{
		p = partition(tab, lo, hi);
		quicksort(tab, lo, p - 1);
		quicksort(tab, p + 1, hi);
	}
}

Array* setByGraph(Graph graph) {
	int size = linkCount(graph);
	Array* tab = malloc(sizeof(Array));
	tab->size = size;
	tab->first = malloc(size*sizeof(Cell));
	int k = 0;
	for (Graph i = graph; i != NULL; i = i->next) {
		if (i->array != NULL) {
			for (Link* j = i->array; j != NULL; j = j->next) {
				tab->first[k].key.x = i->value;
				tab->first[k].key.y = j->node;
				tab->first[k].value = j->value;

				k++;
			}
		}
	}
	return tab;
}

void displayArray(Array tab){
	for (int i = 0; i < tab.size; i++)
	{
		printf("%d -> ", tab.first[i].key.x);
		printf("%d ", tab.first[i].key.y);
		printf(" : %d\n", tab.first[i].value);
	}
}

