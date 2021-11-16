#include <stdlib.h>
#include <string.h>
#include "pilha_flexivel.h"

void newPilha(Pilha *p)
{
	p->topo = NULL;
	p->n = 0;
}

void push(Pilha *p, char d)
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

char pop(Pilha *p)
{
	if (p->n == 0) {
		printf("\nPILHA VAZIA!\n");
		char d = '\0';
		return d;
	}
	else {
		char res = p->topo->dado;
		Celula *tmp = p->topo;
		p->topo = p->topo->prox;
		free(tmp);

		p->n--;
		return res;
	}
}

bool isPilhaVazia(Pilha *p)
{
	return p->n == 0;
}

