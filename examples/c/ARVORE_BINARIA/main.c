
//BOF
#include <stdio.h>
#include <stdlib.h>
#include "../lib/DSGraph.h"
#include <stdint.h> //avoid: cast to pointer from integer of different size [-Wint-to-pointer-cast]



#define MAX 100
typedef struct NODE_STRUCTURE NO;


void criarArvore(NO *pRaiz){
    pRaiz = NULL;
}


NO *inserir(NO *pRaiz, int numero){
    if(pRaiz == NULL){
        pRaiz = (NO *) malloc(sizeof(NO));
        pRaiz->proximo = NULL;
        pRaiz->anterior = NULL;
        pRaiz->valor = (void *) (intptr_t) numero;

        return pRaiz;
    }else{

        if(numero < (intptr_t) pRaiz->valor)
           pRaiz->anterior = inserir(pRaiz->anterior, numero);
        if(numero > (intptr_t) pRaiz->valor)
           pRaiz->proximo = inserir(pRaiz->proximo, numero);
    }

  return pRaiz;
}



int contarNos(NO *pRaiz){
   if(pRaiz == NULL)
        return 0;
   else
        return 1 + contarNos(pRaiz->anterior) + contarNos(pRaiz->proximo);
}


int maior(int a, int b){
    if(a > b)
        return a;
    else
        return b;
}

int altura(NO *pRaiz){
   if((pRaiz == NULL) || (pRaiz->anterior == NULL && pRaiz->proximo == NULL))
       return 0;
   else
       return 1 + maior(altura(pRaiz->anterior), altura(pRaiz->proximo));
}


int main()
{

   init($ARVORE_BINARIA);

    setDataType(int);

    NO *raiz = NULL;

    criarArvore(raiz);

    setViewAddress(0);
    raiz=  inserir(raiz, 15);
    raiz=  inserir(raiz, 9);
    raiz=  inserir(raiz, 20);
    raiz=  inserir(raiz, 7);
    raiz=  inserir(raiz, 11);
    raiz=  inserir(raiz, 18);
    raiz=  inserir(raiz, 22);


    setSleepTime(7);
    show(raiz,0);


    terminateDSGraph();

    return 0;
}

//EOF
