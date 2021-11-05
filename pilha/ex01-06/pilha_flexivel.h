#include <stdbool.h>
#include <stdio.h>
#include "dados.h"

#define MAX 5

typedef struct Celula{
	Dados dado;
	struct Celula *prox;
} Celula;

typedef struct Pilha{
	Celula *topo;
	int n;
} Pilha;

void newPilha(Pilha *p);

void push(Pilha *p, Dados d);

Dados pop(Pilha *p);

void printPilha(Pilha *p);

bool isPilhaVazia(Pilha *p);
