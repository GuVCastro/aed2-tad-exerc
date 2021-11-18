#include "site.h"

typedef struct Celula {
	Site dado;
	struct Celula *prox;
} Celula;

typedef struct Lista {
	Celula *primeiro;
	Celula *ultimo;
	int tam;
} Lista;

void newLista(Lista *l);

void inserir(Lista *l, Site s);

Site remover(Lista *l, char *nome);

void mostrarNomes(Lista *l);

int pesquisar(Lista *l, char *nome);

