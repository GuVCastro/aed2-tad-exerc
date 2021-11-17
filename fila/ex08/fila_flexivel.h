#include <stdio.h>
#include "processo.h"

typedef struct Celula{
	Processo dado;
	struct Celula *prox;
}Celula;

typedef struct Fila{
	Celula *inicio;
	Celula *fim;
	int tam;
}Fila;

void newFila(Fila *f);

int enqueue(Fila *f, Processo p);

Processo dequeue(Fila *f);

void printFila(Fila *f);

