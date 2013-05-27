#include <iostream>
#include "lista_circular.h"
#include "../lib/DSGraph.h"  //DSGRAPH

using namespace std;

int main() {
    //DSGRAPH
    init($LISTA);
    setDataType(int);
    showComment("TAD Lista Simplesmente Encadeada.");
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

    //Ana: tem que arrumar o remove, para retirar a referência do nó que foi removido
    //l->remove(20);
    //l->imprime();

    int achou25 = l->busca(25);
    int achou50 = l->busca(50);

    if (achou25)
        //DSGRAPH
        showComment("Encontrou o valor 25.");
        //DSGRAPH
    else
        //DSGRAPH
        showComment("Não encontrou o valor 25.");
        //DSGRAPH

    l->imprime();


    if (achou50)
        //DSGRAPH
        showComment("Encontrou o valor 50");
        //DSGRAPH
    else
        //DSGRAPH
        showComment("Nao encontrou o valor 50.");
        //DSGRAPH

    l->imprime();

    //DSGRAPH
    terminateDSGraph();
    //DSGRAPH

    return 0;
}
