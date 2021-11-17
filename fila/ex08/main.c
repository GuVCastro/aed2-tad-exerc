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

#define BUF 50

int main(void)
{
	Fila f;
	newFila(&f);
	int opcao = 0;
	Processo p;

	do {
		printf("\n********** Sistema de computacao time-shared **********\n");
		printf("[1] Inserir processo\n");
		printf("[2] Retira processo com maior tempo de espera\n");
		printf("[3] Mostrar processos na fila\n");
		printf("[0] Sair\n");
		printf("\n");
		printf("Insira uma das opcoes acima: ");
		scanf("%d", &opcao);

		switch (opcao) {
			case 0:
				printf("Ate mais\n");
				break;
			case 1:
			{
				system("clear");
				printFila(&f);
				printf("Insira o PID do processo: ");
				scanf("%d", &p.id);
				printf("Insira a descricao do processo: ");
				scanf(" %[^\n]%*c", p.descricao);
				enqueue(&f, p);
				break;
			}
			case 2:
			{
				system("clear");
				printFila(&f);
				dequeue(&f);
				break;
			}
			case 3:
			{
				system("clear");
				printFila(&f);
				break;
			}
			default: printf("OPCAO INVALIDA\n"); break;
		}
	} while (opcao != 0);

	return 0;
}
