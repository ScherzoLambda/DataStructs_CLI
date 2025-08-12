#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define MAX_STRUCTS 20
#define MAX_HISTORY 50

/// @brief Enum type to represent the options of the menu.
/// maps the name of structs to a number.
typedef enum {
    UNKNOW_COMMAND = -1,
    LISTA_LIGADA = 0,
    LISTA_DUPLAMENTE_LIGADA,
    PILHA_DINAMICA,
    PILHA_ESTATICA,
    FILA_DINAMICA,
    FILA_DE_PRIORIDADES,
    DEQUE,
    SET,
    HASH_TABLE,
    CHAINED_HASH_TABLE,
    HEAP,
    BINARY_TREE,
    GRAPH,
    SAIR,
    HELP_MENU
} MenuOption;

typedef enum {
    OP_INVALID = -1,
    OP_S,
    OP_ASET,
    OP_ADD,
    OP_FIND,
    OP_SHOW,
    OP_DEL1,
    OP_DEL2,
    OP_DELSET,
    OP_DEL,
    OP_UNI,
    OP_INTER,
    OP_DIFF,
    OP_MBSET,
    OP_COVER,
    OP_INFO
} StructsOperation;

StructsOperation getStructOperation(const char *op);
MenuOption getMenuOption(const char *op);


void welcomeSaudation();
void menu();
void mainMenu();
void menuListaOperations();
void menuPilhaOperations();
void menuDequeOperations();
void menuSetOperations();
void menuFilaOperations();

extern char structOption[7]; //operations for structures
//int num, num1 = 0;    // indice e valor




