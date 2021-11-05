#include <stdio.h>
#include "fila_flexivel.h"
#include <stdlib.h>
#include <time.h>

int main(void) {

	//srand(time(NULL));

	Fila fila;
	create_fila(&fila);
	int n = 10;

	for(int i=0; i<n; i++){
		Aluno a;
		sprintf(a.nome, "Aluno %d", rand()%n);
		a.nota = rand()%100;
		enqueue(&fila, a);
	}

	print_fila(&fila);

	printf("Ordenando...\n");
	sort_fila_nome2(&fila);
	print_fila(&fila);

	printf("Ordenando...\n");
	sort_fila_nota(&fila);
	print_fila(&fila);
	return 0;
}
