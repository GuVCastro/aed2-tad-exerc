#define TAM_DESC 30

typedef struct Processo {
	int id;
	char descricao[TAM_DESC];
} Processo;

void printProcesso(Processo p);
