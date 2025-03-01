#include <dstruct.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//definição do tamanho MAX do vetor estatico
#define MAX 25

/*---------------------------------- Functions Lista Encadeada---*/
void init_Lista(Lista* l){
	l->tamanho = 0;
	l->inicio = NULL;
	l->fim = NULL;
}
//	Exibe valores lista
void showLista(Lista* l) {
    if (l->inicio == NULL) {
        printf("Lista vazia\n");
        return;
    }
    
    Nod* atual = l->inicio;
    printf(" [");
    while (atual != NULL) {
        printf("%d", atual->info);
        
        atual = atual->next;
        if (atual != NULL) {
            printf(", ");
        }
    }
    printf("]\n");
}

void imprime(Lista* l){
    if (l->inicio == NULL) {
        printf("Lista vazia\n");
        return;
    }

    Nod* atual = l->inicio;
    printf("Elementos da lista:");

    while (atual != NULL) {
        printf(" %d", atual->info);
        atual = atual->next;
    }
    printf(" %d", atual->info);

    printf("\n");
}

void insereInicio(Lista* lista, int Elem) {
    if (lista->tamanho >= MAX) {
        printf("Erro: Lista cheia\n");
        return;
    }
	
	Nod* novoNo = (Nod*)malloc(sizeof(Nod));
    if (novoNo == NULL) {
        printf("Erro: Falha na aloca��o de mem�ria\n");
        return;
    }

    novoNo->info = Elem;
    if (lista->inicio == NULL) {
    	novoNo->next = NULL;
        // Se a lista estiver vazia, o novo n� ser� o primeiro e o �ltimo
        lista->inicio = novoNo;
        lista->fim = novoNo;
        //lista->inicio->next = NULL;
	}else{
		novoNo->next = lista->inicio;
    	lista->inicio = novoNo;
	}
        lista->tamanho++;
    
}

void insereFim(Lista* lista, int Elem) {
    if (lista->tamanho >= MAX) {
        printf("Erro: Lista cheia\n");
        return;
    }
    
    Nod* novoNo = (Nod*)malloc(sizeof(Nod));
    if (novoNo == NULL) {
        printf("Erro: Falha na aloca��o de mem�ria\n");
        return;
    }
    novoNo->info = Elem;
    novoNo->next = NULL;  // Define o pr�ximo como NULL, j� que ser� o �ltimo n�
    
    if (lista->inicio == NULL) {
        // Se a lista estiver vazia, o novo n� ser� o primeiro e o �ltimo
        lista->inicio = novoNo;
        lista->fim = novoNo;
    } else {
        // Se a lista n�o estiver vazia, adiciona o novo n� no final
        lista->fim->next = novoNo;
        lista->fim = novoNo;
    }
    
    lista->tamanho++;
}

void inserePosicao(Lista* lista, int posicao, int elemento) {
    if (posicao < 0 || posicao > lista->tamanho) {
        printf("Erro: Posi��o inv�lida\n");
        return;
    }

    if (lista->tamanho >= MAX) {
        printf("Erro: Lista cheia\n");
        return;
    }

    Nod* novoNo = (Nod*)malloc(sizeof(Nod));
    if (novoNo == NULL) {
        printf("Erro: Falha na aloca��o de mem�ria\n");
        return;
    }
    novoNo->info = elemento;

    if (posicao == 0) {
        // Inser��o no in�cio da lista
        novoNo->next = lista->inicio;
        lista->inicio = novoNo;
        if (lista->fim == NULL) {
            // A lista estava vazia, atualiza o ponteiro fim
            lista->fim = novoNo;
        }
    } else if (posicao == lista->tamanho) {
        // Inser��o no fim da lista
        novoNo->next = NULL;
        lista->fim->next = novoNo;
        lista->fim = novoNo;
    } else {
        // Inser��o em uma posi��o intermedi�ria
        Nod* anterior = lista->inicio;
        int i;
        for (i = 0; i < posicao - 1; i++) {
            anterior = anterior->next;
        }
        novoNo->next = anterior->next;
        anterior->next = novoNo;
    }

    lista->tamanho++;
}

void deletElem(Lista *L, int Elem)
{
    Nod *atual = L->inicio;
    Nod *anterior = NULL;
    while (atual != NULL && atual->info != Elem)
    {
        anterior = atual;
        atual = atual->next;
    }
    if (atual == NULL)
    {
        printf("Elemento n�o encontrado\n");
        return;
    }
    if (anterior == NULL)
    {
        L->inicio = atual->next;
    }
    else
    {
        anterior->next = atual->next;
    }
    if (atual->next == NULL)
    {
        L->fim = anterior;
    }
    free(atual);
    L->tamanho--;
}

//	Deletar elementos
void delLista(Lista* l){
	Nod* atual = l->inicio;
    while (atual != NULL) {
        Nod* proximo = atual->next;
        free(atual);
        atual = proximo;
    }
    l->tamanho = 0;
    l->inicio = NULL;
    l->fim = NULL;
}

void findElem(Lista *l, int Elem)
{
    int indice = 0;
    Nod *atual = l->inicio;
    while (atual != NULL && atual->info != Elem)
    {
        atual = atual->next;
        indice++;
    }
    if (atual == NULL)
    {
        printf("Elemento não encontrado\n");
        return;
    }
    printf("Elemento encontrado na posição %d\n", indice);
}

/* ---------------------------------- Functions Lista duplamente encadeada */
void init_Dlista(Dlista* lista){
	lista->tamanho = 0;
	lista->inicio = NULL;
	lista->fim = NULL;
}

void showDlista(Dlista* lista){
	if (lista->inicio == NULL) {
        printf("Lista vazia\n");
        return;
    }
    
    Nodu* atual = lista->inicio;
    printf("Lista: [");
    while (atual != NULL) {
        printf("%d", atual->info);
        
        atual = atual->next;
        if (atual != NULL) {
            printf(", ");
        }
    }
    printf("]\n");
}

void insDlista(Dlista* lista, int Elem){
	if (lista->tamanho >= MAX) {
        printf("Erro: Lista cheia\n");
        return;
    }
	
	Nodu* novoNo = (Nodu*)malloc(sizeof(Nodu));
    if (novoNo == NULL) {
        printf("Erro: Falha na aloca��o de mem�ria\n");
        return;
    }

    novoNo->info = Elem;
    if (lista->inicio == NULL) {
    	novoNo->next = NULL;
    	novoNo->prev = NULL;
        // Se a lista estiver vazia, o novo n� ser� o primeiro e o �ltimo
        lista->inicio = novoNo;
        lista->fim = novoNo;
        //lista->inicio->next = NULL;
	}else{
		novoNo->next = lista->inicio;
		novoNo->prev = NULL;
    	lista->inicio = novoNo;
	}
        lista->tamanho++;
}

void insFim(Dlista* lista, int Elem){
	if (lista->tamanho >= MAX) {
        printf("Erro: Lista cheia\n");
        return;
    }
    
    Nodu* novoNo = (Nodu*)malloc(sizeof(Nodu));
    if (novoNo == NULL) {
        printf("Erro: Falha na aloca��o de mem�ria\n");
        return;
    }
    novoNo->info = Elem;
    novoNo->next = NULL;
	novoNo->prev = lista->fim;  // Define o pr�ximo como NULL, j� que ser� o �ltimo n�
    
    if (lista->inicio == NULL) {
        // Se a lista estiver vazia, o novo n� ser� o primeiro e o �ltimo
        lista->inicio = novoNo;
        lista->fim = novoNo;
        novoNo->prev = NULL;
    } else {
        // Se a lista n�o estiver vazia, adiciona o novo n� no final
        lista->fim->next = novoNo;
        lista->fim = novoNo;
    }
    
    lista->tamanho++;
}

void ins_Id(Dlista* lista, int id, int Elem){
	    if (id < 0 || id > lista->tamanho) {
        printf("Erro: Posi��o inv�lida\n");
        return;
    }

    if (lista->tamanho >= MAX) {
        printf("Erro: Lista cheia\n");
        return;
    }

    Nodu* novoNo = (Nodu*)malloc(sizeof(Nodu));
    if (novoNo == NULL) {
        printf("Erro: Falha na aloca��o de mem�ria\n");
        return;
    }
    novoNo->info = Elem;

    if (id == 0) {
        // Inser��o no in�cio da lista
        novoNo->next = lista->inicio;
        lista->inicio = novoNo;
        if (lista->fim == NULL) {
            // A lista estava vazia, atualiza o ponteiro fim
            lista->fim = novoNo;
        }
    } else if (id == lista->tamanho) {
        // Inser��o no fim da lista
        novoNo->next = NULL;
        lista->fim->next = novoNo;
        lista->fim = novoNo;
    } else {
        // Inser��o em uma posi��o intermedi�ria
        Nodu* anterior = lista->inicio;
        int i;
        for (i = 0; i < id - 1; i++) {
            anterior = anterior->next;
        }
        novoNo->next = anterior->next;
        anterior->next = novoNo;
    }

    lista->tamanho++;
}

void del_Dlista(Dlista* lista){
	Nodu* atual = lista->inicio;
    while (atual != NULL) {
        Nodu* proximo = atual->next;
        free(atual);
        atual = proximo;
    }
    lista->tamanho = 0;
    lista->inicio = NULL;
    lista->fim = NULL;
}

/* ---------------------------------- Functions StaticStack */
void initPilha(Pilha_* pilha){
	pilha->topo = 0;
}

/// @brief Pushs a element into the stack
/// @param pilha 
/// @param Elem 
void inserir(Pilha_* pilha, int Elem) {
    if (pilha->topo == MAX) {
        printf("Erro: Pilha cheia\n");
        return;
    }

    Nodu* novoNo = (Nodu*)malloc(sizeof(Nodu));
    if (novoNo == NULL) {
        printf("Erro: Falha na aloca��o de mem�ria\n");
        return;
    }

    novoNo->info = Elem;
    novoNo->prev = NULL;
    novoNo->next = NULL;

    pilha->info[pilha->topo] = novoNo;

    if (pilha->topo > 0) {
        pilha->info[pilha->topo]->prev = pilha->info[pilha->topo - 1];
        pilha->info[pilha->topo - 1]->next = pilha->info[pilha->topo];
    }

    pilha->topo++;
}

int pop(Pilha_* pilha){
    if (pilha->topo == 0) {
        printf("Erro: Pilha vazia\n");
        return 0; // Ou algum valor de erro adequado
    }

    pilha->topo--;
    int valor = pilha->info[pilha->topo]->info;

    // Remover refer�ncias ao n� desempilhado
    pilha->info[pilha->topo]->prev = NULL;
    pilha->info[pilha->topo]->next = NULL;

    return valor;
}

void delPilha(Pilha_* pilha){
	if (pilha->topo == 0) {
        printf("Erro: Pilha vazia\n");
        return;
    }

    pilha->topo--;
    free(pilha->info[pilha->topo]);
    pilha->info[pilha->topo] = NULL;

}

void showPilha(Pilha_* pilha) {
    if (pilha->topo == 0) {
        printf("Pilha vazia\n");
        return;
    }

    Nodu* atual = pilha->info[pilha->topo - 1];
    printf("Pilha: [");
    while (atual != NULL) {
        printf("%d", atual->info);

        atual = atual->prev;
        if (atual != NULL) {
            printf(", ");
        }
    }
    printf("]\n");
}


/* ------------------------------------------- Functions dinamicStack ### */
void initPilhaDim(Pilha_dim* pilha){
	pilha->topo = 0;
	pilha->info = NULL;
}

void addElem(Pilha_dim* pilha, int Elem){
    Nodu* novoNo = (Nodu*)malloc(sizeof(Nodu));
    if (novoNo == NULL) {
        printf("Erro: Falha na aloca��o de mem�ria\n");
        return;
    }

    novoNo->info = Elem;
    novoNo->prev = NULL;
    novoNo->next = NULL;
    
    if (pilha->topo > 0) {
      novoNo->prev = pilha->info;
      pilha->info = novoNo;
    }
	pilha->info = novoNo;
    pilha->topo++;
}

int popElem(Pilha_dim* pilha){
	if (pilha->topo == 0) {
        printf("Erro: Pilha vazia\n");
        return 0; // Ou algum valor de erro adequado
    }
    
    Nodu* no_desempilhado = pilha->info;
    pilha->info = no_desempilhado->prev; // Atualiza o ponteiro para o pr�ximo n�
    int valor = no_desempilhado->info;

    free(no_desempilhado); // Libera a mem�ria do n� desempilhado
    
    pilha->topo--;
    
    return valor;
}

void delPilhaDim(Pilha_dim* pilha){
	if (pilha->topo == 0) {
        printf("Erro: Pilha vazia\n");
    	return; // Ou algum valor de erro adequado
    }
    
    pilha->topo--;
    free(pilha->info);
    pilha->info = NULL;
    
}

void showPD(Pilha_dim* pilha){
	if (pilha->topo == 0) {
        printf("Pilha vazia\n");
        return;
    }

    Nodu* atual = pilha->info;
    printf("Pilha: [");
    while (atual != NULL) {
        printf("%d", atual->info);

        atual = atual->prev;
        if (atual != NULL) {
            printf(", ");
        }
    }
    printf("]\n");
}


/* --------------------------------------------- Functions Fila(Queue)*/
void initFila(Fila* f){
	f->inicio = NULL;
	f->fim = NULL;
	f->tamanho = 0;

}

void filaAdd(Fila* f, int Elem){
    if (f->tamanho >= MAX) {
        printf("Erro: Lista cheia\n");
        return;
    }
	
	Nodu* novoNo = (Nodu*)malloc(sizeof(Nodu));
    if (novoNo == NULL) {
        printf("Erro: Falha na aloca��o de mem�ria\n");
        return;
    }

    novoNo->info = Elem;
    if (f->inicio == NULL) {
    	novoNo->next = NULL;
        // Se a fila estiver vazia, o novo n� ser� o primeiro e o �ltimo
        f->inicio = novoNo;
        f->fim = novoNo;
        //lista->inicio->next = NULL;
	}else{
		novoNo->prev = f->fim;
		f->fim->next = novoNo;
		f->fim = novoNo;
	}
        f->tamanho++;
}

int popFila(Fila* f){
	if (f->tamanho >= MAX) {
        printf("Erro: Lista cheia\n");
        return 0;
    }
    
    Nodu* retirado = f->inicio;
    int valor = retirado->info;

    if (f->tamanho == 1) {
        // Se h� apenas um elemento na fila, atualiza os ponteiros de in�cio e fim para NULL
        f->inicio = NULL;
        f->fim = NULL;
    } else {
        // Atualiza o ponteiro de in�cio para o pr�ximo n� da fila
        f->inicio = retirado->next;
        f->inicio->prev = NULL;
    }

    free(retirado);
    f->tamanho--;

    return valor;
}

int peekFila(Fila* f) {
    if (f->inicio == NULL) {
        printf("Erro: Fila vazia\n");
        return -1; // Ou algum valor de erro adequado
    }

    return f->inicio->info;
}

int sizeFila(Fila* f){
	
	if (f->tamanho == 0) {
        printf("Erro: Fila vazia\n");
        return 0;
    }
    //int tam = f->tamanho;
    return f->tamanho;
}

void delFila(Fila* f){
	Nodu* atual = f->inicio;
    while (atual != NULL) {
        Nodu* proximo = atual->next;
        free(atual);
        atual = proximo;
    }
    f->tamanho = 0;
    f->inicio = NULL;
    f->fim = NULL;
}

void showFila(Fila* f){
	if (f->inicio == NULL) {
        printf("Fila vazia\n");
        return;
    }
    
    Nodu* atual = f->inicio;
    printf("Fila: [");
    while (atual != NULL) {
        printf("%d", atual->info);
        
        atual = atual->next;
        if (atual != NULL) {
            printf(", ");
        }
    }
    printf("]\n");
}


/* ------------------------------------------- Functions Deque ### */
void initDeque(Deque* d){
	d->tamanho =0;
	d->inicio = NULL;
	d->fim = NULL;
}

void showDeque(Deque* d){
	if (d->inicio == NULL) {
        printf("Lista vazia\n");
        return;
    }
    
    Nodu* atual = d->inicio;
    printf("Deque: [");
    while (atual != NULL) {
        printf("%d", atual->info);
        
        atual = atual->next;
        if (atual != NULL) {
            printf(", ");
        }
    }
    printf("]\n");
}

void insBegin(Deque* d, int Elem){
	if (d->tamanho >= MAX) {
        printf("Erro: Lista cheia\n");
        return;
    }
	
	Nodu* novoNo = (Nodu*)malloc(sizeof(Nodu));
    if (novoNo == NULL) {
        printf("Erro: Falha na aloca��o de mem�ria\n");
        return;
    }

    novoNo->info = Elem;
    if (d->inicio == NULL) {
    	novoNo->next = NULL;
    	novoNo->prev = NULL;
        // Se o deque estiver vazia, o novo n� ser� o primeiro e o �ltimo
        d->inicio = novoNo;
        d->fim = novoNo;
	}else{
		novoNo->next = d->inicio;
		novoNo->prev = NULL;
    	d->inicio->prev = novoNo;
    	d->inicio = novoNo;
	}
    d->tamanho++;
}

void insEnd(Deque* d, int Elem){
	if (d->tamanho >= MAX) {
        printf("Erro: Lista cheia\n");
        return;
    }
    
    Nodu* novoNo = (Nodu*)malloc(sizeof(Nodu));
    if (novoNo == NULL) {
        printf("Erro: Falha na aloca��o de mem�ria\n");
        return;
    }
    novoNo->info = Elem;
    novoNo->next = NULL;
	novoNo->prev = d->fim;  // Define o pr�ximo como NULL, j� que ser� o �ltimo n�
    
    if (d->inicio == NULL) {
        // Se a lista estiver vazia, o novo n� ser� o primeiro e o �ltimo
        d->inicio = novoNo;
        d->fim = novoNo;
        novoNo->prev = NULL;
    } else {
        // Se a lista n�o estiver vazia, adiciona o novo n� no final
        d->fim->next = novoNo;
        d->fim = novoNo;
    }
    
    d->tamanho++;
}

int getBegin(Deque* d){
	if(d->tamanho == 0){
		printf("Deque vazio");
		return 0;
	}
	return d->inicio->info;
}

int getEnd(Deque* d){
	if(d->tamanho == 0){
		printf("Deque vazio");
		return 0;
	}
	return d->fim->info;
}

int sizeDeque(Deque* d){
	if(d->tamanho == 0){
		printf("Deque vazio");
		return 0;
	}
	return d->tamanho;
}

void del_Deque(Deque* d){
	Nodu* atual = d->inicio;
    while (atual != NULL) {
        Nodu* proximo = atual->next;
        free(atual);
        atual = proximo;
    }
    d->tamanho = 0;
    d->inicio = NULL;
    d->fim = NULL;
}

void delBegin(Deque* d){
	if (d->tamanho == 0) {
        printf("Erro: Deque vazio\n");
        return; // Ou algum valor de erro adequado
    }
    
    Nodu* removido = d->inicio;
    
    if (d->tamanho == 1) {
        d->inicio = NULL;
        d->fim = NULL;
    } else {
        d->inicio = removido->next;
        d->inicio->prev = NULL;
    }
    
    free(removido);
    d->tamanho--;
    
}

void delEnd(Deque* d){
    if (d->tamanho == 0) {
        printf("Erro: Deque vazio\n");
        return;
    }

    Nodu* aux = d->fim;
    d->fim = d->fim->prev;
    if (d->fim == NULL) {  // Se o deque ficar vazio ap�s a remo��o
        d->inicio = NULL;
    } else {
        d->fim->next = NULL;
    }

    free(aux);
    d->tamanho--;
}


/* ----------------------------------- Functions Conjunto(SET) ### */
void initSet(set_* set){
	set->tamanho = 0;
	set->inicio = NULL;
	set->fim = NULL;
}

void delSet(set_* set){
    Nod* atual = set->inicio;
    while (atual != NULL) {
        Nod* proximo = atual->next;
        free(atual);
        atual = proximo;
    }
    set->inicio = NULL;
    set->fim = NULL;
    set->tamanho = 0;
}

void showSet(set_* set){
	if (set->inicio == NULL) {
        printf("Lista vazia\n");
        return;
    }
    
    Nod* atual = set->inicio;
    printf("{");
    while (atual != NULL) {
        printf("%d", atual->info);
        
        atual = atual->next;
        if (atual != NULL) {
            printf(", ");
        }
    }
    printf("}\n");
}

void insertSet(set_* set, int Elem){
    //verificar se elemento a ser inserido ja esta no conjunto
	Nod* atual = set->inicio;
	while (atual != NULL) {
    	if(Elem == atual->info){
        	printf("Erro: Set ja Contem este Elemento: %d\n", atual->info);
        	return;    		
		}
    
    	atual = atual->next;
    	if (atual != NULL) {
        	continue;
    	} else{
    		break;
		}
    	
	}
		
	Nod* novoNo = (Nod*)malloc(sizeof(Nod));	
	if (set->tamanho >= MAX) {
        printf("Erro: Set cheio Elementos: %d\n", set->tamanho);
        return;
    }
    if (novoNo == NULL) {
        printf("Erro: Falha na aloca��o de mem�ria\n");
        return;
    }
    


    novoNo->info = Elem;
    novoNo->next = NULL;
    
	if (set->inicio == NULL) {
        // Se a lista estiver vazia, o novo n� ser� o primeiro e o �ltimo
        set->inicio = novoNo;
        set->fim = novoNo;
        //lista->inicio->next = NULL;
	}else{
		set->fim->next = novoNo;
		set->fim = novoNo;
	}
        set->tamanho++;	
}

void setIndexRemove(set_* set, int Elem){
	Nod* atual = set->inicio;
    Nod* anterior = NULL;

    while (atual != NULL) {
        if (atual->info == Elem) {
            if (anterior == NULL) {
                set->inicio = atual->next;
            } else {
                anterior->next = atual->next;
            }

            if (atual == set->fim) {
                set->fim = anterior;
            }

            free(atual);
            set->tamanho--;
            return;
        }

        anterior = atual;
        atual = atual->next;
    }
}

set_ set_union(set_* set1, set_* set2) {
    set_ uniao;
	initSet(&uniao);
    if(set1->tamanho == 0){
    	printf("Set do parametro esta vazio!\n");
    	return uniao;
	}
	if(set2->tamanho == 0){
		printf("Set do parametro 2 esta vazio!\n");
		return uniao;
	}
	
	Nod* atual = set1->inicio;
	Nod* atual2 = set2->inicio;
	
    while (atual != NULL) {
        insertSet(&uniao, atual->info);
        atual = atual->next;
    }
    
    while (atual2 != NULL) {
        if (!set_isMember(set1, atual2->info)) {
            insertSet(&uniao, atual2->info);
        }
        atual2 = atual2->next;
    }
	
	return uniao;
}

set_ set_intersec(set_* set1, set_* set2) {
    set_ inter;
    initSet(&inter);

    if (set1->tamanho == 0 || set2->tamanho == 0) {
        return inter;
    }

    Nod* atual = set1->inicio;

    while (atual != NULL) {
        if (set_isMember(set2, atual->info)) {
            insertSet(&inter, atual->info);
        }
        atual = atual->next;
    }
    return inter;
}

set_ set_diferenca(set_* set1, set_* set2) {
    set_ diferenca;
    initSet(&diferenca);

    if (set1->tamanho == 0) {
        return diferenca;
    }

    Nod* atual = set1->inicio;

    while (atual != NULL) {
        if (!set_isMember(set2, atual->info)) {
            insertSet(&diferenca, atual->info);
        }
        atual = atual->next;
    }
    return diferenca;
}

int set_isMember(set_* set, int Elem) {
    Nod* atual = set->inicio;
    while (atual != NULL) {
        if (atual->info == Elem) {
            return 1; // O elemento est� presente no conjunto
        }
        atual = atual->next;
    }
    return 0; // O elemento n�o est� presente no conjunto
}

// Verifica se set1 é subconjunto de set2
int set_isSubset(set_* set1, set_* set2) {
    Nod* atual = set1->inicio;
    while (atual != NULL) {
        if (!set_isMember(set2, atual->info)) {
            return 0; // Elemento do set1 n�o est� presente no set2, portanto, set1 n�o � um subconjunto de set2
        }
        atual = atual->next;
    }
    return 1; // Todos os elementos de set1 est�o presentes em set2, portanto, set1 � um subconjunto de set2
}

int set_isEqual(set_* set1, set_* set2) {
    if (set1->tamanho != set2->tamanho) {
        return 0; // Os conjuntos t�m tamanhos diferentes, portanto, n�o s�o iguais
    }
    return set_isSubset(set1, set2) && set_isSubset(set2, set1);
}

int set_size(set_* set) {
    return set->tamanho;
}

// Fun��o para cobertura de conjuntos (cobrir todos os elementos em uma �nica cole��o de conjunto)
// void set_ *set_cover(set_* set1, int tamanho_conjunto, int subconjuntos[][5], int quantidade_subconjuntos) {
//     bool cobertura_conjuntos(int conjunto[], int tamanho_conjunto, int subconjuntos[][5], int quantidade_subconjuntos) {
//         // Implementa��o da fun��o cobertura_conjuntos

//         return true;
//     }

//     void combinacoes(int subconjuntos[][5], int quantidade_subconjuntos, int k, int indice_atual, int combinacao_atual[][5], int indice_combinacao, int conjunto[], int tamanho_conjunto, set_* resultado) {
//         if (indice_combinacao == k) {
//             if (cobertura_conjuntos(conjunto, tamanho_conjunto, combinacao_atual, k)) {
//                 // Criar um novo conjunto e adicionar o conjunto atual a ele
//                 set_* novo_conjunto = malloc(sizeof(set_));
//                 novo_conjunto->tamanho = k;
//                 novo_conjunto->inicio = NULL;
//                 novo_conjunto->fim = NULL;
//                 for (int i = 0; i < k; i++) {
//                     Nod* novo_nod = malloc(sizeof(Nod));
//                     novo_nod->info = combinacao_atual[i][0];
//                     novo_nod->next = NULL;
//                     if (novo_conjunto->inicio == NULL) {
//                         novo_conjunto->inicio = novo_nod;
//                         novo_conjunto->fim = novo_nod;
//                     } else {
//                         novo_conjunto->fim->next = novo_nod;
//                         novo_conjunto->fim = novo_nod;
//                     }
//                 }
//                 // Adicionar o novo conjunto ao resultado
//                 if (resultado->inicio == NULL) {
//                     resultado->inicio = novo_conjunto;
//                     resultado->fim = novo_conjunto;
//                 } else {
//                     resultado->fim->next = novo_conjunto;
//                     resultado->fim = novo_conjunto;
//                 }
//             }
//             return;
//         }

//         if (indice_atual >= quantidade_subconjuntos) {
//             return;
//         }
        
//         for (int i = indice_atual; i < quantidade_subconjuntos; i++) {
//             for (int j = 0; j < 5; j++) {
//                 combinacao_atual[indice_combinacao][j] = subconjuntos[i][j];
//             }
//             combinacoes(subconjuntos, quantidade_subconjuntos, k, i + 1, combinacao_atual, indice_combinacao + 1, conjunto, tamanho_conjunto, resultado);
//         }
//     }
    
//     set_* resultado = malloc(sizeof(set_));
//     resultado->tamanho = 0;
//     resultado->inicio = NULL;
//     resultado->fim = NULL;

//     int combinacao_atual[quantidade_subconjuntos][5];
    
//     for (int k = 1; k <= quantidade_subconjuntos; k++) {
//         combinacoes(subconjuntos, quantidade_subconjuntos, k, 0, combinacao_atual, 0, set1->conjunto, tamanho_conjunto, resultado);
//     }
    
//     return resultado;
// }

/*void set_cover(set_** sets, int numSets, set_* result) {
    // Implemente a l�gica para realizar a cobertura dos conjuntos
}*/





