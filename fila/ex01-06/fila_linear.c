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

int enqueue(Fila *f, Pessoa p)
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

Pessoa dequeue(Fila *f)
{
	Pessoa resp = {'\0', -1};

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

	while (i != f->ultimo) {
		printPessoa(f->dados[i]);
		i = (i + 1) % MAX;
	}
	printf("\n");
}

int priorityEnqueue(Fila *f, Pessoa p)
{
	int i = f->primeiro, j;
	Pessoa tmp1, tmp2;

	if (((f->ultimo + 1) % MAX) == f->primeiro) {
		printf("FILA CHEIA\n");
		return -1;
	}
	
	if (p.idade < 65) {
		enqueue(f, p);
		return 0;
	}

	while (i != f->ultimo) {
		if (f->dados[i].idade <= p.idade)
			break;
		
		i = (i + 1) % MAX;
	}

	tmp2 = f->dados[i];
	for (j = i; j != (f->ultimo + 1) % MAX; j = (j + 1) % MAX) {
		tmp1 = f->dados[j];
		f->dados[j] = tmp2;
		tmp2 = tmp1;	
	}

	f->dados[i] = p;
	f->ultimo = (f->ultimo + 1) % MAX;
	f->tam++;
	
	return 0;
}

void clonarFila(Fila *f, Fila *f1)
{
	int i = f->primeiro, j = 0;
	
	while (i != f->ultimo) {
		f1->dados[j] = f->dados[i];
		i = (i + 1) % MAX;
		j++;
	}

	f1->tam = f->tam;
	f1->primeiro = 0;
	f1->ultimo = f1->tam;
}

void concatenarFilas(Fila *f1, Fila *f2, Fila *f)
{
	int i = f2->primeiro, j = 0, flagEncheu = 0;
	Pessoa *v = malloc(f2->tam*sizeof(Pessoa));

	clonarFila(f1, f);

	while (i != f2->ultimo) {
		v[j] = f2->dados[i];
		i = (i + 1) % MAX;
		j++;
	}

	for(i = 0; i < f2->tam; i++) {
		flagEncheu = enqueue(f, v[i]);

		if (flagEncheu == -1)
			break;
	}

	free(v);
}

void inverterFila(Fila *f)
{
	int i = f->primeiro, j = f->tam-1, fSize = f->tam;
	Pessoa *v = malloc(f->tam*sizeof(Pessoa));

	while(i != f->ultimo) {
		v[j] = f->dados[i];
		i = (i + 1) % MAX;
		j--;
	}

	newFila(f);

	for(i = 0; i < fSize; i++)
		enqueue(f, v[i]);

	free(v);
}

void ordenarFila(Fila *f)
{
	int i = f->primeiro, j = 0, fSize = f->tam;
	Pessoa *v = malloc(f->tam*sizeof(Pessoa));
	Pessoa tmp;

	while (i != f->ultimo) {
		v[j] = f->dados[i];
		i = (i + 1) % MAX;
		j++;
	}

    for (i = fSize-1; i > 0; i--) 
		for (j = 0; j < i; j++) 
			if (strcmp(v[j].nome, v[j + 1].nome) > 0) {
				tmp = v[j];
				v[j] = v[j + 1];
				v[j + 1] = tmp;
			}
	
	newFila(f);
	for (i = 0; i < fSize; i++)
		enqueue(f, v[i]);
}


