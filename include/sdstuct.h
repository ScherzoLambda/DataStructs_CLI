

#ifndef SDSTRUCT_H_INLUDED
#define SDSTRUCT_H_INLUDED




/*********************************************
*---Defini��o da estrutura Tabela hash---*
**********************************************/
/*No para armazenazem de dados.*/
typedef struct {
	int ra;
	char *nome;
} tHash;

void initTH(tHash *t);
void iniciaTH(int ra_, char* nome_, tHash *t);
char* getNome(tHash *t);
int getRa(tHash *t);

/*********************************************
*---Definição da estrutura Tabela hash Encadeada ---*
**********************************************/
typedef struct {
	int ra;
	char *nome;
}thash_encadeada;

/*********************************************
*---Definição da estrutura Arvore binaria---*
**********************************************/
typedef struct{
} binaryArvore;

/*********************************************
*---Defini��o da estrutura Heap ---*
**********************************************/
typedef struct{
} heap_;
/*********************************************
*---Defini��o da estrutura Fila Prioritaria---*
**********************************************/
typedef struct{
} filaPriority;
/*********************************************
*---Definiçãoo da estrutura Grafo---*
**********************************************/
typedef struct{
} grafo;

#endif