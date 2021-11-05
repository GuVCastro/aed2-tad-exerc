#include <stdbool.h>
#include <stdio.h>
#include "dados.h"

#define MAX 25

typedef struct Pilha {
	Dados dados[MAX];
	int n;
} Pilha;

void newPilha(Pilha *p);

void push(Pilha *p, Dados d);

Dados pop(Pilha *p);

void printPilha(Pilha *p);

bool isPilhaVazia(Pilha *p);

void clonarPilha(Pilha *p1, Pilha *p2);

void concatenarPilha(Pilha *p1, Pilha *p2, Pilha *p);

void inverterPilha(Pilha *p);

void ordenarPilha(Pilha *p);

void retiraImpares(Pilha *p);
