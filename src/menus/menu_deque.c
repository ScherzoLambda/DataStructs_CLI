#include <deque.h>
#include <utils.h>

void comandosDeque(){
    printf("Playground Deques\n");
    printf("'aset' adiciona novo set.\n'uni' uniao de set.\n");
    printf("'add' adiciona item no set1 .\n'add2' adiciona item no set2 .\n'del1' deleta item set1.\n'del2' deleta item set2.\n'delset' deleta set especifico.\n");
    printf("'mbset' verifica se um set contem o item.\n");
    printf("'show' Lista todos os Conjuntos.\n");
    printf("'del' deleta todos os Conjuntos.\n");
}

void menuDequeOperations(){
    Deque d1;
    Deque d2;
    initDeque(&d1);
    initDeque(&d2);
    Deque deques[MAX_STRUCTS];
    deques[0] = d1;
    deques[1] = d2;

    int i;
    for(i=2; i<MAX_STRUCTS;i++){
        deques[i].tamanho = 0;
        deques[i].inicio = NULL;
        deques[i].fim = NULL;
    }
    comandosDeque();
}

