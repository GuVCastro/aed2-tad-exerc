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

int enqueue(Fila *f, Processo p)
{
	Celula *tmp = malloc(sizeof(Celula));
	tmp->prox = NULL;
	tmp->dado = p;

	f->fim->prox = tmp;
	f->fim = tmp;
	f->tam++;
	
	return 0;
}

Processo dequeue(Fila *f)
{
	if(f->tam == 0){
		printf("FILA VAZIA\n");
		Processo p = {-1, '\0'};
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

	printf("Processos:\n");
	while(tmp != NULL){
		printProcesso(tmp->dado);
		tmp = tmp->prox;
	}
	printf("\n");
}

