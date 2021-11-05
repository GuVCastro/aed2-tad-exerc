#include <stdbool.h>
#include <stdio.h>
#include "carro.h"

#define MAX 5

typedef struct Pilha{
	Carro dados[MAX];
	int n;
} Pilha;

void newPilha(Pilha *p);

void push(Pilha *p, Carro c);

Carro pop(Pilha *p);

void printPilha(Pilha *p);

bool isPilhaVazia(Pilha *p);
