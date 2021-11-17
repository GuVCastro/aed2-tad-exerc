/*****************************************************************************************
 * NOME DO ARQUIVO: main.c 
 * 
 * AUTOR: Gustavo Valadares Castro
 *
 * DESCRIÇÃO:	Programa recebe instrucoes em RPN e efetua operacoes
 *
 * OBSERVAÇÕES:
 *				Repositório: https://github.com/GuVCastro/aed2-tad-exerc
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

#define TAM 50

int main(void)
{ 
	int i, a, b, res;
	char texto[TAM];
	Pilha p;
	newPilha(&p);

	fgets(texto, TAM - 1, stdin);
	if(texto[strlen(texto) - 1] == '\n')
		texto[strlen(texto) - 1] = '\0';
	if(texto[strlen(texto) - 1] == '\r')
		texto[strlen(texto) - 1] = '\0';

	for (i = 0; i < strlen(texto); i++) {
		switch (texto[i]) {
			case '+':
			{
				a = pop(&p);
				b = pop(&p);
				res = a + b;
				push(&p, res);
				break;
			}
			case '-':
			{
				a = pop(&p);
				b = pop(&p);
				res = b - a;
				push(&p, res);
				break;
			}
			case '*':
			{
				a = pop(&p);
				b = pop(&p);
				res = a * b;
				push(&p, res);
				break;
			}
			case '/':
			{
				a = pop(&p);
				b = pop(&p);
				res = b / a;		
				push(&p, res);
				break;
			}
			default:
			{
				if(texto[i] != ' ')
					push(&p, texto[i] - 48);     
			}
		}
	}

	res = pop(&p);
	printf("Resultado: %d\n", res);

	return 0;
}
