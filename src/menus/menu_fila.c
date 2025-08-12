#include <fila.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <utils.h>
#include <fila.h>

void comandosFila(){
    printf("Playground Listas\n");
    printf(" 'new' <id lista> <item> \t adiciona nova lista.\n");
    printf(" 'add' <id lista> <item> \t adiciona item.\n");
    printf(" 'del1' <id lista> <item> \t deleta item lista(1).\n");
    printf(" 'dellist' <n lista> deleta lista de acordo com seu índice.\n");
    printf(" 'find' verifica se uma lista contém o item.\n");
    printf(" 'show' Exibe todos as Listas.\n");
    printf(" 'del' deleta todos as Listas.\n");
    printf(" 'quit' volta menu de estruturas.\n");
    printf(" 'info' informações sobre esse Playground.\n");
}

void menuFilaOperations(){
    int indice = 0; 
    int valor = 0; 
    Fila f1;

    initFila(&f1);

    Fila filas[MAX_STRUCTS];
    filas[0] = f1;

    int i;
    for(i=1; i<MAX_STRUCTS;i++){
        filas[i].tamanho = 0;
        filas[i].inicio = NULL;
        filas[i].fim = NULL;    
    }
    comandosFila();

    while(1){
        printf("<dstruct>:[\x1b[34mListas\x1b[0m]$ ");

        if(scanf("%s", structOption) != 1){
            printf("Opção inválida! Tente novamente.\n");
            while (getchar() != '\n'); 
            continue;
        }
        switch (getStructOperation(structOption)) {
            case OP_S:
            delFila(filas);
                return;
            case OP_ADD:
                //printf("Digite um numero: ");
                scanf("%d", &indice); //indice
                scanf("%d", &valor); // valor
                getchar();  // Consumir o caractere de nova linha pendente
                // TODO: fazer do jeito certo
                break;
            case OP_SHOW:
                for (i = 0; i < MAX_STRUCTS; i++) {

                    if(filas[i].inicio == NULL){
                        continue;
                    }
                    printf("F%d: ", i);
                    showFila(&filas[i]);
        
                }
                break;
            case OP_DEL1:
                scanf("%d", &indice); //indice
                scanf("%d", &valor); // valor
                // deletElem(&filas[indice], valor);
                // showFila(&filas[0]);
                break;
            case OP_DELSET:
                scanf("%d", &indice);
                delFila(&filas[indice]);
                printf("Fila apagada!");
                break;
            case OP_DEL:
                int j;
                for(j=0; j<=MAX_STRUCTS; j++){
                    if(filas[j].inicio != NULL){
                        delFila(&filas[j]);
                    }
                }
                printf("Todas as Filas foram apagadas");
                break;
            case OP_INFO:
                printf("\t Tamanho array de filas %d \n", MAX_STRUCTS);
                printf("\t Quantidade de filas criadas %d\n", filas->tamanho);
                // system("clear");
                break;
            default:
                printf("Opção inválida! Digite novamente.\n");
                break;
        }
        
    }
    
}