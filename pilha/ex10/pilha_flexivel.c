#include "pilha_flexivel.h"
#include <stdlib.h>

void newPilha(Pilha *p)
{
	p->topo = NULL;
	p->n = 0;
}

bool push(Pilha *p, int c)
{
	if(p->n == MAX)
		return false;
	
	Celula *tmp = malloc(sizeof(Celula));
	tmp->dado = c;
	tmp->prox = p->topo;

	p->topo = tmp;
	p->n++;    
	
	return true;
}

int pop(Pilha *p)
{
	if (p->n == 0) {
		return -1;
	}
	else {
		int res = p->topo->dado;
		Celula *tmp = p->topo;
		p->topo = p->topo->prox;
		free(tmp);

		p->n--;
		return res;
	}
}

void printPilha(Pilha *p)
{
	int *v = malloc(p->n*sizeof(int));
	int i = p->n-1;

	Celula *tmp = p->topo;
	while (tmp != NULL) {
		v[i] = tmp->dado;
		i--;
		tmp = tmp->prox;
	}

	for(int i=0; i < p->n; i++)
		printf("%d", v[i]);

	printf("\n");
}

bool isPilhaVazia(Pilha *p)
{
  return p->n == 0;
}
