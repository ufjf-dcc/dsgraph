#include "fila.h"
#include "../lib/DSGraph.h" //DSGRAPH
#include <stdio.h>

using namespace std;

Fila::Fila()
{
    this->inicio = NULL;
    this->fim = NULL;
}

/**
 * Verifica se a fila esta vazia.
 * @return TRUE se estiver vazia FALSE caso contrário.
 */
bool Fila::vazia()
{
    return (this->inicio == NULL);
}

/**
 * Operação de enfeleiramento(enqueue)
 * @param valor
 */
void Fila::enfileira(int valor)
{
    No *novo = new No;
    novo->setInfo(valor);
    novo->setProx(NULL);

    if(this->vazia())
        this->inicio = novo;
    else
        this->fim->setProx(novo);

    this->fim = novo;
}

/**
 * Operação de desenfileiramento (dequeue)
 * @return valor desenfilerado
 */
int Fila::desenfileira()
{
    No *f;
    int valor;
    if(this->vazia())
    {
        //DSGRAPH
        showComment("Fila esta vazia.");
        //DSGRAPH
        exit(1);
    }
    f = this->inicio;
    valor = f->getInfo();
    this->inicio = this->inicio->getProx();
    delete f;
    if(this->vazia())
        this->fim = NULL;
    return valor;
}

void Fila::imprime()
{
    //DSGRAPH
    DSGraph ds;
    ds.showCPP(this->inicio, 2, this->inicio, this->fim);
    //DSGRAPH
}
