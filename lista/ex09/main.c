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
 *				2021/11/10	Gustavo Programa completo
 ****************************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista_encadeada.h"

#define TAM_NOMES 20
#define TAM_LINKS 25

void inserirPadroes(Lista *l, char *nomes, char *links)
{
	Site s;
	strcpy(s.nomes, nomes);
	strcpy(s.links, links);
	inserir(l, s);
}

int main(void)
{
	Lista l;
	newLista(&l);
	Site s;
	
	char *nomesPadrao[10] = {
		"Google",
		"Facebook",
		"Instagram",
		"Whatsapp",
		"Linkedin",
		"Amazon",
		"Pinterest",
		"Tiktok",
		"Spotify",
		"Snapchat"
	};
	char *linksPadrao[10] = {
		"google.com",
		"facebook.com",
		"instagram.com",
		"web.whatsapp.com",
		"linkedin.com",
		"amazon.com",
		"pinterest.com",
		"tiktok.com",
		"spotify.com",
		"snapchat.com"
	};
	for (int i = 0; i < 10; i++)
		inserirPadroes(&l, nomesPadrao[i], linksPadrao[i]);
	
	char nome[TAM_NOMES];
	int sitesVisitados, opcao = 0;

	do {
		printf("*****************************************\n");
		printf("[1] Mostrar lista\n");
		printf("[2] Pesquisar URL\n");
		printf("[3] Inserir endereco\n");
		printf("[4] Remover endereco\n");
		printf("[0] Sair\n");
		printf("*****************************************\n");
		printf("\nInsira uma das opcoes: ");
		scanf("%i", &opcao);
		printf("\n");

		switch (opcao) {
			case 0:
				system("clear");
				printf("ATE MAIS\n");

			case 1:
				system("clear");
				mostrarNomes(&l);
				break;

			case 2:
				system("clear");
				mostrarNomes(&l);
				printf("Insira o nome: ");
				scanf(" %[^\n]%*c", nome);
				sitesVisitados = pesquisar(&l, nome);
				printf("Enderecos visitados durante pesquisa: %i\n\n", sitesVisitados);
				break;
			
			case 3:
				system("clear");
				printf("Insira o nome: ");
				scanf(" %[^\n]%*c", s.nomes);
				printf("Insira o link: ");
				scanf(" %[^\n]%*c", s.links);	
				inserir(&l, s);
				mostrarNomes(&l);
				break;

			case 4:
				system("clear");
				mostrarNomes(&l);
				printf("Insira o nome: ");
				scanf(" %[^\n]%*c", nome);
				remover(&l, nome);
				mostrarNomes(&l);
				break;

			default: system("clear"); printf("OPCAO INVALIDA\n");	
		}
	} while (opcao != 0);

	return 0;
}

