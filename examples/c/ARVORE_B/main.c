//BOF
#include <stdio.h>
#include <stdlib.h>
#include "../lib/DSGraph.h"

typedef struct NODE_B_TREE NO;



int main()
{

    int numeroDeChaves = 3;

    init($ARVORE_B, numeroDeChaves);



    NO *raiz = NULL;
    raiz = (NO *) malloc(sizeof(NO));

    NO *primeiroFilho = NULL;
   // primeiroFilho = (NO *) malloc(sizeof(NO));
    NO *segundoFilho = NULL;
    //segundoFilho = (NO *) malloc(sizeof(NO));
    NO *terceiroFilho = NULL;
   // terceiroFilho = (NO *) malloc(sizeof(NO));
    NO *quartoFilho = NULL;
   // quartoFilho = (NO *) malloc(sizeof(NO));
    NO *quintoFilho = NULL;
    //quintoFilho = (NO *) malloc(sizeof(NO));

    raiz->CHAVES[0] = (int *) 309;
    raiz->CHAVES[1] = (int *)589;
    raiz->CHAVES[2] = (int *)658;
    raiz->CHAVES[3] = NULL;
    raiz->CHAVES[4] = NULL;



    //Primeiro Filho

    primeiroFilho = (NO *) malloc(sizeof(NO));

    primeiroFilho->CHAVES[0] = (int *) 128;
    primeiroFilho->CHAVES[1] = (int *)169;
    primeiroFilho->CHAVES[2] = (int *)184;
    primeiroFilho->CHAVES[3] = (int *)216;

    primeiroFilho->filhos[0] = NULL;
    primeiroFilho->filhos[1] = NULL;
    primeiroFilho->filhos[2] = NULL;
    primeiroFilho->filhos[3] = NULL;
    primeiroFilho->filhos[4] = NULL;


    //Segundo Filho

    segundoFilho = (NO *) malloc(sizeof(NO));

    segundoFilho->CHAVES[0] = (int *)356;
    segundoFilho->CHAVES[1] = (int *)464;
    segundoFilho->CHAVES[2] = (int *)489;
    segundoFilho->CHAVES[3] = (int *)495;

    segundoFilho->filhos[0] = NULL;
    segundoFilho->filhos[1] = NULL;
    segundoFilho->filhos[2] = NULL;
    segundoFilho->filhos[3] = NULL;
    segundoFilho->filhos[4] = NULL;


    //Tereiro Filho

    terceiroFilho = (NO *) malloc(sizeof(NO));

    terceiroFilho->CHAVES[0] = (int *)526;
    terceiroFilho->CHAVES[1] = (int *)548;
    terceiroFilho->CHAVES[2] = (int *)584;
    terceiroFilho->CHAVES[3] = (int *)598;

    terceiroFilho->filhos[0] = NULL;
    terceiroFilho->filhos[1] = NULL;
    terceiroFilho->filhos[2] = NULL;
    terceiroFilho->filhos[3] = NULL;
    terceiroFilho->filhos[4] = NULL;




    //Quarto Filho

    quartoFilho = (NO *) malloc(sizeof(NO));

    quartoFilho->CHAVES[0] = (int *)718;
    quartoFilho->CHAVES[1] = (int *)739;
    quartoFilho->CHAVES[2] = (int *)857;
    quartoFilho->CHAVES[3] = (int *)865;

    quartoFilho->filhos[0] = NULL;
    quartoFilho->filhos[1] = NULL;
    quartoFilho->filhos[2] = NULL;
    quartoFilho->filhos[3] = NULL;
    quartoFilho->filhos[4] = NULL;



    //Quinto Filho

    quintoFilho = (NO *) malloc(sizeof(NO));


    quintoFilho->CHAVES[0] = (int *)918;
    quintoFilho->CHAVES[1] = (int *)939;
    quintoFilho->CHAVES[2] = (int *)957;
    quintoFilho->CHAVES[3] = (int *)978;

    quintoFilho->filhos[0] = NULL;
    quintoFilho->filhos[1] = NULL;
    quintoFilho->filhos[2] = NULL;
    quintoFilho->filhos[3] = NULL;
    quintoFilho->filhos[4] = NULL;


    NO *ultimoFilho = NULL;
    ultimoFilho = (NO *) malloc(sizeof(NO));

    ultimoFilho->CHAVES[0] = (int *)148;
    ultimoFilho->CHAVES[1] = (int *)457;
    ultimoFilho->CHAVES[2] = (int *)766;
    ultimoFilho->CHAVES[3] = (int *)245;

    ultimoFilho->filhos[0] = NULL;
    ultimoFilho->filhos[1] = NULL;
    ultimoFilho->filhos[2] = NULL;
    ultimoFilho->filhos[3] = NULL;
    ultimoFilho->filhos[4] = NULL;


    /*
    NO *ultimoFilho1 = NULL;
    ultimoFilho = (NO *) malloc(sizeof(NO));

    ultimoFilho1->CHAVES[0] = 35;
    ultimoFilho1->CHAVES[1] = 23;
    ultimoFilho1->CHAVES[2] = 78;
    ultimoFilho1->CHAVES[3] = 99;

    ultimoFilho1->filhos[0] = NULL;
    ultimoFilho1->filhos[1] = NULL;
    ultimoFilho1->filhos[2] = NULL;
    ultimoFilho1->filhos[3] = NULL;
    ultimoFilho1->filhos[4] = NULL;
    */


    primeiroFilho->filhos[0] = ultimoFilho;
    primeiroFilho->filhos[1] = NULL;
    primeiroFilho->filhos[2] = NULL;
    primeiroFilho->filhos[3] = NULL;
    primeiroFilho->filhos[4] = NULL;

    segundoFilho->filhos[0] = NULL;
    segundoFilho->filhos[1] = NULL;
    segundoFilho->filhos[2] = NULL;
    segundoFilho->filhos[3] = NULL;
    segundoFilho->filhos[4] = NULL;

    terceiroFilho->filhos[0] = NULL;
    terceiroFilho->filhos[1] = NULL;
    terceiroFilho->filhos[2] = NULL;
    terceiroFilho->filhos[3] = NULL;
    terceiroFilho->filhos[4] = NULL;

    quartoFilho->filhos[0] = ultimoFilho;
    quartoFilho->filhos[1] = NULL;
    quartoFilho->filhos[2] = ultimoFilho;
    quartoFilho->filhos[3] = NULL;
    quartoFilho->filhos[4] = NULL;


    quintoFilho->filhos[0] = ultimoFilho;
    quintoFilho->filhos[1] = ultimoFilho;
    quintoFilho->filhos[2] = ultimoFilho;
    quintoFilho->filhos[3] = ultimoFilho;
    quintoFilho->filhos[4] = ultimoFilho;


    //printf("%d",primeiroFilho->filhos[1]->CHAVES[0]);

    raiz->filhos[0] = primeiroFilho;
    raiz->filhos[1] = quintoFilho;
    raiz->filhos[2] = terceiroFilho;
    raiz->filhos[3] = quartoFilho;
    raiz->filhos[4] = quintoFilho;

    show(raiz,0);

    terminateDSGraph();

    return 0;
}

//EOF

