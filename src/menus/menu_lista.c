#include <utils.h>
#include <dstruct.h>
#include <lista.h>

void menuListaOperations(){
    int indice = 0; 
    int valor = 0; 
    Lista l1;
    // Lista l2;
    init_Lista(&l1);
    // init_Lista(&l2);
    Lista listas[MAX_STRUCTS];
    listas[0] = l1;
	// listas[1] = l2;
    listas->tamanho = 2;

    int i;
    for(i=1; i<MAX_STRUCTS;i++){
        listas[i].tamanho = 0;
        listas[i].inicio = NULL;
        listas[i].fim = NULL;    
    }
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

    while(1){
        printf("<dstruct>:[\x1b[34mListas\x1b[0m]$ ");
        // scanf("%6s", op);
        if(scanf("%s", structOption) != 1){
            printf("Opção inválida! Tente novamente.\n");
            while (getchar() != '\n'); 
            continue;
        }
        switch (getStructOperation(structOption)) {
            case OP_S:
            delListas(listas);
                return;
            case OP_ADD:
                //printf("Digite um numero: ");
                scanf("%d", &indice); //indice
                scanf("%d", &valor); // valor
                getchar();  // Consumir o caractere de nova linha pendente
                insereFim(&listas[indice], valor);
                showLista(&listas[indice]);
                break;
            case OP_SHOW:
                for (i = 0; i < MAX_STRUCTS; i++) {
                    // if(listas[0].inicio == NULL && listas[1].inicio == NULL){
                    //      printf("Erro: Nao ha nenhum conjunto criado.");
                    //      break;
                    // }
                    if(listas[i].inicio == NULL){
                        continue;
                    }
                    printf("L%d: ", i);
                    showLista(&listas[i]);
        
                }
                break;
            case OP_DEL1:
                scanf("%d", &indice); //indice
                scanf("%d", &valor); // valor
                deletElem(&listas[indice], valor);
                showLista(&listas[0]);
                break;
            case OP_DELSET:
                scanf("%d", &indice);
                delLista(&listas[indice]);
                printf("Lista apagada!");
                break;
            case OP_DEL:
                int j;
                for(j=0; j<=MAX_STRUCTS; j++){
                    if(listas[j].inicio != NULL){
                        delLista(&listas[j]);
                    }
                }
                printf("Todas as Listas foram apagadas");
                break;
            case OP_FIND:
                scanf("%d", &indice); //indice
                scanf("%d", &valor); // valor
                findElem(&listas[indice], valor);
                break;
            case OP_INFO:
                printf("\t Tamanho array de listas %d \n", MAX_STRUCTS);
                printf("\t Quantidade de listas criadas %d\n", listas->tamanho);
                // system("clear");
                break;
            default:
                printf("Opção inválida! Digite novamente.\n");
                break;
        }
        
    }
    
}