#pragma once

typedef struct Link {
	int node;
	int value;
	struct Link* next;
}Link;
typedef struct Node {
	int value;
	int component;
	struct Node* next;
	Link* array;
}Node;
typedef Node* Graph;





void initNode(Node* node);
void initLink(Link* link);

void delNode(Graph* graph, int node);
void addLink(Graph* graph, Link *link, int node);
void addNode(Graph* graph, Node *node);
Link* createLink(int node, int value);
Node* createNode(int value);
void displayGraph(Graph graph);

int linkCount(Graph graph);
int lengthGraph(Graph graph);

int* getListNode(Graph graph, int size);

void readGraph(Graph* graph);
void writeGraph(Graph* graph);
int isExist(Graph graph, int value);

