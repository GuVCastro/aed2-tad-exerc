#include <stdbool.h>
#include <stdio.h>

#define MAX 70

typedef struct Pilha{
	int dados[MAX];
	int n;
} Pilha;

void newPilha(Pilha *p);

bool push(Pilha *p, int d);

int pop(Pilha *p);

void printPilha(Pilha *p);

bool isPilhaVazia(Pilha *p);
