#include "pilha_flexivel.h"
#include <stdlib.h>

void newPilha(Pilha *p)
{
	p->topo = NULL;
	p->n = 0;
}

void push(Pilha *p, Carro c)
{
	if(p->n == MAX)
		printf("\nEstacionamento cheio!\n");
	else {
		Celula *tmp = malloc(sizeof(Celula));
		tmp->dado = c;
		tmp->prox = p->topo;

		p->topo = tmp;
		p->n++;    
	}
}

Carro pop(Pilha *p)
{
	if (p->n == 0) {
		printf("\nEstacionamento vazio!\n");
		Carro c = {-1,-1};
		return c;
	}
	else {
		Carro res = p->topo->dado;
		Celula *tmp = p->topo;
		p->topo = p->topo->prox;
		free(tmp);

		p->n--;
		return res;
	}
}

void printPilha(Pilha *p)
{
	Carro *v = malloc(p->n*sizeof(Carro));
	int i = p->n-1;

	Celula *tmp = p->topo;
	while (tmp != NULL) {
		v[i] = tmp->dado;
		i--;
		tmp = tmp->prox;
	}

	printf("\n");
	printf("TOPO ");
	for(int i=p->n-1; i>=0; i--)
		printCarro(v[i]);
	printf("\n");
}

bool isPilhaVazia(Pilha *p)
{
  return p->n == 0;
}
