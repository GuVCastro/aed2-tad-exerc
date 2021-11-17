#include <stdio.h>
#include "pessoa.h"

void printPessoa(Pessoa p)
{
	printf("{ Nome: %s, Idade: %d }\n", p.nome, p.idade);
}
