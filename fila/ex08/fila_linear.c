#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "fila_linear.h"

void newFila(Fila *f)
{
	f->primeiro = 0;
	f->ultimo = 0;
	f->tam = 0;
}

int enqueue(Fila *f, Processo p)
{
	if (((f->ultimo + 1) % MAX) == f->primeiro) {
		printf("FILA CHEIA\n");
		return -1;
	}
	
	f->dados[f->ultimo] = p;
	f->ultimo = (f->ultimo + 1) % MAX;
	f->tam++;
	return 0;
}

Processo dequeue(Fila *f)
{
	Processo resp = {-1, '\0'};

	if (f->primeiro == f->ultimo) {
		printf("FILA VAZIA\n");
		return resp;
	}

	resp = f->dados[f->primeiro];
	f->primeiro = (f->primeiro + 1) % MAX;
	f->tam--;

	return resp;
}

void printFila(Fila *f)
{
	int i = f->primeiro;

	printf("Processos:\n");
	while (i != f->ultimo) {
		printProcesso(f->dados[i]);
		i = (i + 1) % MAX;
	}
	printf("\n");
}

