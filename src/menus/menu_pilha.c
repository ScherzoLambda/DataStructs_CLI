#include <utils.h>
#include <pilha.h>

void comandosPilha(){
    printf("Playground Pilhas\n");
    printf("'new' cria nova pilha.\n");
    printf("'add' adiciona item na pilha1. \n'add2' adiciona item na pilha2 .\n'del1' deleta item pilha1.\n'del2' deleta item pilha2.\n'delStack' deleta pilha especifica.\n");
    printf("'find' verifica se um pilha contem o item.\n");
    printf("'show' exibe todas as pilhas.\n");
    printf("'del' deleta todas pilhas.\n");
}

void menuPilhaOperations(){
    Pilha p1;
    Pilha p2;
    initPilha(&p1);
    initPilha(&p2);
    Pilha pilhas[MAX_STRUCTS];
    pilhas[0] = p1;
    pilhas[1] = p2;
    int indice, valor = 0;
    int i;
    for(i=2; i<MAX_STRUCTS;i++){
        pilhas[i].topo = 0;
        // pilhas[i].info = NULL;
    }

    comandosPilha();

    while(1){
        printf("\n<dstruct>:[\x1b[34mPilhas\x1b[0m]$ ");
        // scanf("%4s", op);
        if(scanf("%4s", structOption) != 1){
            printf("Opção inválida! Tente novamente.\n");
            while (getchar() != '\n');
            continue;
        }
        switch (getStructOperation(structOption)) {
            case OP_S:
            return;
            // case OP_ASET:
            //     Pilha newPilha;
            //     initPilha(&newPilha);
            //     pilhas[pilhas->topo] = newPilha;
            //     pilhas->topo++;
            //     break;
            case OP_ADD:
                printf("Digite: <id_pilha> <valor> ");
                scanf("%d", &indice); //indice
                scanf("%d", &valor); 
                getchar();  // Consumir o caractere de nova linha pendente
                inserir(&pilhas[indice], valor);
                showPilha(&pilhas[indice]);
                break;
            case OP_SHOW:
                for (i = 0; i < MAX_STRUCTS; i++) {
                    if(pilhas[0].topo == 0 && pilhas[1].topo == 0){
                        printf("Erro: Nao ha nenhuma pilha criada.");
                        break;
                    }else{
                        if(pilhas[i].topo == 0){
                            continue;
                        }
                        printf("P%d: ", i);
                        showPilha(&pilhas[i]);
                    }
                }
                break;
            case OP_DEL1:

                pop(&pilhas[0]);
                showPilha(&pilhas[0]);
                break;
            default:
                printf("Opção inválida! Digite novamente.\n");
                break;
        }
    }
}
