#ifndef LISTA_ENCADEADA_TAD_
#define LISTA_ENCADEADA_TAD_

#include <iostream>
#include <cstdlib>
#include "../lib/DSGraph.h" //DSGRAPH

/**
  Nó da lista encadeada.
 */
class No : public DSGraphStr
{
    int info;
    No * prox;
    No * ant;

public:

    No():DSGraphStr()
    {};

    void setInfo(int i)
    {
        info = i;
    }

    void setProx(No * p)
    {
        prox = p;
    }

    void setAnt(No *p)
    {
        ant = p;
    }

    int getInfo()
    {
        return info;
    }

    No * getProx()
    {
        return prox;
    }


    No * getAnt()
    {
        return ant;
    }




    virtual ~No(){};

};

/**
  Lista simplesmente encadeada.
 */
class ListaEncadeada
{
private:
    No * prim;

public:
    ListaEncadeada();
    void insere(int x);
    bool busca(int x);
    void remove(int x);
    void imprime();
    virtual ~ListaEncadeada(){};
};

#endif

