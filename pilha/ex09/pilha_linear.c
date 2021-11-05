#include "pilha_linear.h"

void newPilha(Pilha *p)
{
	p->n = 0;
}

void push(Pilha *p, Carro c)
{
	if (p->n == MAX)
		printf("\nEstacionamento cheio!\n");
	else {
		p->dados[p->n] = c;
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
	else{
		p->n--;
		return p->dados[p->n];
	}
}

void printPilha(Pilha *p)
{
	printf("\n");
	printf("TOPO ");
	for(int i=p->n-1; i>=0; i--)
		printCarro(p->dados[i]);
	printf("\n");
}

bool isPilhaVazia(Pilha *p)
{
	return p->n == 0;
}
