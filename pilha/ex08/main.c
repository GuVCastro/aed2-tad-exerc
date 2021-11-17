/*****************************************************************************************
 * NOME DO ARQUIVO: main.c 
 * 
 * AUTOR: Gustavo Valadares Castro
 *
 * DESCRIÇÃO:	Implementacoes de funcionalidades de editores de texto usando pilha
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

#define TAM 1000

int main(void)
{ 
	int i;
	char texto[] = "Este et# um teste para o ET, o extraterrestre em C.@Acabamos de testar a capacidade de o ET saltar de linha, utilizando seus poderes extras (cuidado, pois agora vamos estourar a capacidade máxima da linha de impressão, que é de 70 caracteres.)@O k#cut#rso dh#e Estruturas de Dados II et# h#um cuu#rsh#o #x# x?@!#?!#+.@ Como et# bom n#nt#ao### r#ess#tt#ar mb#aa#triz#cull#ado nn#x#ele!/ Sera que este funciona/// O sinal? não### deve ficar! ~";
	Pilha p;
	newPilha(&p);

	//printf("Insira o texto:\n");
	//fgets(texto, TAM - 1, stdin);
	if (texto[strlen(texto) - 1] == '\n')
		texto[strlen(texto) - 1] = '\0';
	if (texto[strlen(texto) - 1] == '\r')
		texto[strlen(texto) - 1] = '\0';

	for (i = 0; i < strlen(texto); i++) {
		switch (texto[i]) {
			case '#':
				pop(&p);
				break;
			case '/':
				newPilha(&p);
				break;
			case '@':
				printPilha(&p);
				newPilha(&p);
				break;
			default:
			{
				bool empilhou = push(&p, texto[i]);
				if (!empilhou) {
					printPilha(&p);
					newPilha(&p);
				}
			}
		}
	}

	printPilha(&p);

	return 0;
}
