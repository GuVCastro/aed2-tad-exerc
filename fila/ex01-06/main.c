/*****************************************************************************************
 * NOME DO ARQUIVO: main.c 
 * 
 * AUTOR: Gustavo Valadares Castro
 *
 * DESCRIÇÃO:	Programa baseado nos conceitos de fila
 *
 * OBSERVAÇÕES:
 *				Repositório: https://github.com/GuVCastro/aed2-tad-exerc
 *				Compilador: gcc (Ubuntu 9.3.0-17ubuntu1~20.04) 9.3.0 
 *
 * MUDANÇAS:
 *				DATA		AUTOR	DETALHES
 *				2021/11/04	Gustavo	Esqueleto do código
 *				2021/11/06	Gustavo	Código Finalizado
 ****************************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//#include "fila_linear.h"
#include "fila_flexivel.h"

#define BUF 7

void preencheValores(Pessoa *p)
{
	int i;
	char letras[] = "abcdefghijklmnopqrstuvwxyz";

	for (i = 0; i < BUF; i++)
		p->nome[i] = letras[rand() % 26];
	
	p->nome[i] = '\0';

	p->idade = rand() % 100;
}

int main(void)
{
	srand((unsigned int) time(NULL));

	int i;
	Pessoa p;
	Fila f;
	newFila(&f);

	printf("***** Insere pessoa *****\n");
	for (i = 0; i < 11; i++) {
		preencheValores(&p);
		enqueue(&f, p);
	}
	printFila(&f);

	printf("***** Remove pessoa (x3) *****\n");
	dequeue(&f);
	dequeue(&f);
	dequeue(&f);
	printFila(&f);

	printf("***** Insere com prioridade [priodade: acima de 65 anos] *****\n");
	p = (Pessoa) {"jose", 65};
	priorityEnqueue(&f, p);
	p = (Pessoa) {"ana", 73};
	priorityEnqueue(&f, p);
	p = (Pessoa) {"paulo", 88};
	priorityEnqueue(&f, p);
	printFila(&f);

	printf("***** Clonar Fila *****\n");
	Fila f1;
	newFila(&f1);
	clonarFila(&f, &f1);
	printFila(&f1);

	printf("***** Concatenar Filas *****\n");
	Fila f2;
	newFila(&f2);
	concatenarFilas(&f, &f1, &f2);
	printFila(&f2);

	printf("***** Inverter Fila *****\n");
	inverterFila(&f);
	printFila(&f);

	printf("***** Ordenar Fila *****\n");
	ordenarFila(&f);
	printFila(&f);

	return 0;
}
