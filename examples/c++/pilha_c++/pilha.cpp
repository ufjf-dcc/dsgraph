#include "pilha.h"
#include "../lib/DSGraph.h" //DSGRAPH
#include <stdio.h>

using namespace std;

Pilha::Pilha()
{
    this->topo = NULL;
}

/**
 * Verifica se a pilha esta vazia.
 * @return TRUE se estiver vazia e FALSE caso contrário.
 */
bool Pilha::vazia()
{
    return (this->topo == NULL);
}

/**
 * Operação de empilhamento.
 * @param valor
 */
void Pilha::empilha(int valor)
{
    No *novo = new No;
    novo->setInfo(valor);
    novo->setProx(this->topo);
    this->topo = novo ;
}

/**
 * Operação de desempilhamento.
 * @param valor
 */
int Pilha::desempilha()
{
    No *aux;
    int valor;

    if(this->vazia())
    {
        //DSGRAPH
        showComment("Pilha esta vazia.");
        //DSGRAPH
        exit(1);
    }

    valor = this->topo->getInfo();
    aux = this->topo;
    this->topo = aux->getProx();
    delete aux;

    return valor;
}

/**
 * Imprime a pilha.
 */
void Pilha::imprime()
{
    //DSGRAPH
    DSGraph ds;
    ds.showCPP(this->topo);
    //DSGRAPH

}
