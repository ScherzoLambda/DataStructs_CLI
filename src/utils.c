
#include <utils.h>

char structOption[7];
StructsOperation getStructOperation(const char *op) {
    if (strcmp(op, "quit") == 0) return OP_S;
    if (strcmp(op, "new") == 0) return OP_ASET;
    if (strcmp(op, "add") == 0) return OP_ADD;
    if (strcmp(op, "find") == 0) return OP_FIND;
    if (strcmp(op, "show") == 0) return OP_SHOW;
    if (strcmp(op, "del1") == 0) return OP_DEL1;
    if (strcmp(op, "del2") == 0) return OP_DEL2;
    if (strcmp(op, "dellist") == 0 ) return OP_DELSET;
    if (strcmp(op, "del") == 0) return OP_DEL;
    if (strcmp(op, "uni") == 0) return OP_UNI;
    if (strcmp(op, "inter") == 0) return OP_INTER;
    if (strcmp(op, "diff") == 0) return OP_DIFF;
    if (strcmp(op, "mbset") == 0) return OP_MBSET;
    if (strcmp(op, "cover") == 0) return OP_COVER;
    if (strcmp(op, "info") == 0) return OP_INFO;
    return OP_INVALID;
}

MenuOption getMenuOption(const char *op) {
    if (strcmp(op, "0") == 0) return LISTA_LIGADA;
    if (strcmp(op, "1") == 0) return LISTA_DUPLAMENTE_LIGADA;
    if (strcmp(op, "2") == 0) return PILHA_DINAMICA;
    if (strcmp(op, "3") == 0) return PILHA_ESTATICA;
    if (strcmp(op, "4") == 0) return FILA_DINAMICA;
    if (strcmp(op, "5") == 0) return FILA_DE_PRIORIDADES;
    if (strcmp(op, "6") == 0) return DEQUE;
    if (strcmp(op, "7") == 0) return SET;
    if (strcmp(op, "8") == 0) return HASH_TABLE;
    if (strcmp(op, "9") == 0) return CHAINED_HASH_TABLE;
    if (strcmp(op, "10") == 0) return HEAP;
    if (strcmp(op, "11") == 0) return BINARY_TREE;
    if (strcmp(op, "12") == 0) return GRAPH;
    if (strcmp(op, "exit") == 0) return SAIR;
    if (strcmp(op, "help") == 0) return HELP_MENU;
    return UNKNOW_COMMAND;
}

void welcomeSaudation(){
    printf("\n\t===========Bem Vindo ao dataStruct===========");
    printf("\nUm programa para interagir e entender o funcionamento de estruturas de dados.");
}

void menu(){
    printf("\n[0] \t Lista ligada   | [1] \t Lista duplamente ligada");
    printf("\n[2] \t Pilha dinamica | [3] \t Pilha estatica");
    printf("\n[4] \t Fila dinamica  | [5] \t Fila de prioridades");
    printf("\n[6] \t Deque          | [7] \t Set");
    printf("\n[8] \t Hash Table     | [9] \t chained hash table");
    printf("\n[10] \t Heap           | [11] \t Binary Tree");
    printf("\n[12] \t Graph");
    printf("\n'exit' finalizar o programa.\n");

}