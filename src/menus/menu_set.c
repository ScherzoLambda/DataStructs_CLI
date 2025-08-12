
#include <utils.h>
#include <conjunto.h>


void menuSetOperations(){
    set_ d1;
	set_ s1;
	initSet(&s1);
	initSet(&d1);
	set_ conjuntos[MAX_STRUCTS];
	conjuntos[0] = d1;
	conjuntos [1] = s1;
    int indice, valor = 0;
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
            scanf("%d", &indice);
            getchar();  // Consumir o caractere de nova linha pendente
            insertSet(&conjuntos[0], indice);
            showSet(&conjuntos[0]);
        } else if(strcmp(structOption, "add2") == 0){
            printf("Digite um numero: ");
            scanf("%d", &indice);
            getchar();  // Consumir o caractere de nova linha pendente
            insertSet(&conjuntos[1], indice);
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
            scanf("%d", &indice);
            setIndexRemove(&conjuntos[0], indice);
            showSet(&conjuntos[0]);
        } else if(strcmp(structOption, "del2") == 0){
        	printf("Digite a posicao do item: ");
            scanf("%d", &indice);
            setIndexRemove(&conjuntos[1], indice);
            showSet(&conjuntos[1]);
        } else if(strcmp(structOption, "delset") == 0){
        	printf("Digite a posicao do set: ");
            scanf("%d", &indice);
            delSet(&conjuntos[indice]);
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
            scanf("%d", &indice);
            getchar();  // Consumir o caractere de nova linha pendente
            printf("posicao set 2: ");
            scanf("%d", &valor);
            getchar();
            if(conjuntos->tamanho == 2){}
			set_ uniresultado = set_union(&conjuntos[indice], &conjuntos[valor]);
			showSet(&uniresultado);
        } else if(strcmp(structOption, "inter") == 0){
            printf("posicao set 1: ");
            scanf("%d", &indice);
            getchar();  // Consumir o caractere de nova linha pendente
            printf("posicao set 2: ");
            scanf("%d", &valor);
            getchar();
			set_ interresultado = set_intersec(&conjuntos[indice], &conjuntos[valor]);
			if(interresultado.inicio != NULL){
				showSet(&interresultado);
			}else{
				printf("Intersecao vazia {}");
			}

        } else if(strcmp(structOption, "diff") == 0){
            printf("posicao set 1: ");
            scanf("%d", &indice);
            getchar();  // Consumir o caractere de nova linha pendente
            printf("posicao set 2: ");
            scanf("%d", &valor);
            getchar();
			set_ valor2 = set_diferenca(&conjuntos[indice], &conjuntos[valor]);
			//valor->inicio = set_differenca(&conjuntos[num], &conjuntos[num1]);

			if(valor2.inicio != NULL){
				showSet(&valor2);
			}else{
				printf("Diferenca vazia {}");
			}
        } else if(strcmp(structOption, "mbset") == 0){
            printf("posicao set 1: ");
            scanf("%d", &indice);
            getchar();  // Consumir o caractere de nova linha pendente
            printf("item verificado: ");
            scanf("%d", &valor);
            getchar();
			int val = set_isMember(&conjuntos[indice], valor);
			if(val){
				printf("Valor esta no set");
			}else{
				printf("Valor nao esta no set");
			}
        }else if(strcmp(structOption, "cover") == 0){
            printf("posicao set 1: ");
            scanf("%d", &indice);
            getchar();  // Consumir o caractere de nova linha pendente
            printf("item verificado: ");
            scanf("%d", &valor);
            getchar();
			int val = set_isMember(&conjuntos[indice], valor);
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
