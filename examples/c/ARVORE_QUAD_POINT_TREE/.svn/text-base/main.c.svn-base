#include <stdio.h>
#include <stdlib.h>
#include "../lib/DSGraph.h"


#define MAX 100
typedef struct NODE_QUADTREE NO;

// Retorna a posição do vetor que o nó deve ser inserido
int retorna_quadrante(NO *pRaiz, float x, float y)
{
    if (pRaiz->x < x)
        if (pRaiz->y < y)
            return 3;
        else
            return 0;
    else if (pRaiz->y < y)
        return 2;
    else
        return 1;
}

void criarArvore(NO *pRaiz)
{
    pRaiz = NULL;
}

NO *criaFilhos(char valor[100], float x, float y)
{
    NO *f;
    int q;
    f = (NO*) malloc(sizeof(NO));
    f->valor = valor;
    f->x = x;
    f->y = y;
    for(q = 0; q < 4; q++)
        f->filhos[q] = NULL;

    return f;
}

NO *inserir(NO *pRaiz, char valor[100], float x, float y)
{
    int q;
    if(pRaiz == NULL)
    {
        pRaiz = criaFilhos(valor, x, y);
    }
    else
    {
        q = retorna_quadrante(pRaiz, x, y);
        pRaiz->filhos[q] = inserir(pRaiz->filhos[q], valor, x, y);
    }
    return pRaiz;

}


int main()
{

    init($POINT_QUADTREE);

    setDataType(char);

    NO *raiz = NULL;
    criarArvore(raiz);

    showComment("Arvore POINT QUADTREE: ");

    raiz = inserir(raiz, "Chicago", 35.0, 40.0);
    raiz = inserir(raiz, "Mobile", 50.0, 10.0);
    raiz = inserir(raiz, "Toronto", 60.0, 75.0);
    raiz = inserir(raiz, "Buffalo", 80.0, 65.0);
    raiz = inserir(raiz, "Denver", 5.0, 45.0);
    raiz = inserir(raiz, "Omaha", 25.0, 35.0);
    raiz = inserir(raiz, "Miami", 90.0, 5.0);
    raiz = inserir(raiz, "Atlanta", 85.0, 15.0);


    setSleepTime(10);
    show(raiz,0);

    terminateDSGraph();

    return 0;
}
