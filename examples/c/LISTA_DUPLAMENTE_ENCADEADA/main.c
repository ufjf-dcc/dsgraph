/*
+--------------------------------------------------------------------------------------+
|Federal University Of Juiz de Fora - UFJF - Minas Gerais - Brazil                     |
|Institute for Exact Sciences - ICE                                                    |
|Computer Science Departament - DCC                                                    |
|Project: Visual library to support Data Structures classes                            |
|Professor:Jairo Francisco de Souza    jairo.souza@ufjf.edu.br                         |
|Students......:Thiago Moratori Peixoto     thiagomoratori@gmail.com	               |
|               Sandro Athaide Coelho       sandroacoelho@gmail.com                    |
|               Ana Carolina Gonçalves Fideles acarolinafg@gmail.com                   |
|Created in......:Set/23/2011                                                          |
|Objective:                                                                            |
|Este é um programa de exemplo de implementação de Lista encadeada em C ANSI usando    |
|a biblioteca gráfica criada para a apresentação da estrutura na tela.                 |
|A biblioteca foi criada como static library. Sendo assim você deverá utilizar os dois |
|cabeçalhos constantes na mesma, bem como incluir os cabeçalhos de código marcado      |
| abaixo                                                                               |
|Para o processo de compilação, você deverá referenciar a mesma DSGraph_LIB.a.         |
| No Codeblocks:                                                                       |
| Properties(do seu projeto)->Project's build option->Linker Settings->Link libraries  |
|                                                                                      |
| * ATENÇÃO *                                                                          |
| Para o correto funcionamento, será ainda necessário que você tenha a Allegro 5.0 con-|
|figurada no seu sistema operacional                                                   |
|                                                                                      |
|--------------------------------------------------------------------------------------+
*/
//BOF
#include <stdio.h>
#include <stdlib.h>
#include "../lib/DSGraph.h"
#include <stdint.h>



typedef struct NODE_STRUCTURE LISTA;


LISTA* primeiro = NULL;

//Aloca a lista em memória
LISTA* inicializa()
{
    return NULL;
}

//Verifica se a lista está ou não vazia
//@param: LISTA *l a fila criada
int vazia(LISTA *l)
{
    return (l ==NULL);
}

//Operação de encadeamento
//@param: LISTA *l a lista criada
//@param: int v o valor a ser encadeado
LISTA *adicionar(LISTA *l, int v)
{

    LISTA *novo;
    novo= (LISTA*)malloc(sizeof(LISTA));
    novo->valor =  (void *) (intptr_t)v;
    novo->proximo = l;

     if(primeiro == NULL)
        primeiro = novo;


    if (l!=NULL)
    {
       l->anterior = novo;
       primeiro->proximo = novo;
       novo->anterior = primeiro;
    }else
    {
        novo->anterior=primeiro;
        novo->proximo = primeiro;
    }

    return novo;

}

//Operação de remoção
//@param: Lista *L a lista criada
LISTA *remover(LISTA *l, int v)
{
    LISTA *ant = NULL;
    LISTA *p = l;
    if (vazia(l))
    {
        printf("A lista está vazia");
        return NULL;
    }


    while (p != NULL && (intptr_t)p->valor!=v)
    {
        ant = p;
        p = p->proximo;
    }


    if (p == NULL)
        return l; /* não achou: retorna a lista original */


    if (ant == NULL)
        l = p->proximo; /* retira elemento do inicio */
     else
        ant->proximo = p->proximo; /* retira elmento do meio da lista */

    free(p);

    return l;


}

//Libera a memória alocada na estrutura
//@param: Lista *l a fila criada
void libera(LISTA *l)
{
    LISTA* q = l;

    while (q!=NULL)
    {
          LISTA *t = q->proximo;
          q->proximo = NULL;
          q->anterior = NULL;
          free(q);
          q=t;
    }

    //free(l);

}




//Programa principal
int main()
{
    //Inicializa a biblioteca gráfica com a estrutura a ser apresentada na tela
    init($LISTA);

    setDataType(int);

    LISTA *l = inicializa(); //Cria a lista

    int i;

    for (i=0;i<10;i++)
    {
        l = adicionar(l, i);
        show(l, 0);
    }

    show(l, 0);

    l = remover(l, 2);

    show(l, 1, l->proximo);

    terminateDSGraph();

    libera(l);

    return 0;
}


//EOF
