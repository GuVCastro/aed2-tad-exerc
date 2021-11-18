#include <stdio.h>
#include "pessoa.h"

void printPessoa(Pessoa p)
{
	printf("{ Codigo: %d, Nome: %s, Idade: %d }\n", p.codigo, p.nome, p.idade);
}
