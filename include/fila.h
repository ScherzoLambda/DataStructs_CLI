#ifndef FILA_H_INLUDED
#define FILA_H_INLUDED
#include <dstruct.h>

/*********************************************
*---Defini��o da estrutura Fila Dinamica---*
**********************************************/
typedef struct{
	int tamanho;
	Nodu* fim;
	Nodu* inicio;
}Fila;

//functions fila
void initFila(Fila* f);
void filaAdd(Fila* f, int Elem);
int popFila(Fila* f);
int peekFila(Fila* f);
int sizeFila(Fila* f);
void delFila(Fila* f);
void showFila(Fila* f);

#endif
