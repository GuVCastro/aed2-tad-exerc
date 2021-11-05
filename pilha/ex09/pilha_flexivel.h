#include <stdbool.h>
#include <stdio.h>
#include "carro.h"

#define MAX 5

typedef struct Celula{
	Carro dado;
	struct Celula *prox;
} Celula;

typedef struct Pilha{
	Celula *topo;
	int n;
} Pilha;

void newPilha(Pilha *p);

void push(Pilha *p, Carro c);

Carro pop(Pilha *p);

void printPilha(Pilha *p);

bool isPilhaVazia(Pilha *p);
