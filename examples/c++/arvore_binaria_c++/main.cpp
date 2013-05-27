#include <iostream>
#include "arvore.h"
#include "../lib/DSGraph.h"  //DSGRAPH

using namespace std;

int main() {
    //DSGRAPH
    init($ARVORE_BINARIA);
    setDataType(int);
    showComment("TAD Arvore Binaria:");
    //DSGRAPH

    ArvoreBinaria *arv = new ArvoreBinaria;

    arv->insere(15);
    arv->insere(9);
    arv->insere(20);
    arv->insere(7);
    arv->insere(11);
    arv->insere(18);
    arv->insere(24);
    arv->insere(6);
    arv->insere(8);
    arv->insere(10);
    arv->insere(12);
    arv->insere(17);
    arv->insere(19);
    arv->imprime();

    arv->busca(20);
    arv->busca(5);


    arv->remove(24);
    arv->remove(6);
    arv->remove(7);
    arv->remove(12);
    arv->remove(18);
    arv->remove(5);



    //DSGRAPH
    setSleepTime(10);
    terminateDSGraph();
    //DSGRAPH

    return 0;
}

