#include "pilha_linear.h"

void newPilha(Pilha *p)
{
	p->n = 0;
}

void push(Pilha *p, Dados c)
{
	if (p->n == MAX)
		printf("\nEstacionamento cheio!\n");
	else {
		p->dados[p->n] = c;
		p->n++;    
	}
}

Dados pop(Pilha *p)
{
	if (p->n == 0) {
		printf("\nEstacionamento vazio!\n");
		Dados c = {-1,-1};
		return c;
	}
	else{
		p->n--;
		return p->dados[p->n];
	}
}

void printPilha(Pilha *p)
{
	printf("TOPO ");
	for(int i=p->n-1; i>=0; i--)
		printDados(p->dados[i]);
	printf("\n");
}

bool isPilhaVazia(Pilha *p)
{
	return p->n == 0;
}

void clonarPilha(Pilha *p1, Pilha *p2)
{
	printf("foo\n");
}

void concatenarPilha(Pilha *p1, Pilha *p2, Pilha *p)
{
	printf("foo\n");

}

void inverterPilha(Pilha *p)
{
	printf("foo\n");

}

void ordenarPilha(Pilha *p)
{
	printf("foo\n");

}

void retiraImpares(Pilha *p)
{
	printf("foo\n");

}
