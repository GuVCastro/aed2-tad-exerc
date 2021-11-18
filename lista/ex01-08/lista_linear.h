#include "pessoa.h"

#define MAX 10

typedef struct Lista {
	Pessoa dado;
	int n;
	int MAX;
} Lista;

void newLista(Lista *l);

void inserir(Lista *l, Pessoa p);

Pessoa remover(Lista *l, int codigo);

void printLista(Lista *l);

void clonarLista(Lista *l, Lista *l1);

void concatenarListas(Lista *l1, Lista *l2, Lista *l);

void inserirOrdenado(Lista *l, Pessoa p);

Pessoa verificaMaior(Lista *l);

int pesquisar(Lista *l, char *nome);

void ordenarCrescente(Lista *l);

void ordenarDecrescente(Lista *l);
