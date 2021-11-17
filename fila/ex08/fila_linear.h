#include <stdio.h>
#include "processo.h"

#define MAX 7 

typedef struct Fila{
	Processo dados[MAX + 1];
	int primeiro;
	int ultimo;
	int tam;
} Fila;

void newFila(Fila *f);

int enqueue(Fila *f, Processo p);

Processo dequeue(Fila *f);

void printFila(Fila *f);

