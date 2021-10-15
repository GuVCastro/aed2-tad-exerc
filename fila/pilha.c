/*****************************************************************************************
 * NOME DO ARQUIVO: pilha.c 
 * 
 * AUTOR: Gustavo Valadares Castro
 *
 * DESCRIÇÃO:	
 *
 * OBSERVAÇÕES:
 *				Repositório: https://github.com/GuVCastro/aed2-tad-exerc
 *				Compilador: gcc (Ubuntu 9.3.0-17ubuntu1~20.04) 9.3.0 
 *
 * MUDANÇAS:
 *				DATA		AUTOR	DETALHES
 *				2021/10/15	Gustavo	Esqueleto do código
 ****************************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

typedef struct Pilha{
	float dados[MAX];
	int topo;
	//int MAX;
} Pilha;

void new_pilha(Pilha *p, float n)
{
	//p->MAX = n;
	//p->dados = malloc(n*sizeof(float));
	p->topo = 0;
}

void push(Pilha *p, float x)
{
	if(p->topo == MAX)
		printf("Pilha Cheia!\n");
	else{
		p->dados[p->topo] = x;
		p->topo++;
	}
}

float pop(Pilha *p)
{
	if(p->topo == 0){
		printf("Pilha Vazia!\n");
		return -1;
	}

	p->topo--;
	return p->dados[p->topo];
}


void print_pilha(Pilha p)
{
	for(int i=p.topo-1; i >= 0; i--) {
		printf("[%i] - %f", i, p.dados[i]);
		if (i == p.topo-1) printf(" ==> TOPO\n");
		else printf("\n");
	}
}

int main(void)
{  
	Pilha p;
	new_pilha(&p, 6);

	push(&p, 1.3);
	push(&p, 2.5);
	push(&p, 3.8);
	push(&p, 4.9);
	push(&p, 5.8);
	push(&p, 6.1);
	push(&p, 7.4);

	print_pilha(p);

	for (int i=0; i<7; i++) {
		int res = pop(&p);
		printf("\nElemento desempilhado: %i\n", res);
		print_pilha(p);
	} 

	return 0;
}
