#ifndef CONJUNTO_H_INLUDED
#define CONJUNTO_H_INLUDED

#include<dstruct.h>

/*********************************************
*---Definiçõo da estrutura Conjunto(Set)---*
**********************************************/
typedef struct {
	int tamanho;
	Nod* inicio;
	Nod* fim;
} set_ ;

//	functions Set(conjuntos)
void initSet(set_ *set);
void delSet(set_ *set);
void insertSet(set_* set, int Elem);
void setIndexRemove(set_* set, int Elem);
set_ set_union(set_* set1, set_* set2);
set_ set_intersec(set_* set1, set_* set2);
set_ set_diferenca(set_* set1, set_* set2);
int set_isMember(set_* set, int Elem);
int set_isSubset(set_* set1, set_* set2);
int set_isEqual(set_* set1, set_* set2);
int set_size(set_* set);
void set_cover(int conjunto[], int tamanho_conjunto, int subconjuntos[][5], int quantidade_subconjuntos);
void showSet(set_* set);
//void set_cover(set_** sets, int numSets, set_* result);


#endif