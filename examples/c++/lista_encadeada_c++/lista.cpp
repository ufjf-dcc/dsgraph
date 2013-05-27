#include "lista.h"
#include "../lib/DSGraph.h" //DSGRAPH
#include <stdio.h>


using namespace std;

/**
 * Cria uma lista encadeada vazia.
 */
ListaEncadeada::ListaEncadeada()
{
    this->prim = NULL;
}

/**
 * Insere um novo elemento na lista.
 * @param item
 */
void ListaEncadeada::insere(int item)
{
    No* novo = new No();
    novo->setInfo(item);
    novo->setProx(NULL);
    if(this->prim == NULL)
    {
        this->prim = novo;
    }
    else
    {
        // vai até o final da lista
        No* temp = this->prim;
        while(temp->getProx() != NULL)
        {
            temp = temp->getProx();
        }

        // faz ultimo apontar para o novo nó
        temp->setProx(novo);
    }
}

/**
 * Remove um elemento na lista.
 * @param item
 */
void ListaEncadeada::remove(int item)
{
    No *p, *ant;
    ant = NULL;
    p = this->prim;

    while(p != NULL && p->getInfo() != item)
    {
        ant = p;
        p = p->getProx();
    }

    if (p != NULL)
    {
        if (ant == NULL)
            this->prim = p->getProx();
        else
            ant->setProx( p->getProx());
        free(p);
    }
}

/**
 * Imprime os elementos da lista com o auxilio da biblioteca DSGraph.
 */
void ListaEncadeada::imprime()
{
   No *p = this->prim;

    //DSGRAPH
    DSGraph ds;
    ds.showCPP(p);
    //DSGRAPH

}

/**
 * Realiza a busca de um elemento na lista.
 * @param item
 * @return
 */
bool ListaEncadeada::busca(int item)
{
    No * p;
    for(p=this->prim; p!=NULL; p=p->getProx())
    {
        if (p->getInfo() == item)
            return true;
    }
    return false;
}
