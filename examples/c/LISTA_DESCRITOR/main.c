#include <stdio.h>
#include <stdlib.h>
#include <stdint.h> //avoid: cast to pointer from integer of different size [-Wint-to-pointer-cast]
#include "../lib/DSGraph.h"

typedef struct NODE_STRUCTURE NO;

//MAIN
int main()
{

    //Inicializa a biblioteca gráfica com a estrutura a ser apresentada na tela
    init($LISTA_DESCRITOR);

    setDataType(int);

    NO *descritor;
    descritor = (NO*)malloc(sizeof(NO));
    descritor->proximo = NULL;
    descritor->anterior = NULL;
    descritor->valor = 0;

    NO *P;
    int i,valor = 10;

    for(i = 0; i <= 10; i++)
    {

        P = (NO*)malloc(sizeof(NO));
        P->proximo = descritor->anterior;
        P->anterior = NULL;
        P->valor = (void *) (intptr_t) valor;

        descritor->anterior = P ;

        if(descritor->valor == 0)
            descritor->proximo = P;

        descritor->valor =(void *) (intptr_t)  i+1;

        valor = valor + 10;
    }


     show(descritor, 1 , descritor->proximo);

    return 0;
}
