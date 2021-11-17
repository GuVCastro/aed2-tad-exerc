#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "fila_flexivel.h"

void newFila(Fila *f)
{
	Celula *tmp = malloc(sizeof(Celula));
	tmp->prox = NULL;

	f->inicio = f->fim = tmp;
	f->tam = 0;
}

int enqueue(Fila *f, Pessoa p)
{
	Celula *tmp = malloc(sizeof(Celula));
	tmp->prox = NULL;
	tmp->dado = p;

	f->fim->prox = tmp;
	f->fim = tmp;
	f->tam++;
	
	return 0;
}

Pessoa dequeue(Fila *f)
{
	if(f->tam == 0){
		printf("FILA VAZIA\n");
		Pessoa p = {-1, '\0'};
		return p;
	}
	
	Celula *tmp = f->inicio;
	f->inicio = f->inicio->prox;
	free(tmp);
	f->tam--;
	return f->inicio->dado;
}

void printFila(Fila *f)
{
	Celula *tmp = f->inicio->prox;

	while(tmp != NULL){
		printPessoa(tmp->dado);
		tmp = tmp->prox;
	}
	printf("\n");
}

int priorityEnqueue(Fila *f, Pessoa p)
{
	Celula *tmpDado = malloc(sizeof(Celula));
	Celula *tmpPosicaoAnterior = f->inicio;
	Celula *tmp = f->inicio->prox;

	if (p.idade < 65) {
		enqueue(f, p);
		return 0;
	}

	while (tmp != NULL) {
		if (tmp->dado.idade <= p.idade) 
			break;
		
		tmpPosicaoAnterior = tmpPosicaoAnterior->prox;
		tmp = tmp->prox;
	}
	
	tmpPosicaoAnterior->prox = tmpDado;
	tmpDado->dado = p;
	tmpDado->prox = tmp;
	
	f->tam++;	
	
	return 0;
}

void clonarFila(Fila *f, Fila *f1)
{
	Celula *tmp = f->inicio->prox;

	newFila(f1);

	while(tmp != NULL) {
		enqueue(f1, tmp->dado);
		tmp = tmp->prox;
	}
}

void concatenarFilas(Fila *f1, Fila *f2, Fila *f)
{
	Celula *tmp = f2->inicio->prox;
	
	clonarFila(f1, f);

	while(tmp != NULL) {
		enqueue(f, tmp->dado);
		tmp = tmp->prox;
	}
}

void inverterFila(Fila *f)
{
	int i = 0, fSize = f->tam;
	Pessoa *v = malloc(f->tam*sizeof(Pessoa));
	Celula *tmp = f->inicio->prox;

	while (tmp != NULL) {
		v[i] = tmp->dado;
		i++;
		tmp = tmp->prox;
	}

	newFila(f);

	for (i = fSize - 1; i >= 0; i--)
		enqueue(f, v[i]);

	free(v);
}

void ordenarFila(Fila *f)
{
	int i = 0, j, fSize = f->tam;
	Pessoa *v = malloc(f->tam*sizeof(Pessoa));
	Pessoa tmp2;
	Celula *tmp = f->inicio->prox;

	while (tmp != NULL) {
		v[i] = tmp->dado;
		i++;
		tmp = tmp->prox;
	}

    for (i = fSize-1; i > 0; i--) 
		for (j = 0; j < i; j++) 
			if (strcmp(v[j].nome, v[j + 1].nome) > 0) {
				tmp2 = v[j];
				v[j] = v[j + 1];
				v[j + 1] = tmp2;
			}

	newFila(f);
	for (i = 0; i < fSize; i++)
		enqueue(f, v[i]);

	free(v);
}

