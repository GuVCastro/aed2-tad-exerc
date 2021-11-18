#define TAM_NOME 50

typedef struct Pessoa {
	int codigo;
	char nome[TAM_NOME];
	int idade;
} Pessoa;

void printPessoa(Pessoa p);
