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
 *				2021/11/18	Gustavo Programa completo
 ****************************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "lista_linear.h"
//#include "lista_flexivel.h"

#define BUF 7

void preencheValores(Pessoa *p)
{
	int i;
	char letras[] = "abcdefghijklmnopqrstuvwxyz";

	for (i = 0; i < BUF; i++)
		p->nome[i] = letras[rand() % 26];
	
	p->nome[i] = '\0';

	p->codigo = rand() % 100000;
	p->idade = rand() % 100;
}

int main(void)
{
	srand((unsigned int) time(NULL));

	int i, codigo;
	Lista l;
	newLista(&l);
	Pessoa p;
	Pessoa pTeste[5] = {	{12345, "ana", 46},
							{54321, "maria", 56},
							{23456, "jose", 98},
							{65432, "rodolfo", 64},
							{56789, "mario", 78}
	};

	printf("***** Insere pessoa *****\n");
	for (i = 0; i < 8; i++) {
		preencheValores(&p);
		inserir(&l, p);
	}
	inserir(&l, pTeste[0]);
	inserir(&l, pTeste[1]);
	inserir(&l, pTeste[2]);
	inserir(&l, pTeste[3]);
	printLista(&l);

	printf("***** Remove pessoa (x3) *****\n");
	remover(&l, pTeste[1].codigo);
	remover(&l, pTeste[2].codigo);
	remover(&l, pTeste[3].codigo);
	printLista(&l);

	printf("***** Clonar Lista *****\n");
	Lista l1;
	newLista(&l1);
	clonarLista(&l, &l1);
	printLista(&l1);

	printf("***** Concatenar Listas *****\n");
	Lista l2;
	newLista(&l2);
	concatenarListas(&l, &l1, &l2);
	printLista(&l2);

	printf("***** Inserir ordenado *****\n");
	inserirOrdenado(&l, pTeste[4]);
	printLista(&l);

	printf("***** Mostra maior idade *****\n");
	p = verificaMaior(&l);
	printPessoa(p);
	

	printf("\n***** Pesquisar [pesquisar por \"ana\"] *****\n");
	codigo = pesquisar(&l, pTeste[0].nome);
	printf("Codigo: %d\n\n", codigo);

	printf("***** Ordenar Lista crescente *****\n");
	ordenarCrescente(&l);
	printLista(&l);

	printf("***** Ordenar Lista descrescente *****\n");
	ordenarDecrescente(&l);
	printLista(&l);
	
	return 0;
}

