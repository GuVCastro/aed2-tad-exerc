#include <stdio.h>
#include <string.h>
#include "lista_linear.h"

void newLista(Lista *l)
{
	l->n = 0;
}

void inserir(Lista *l, Pessoa p)
{
	if (l->n >= MAX)
		printf("LISTA CHEIA\n");
	else {
		l->dado[l->n] = p;
		l->n++;
	}
}

Pessoa remover(Lista *l, int codigo)
{
	Pessoa res = {0, '\0', 0};
	int pos = -1;

	for (int i = 0; i < l->n; i++) {
		if (l->dado[i].codigo == codigo) {
			pos = i;
			break;
		}
	}

	if (pos == -1) {
		printf("\nNOME NAO ENCONTRADO\n\n");
		return res;
	}
	
	res = l->dado[pos];
	for (int i = pos; i < l->n; i++) 
		l->dado[i] = l->dado[i+1];
	l->n--;
}

void printLista(Lista *l)
{
	int i;

	for (i = 0; i < l->n; i++)
		printPessoa(l->dado[i]);
	printf("\n");
}

void clonarLista(Lista *l, Lista *l1)
{	
	int i;

	for (i = 0; i < l->n; i++)
		l1->dado[i] = l->dado[i];

	l1->n = l->n;
}

void concatenarListas(Lista *l1, Lista *l2, Lista *l)
{
	int i = 0;

	clonarLista(l1, l);

	for (i = 0; i < l2->n; i++) {
		inserir(l, l2->dado[i]);

		if (l->n == MAX) {
			printf("LISTA CHEIA\n");
			break;
		}
	}
}

void inserirOrdenado(Lista *l, Pessoa p)
{
	int i, j;
	Pessoa tmp1;

	for (i = 0; i < l->n; i++)
		if (strcmp(l->dado[i].nome, p.nome) > 0)
			break;

	for (j = l->n; j >= i; j--) {
		l->dado[j] = l->dado[j - 1];
	}

	l->dado[i] = p;
	l->n++;
}

Pessoa verificaMaior(Lista *l)
{
	Pessoa p = l->dado[0];
	int maiorIdade = l->dado[0].idade, i;

	for (i = 0; i < l->n; i++)
		if (l->dado[i].idade > maiorIdade) {
			maiorIdade = l->dado[i].idade;
			p = l->dado[i];
		}
	return p;
}

int pesquisar(Lista *l, char *nome)
{
	int i = 0;

	for (i = 0; i < l->n; i++)
		if (strcmp(l->dado[i].nome, nome) == 0)
			break;

	return l->dado[i].codigo;
}

void ordenarCrescente(Lista *l)
{
	int i = 0, j, lSize = l->n;
	Pessoa tmp;

	for (i = lSize-1; i > 0; i--) 
		for (j = 0; j < i; j++) 
			if (strcmp(l->dado[j].nome, l->dado[j + 1].nome) > 0) {
				tmp = l->dado[j];
				l->dado[j] = l->dado[j + 1];
				l->dado[j + 1] = tmp;
			}
}

void ordenarDecrescente(Lista *l)
{
	int i = 0, j, lSize = l->n;
	Pessoa tmp;

	for (i = lSize-1; i > 0; i--) 
		for (j = 0; j < i; j++) 
			if (strcmp(l->dado[j].nome, l->dado[j + 1].nome) < 0) {
				tmp = l->dado[j];
				l->dado[j] = l->dado[j + 1];
				l->dado[j + 1] = tmp;
			}
}

