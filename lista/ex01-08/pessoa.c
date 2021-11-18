#include <stdio.h>
#include "pessoa.h"

void printPessoa(Pessoa p)
{
	printf("{ Codigo: %d, Nome: %s, Idade: %d }", p.codigo, p.nome, p.idade);
}
