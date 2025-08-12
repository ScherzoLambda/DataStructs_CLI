#include <fila.h>

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
