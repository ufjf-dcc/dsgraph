#include <stdio.h>
#include <stdlib.h>
#include "../lib/DSGraph.h"
#include <stdint.h> //avoid: cast to pointer from integer of different size [-Wint-to-pointer-cast]


#define MAX 100
typedef struct NODE_TERNARY NO;



int main()
{

    int i = 0;

    init($ARVORE_TERNARIA);

    setDataType(int);

    NO *raiz, *filho1,*filho2,*filho3;
    NO *filho[9];

    for(i = 0; i < 9; i++)
    {
        filho[i] = (NO *) malloc(sizeof(NO));
        filho[i]->centro = NULL;
        filho[i]->esquerdo = NULL;
        filho[i]->direito = NULL;

        int valor = (9 * i);

        filho[i]->valor =(void *) (intptr_t)  valor;


    }

    raiz =   (NO *) malloc(sizeof(NO));
    filho1 = (NO *) malloc(sizeof(NO));

    filho2 = (NO *) malloc(sizeof(NO));
    filho3 = (NO *) malloc(sizeof(NO));

    filho1->esquerdo = filho[0];
    filho1->direito = filho[1];
    filho1->centro = filho[2];
    filho1->valor =(int *) 85;

    filho2->esquerdo = filho[3];
    filho2->direito = filho[4];
    filho2->centro = filho[5];
    filho2->valor = (int *) 30;

    filho3->esquerdo = filho[6];
    filho3->direito = filho[7];
    filho3->centro = filho[8];
    filho3->valor = (int *) 7;

    raiz->centro = filho1;
    raiz->esquerdo = filho2;
    raiz->direito = filho3;
    raiz->valor = (int *) 10;

    setSleepTime(6);

    show(raiz,0);

    terminateDSGraph();

    return 0;
}
