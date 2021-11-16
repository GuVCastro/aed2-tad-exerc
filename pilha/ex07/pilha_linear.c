#include <string.h>
#include "pilha_linear.h"

void newPilha(Pilha *p)
{
	p->n = 0;
}

void push(Pilha *p, char d)
{
	if (p->n == MAX)
		printf("\nPILHA CHEIA!\n");
	else {
		p->dados[p->n] = d;
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
	else{
		p->n--;
		return p->dados[p->n];
	}
}

bool isPilhaVazia(Pilha *p)
{
	return p->n == 0;
}

