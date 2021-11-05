/*****************************************************************************************
 * NOME DO ARQUIVO: main.c 
 * 
 * AUTOR: Gustavo Valadares Castro
 *
 * DESCRIÇÃO:	Programa de estacionamento utilizando os conceitos de pilha
 *
 * OBSERVAÇÕES:
 *				Repositório: https://github.com/GuVCastro/aed2-tad-pilha
 *				Compilador: gcc (Ubuntu 9.3.0-17ubuntu1~20.04) 9.3.0 
 *
 * MUDANÇAS:
 *				DATA		AUTOR	DETALHES
 *				2021/10/15	Gustavo	Esqueleto do código
 *				2021/10/22	Gustavo	Alterações na interface
 *				2021/10/22	Gustavo	Código finalizado
 ****************************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include "pilha_flexivel.h"
//#include "pilha_linear.h"

int main(void)
{ 
	Pilha estacionamento;
	newPilha(&estacionamento);
	int operacao, placa;

	do{
		printf("Insira a operacao [1] entrada, [2] saida: "); scanf("%d", &operacao);
		printf("Insira a placa: "); scanf("%d", &placa);
		switch (operacao) {
			case 0:
				printf("\nPrograma finalizado!\n");
				break;

			case 1: 
			{
				Carro c;
				c.placa = placa;
				c.manobras = 0;
				push(&estacionamento, c);
				printf("\nCarro inserido\n");
				printPilha(&estacionamento);
				break;
			}

			case 2:
			{
				Pilha pAux;
				newPilha(&pAux);

				while (!isPilhaVazia(&estacionamento)) {
					Carro c = pop(&estacionamento);
					if (c.placa == placa) {
						printf("\nCarro encontrado!\n");
						break;
					}
					push(&pAux, c);
				}

				while (!isPilhaVazia(&pAux)) {
					Carro c = pop(&pAux);
					c.manobras++;
					push(&estacionamento,c);
				}
				printf("\nCarro removido!\n");
				printPilha(&estacionamento);        
				break;
			}

			default:	printf("\nOpcao Invalida!\n");
		}

	} while(operacao != 0);

	return 0;
}
