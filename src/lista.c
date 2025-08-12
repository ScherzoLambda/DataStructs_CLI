#include <lista.h>


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

void delListas(Lista listas[])
{
    for (int i = 0; i < MAX; i++) {
        delLista(&listas[i]);
    }
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

