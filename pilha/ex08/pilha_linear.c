#include "pilha_linear.h"

void newPilha(Pilha *p)
{
	p->n = 0;
}

bool push(Pilha *p, char d)
{
	if (p->n == MAX)
		return false;
	else {
		p->dados[p->n++] = d;
		return true;
	}
}

char pop(Pilha *p)
{
	if (p->n == 0) 
		return '\0';
	
	p->n--;
	return p->dados[p->n];
}

void printPilha(Pilha *p)
{
	int i;

	for(i = 0; i < p->n; i++)
		printf("%c", p->dados[i]);
	
	printf("\n");
}

bool isPilhaVazia(Pilha *p)
{
	return p->n == 0;
}
