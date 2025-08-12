#ifndef PILHA_H_INLUDED
#define PILHA_H_INLUDED

#include <dstruct.h>
/*********************************************
*---Defini��o da estrutura Pilha estatica---*
**********************************************/
typedef struct{
	int topo;
	Nodu* info[MAX];
} Pilha;

void initPilha(Pilha* pilha);
void inserir(Pilha* pilha, int Elem);
int pop(Pilha* pilha);
void delPilha(Pilha* pilha);
void showPilha(Pilha* pilha);

#endif
