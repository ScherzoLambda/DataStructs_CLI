#include <stdio.h>

#include <sdstruct.h>

/* ### Fun��es Tabela Hash ### */
void initTH(tHash *t){
	t->ra = -1;
	t->nome = (char*) malloc(2 * sizeof(char));  // Alocando mem�ria para 2 caracteres (incluindo o caractere nulo)
    strcpy(t->nome, " ");
}

void iniciaTH(int ra_, char* nome_, tHash *t){
	t->ra = ra_;
    strcpy(t->nome, nome_);
}

int getRa(tHash *t){
	return t->ra;
}
char* getNome(tHash *t){
	return t->nome;
}