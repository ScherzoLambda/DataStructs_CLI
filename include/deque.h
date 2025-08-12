#ifndef DEQUE_H_INLUDED
#define DEQUE_H_INLUDED

#include <dstruct.h>


/*********************************************
*---Definition of Deque Struct---*
**********************************************/
typedef struct {
	int tamanho;
	Nodu* inicio;
	Nodu* fim;
} Deque;

//functions Deque
void initDeque(Deque* d);
void showDeque(Deque* d);
void insBegin(Deque* d, int Elem);
void insEnd(Deque* d, int Elem);
int getBegin(Deque* d);
int getEnd(Deque* d);
int sizeDeque(Deque* d);
void del_Deque(Deque* d);
void delBegin(Deque* d);
void delEnd(Deque* d);

#endif