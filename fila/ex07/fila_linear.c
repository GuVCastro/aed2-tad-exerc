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

void enqueue(Fila *f, Aviao dados)
{
	if (((f->ultimo + 1) % MAX) == f->primeiro)
		printf("AEROPORTO LOTADO\n");
	else {
		f->dados[f->ultimo] = dados;
		f->ultimo = (f->ultimo + 1) % MAX;
		f->tam++;
	}
}

Aviao dequeue(Fila *f)
{
	Aviao resp;

	if (f->primeiro == f->ultimo) {
		printf("AEROPORTO VAZIO\n");
	}
	else {
		resp = f->dados[f->primeiro];
		f->primeiro = (f->primeiro + 1) % MAX;
		f->tam--;
	}

	return resp;
}

void printFila(Fila *f)
{
	int i = f->primeiro;

	printf("****** Fila Aeroporto ******\n");
	while (i != f->ultimo) {
		printAviao(f->dados[i]);
		i = (i + 1) % MAX;
	}

	printf("Avioes na fila: %d\n", f->tam);
}

void mostrarPrimeiro(Fila *f)
{
	printf("****** Primeiro da fila ******\n");
	printAviao(f->dados[f->primeiro]);

	printf("Avioes na fila: %d\n", f->tam);
}

void priorityEnqueue(Fila *f, Aviao dados)
{
	int i = f->primeiro, j;
	Aviao tmp1, tmp2;

	if (((f->ultimo + 1) % MAX) == f->primeiro)
		printf("AEROPORTO LOTADO\n");
	else {
		while (i != f->ultimo) {
			if (f->dados[i].envergadura <= dados.envergadura)
				break;
			
			i = (i + 1) % MAX;
		}
	
		tmp2 = f->dados[i];
		for (j = i; j != (f->ultimo + 1) % MAX; j = (j + 1) % MAX) {
			tmp1 = f->dados[j];
			f->dados[j] = tmp2;
			tmp2 = tmp1;	
		}

		f->dados[i] = dados;
		f->ultimo = (f->ultimo + 1) % MAX;
		f->tam++;
	}
}
