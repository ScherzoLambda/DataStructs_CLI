
#include <conjunto.h>

/* ----------------------------------- Functions Conjunto(SET) ### */
void initSet(set_* set){
	set->tamanho = 0;
	set->inicio = NULL;
	set->fim = NULL;
}

void delSet(set_* set){
    Nod* atual = set->inicio;
    while (atual != NULL) {
        Nod* proximo = atual->next;
        free(atual);
        atual = proximo;
    }
    set->inicio = NULL;
    set->fim = NULL;
    set->tamanho = 0;
}

void showSet(set_* set){
	if (set->inicio == NULL) {
        printf("Lista vazia\n");
        return;
    }

    Nod* atual = set->inicio;
    printf("{");
    while (atual != NULL) {
        printf("%d", atual->info);

        atual = atual->next;
        if (atual != NULL) {
            printf(", ");
        }
    }
    printf("}\n");
}

void insertSet(set_* set, int Elem){
    //verificar se elemento a ser inserido ja esta no conjunto
	Nod* atual = set->inicio;
	while (atual != NULL) {
    	if(Elem == atual->info){
        	printf("Erro: Set ja Contem este Elemento: %d\n", atual->info);
        	return;
		}

    	atual = atual->next;
    	if (atual != NULL) {
        	continue;
    	} else{
    		break;
		}

	}

	Nod* novoNo = (Nod*)malloc(sizeof(Nod));
	if (set->tamanho >= MAX) {
        printf("Erro: Set cheio Elementos: %d\n", set->tamanho);
        return;
    }
    if (novoNo == NULL) {
        printf("Erro: Falha na aloca��o de mem�ria\n");
        return;
    }



    novoNo->info = Elem;
    novoNo->next = NULL;

	if (set->inicio == NULL) {
        // Se a lista estiver vazia, o novo n� ser� o primeiro e o �ltimo
        set->inicio = novoNo;
        set->fim = novoNo;
        //lista->inicio->next = NULL;
	}else{
		set->fim->next = novoNo;
		set->fim = novoNo;
	}
        set->tamanho++;
}

void setIndexRemove(set_* set, int Elem){
	Nod* atual = set->inicio;
    Nod* anterior = NULL;

    while (atual != NULL) {
        if (atual->info == Elem) {
            if (anterior == NULL) {
                set->inicio = atual->next;
            } else {
                anterior->next = atual->next;
            }

            if (atual == set->fim) {
                set->fim = anterior;
            }

            free(atual);
            set->tamanho--;
            return;
        }

        anterior = atual;
        atual = atual->next;
    }
}

set_ set_union(set_* set1, set_* set2) {
    set_ uniao;
	initSet(&uniao);
    if(set1->tamanho == 0){
    	printf("Set do parametro esta vazio!\n");
    	return uniao;
	}
	if(set2->tamanho == 0){
		printf("Set do parametro 2 esta vazio!\n");
		return uniao;
	}

	Nod* atual = set1->inicio;
	Nod* atual2 = set2->inicio;

    while (atual != NULL) {
        insertSet(&uniao, atual->info);
        atual = atual->next;
    }

    while (atual2 != NULL) {
        if (!set_isMember(set1, atual2->info)) {
            insertSet(&uniao, atual2->info);
        }
        atual2 = atual2->next;
    }

	return uniao;
}

set_ set_intersec(set_* set1, set_* set2) {
    set_ inter;
    initSet(&inter);

    if (set1->tamanho == 0 || set2->tamanho == 0) {
        return inter;
    }

    Nod* atual = set1->inicio;

    while (atual != NULL) {
        if (set_isMember(set2, atual->info)) {
            insertSet(&inter, atual->info);
        }
        atual = atual->next;
    }
    return inter;
}

set_ set_diferenca(set_* set1, set_* set2) {
    set_ diferenca;
    initSet(&diferenca);

    if (set1->tamanho == 0) {
        return diferenca;
    }

    Nod* atual = set1->inicio;

    while (atual != NULL) {
        if (!set_isMember(set2, atual->info)) {
            insertSet(&diferenca, atual->info);
        }
        atual = atual->next;
    }
    return diferenca;
}

int set_isMember(set_* set, int Elem) {
    Nod* atual = set->inicio;
    while (atual != NULL) {
        if (atual->info == Elem) {
            return 1; // O elemento est� presente no conjunto
        }
        atual = atual->next;
    }
    return 0; // O elemento n�o est� presente no conjunto
}

// Verifica se set1 é subconjunto de set2
int set_isSubset(set_* set1, set_* set2) {
    Nod* atual = set1->inicio;
    while (atual != NULL) {
        if (!set_isMember(set2, atual->info)) {
            return 0; // Elemento do set1 n�o est� presente no set2, portanto, set1 n�o � um subconjunto de set2
        }
        atual = atual->next;
    }
    return 1; // Todos os elementos de set1 est�o presentes em set2, portanto, set1 � um subconjunto de set2
}

int set_isEqual(set_* set1, set_* set2) {
    if (set1->tamanho != set2->tamanho) {
        return 0; // Os conjuntos t�m tamanhos diferentes, portanto, n�o s�o iguais
    }
    return set_isSubset(set1, set2) && set_isSubset(set2, set1);
}

int set_size(set_* set) {
    return set->tamanho;
}

// Fun��o para cobertura de conjuntos (cobrir todos os elementos em uma �nica cole��o de conjunto)
// void set_ *set_cover(set_* set1, int tamanho_conjunto, int subconjuntos[][5], int quantidade_subconjuntos) {
//     bool cobertura_conjuntos(int conjunto[], int tamanho_conjunto, int subconjuntos[][5], int quantidade_subconjuntos) {
//         // Implementa��o da fun��o cobertura_conjuntos

//         return true;
//     }

//     void combinacoes(int subconjuntos[][5], int quantidade_subconjuntos, int k, int indice_atual, int combinacao_atual[][5], int indice_combinacao, int conjunto[], int tamanho_conjunto, set_* resultado) {
//         if (indice_combinacao == k) {
//             if (cobertura_conjuntos(conjunto, tamanho_conjunto, combinacao_atual, k)) {
//                 // Criar um novo conjunto e adicionar o conjunto atual a ele
//                 set_* novo_conjunto = malloc(sizeof(set_));
//                 novo_conjunto->tamanho = k;
//                 novo_conjunto->inicio = NULL;
//                 novo_conjunto->fim = NULL;
//                 for (int i = 0; i < k; i++) {
//                     Nod* novo_nod = malloc(sizeof(Nod));
//                     novo_nod->info = combinacao_atual[i][0];
//                     novo_nod->next = NULL;
//                     if (novo_conjunto->inicio == NULL) {
//                         novo_conjunto->inicio = novo_nod;
//                         novo_conjunto->fim = novo_nod;
//                     } else {
//                         novo_conjunto->fim->next = novo_nod;
//                         novo_conjunto->fim = novo_nod;
//                     }
//                 }
//                 // Adicionar o novo conjunto ao resultado
//                 if (resultado->inicio == NULL) {
//                     resultado->inicio = novo_conjunto;
//                     resultado->fim = novo_conjunto;
//                 } else {
//                     resultado->fim->next = novo_conjunto;
//                     resultado->fim = novo_conjunto;
//                 }
//             }
//             return;
//         }

//         if (indice_atual >= quantidade_subconjuntos) {
//             return;
//         }

//         for (int i = indice_atual; i < quantidade_subconjuntos; i++) {
//             for (int j = 0; j < 5; j++) {
//                 combinacao_atual[indice_combinacao][j] = subconjuntos[i][j];
//             }
//             combinacoes(subconjuntos, quantidade_subconjuntos, k, i + 1, combinacao_atual, indice_combinacao + 1, conjunto, tamanho_conjunto, resultado);
//         }
//     }

//     set_* resultado = malloc(sizeof(set_));
//     resultado->tamanho = 0;
//     resultado->inicio = NULL;
//     resultado->fim = NULL;

//     int combinacao_atual[quantidade_subconjuntos][5];

//     for (int k = 1; k <= quantidade_subconjuntos; k++) {
//         combinacoes(subconjuntos, quantidade_subconjuntos, k, 0, combinacao_atual, 0, set1->conjunto, tamanho_conjunto, resultado);
//     }

//     return resultado;
// }