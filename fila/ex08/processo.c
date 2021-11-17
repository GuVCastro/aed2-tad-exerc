#include <stdio.h>
#include "processo.h"

void printProcesso(Processo p)
{
	printf("{ PID: %d, Descricao: %s }\n", p.id, p.descricao);
}
