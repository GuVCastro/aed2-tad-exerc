/*****************************************************************************************
 * NOME DO ARQUIVO: main.c 
 * 
 * AUTOR: Gustavo Valadares Castro
 *
 * DESCRIÇÃO:	Programa baseado nos conceitos de pilha
 *
 * OBSERVAÇÕES:
 *				Repositório: https://github.com/GuVCastro/aep2-tad-pilha
 *				Compilador: gcc (Ubuntu 9.3.0-17ubuntu1~20.04) 9.3.0 
 *
 * MUDANÇAS:
 *				DATA		AUTOR	DETALHES
 *				2021/10/29	Gustavo	Esqueleto do código
 *				2021/11/04	Gustavo	Código finalizado
 ****************************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
//#include "pilha_flexivel.h"
#include "pilha_linear.h"

#define TAM 10

void preencheValores(Dados *d)
{
	int i;
	char letras[] = "abcdefghijklmnopqrstuvwxyz";

	for (i = 0; i < TAM; i++)
		d->dado[i] = letras[rand() % 26];

	d->numero = rand() % 100;
}

int main(void)
{ 
	srand((unsigned int) time(NULL));

	Pilha p;
	newPilha(&p);
	Dados d;
	int i;

	for (i = 0; i < 10; i++) {
		preencheValores(&d);
		push(&p, d);
	}
	printf("Procedimento PUSH\n");
	printPilha(&p);

	printf("Funcao POP\n");
	pop(&p);
	pop(&p);
	pop(&p);
	printPilha(&p);

	/* CLONAR pilha */
	printf("Procedimento CLONAR\n");
	Pilha p1;
	newPilha(&p1);
	clonarPilha(&p, &p1);
	printPilha(&p1);

	/* CONCATENAR pilhas */
	printf("Procedimento CONCATENAR\n");
	Pilha p2;
	newPilha(&p2);
	concatenarPilha(&p, &p1, &p2);
	printPilha(&p2);

	/* INVERTER pilha */
	printf("Procedimento INVERTER\n");
	inverterPilha(&p);
	printPilha(&p);

	/* ORDENAR pilha */
	printf("Procedimento ORDENAR\n");
	ordenarPilha(&p);
	printPilha(&p);

	/* RETIRAR INTEIROS IMPARES da pilha */
	printf("Procedimento RETIRAR IMPARES\n");
	retiraImpares(&p);
	printPilha(&p);

	return 0;
}
