#include <stdio.h>
#include "dados.h"

void inserirDados(Dados *d)
{
	printf("Insira um numero: ");
	scanf("%d", &d->numero);
	printf("Insira uma pessoa: ");
	scanf(" %[^\n]%*c", d->nome);
}

void printDados(Dados d)
{
	printf("{ Numero: %d, Nome: %s }\n", d.numero, d.nome);
}
