#ifndef DSTRUCT_H_INLUDED
#define DSTRUCT_H_INLUDED
#define MAX 20
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
/*Nó para armazenazem de dados.*/
typedef struct Nod {
    int info;
    struct Nod* next;
} Nod;
/* No para o encadeamento duplo*/
typedef struct Nodu{
	int info;
	struct Nodu* prev;
	struct Nodu* next;
} Nodu;


#endif
