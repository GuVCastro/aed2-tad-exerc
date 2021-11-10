#include <string.h>
#include "pilha_linear.h"

void newPilha(Pilha *p)
{
	p->n = 0;
}

void push(Pilha *p, Dados c)
{
	if (p->n == MAX)
		printf("\nPILHA CHEIA!\n");
	else {
		p->dados[p->n] = c;
		p->n++;    
	}
}

Dados pop(Pilha *p)
{
	if (p->n == 0) {
		printf("\nPILHA VAZIA!\n");
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
	for (int i = p->n-1; i >= 0; i--)
		printDados(p->dados[i]);
	printf("\n");
}

bool isPilhaVazia(Pilha *p)
{
	return p->n == 0;
}

void clonarPilha(Pilha *p1, Pilha *p2)
{
	int i;

	for (i = p1->n-1; i >= 0; i--)
		p2->dados[i] = p1->dados[i];
	
	p2->n = p1->n;
}

void concatenarPilha(Pilha *p1, Pilha *p2, Pilha *p)
{
	int i;

	clonarPilha(p1, p);

	for (i = 0; i < p2->n; i++)
		push(p, p2->dados[i]);
}

void inverterPilha(Pilha *p)
{
	int i, pSize = p->n;
	Pilha tmp;
	Dados dTmp;
	
	newPilha(&tmp);

	for (i = 0; i < pSize; i++) {
		dTmp = pop(p);
		strcpy(tmp.dados[i].dado, dTmp.dado);
		tmp.dados[i].numero = dTmp.numero;	
	}
	tmp.n = pSize;

	clonarPilha(&tmp, p);
}

void ordenarPilha(Pilha *p)
{
    int i, j;
	Dados tmp;

    for (i = p->n-1; i > 0; i--) 
		for (j = 0; j < i; j++) 
			if (strcmp(p->dados[j].dado, p->dados[j + 1].dado) < 0) {
				tmp = p->dados[j];
				p->dados[j] = p->dados[j + 1];
				p->dados[j + 1] = tmp;
			}
}

void retiraImpares(Pilha *p)
{
	int i, j = 0;
	Pilha tmp;
	
	newPilha(&tmp);

	for (i = 0; i < p->n; i++)
		if ((p->dados[i].numero % 2) == 0) {
			tmp.dados[j] = p->dados[i];
			j++;
		}
	tmp.n = j;

	clonarPilha(&tmp, p);
}
