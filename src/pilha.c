#include <pilha.h>


/* ---------------------------------- Functions StaticStack */
void initPilha(Pilha* pilha){
	pilha->topo = 0;
}

/// @brief Pushs a element into the stack
/// @param pilha
/// @param Elem
void inserir(Pilha* pilha, int Elem) {
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

int pop(Pilha* pilha){
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

void delPilha(Pilha* pilha){
	if (pilha->topo == 0) {
        printf("Erro: Pilha vazia\n");
        return;
    }

    pilha->topo--;
    free(pilha->info[pilha->topo]);
    pilha->info[pilha->topo] = NULL;

}

void showPilha(Pilha* pilha) {
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
