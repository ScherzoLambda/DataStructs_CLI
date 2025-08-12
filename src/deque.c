#include <deque.h>

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
