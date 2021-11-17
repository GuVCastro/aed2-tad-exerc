#define TAM_NOME 50

typedef struct Pessoa {
	char nome[TAM_NOME];
	int idade;
} Pessoa;

void printPessoa(Pessoa p);

