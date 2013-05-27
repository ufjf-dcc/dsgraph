#include <iostream>
#include "lista_duplamente.h"
#include "../lib/DSGraph.h" //DSGRAPH

using namespace std;

int main()
{
    //DSGRAPH
    init($LISTA_DESCRITOR);
    setDataType(int);
    //DSGRAPH

    ListaDuplamenteEncadeada *l = new ListaDuplamenteEncadeada;

    int i = 0;
    for(i = 0; i < 6; i++)
    {
        //DSGRAPH
        showComment("Inserindo o valor %d no final da lista...", i);
        //DSGRAPH
        l->inserirFinal(i);
        l->imprimir();
    }

    for(i = 10; i >= 6; i--)
    {
        //DSGRAPH
        showComment("Inserindo o valor %d no inicio da lista...", i);
        //DSGRAPH
        l->inserirInicio(i);
        l->imprimir();
    }
    l->imprimir();

    //DSGRAPH
    setSleepTime(30);
    terminateDSGraph();
    //DSGRAPH

    return 0;
}
