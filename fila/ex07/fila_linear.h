#include <stdio.h>
#include "aviao.h"

#define MAX 5

typedef struct Fila{
	Aviao dados[MAX + 1];
	int primeiro;
	int ultimo;
	int tam;
} Fila;

void newFila(Fila *f);

void enqueue(Fila *f, Aviao dado);

Aviao dequeue(Fila *f);

void printFila(Fila *f);

void mostrarPrimeiro(Fila *f);

void priorityEnqueue(Fila *f, Aviao dado);
