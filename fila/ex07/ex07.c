/*****************************************************************************************
 * NOME DO ARQUIVO: ex07.c 
 * 
 * AUTOR: Gustavo Valadares Castro
 *
 * DESCRIÇÃO:	Programa de aeroporto utilizando os conceitos de fila
 *
 * OBSERVAÇÕES:
 *				Repositório: https://github.com/GuVCastro/aed2-tad-fila
 *				Compilador: gcc (Ubuntu 9.3.0-17ubuntu1~20.04) 9.3.0 
 *
 * MUDANÇAS:
 *				DATA		AUTOR	DETALHES
 *				2021/10/29	Gustavo	Esqueleto do código
 ****************************************************************************************/

#include <stdio.h>
#include <stdlib.h>
//#include "fila_linear.h"
#include "fila_flexivel.h"

int main(void) {
	Fila fila;
	newFila(&fila);
	Aviao a;
	int opcao = -1;

	while (opcao != 0) {
		printf("\n*****************************************\n");
		printf("Programa Aeroporto Fila\n");
		printf("[1] Autorizar pouso [inserir]\n");
		printf("[2] Autorizar decolagem [remover]\n");
		printf("[3] Mostrar avioes na fila\n");
		printf("[4] Mostrar primeiro aviao\n");
		printf("[5] Autorizar com prioridade [prioridade: envergadura]\n");
		printf("[0] Sair\n");
		printf("*****************************************\n");
		printf("Insira uma das opcoes acima: ");
		scanf("%d", &opcao);

		switch (opcao) {
			case 0:
				printf("\nAte mais!\n\n");
				break;
			case 1:
				system("clear");
				printFila(&fila);
				printf("\nNome do aviao: "); scanf("%s", a.nome);
				printf("Id do aviao: "); scanf("%d", &a.id);
				printf("Envergadura do aviao (m): "); scanf("%d", &a.envergadura);
				enqueue(&fila, a);
				break;
			case 2:
				system("clear");
				dequeue(&fila);
				printFila(&fila);
				break;
			case 3:
				system("clear");
				printFila(&fila);
				break;
			case 4:
				system("clear");
				mostrarPrimeiro(&fila);
				break;
			case 5:
				system("clear");
				printFila(&fila);
				printf("\nNome do aviao: "); scanf("%s", a.nome);
				printf("Id do aviao: "); scanf("%d", &a.id);
				printf("Envergadura do aviao (m): "); scanf("%d", &a.envergadura);
				priorityEnqueue(&fila, a);
				break;
			default: system("clear"); printf("OPCAO INVALIDA\n");
				break;
		}
	}

	return 0;
}
