#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista_encadeada.h"

void newCelula(Celula *c, Site s)
{
	c->dado = s;
	c->prox = NULL;
}

void newLista(Lista *l)
{
	Celula *tmp = malloc(sizeof(Celula));
	tmp->prox = NULL;

	l->primeiro = l->ultimo = tmp;
	l->tam = 0;
}

void inserir(Lista *l, Site s)
{
	Celula *tmp = malloc(sizeof(Celula));
	newCelula(tmp, s);

	tmp->prox = l->primeiro->prox;
	l->primeiro->prox = tmp;
	if (l->primeiro == l->ultimo)
		l->ultimo = tmp;

	tmp = NULL;
	l->tam++;
}

Site remover(Lista *l, char *nome)
{
	Celula *tmp = l->primeiro->prox;
	Site res = {0, '\0'};
	int flagEncontrou = 0, pos = 0;

	while(tmp != NULL) {
		if (strcmp(tmp->dado.nomes, nome) == 0) {
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

void mostrarNomes(Lista *l)
{
	Celula *tmp;

	tmp = l->primeiro->prox;
	while(tmp != NULL) {
		printNome(tmp->dado);
		tmp = tmp->prox;
	}
}

int pesquisar(Lista *l, char *nome)
{
	Celula *tmp = l->primeiro->prox;
	int pos = 1, flagEncontrou = 0;
	Site s;

	while(tmp != NULL) {
		if (strcmp(tmp->dado.nomes, nome) == 0) {
			flagEncontrou = 1;
			break;
		}
		pos++;
		tmp = tmp->prox;
	}

	if (flagEncontrou == 0) {
		printf("\nNOME NAO ENCONTRADO\n");
		return pos - 1;
	}
	else {
		s = remover(l, nome);
		printf("\n{ Nome: %s, Site: %s }\n", s.nomes, s.links);
		inserir(l, s);
		return pos;
	}
}

