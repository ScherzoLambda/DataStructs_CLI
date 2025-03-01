#include <stdio.h>
#include <stdlib.h>
// #include <windows.h>
#include <dstruct.h>
#include <utils.h>
#include <string.h>

// TODO: MAnipulation of history of operations, like an traditional shell
// TODO: Possibility to undo operations
// TODO: Possibility to clear the screen
int main()
{

    char opt_[5];
    welcomeSaudation();
    menu();
    while (1)
    {

        printf("\n<dstruct>:\x1b[34m~\x1b[0m$ ");
        if (scanf("%4s", opt_) != 1)
        {
            printf("Opção inválida! Tente novamente.\n");
            while (getchar() != '\n')
                ;
            continue;
        }
        switch (getMenuOption(opt_))
        {
        case LISTA_LIGADA:
            menuListaOperations();
            break;
        case LISTA_DUPLAMENTE_LIGADA:
            printf("Você escolheu Lista duplamente ligada!\n");
            break;
        case PILHA_DINAMICA:
        case PILHA_ESTATICA:
            menuPilhaOperations();
            break;
        case FILA_DINAMICA:
            printf("Você escolheu Fila dinâmica!\n");
            break;
        case FILA_DE_PRIORIDADES:
            printf("Você escolheu Fila de prioridades!\n");
            break;
        case DEQUE:
            printf("Você escolheu Deque!\n");
            break;
        case SET:
            printf("Você escolheu Set!\n");
            break;
        case HASH_TABLE:
            printf("Você escolheu Hash Table!\n");
            break;
        case CHAINED_HASH_TABLE:
            printf("Você escolheu Chained Hash Table!\n");
            break;
        case HEAP:
            printf("Você escolheu Heap!\n");
            break;
        case BINARY_TREE:
            printf("Você escolheu Binary Tree!\n");
            break;
        case GRAPH:
            printf("Você escolheu Graph!\n");
            break;
        case SAIR: // 13
            return 0;
        case HELP_MENU: // 13
            menu();
            break;
        default:
            printf("Opção inválida! Tente novamente.\n");
        }
    }

    printf("Programa Finalizado.\n");
    return 0;
}
