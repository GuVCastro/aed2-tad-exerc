#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista_flexivel.h"

void newCelula(Celula *c, Pessoa p)
{
	c->dado = p;
	c->prox = NULL;
}

void newLista(Lista *l)
{
	Celula *tmp = malloc(sizeof(Celula));
	tmp->prox = NULL;

	l->primeiro = l->ultimo = tmp;
	l->tam = 0;
}

void inserir(Lista *l, Pessoa p)
{
	Celula *tmp = malloc(sizeof(Celula));
	newCelula(tmp, p);

	l->ultimo->prox = tmp;
	l->ultimo = tmp;

	tmp = NULL;
	l->tam++;
}

Pessoa remover(Lista *l, int codigo)
{
	Celula *tmp = l->primeiro->prox;
	Pessoa res = {0, '\0', 0};
	int flagEncontrou = 0, pos = 0;

	while(tmp != NULL) {
		if (tmp->dado.codigo == codigo) {
			flagEncontrou = 1;
			break;
		}
		pos++;
		tmp = tmp->prox;
	}

	if (flagEncontrou == 0)
		printf("NOME NAO ENCONTRADO\n");
	else {
		Celula *i = l->primeiro->prox;
		for (int j = 0; j < pos - 1; j++, i = i->prox);
		
		res = i->prox->dado;
		i->prox = i->prox->prox;	
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
		printPessoa(tmp->dado);
		tmp = tmp->prox;
	}
	printf("\n");
}

void clonarLista(Lista *l, Lista *l1)
{
	Celula *tmp = l->primeiro->prox;

	newLista(l1);

	while(tmp != NULL) {
		inserir(l1, tmp->dado);
		tmp = tmp->prox;
	}
}

void concatenarListas(Lista *l1, Lista *l2, Lista *l)
{

	Celula *tmp = l2->primeiro->prox;

	clonarLista(l1, l);

	while(tmp != NULL) {
		inserir(l, tmp->dado);
		tmp = tmp->prox;
	}
}

void inserirOrdenado(Lista *l, Pessoa p)
{
	int flagInseriu = 0;
	Celula *tmp = malloc(sizeof(Celula));
	newCelula(tmp, p);
	Celula *tmp2 = l->primeiro->prox;
	Celula *tmp3 = l->primeiro;

	while (tmp2 != NULL) {
		if (strcmp(tmp2->dado.nome, tmp->dado.nome) > 0) {
			tmp3->prox = tmp;
			tmp->prox = tmp2;
			l->tam++;
			flagInseriu = 1;
			break;
		}
		tmp2 = tmp2->prox;
		tmp3 = tmp3->prox;
	}

	if (flagInseriu == 0)
		inserir(l, tmp->dado);

	tmp = NULL;
}

Pessoa verificaMaior(Lista *l)
{
	Celula *tmp = l->primeiro->prox;
	Pessoa maior = l->primeiro->prox->dado;

	while(tmp != NULL) {
		if (tmp->dado.idade > maior.idade)
			maior = tmp->dado;
		tmp = tmp->prox;
	}
	return maior;
}

int pesquisar(Lista *l, char *nome)
{
	Celula *tmp = l->primeiro->prox;

	while(tmp != NULL) {
		if (strcmp(tmp->dado.nome, nome) == 0)
			return tmp->dado.codigo;
		tmp = tmp->prox;
	}
	return -1;
}

void ordenarCrescente(Lista *l)
{
	int i = 0, j, lSize = l->tam;
	Pessoa *v = malloc(l->tam*sizeof(Pessoa)), tmp2;
	Celula *tmp = l->primeiro->prox;
	
	while (tmp != NULL) {
		v[i] = tmp->dado;
		i++;
		tmp = tmp->prox;
	}

	for (i = lSize-1; i > 0; i--) 
		for (j = 0; j < i; j++) 
			if (strcmp(v[j].nome, v[j + 1].nome) > 0) {
				tmp2 = v[j];
				v[j] = v[j + 1];
				v[j + 1] = tmp2;
			}

	newLista(l);
	for (i = 0; i < lSize; i++)
		inserir(l, v[i]);

	free(v);
}

void ordenarDecrescente(Lista *l)
{
	int i = 0, j, lSize = l->tam;
	Pessoa *v = malloc(l->tam*sizeof(Pessoa)), tmp2;
	Celula *tmp = l->primeiro->prox;
	
	while (tmp != NULL) {
		v[i] = tmp->dado;
		i++;
		tmp = tmp->prox;
	}

	for (i = lSize-1; i > 0; i--) 
		for (j = 0; j < i; j++) 
			if (strcmp(v[j].nome, v[j + 1].nome) < 0) {
				tmp2 = v[j];
				v[j] = v[j + 1];
				v[j + 1] = tmp2;
			}

	newLista(l);
	for (i = 0; i < lSize; i++)
		inserir(l, v[i]);

	free(v);
}
