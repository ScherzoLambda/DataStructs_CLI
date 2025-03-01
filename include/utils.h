#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dstruct.h>


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

void welcomeSaudation();
void menu();
void menuListaOperations();
void menuPilhaOperations();
void menuDequeOperations();
void menuSetOperations();

char structOption[7]; //operations for structures
int num, num1 = 0;    // indice e valor

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

void menuListaOperations(){
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
    printf(" 'new' <n lista> <item> \t adiciona nova lista.\n");
    printf(" 'add' <n lista> <item> \t adiciona item.\n");
    printf(" 'del1' <n lista> <item> \t deleta item lista(1).\n");
    printf(" 'dellist' <n lista> deleta lista de acordo com seu índice.\n");
    printf(" 'find' verifica se uma lista contém o item.\n");
    printf(" 'show' Exibe todos as Listas.\n");
    printf(" 'del' deleta todos as Listas.\n");
    printf(" 'quit' volta menu de estruturas.\n");
    printf(" 'info' informações sobre esse Playground.\n");

    while(1){
        printf("\n<dstruct>:[\x1b[34mListas\x1b[0m]$ ");
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
                scanf("%d", &num); //indice
                scanf("%d", &num1); // valor
                getchar();  // Consumir o caractere de nova linha pendente
                insereFim(&listas[num], num1);
                showLista(&listas[num]);
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
                scanf("%d", &num); //indice
                scanf("%d", &num1); // valor
                deletElem(&listas[num], num1);
                showLista(&listas[0]);
                break;
            case OP_DELSET:
                scanf("%d", &num);
                delLista(&listas[num]);
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
                scanf("%d", &num); //indice
                scanf("%d", &num1); // valor
                findElem(&listas[num], num1);
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

void menuPilhaOperations(){
    Pilha_ p1;
    Pilha_ p2;
    initPilha(&p1);
    initPilha(&p2);
    Pilha_ pilhas[MAX_STRUCTS];
    pilhas[0] = p1;
    pilhas[1] = p2;

    int i;
    for(i=2; i<MAX_STRUCTS;i++){
        pilhas[i].topo = 0;
        // pilhas[i].info = NULL;
    }
    printf("Playground Pilhas\n");
    printf("'new' cria nova pilha.\n");
    printf("'add' adiciona item na pilha1. \n'add2' adiciona item na pilha2 .\n'del1' deleta item pilha1.\n'del2' deleta item pilha2.\n'delStack' deleta pilha especifica.\n");
    printf("'find' verifica se um pilha contem o item.\n");
    printf("'show' exibe todas as pilhas.\n");
    printf("'del' deleta todas pilhas.\n");

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
            case OP_ASET:
                Pilha_ newPilha;
                initPilha(&newPilha);
                pilhas[pilhas->topo] = newPilha;
                pilhas->topo++;
                break;
            case OP_ADD:
                printf("Digite um numero: ");
                scanf("%d", &num);
                getchar();  // Consumir o caractere de nova linha pendente
                inserir(&pilhas[0], num);
                showPilha(&pilhas[0]);
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
    printf("Playground Deques\n");
    printf("'aset' adiciona novo set.\n'uni' uniao de set.\n");
    printf("'add' adiciona item no set1 .\n'add2' adiciona item no set2 .\n'del1' deleta item set1.\n'del2' deleta item set2.\n'delset' deleta set especifico.\n");
    printf("'mbset' verifica se um set contem o item.\n");
    printf("'show' Lista todos os Conjuntos.\n");
    printf("'del' deleta todos os Conjuntos.\n");
}

void menuSetOperations(){
    set_ d1;
	set_ s1;
	initSet(&s1);
	initSet(&d1);
	set_ conjuntos[MAX_STRUCTS];
	conjuntos[0] = d1;
	conjuntos [1] = s1;

    int i;
    for(i=2; i<MAX_STRUCTS;i++){
        conjuntos[i].tamanho = 0;
        conjuntos[i].inicio = NULL;
        conjuntos[i].fim = NULL;    
    }
    printf("Playground Conjuntos(Set)\n");
    printf("'aset' adiciona novo set.\n'uni' uniao de set.\n");
    printf("'add' adiciona item no set1 .\n'add2' adiciona item no set2 .\n'del1' deleta item set1.\n'del2' deleta item set2.\n'delset' deleta set especifico.\n");
    printf("'mbset' verifica se um set contem o item.\n");
	printf("'show' Lista todos os Conjuntos.\n");
    printf("'del' deleta todos os Conjuntos.\n");
    
    while (1) {
        printf("\nDigite uma opcao: ");
        scanf("%6s", structOption);
        
        if (strcmp(structOption, "s") == 0) {
            // Op��o 's' para finalizar o programa
            break;
        }else if(strcmp(structOption, "aset") == 0){
            set_ novoSet;
            initSet(&novoSet);
            int k;
			for(k=2; k<MAX_STRUCTS;k++){
                if(conjuntos[k].inicio == NULL){
                    conjuntos[k] = novoSet;
                    break;
                }else{
                    continue;
                }
            }
        } else if(strcmp(structOption, "add") == 0){
            printf("Digite um numero: ");
            scanf("%d", &num);
            getchar();  // Consumir o caractere de nova linha pendente
            insertSet(&conjuntos[0], num);
            showSet(&conjuntos[0]);            
        } else if(strcmp(structOption, "add2") == 0){
            printf("Digite um numero: ");
            scanf("%d", &num);
            getchar();  // Consumir o caractere de nova linha pendente
            insertSet(&conjuntos[1], num);
            showSet(&conjuntos[1]);
        }  else if(strcmp(structOption, "show") == 0){
            for (i = 0; i < MAX_STRUCTS; i++) {
                if(conjuntos[0].inicio == NULL && conjuntos[1].inicio == NULL){
                	printf("Erro: Nao ha nenhum conjunto criado.");
                	break;
            	}else{
            		if(conjuntos[i].inicio == NULL){
            			continue;
					}
					printf("C%d: ", i);
                	showSet(&conjuntos[i]);
				}
				
    		}
        } else if(strcmp(structOption, "del1") == 0){
        	printf("Digite a posicao do item: ");
            scanf("%d", &num);
            setIndexRemove(&conjuntos[0], num);
            showSet(&conjuntos[0]);            
        } else if(strcmp(structOption, "del2") == 0){
        	printf("Digite a posicao do item: ");
            scanf("%d", &num);
            setIndexRemove(&conjuntos[1], num);
            showSet(&conjuntos[1]);            
        } else if(strcmp(structOption, "delset") == 0){
        	printf("Digite a posicao do set: ");
            scanf("%d", &num);
            delSet(&conjuntos[num]);
            printf("Set apagado!");            
        } else if(strcmp(structOption, "del") == 0){
            int l;
			for(l=0; l<=MAX_STRUCTS; l++){
                if(conjuntos[l].inicio != NULL){
                    delSet(&conjuntos[l]);
                }
            }
            printf("Todos os Conjuntos foram apagados");
        } else if(strcmp(structOption, "uni") == 0){
            printf("posicao set 1: ");
            scanf("%d", &num);
            getchar();  // Consumir o caractere de nova linha pendente
            printf("posicao set 2: ");
            scanf("%d", &num1);
            getchar();
            if(conjuntos->tamanho == 2){}
			set_ uniresultado = set_union(&conjuntos[num], &conjuntos[num1]);
			showSet(&uniresultado);          
        } else if(strcmp(structOption, "inter") == 0){
            printf("posicao set 1: ");
            scanf("%d", &num);
            getchar();  // Consumir o caractere de nova linha pendente
            printf("posicao set 2: ");
            scanf("%d", &num1);
            getchar();
			set_ interresultado = set_intersec(&conjuntos[num], &conjuntos[num1]);
			if(interresultado.inicio != NULL){
				showSet(&interresultado);
			}else{
				printf("Intersecao vazia {}");
			} 
			          
        } else if(strcmp(structOption, "diff") == 0){
            printf("posicao set 1: ");
            scanf("%d", &num);
            getchar();  // Consumir o caractere de nova linha pendente
            printf("posicao set 2: ");
            scanf("%d", &num1);
            getchar();
			set_ valor = set_diferenca(&conjuntos[num], &conjuntos[num1]);
			//valor->inicio = set_differenca(&conjuntos[num], &conjuntos[num1]);
	
			if(valor.inicio != NULL){
				showSet(&valor);
			}else{
				printf("Diferenca vazia {}");
			} 	          
        } else if(strcmp(structOption, "mbset") == 0){
            printf("posicao set 1: ");
            scanf("%d", &num);
            getchar();  // Consumir o caractere de nova linha pendente
            printf("item verificado: ");
            scanf("%d", &num1);
            getchar();
			int val = set_isMember(&conjuntos[num], num1);
			if(val){
				printf("Valor esta no set");
			}else{
				printf("Valor nao esta no set");
			}          
        }else if(strcmp(structOption, "cover") == 0){
            printf("posicao set 1: ");
            scanf("%d", &num);
            getchar();  // Consumir o caractere de nova linha pendente
            printf("item verificado: ");
            scanf("%d", &num1);
            getchar();
			int val = set_isMember(&conjuntos[num], num1);
			if(val){
				printf("Valor esta no set");
			}else{
				printf("Valor nao esta no set");
			}          
        }
		else{
            printf("Op��o inv�lida! Digite novamente.\n");            
        }
	}
}