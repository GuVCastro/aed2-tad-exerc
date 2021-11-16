/*****************************************************************************************
 * NOME DO ARQUIVO: main.c 
 * 
 * AUTOR: Gustavo Valadares Castro
 *
 * DESCRIÇÃO:	Programa verifica sintaxe de expressoes usando conceitos de pilha
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
#include <string.h>
#include "pilha_flexivel.h"
//#include "pilha_linear.h"

#define TAM 100

int main(void)
{
	char expressao[TAM];
	int i = 0;
	Pilha p;
	newPilha(&p);

	printf("Insira a expressao matematica: ");
	fgets(expressao, TAM, stdin);

	while (i < strlen(expressao)) {
		if (expressao[i] == '(')
			push(&p, '(');
		if (expressao[i] == ')')
			if (!isPilhaVazia(&p))
				pop(&p);
			else {
				push(&p, ')');
				break;
			}
		i++;
	}

	if (isPilhaVazia(&p))
		printf("Expressao Matematica Correta\n");
	else
		printf("Expressao Matematica Incorreta\n");

	return 0;
}
