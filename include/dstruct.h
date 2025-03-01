#ifndef DSTRUCT_H_INLUDED
#define DSTRUCT_H_INLUDED
#define MAX 25
/*Nó para armazenazem de dados.*/
typedef struct Nod {
    int info;
    struct Nod* next;
} Nod;
/* No para o encadeamento duplo*/
typedef struct Nodu{
	int info;
	struct Nodu* prev;
	struct Nodu* next;
} Nodu;

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


/*********************************************
*---Definition da estrutura Pilha dinamica---*
**********************************************/
/*N� para armazenazem de dados.*/
typedef struct{
	int topo;
	Nodu* info;
}Pilha_dim;

//fun��es pilha
void initPilhaDim(Pilha_dim* pilha);
void addElem(Pilha_dim* pilha, int Elem);
int popElem(Pilha_dim* pilha);
void delPilhaDim(Pilha_dim* pilha);
void showPD(Pilha_dim* pilha);

/*********************************************
*---Defini��o da estrutura Pilha estatica---*
**********************************************/
typedef struct{
	int topo;
	Nodu* info[MAX];
} Pilha_;

void initPilha(Pilha_* pilha);
void inserir(Pilha_* pilha, int Elem);
int pop(Pilha_* pilha);
void delPilha(Pilha_* pilha);
void showPilha(Pilha_* pilha);

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


/*********************************************
*---Definition of Deque Struct---*
**********************************************/
typedef struct {
	int tamanho;
	Nodu* inicio;
	Nodu* fim;
} Deque;

//functions Deque
void initDeque(Deque* d);
void showDeque(Deque* d);
void insBegin(Deque* d, int Elem);
void insEnd(Deque* d, int Elem);
int getBegin(Deque* d);
int getEnd(Deque* d);
int sizeDeque(Deque* d);
void del_Deque(Deque* d);
void delBegin(Deque* d);
void delEnd(Deque* d);


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
//void set_cover(set_** sets, int numSets, set_* result);


#endif







