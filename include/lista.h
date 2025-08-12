#ifndef LISTA_H_INLUDED
#define LISTA_H_INLUDED

#include <dstruct.h>

/*********************************************
*---Definition of struct List---*
**********************************************/
typedef struct {
	int tamanho;
	Nod* inicio;
	Nod* fim;
} Lista;

/*---Fun�oes Lista---*/
void init_Lista(Lista* l);
void imprime(Lista* l);
void showLista(Lista* l);
void insereInicio(Lista* lista, int Elem);
void insereFim(Lista* lista, int Elem);
void inserePosicao(Lista* lista, int posicao, int elemento);
void deletElem(Lista* L, int Elem);
void delLista(Lista* l);
void delListas(Lista listas[]);
void findElem(Lista* l, int Elem);



/*********************************************
*---Definition da estrutura Lista Duplamente encadeada---*
**********************************************/
typedef struct {
	int tamanho;
	Nodu* inicio;
	Nodu* fim;
} Dlista;

/*---Functions Lista---*/
void init_Dlista(Dlista* lista);
void showDlista(Dlista* lista);
void insDlista(Dlista* lista, int Elem);
void insFim(Dlista* lista, int Elem);
void ins_Id(Dlista* lista, int id, int Elem);
void del_Dlista(Dlista* lista);
void del_Delem(Dlista* lista, int id);


#endif