#include <iostream>
#include "fila.h"
#include "../lib/DSGraph.h"   //DSGRAPH

using namespace std;

int main()
{
    //DSGRAPH
    init($LISTA);
    setDataType(int);
    //DSGRAPH

    Fila *f = new Fila;

    for(int i = 10; i >= 1; i--)
    {
        showComment("Inclusao do valor %d...", i);
        f->enfileira(i);
        f->imprime();
    }

    f->imprime();

    int valor;
    for(int i = 1; i <= 5; i++)
    {
        valor = f->desenfileira();
        showComment("Valor %d saindo da fila...", valor);
        f->imprime();
    }

    f->imprime();

    //DSGRAPH
    setSleepTime(30);
    terminateDSGraph();
    //DSGRAPH

    return 0;
}
