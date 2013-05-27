#include <iostream>
#include "lista_descritor.h"
#include "../lib/DSGraph.h" //DSGRAPH

using namespace std;

int main()
{
    //DSGRAPH
    init($LISTA_DESCRITOR);
    setDataType(int);
    setNodeColor(255, 100, 24);
    showComment("TAD Lista Simplesmente Encadeada com descritor");
    //DSGRAPH

    ListaDescritor *l = new ListaDescritor;

    l->insere(5);
    l->insere(10);
    l->insere(15);
    l->insere(20);
    l->insere(25);
    l->insere(30);
    l->insere(35);
    l->insere(40);
    l->insere(45);
    l->imprime();

    //DSGRAPH
    setNodeColor(255, 100, 24);
    //DSGRAPH

    l->remove(5);
    l->imprime();


    //DSGRAPH
    setNodeColor(255, 100, 24);
    //DSGRAPH

    l->remove(20);
    l->imprime();

    //DSGRAPH
    setNodeColor(255, 100, 24);
    //DSGRAPH

    l->busca(50);

    //DSGRAPH
    setSleepTime(30);
    terminateDSGraph();
    //DSGRAPH

    return 0;
}


