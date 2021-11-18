#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista_dupla.h"

void newCelula(Celula *c, Dados d)
{
	c->dado = d;
	c->anterior = NULL;
	c->prox = c->anterior;
}

void newLista(Lista *l)
{
	Celula *tmp = malloc(sizeof(Celula));
	tmp->anterior = NULL;
	tmp->prox = NULL;

	l->primeiro = l->ultimo = tmp;
	l->tam = 0;
}

void insereInicio(Lista *l, Dados d)
{
	Celula *tmp = malloc(sizeof(Celula));
	newCelula(tmp, d);
	
	tmp->anterior = l->primeiro;	
	tmp->prox = l->primeiro->prox;
	l->primeiro->prox = tmp;

	if (l->primeiro == l->ultimo)
		l->ultimo = tmp;
	else 
		tmp->prox->anterior = tmp;
	
	tmp = NULL;

	l->tam++;
}

void insereFim(Lista *l, Dados d)
{
	Celula *tmp = malloc(sizeof(Celula));
	newCelula(tmp, d);

	l->ultimo->prox = tmp;
	l->ultimo->prox->anterior = l->ultimo;
	l->ultimo = l->ultimo->prox;

	l->tam++;
}

void inserePosicao(Lista *l, Dados d, int pos)
{
	int tam = tamanhoLista(l);

	if (pos < 0 || pos > tam) {
		printf("POSICAO INVALIDA\n");
	}
	else if (pos == 0)
		insereInicio(l, d);
	else if (pos == tam)
		insereFim(l, d);
	else {
		Celula *i = l->primeiro->prox;
		for (int j = 0; j < pos; j++, i = i->prox);
		
		Celula *tmp = malloc(sizeof(Celula));
		newCelula(tmp, d);

		tmp->anterior = i;
		tmp->prox = i->prox;
		tmp->anterior->anterior = tmp->prox->anterior = tmp;
		tmp = i = NULL;
		
		l->tam++;
	}
}

Dados removeInicio(Lista *l)
{
	Dados res = {-1, '\0'};
	Celula *tmp = l->primeiro->prox;

	if (l->primeiro == l->ultimo) {
		printf("FILA VAZIA\n");
		return res;
	}
	else { 
		res = tmp->dado;
		if (l->tam > 1) {
			l->primeiro->prox = tmp->prox;
			tmp->prox->anterior = l->primeiro;
		}
		else 
			newLista(l);

		tmp = NULL;
		l->tam--;

		return res;
	}
}

Dados removeFim(Lista *l)
{
	Dados res = {-1, '\0'};

	if (l->primeiro == l->ultimo) {
		printf("FILA VAZIA\n");
		return res;
	}
	else { 
		res = l->ultimo->dado;
		l->ultimo = l->ultimo->anterior;
		l->ultimo->prox = NULL;
		l->tam--;

		return res;
	}
}

Dados removePosicao(Lista *l, int pos)
{
	int tam = tamanhoLista(l);
	system("clear");

	if (pos < 0 || pos > tam) {
		printf("POSICAO INVALIDA\n");
	}
	else if (pos == 0)
		removeInicio(l);
	else if (pos == tam - 1)
		removeFim(l);
	else {
		Dados res = {0, '\0'}; 
		Celula *i = l->primeiro->prox;
		for (int j = 0; j < pos; j++, i = i->prox);
		
		res = i->dado;
		i->prox->anterior = i->anterior;
		i->anterior->prox = i->prox;
		i = NULL;
		l->tam--;

		return res;
	}
}

void printLista(Lista *l)
{
	Celula *tmp;

	tmp = l->primeiro->prox;
	while(tmp != NULL) {
		printDados(tmp->dado);
		tmp = tmp->prox;
	}
}

int tamanhoLista(Lista *l)
{
	printf("Tamanho da lista: %d\n", l->tam);
	return l->tam;
}

Dados pesquisarElemento(Lista *l, int numElemento)
{
	Celula *tmp = l->primeiro->prox;
	Dados res = {0, '\0'};

	while (tmp != NULL) {
		if (tmp->dado.numero == numElemento) {
			printDados(tmp->dado);
			return res;
		}
		tmp = tmp->prox;
	}

	return res;
}

