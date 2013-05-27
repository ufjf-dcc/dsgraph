#include <iostream>
#include "lista.h"
#include "../lib/DSGraph.h"  //DSGRAPH

using namespace std;

int main() {
    //DSGRAPH
    init($LISTA);
    setDataType(int);
    showComment("TAD Lista Duplamente Encadeada.");
    //DSGRAPH

    ListaEncadeada *l = new ListaEncadeada;
    l->insere(10);
    l->insere(20);
    l->insere(30);
    l->insere(25);
    l->insere(40);
    l->insere(45);
    l->insere(35);
    l->insere(50);
    l->imprime();


    //DSGRAPH
    terminateDSGraph();
    //DSGRAPH

    return 0;
}
