#include <iostream>
#include "pilha.h"
#include "../lib/DSGraph.h"   //DSGRAPH

using namespace std;

int main()
{
    //DSGRAPH
    init($PILHA);
    setDataType(int);
    //DSGRAPH

    Pilha *p = new Pilha;

    for(int i = 15; i >= 0; i--)
    {
        p->empilha(i);
        p->imprime();
    }

    p->imprime();

    int valor;

    for(int j = 0; j < 10; j++)
    {
        valor = p->desempilha();
        showComment("Valor retirado da pilha: %d", valor);
        p->imprime();
    }

    p->imprime();


    //DSGRAPH
    setSleepTime(30);
    terminateDSGraph();
    //DSGRAPH

    return 0;
}
