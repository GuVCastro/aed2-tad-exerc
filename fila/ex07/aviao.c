#include <stdio.h>
#include "aviao.h"

void printAviao(Aviao a)
{
	printf("{ nome: %s, id: %d, envergadura: %d }\n", a.nome, a.id, a.envergadura);
}
