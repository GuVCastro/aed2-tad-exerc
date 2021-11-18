#include "dados.h"

typedef struct Celula {
	Dados dado;
	struct Celula *prox;
	struct Celula *anterior;
} Celula;

typedef struct Lista {
	Celula *primeiro;
	Celula *ultimo;
	int tam;
} Lista;

void newLista(Lista *l);

void insereInicio(Lista *l, Dados d);

void insereFim(Lista *l, Dados d);

void inserePosicao(Lista *l, Dados d, int pos);

Dados removeInicio(Lista *l);

Dados removeFim(Lista *l);

Dados removePosicao(Lista *l, int pos);

void printLista(Lista *l);

int tamanhoLista(Lista *l);

Dados pesquisarElemento(Lista *l, int numElemento);
