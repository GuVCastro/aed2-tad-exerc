#include "fila_flexivel.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void create_fila(Fila *f){
	Celula *tmp = malloc(sizeof(Celula));
	tmp->prox = NULL;

	f->inicio = f->fim = tmp;
	f->tam = 0;
}

void enqueue(Fila *f, Aluno dado){
	Celula *tmp = malloc(sizeof(Celula));
	tmp->prox = NULL;
	tmp->dado = dado;

	f->fim->prox = tmp;
	f->fim = tmp;

	f->tam++;
}

Aluno dequeue(Fila *f){

	if(f->tam == 0){
		printf("Fila Vazia!");
		Aluno a;
		strcpy(a.nome, "-1");
		a.nota = -1;
		return a;
	}else{

		Celula *tmp = f->inicio;
		f->inicio = f->inicio->prox;
		free(tmp);
		f->tam--;
		return f->inicio->dado;
	}
	
}

void print_aluno(Aluno a){
	printf("{%s - %d}\n", a.nome, a.nota);
}

void print_fila(Fila *f){
	Celula *tmp = f->inicio->prox;
	while(tmp != NULL){
		print_aluno(tmp->dado);
		tmp = tmp->prox;
	}
}

void bolha_nome(Aluno *v, int n){

	for(int i=0; i<n-1; i++)
		for(int j=0; j<n-1-i; j++)
			if(strcmp(v[j].nome, v[j+1].nome) >0){
				Aluno aux = v[j];
				v[j] = v[j+1];
				v[j+1] = aux;
			}
}

void bolha_nota(Aluno *v, int n){

	for(int i=0; i<n-1; i++)
		for(int j=0; j<n-1-i; j++)
			if(v[j].nota > v[j+1].nota){
				Aluno aux = v[j];
				v[j] = v[j+1];
				v[j+1] = aux;
			}
}

void sort_fila_nome(Fila *f){
	//COPIA OS DADOS DA FILA PARA UM VETOR
	int n = f->tam;
	Aluno *vetor = malloc(n*sizeof(Aluno));
	for(int i=0; i<n;i++)
		vetor[i] = dequeue(f);

	// ORDENO O VETOR
	bolha_nome(vetor, n);

	for(int i=0; i<n;i++)
		enqueue(f, vetor[i]);
}

void sort_fila_nota(Fila *f){
	//COPIA OS DADOS DA FILA PARA UM VETOR
	int n = f->tam;
	Aluno *vetor = malloc(n*sizeof(Aluno));
	for(int i=0; i<n;i++)
		vetor[i] = dequeue(f);

	// ORDENO O VETOR
	bolha_nota(vetor, n);

	for(int i=0; i<n;i++)
		enqueue(f, vetor[i]);
}

void sort_fila_nome2(Fila *f){

int n = f->tam;
 for(int i=0; i<n-1; i++){
	 Celula *j1 = f->inicio->prox;
	 while(j1 != NULL && j1->prox != NULL){
		 Celula *j2 = j1->prox;
		 if(strcmp(j1->dado.nome, j2->dado.nome) >0){
				Aluno aux = j1->dado;
				j1->dado = j2->dado;
				j2->dado = aux;
			}
			j1 = j1->prox;
	 }

 }

}
