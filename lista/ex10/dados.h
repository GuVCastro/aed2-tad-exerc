#define TAM_NOME 30

typedef struct Dados {
	int numero;
	char nome[30];
} Dados;

void printDados(Dados d);

void inserirDados(Dados *d);
