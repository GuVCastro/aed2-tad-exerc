#include <stdbool.h>
#include <stdio.h>

#define MAX 70

typedef struct Celula{
	char dado;
	struct Celula *prox;
} Celula;

typedef struct Pilha{
	Celula *topo;
	int n;
} Pilha;

void newPilha(Pilha *p);

bool push(Pilha *p, char d);

char pop(Pilha *p);

void printPilha(Pilha *p);

bool isPilhaVazia(Pilha *p);
