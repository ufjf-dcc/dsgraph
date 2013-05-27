/*
+--------------------------------------------------------------------------------------+
|Federal University Of Juiz de Fora - UFJF - Minas Gerais - Brazil                     |
|Institute for Exact Sciences - ICE                                                    |
|Computer Science Departament - DCC                                                    |
|Project: Visual library to support Data Structures classes                            |
|Professor:Jairo Francisco de Souza    jairo.souza@ufjf.edu.br                         |
|Students......:Thiago Moratori Peixoto     thiagomoratori@gmail.com	               |
|               Sandro Athaide Coelho       sandroacoelho@gmail.com                    |
|Created in......:Abril/23/2011                                                        |
|Objective:                                                                            |
|Este é um programa de exemplo de implementação de Pilhas em C ANSI usando a biblioteca|
|gráfica criada para a apresentação da estrutura na tela.                              |
|A biblioteca foi criada como static library. Sendo assim você deverá utilizar os dois |
|cabeçalhos constantes na mesma, bem como incluir o snippet de código marcado abaixo   |
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
#include <stdint.h>
#include "../lib/DSGraph.h"

typedef struct NODE_STRUCTURE NO;



struct pilha{
  NO* topo;
};

typedef struct pilha PILHA;


//Aloca a pilha em memória
PILHA* cria()
{
    PILHA *p;
        p =(PILHA*) malloc(sizeof(PILHA));
        p->topo = NULL;
    return p;
}

//Verifica se a pilha está ou não vazia
//@param: PILHA *p a pilha criada
int vazia(PILHA *p)
{
    return (p->topo ==NULL);
}

//Operação de empilhamento (push)
//@param: PILHA *p a pilha criada
//@param: int v    o valor a ser empilhado
void empilha(PILHA *p, int v)
{
    NO* aux;
    aux = (NO*)malloc(sizeof(NO));
    aux->valor =(void *) (intptr_t) v;
    aux->proximo=p->topo;
    p->topo = aux;
}

//Operação de desempilhamento
//@param: PILHA *p a pilha criada
void desempilha(PILHA *p)
{
    NO* aux;
    if (vazia(p))
    {
        printf("A pilha está vazia");
        return;
    }

    aux = p->topo;
    p->topo = aux->proximo;
    free(aux);
}

//Libera a memória alocada na estrutura
//@param: PILHA *p a pilha criada
void libera(PILHA *p)
{
    NO* q = p->topo;

    while (q!=NULL)
    {
          NO *t = q->proximo;
          free(q);
          q=t;
    }

    free(p);
}

//Programa principal
int main()
{
    //Inicializa a biblioteca gráfica com a estrutura a ser apresentada na tela
    init($PILHA);

    setDataType(int);

    PILHA *p = cria(); //Cria a pilha

    int i;


    for (i=0;i<100;i++)
    {
        empilha(p, i);
    }

    show(p->topo, 0);
    show(p->topo, 3, p->topo, p->topo->proximo, p->topo->proximo->proximo);

    for (i=0;i<1;i++)
    {
      desempilha(p);
      show(p->topo, 3, p->topo, p->topo->proximo, p->topo->proximo->proximo);
    }

    libera(p);

    terminateDSGraph();

    return 0;
}


//EOF
