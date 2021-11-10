#include <stdlib.h>
#include <string.h>
#include "pilha_flexivel.h"

void newPilha(Pilha *p)
{
	p->topo = NULL;
	p->n = 0;
}

void push(Pilha *p, Dados d)
{
	if(p->n == MAX)
		printf("\nPILHA CHEIA!\n");
	else {
		Celula *tmp = malloc(sizeof(Celula));
		tmp->dado = d;
		tmp->prox = p->topo;

		p->topo = tmp;
		p->n++;    
	}
}

Dados pop(Pilha *p)
{
	if (p->n == 0) {
		printf("\nPILHA VAZIA!\n");
		Dados d = {-1, -1};
		return d;
	}
	else {
		Dados res = p->topo->dado;
		Celula *tmp = p->topo;
		p->topo = p->topo->prox;
		free(tmp);

		p->n--;
		return res;
	}
}

void printPilha(Pilha *p)
{
	int i = p->n-1;
	Celula *tmp = p->topo;

	printf("TOPO ");
	while (tmp != NULL) {
		printDados(tmp->dado);
		tmp = tmp->prox;
	}
	printf("\n");
}

bool isPilhaVazia(Pilha *p)
{
	return p->n == 0;
}

void clonarPilha(Pilha *p1, Pilha *p2)
{
	Dados *v = malloc(p1->n*sizeof(Dados));
	int i = p1->n-1;

	Celula *tmp = p1->topo;
	while (tmp != NULL) {
		v[i] = tmp->dado;
		i--;
		tmp = tmp->prox;
	}

	for(i = 0; i < p1->n; i++) {
		push(p2, v[i]);		
	}
}

void concatenarPilha(Pilha *p1, Pilha *p2, Pilha *p)
{
	Celula *tmp = p2->topo;
	Dados *v = malloc(p1->n*sizeof(Dados));
	int i = p2->n-1;

	clonarPilha(p1, p);

	while (tmp != NULL) {
		v[i] = tmp->dado;
		i--;
		tmp = tmp->prox;
	}

	for(i = 0; i < p2->n; i++) {
		push(p, v[i]);		
	}
}

void inverterPilha(Pilha *p)
{
	Pilha tmp;
	int i, pSize = p->n;
	
	newPilha(&tmp);

	for (i = 0; i < pSize; i++)
		push(&tmp, pop(p));

	clonarPilha(&tmp, p);
}

void ordenarPilha(Pilha *p)
{
	Dados *v = malloc(p->n*sizeof(Dados));
	Dados tmp;
	int i, j, pSize = p->n;

	for (i = 0; i < pSize; i++) {
		v[i] = pop(p);
	}
    
	for (i = pSize - 1; i > 0; i--)
		for (j = 0; j < i; j++)
			if (strcmp(v[j].dado, v[j + 1].dado) < 0 ) {
				tmp = v[j];
				v[j] = v[j + 1];
				v[j + 1] = tmp;
			}
	
	for (i = 0; i < pSize; i++)
		push(p, v[i]);
}

void retiraImpares(Pilha *p)
{
	Dados *v = malloc(p->n*sizeof(Dados));
	int i = 0, pSize = p->n, vSize;

	Celula *tmp = p->topo;
	while (tmp != NULL) {
		if ((tmp->dado.numero % 2) == 0) {
			v[i] = tmp->dado;
			i++;
		}
		tmp = tmp->prox;
		pop(p);
	}
	vSize = i;

	for(i = vSize - 1; i >= 0; i--) {
		push(p, v[i]);		
	}
}

