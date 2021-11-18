/*****************************************************************************************
 * NOME DO ARQUIVO: main.c 
 * 
 * AUTOR: Gustavo Valadares Castro
 *
 * DESCRIÇÃO:	Programa baseado nos conceitos de lista 
 *
 * OBSERVAÇÕES:
 *				Repositório: https://github.com/GuVCastro/aed2-tad-exerc
 *				Compilador: gcc (Ubuntu 9.3.0-17ubuntu1~20.04) 9.3.0 
 *
 * MUDANÇAS:
 *				DATA		AUTOR	DETALHES
 *				2021/11/06	Gustavo	Programa completo
 *				2021/11/17	Gustavo Programa completo
 ****************************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista_dupla.h"

int main(void)
{
	int opcao = 0, pos = 0, numElemento = 0;
	Lista l;
	newLista(&l);
	Dados d;

	do {
		printf("***********************************\n");
		printf("[1] Inserir no inicio\n");
		printf("[2] Inserir no fim\n");
		printf("[3] Inserir na posicao\n");
		printf("[4] Remover no inicio\n");
		printf("[5] Remover no fim\n");
		printf("[6] Remover na posicao\n");
		printf("[7] Mostrar lista\n");
		printf("[8] Exibir tamanho\n");
		printf("[9] Pesquisar elemento\n");
		printf("[0] Sair\n");
		printf("***********************************\n");
		printf("\nInsira uma das opcoes acima: ");
		scanf("%d", &opcao);

		switch (opcao) {
			case 0:
				printf("Ate mais!\n");
				break;
			case 1:
				system("clear");
				inserirDados(&d);
				insereInicio(&l, d);
				break;
			case 2:
				system("clear");
				inserirDados(&d);
				insereFim(&l, d);
				break;
			case 3:
				system("clear");
				tamanhoLista(&l);
				inserirDados(&d);
				printf("Insira a posicao a ser inserida: ");
				scanf("%d", &pos);
				inserePosicao(&l, d, pos);
				break;
			case 4:
				system("clear");
				removeInicio(&l);
				printLista(&l);
				break;
			case 5:
				system("clear");
				removeFim(&l);
				printLista(&l);
				break;
			case 6:
				system("clear");
				printf("Insira a posicao a ser removida: ");
				scanf("%d", &pos);
				removePosicao(&l, pos);
				printLista(&l);
				break;
			case 7:
				system("clear");
				printLista(&l);
				break;
			case 8:
				system("clear");
				tamanhoLista(&l);
				break;
			case 9:
				system("clear");
				printf("Insira o numero do elemento a ser pesquisado: ");
				scanf("%d", &numElemento);
				pesquisarElemento(&l, numElemento);
				break;
			default: printf("OPCAO INVALIDA\n");
		}
	} while(opcao != 0);

	return 0;
}


