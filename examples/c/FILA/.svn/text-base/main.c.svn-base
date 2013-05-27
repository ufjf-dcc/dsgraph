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
#include <stdint.h> //avoid: cast to pointer from integer of different size [-Wint-to-pointer-cast]
#include "../lib/DSGraph.h"

typedef struct NODE_STRUCTURE NO;



struct fila{
  NO* inicio;
  NO* fim;
};


typedef struct fila FILA;


//Aloca a fila em memória
FILA* cria()
{
    FILA *f;
    f =(FILA*) malloc(sizeof(FILA));
    f->inicio = NULL;
    f->fim = NULL;
    return f;
}

//Verifica se a fila está ou não vazia
//@param: FILA *f a fila criada
int vazia(FILA *f)
{
    return (f->inicio ==NULL);
}

//Operação de enfileiramento (enqueue)
//@param: FILA *f a fila criada
//@param: int v o valor a ser enfileirado
void enfileira(FILA *f, int v)
{
    NO *q;
    q = (NO*)malloc(sizeof(NO));

    /*

        #include <stdint.h> //avoid: cast to pointer from integer of different size [-Wint-to-pointer-cast]
        Converte um int para um ponteiro sem enviar o chato erro de cast acima.
        (void *) (intptr_t) v;

    */



    q->valor =(void *) (intptr_t) v;

    q->proximo=NULL;
    q->anterior=NULL;

    if (vazia(f))
    {
        f->inicio = q;
        f->fim=q;
    }else
    {
        f->fim->proximo= q;
        f->fim=q;
    }




}

//Operação de desenfileiramento (dequeue)
//@param: FILA *f a fila criada
void desenfileira(FILA *f)
{
    NO *aux;
    if (vazia(f))
    {
        printf("A fila está vazia");
        return;
    }

    aux = f->inicio;
    f->inicio=f->inicio->proximo;
    if(f->inicio==NULL)
    {
      f->fim=NULL;
    }
    free(aux);
}

//Libera a memória alocada na estrutura
//@param: FILA *f a fila criada
void libera(FILA *f)
{
    NO* q = f->inicio;

    while (q!=NULL)
    {
          NO *t = q->proximo;
          free(q);
          q=t;
    }

    free(f);
}

//Programa principal
int main()
{
    //Inicializa a biblioteca gráfica com a estrutura a ser apresentada na tela
    init($LISTA);

    setDataType(int);

    FILA *f = cria(); //Cria a fila

    int i;

    setSleepTime(1);
    for (i=0;i<10;i++)
    {
        enfileira(f, i);

    }

     setSleepTime(1);
    //Exibe a operação de enfileiramento(enqueue) na tela usando a DSGraph
    //imprimir(f->inicio);
    //setNodeColor(55,200,10);//Trocando a cor
    show(f->inicio, 1, f->inicio);


    for (i=0;i<3;i++)
    {
      desenfileira(f);
      show(f->inicio, 0);
    }


    setSleepTime(3);
    show(f->inicio, 0);
    libera(f);

    terminateDSGraph();

    return 0;
}


//EOF
