#include <stdio.h>
#include "pessoa.h"

#define MAX 15 

typedef struct Fila{
	Pessoa dados[MAX + 1];
	int primeiro;
	int ultimo;
	int tam;
} Fila;

void newFila(Fila *f);

int enqueue(Fila *f, Pessoa p);

Pessoa dequeue(Fila *f);

void printFila(Fila *f);

int priorityEnqueue(Fila *f, Pessoa p);

void clonarFila(Fila *f, Fila *f1);

void concatenarFilas(Fila *f1, Fila *f2, Fila *f);

void inverterFila(Fila *f);

void ordenarFila(Fila *f);

