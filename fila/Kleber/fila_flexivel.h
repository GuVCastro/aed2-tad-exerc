#include <stdio.h>

typedef struct Aluno{
	char nome[100];
	int nota;
}Aluno;

void print_aluno(Aluno a);

typedef struct Celula{
	Aluno dado;
	struct Celula *prox;
}Celula;

typedef struct Fila{
	Celula *inicio;
	Celula *fim;
	int tam;
}Fila;

void create_fila(Fila *f);

void enqueue(Fila *f, Aluno dado);

Aluno dequeue(Fila *f);

void print_fila(Fila *f);

void sort_fila_nome(Fila *f);

void sort_fila_nome2(Fila *f);

void sort_fila_nota(Fila *f);
