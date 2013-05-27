#ifndef LISTA_DESCRITOR_H
#define	LISTA_DESCRITOR_H

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


    int getInfo()
    {
        return info;
    };

    No * getProx()
    {
        return prox;
    };

    virtual ~No() {};

};

/**
*  Descritor da lista
*/
class Descritor: public DSGraphStr
{
    int total;
    No *primeiro;
    No *ultimo;

public:
    Descritor():DSGraphStr()
    {};

    void setInfo(int i)
    {
        total = i;
    };

    int getInfo()
    {
        return total;
    };

    void setPrimeiro(No *p)
    {
        primeiro = p;
    };

    No *getAnt()
    {
        return primeiro;
    };

    void setUltimo(No *u)
    {
        ultimo = u;
    };

    No *getProx()
    {
        return ultimo;
    };

    virtual ~Descritor() {};
};

/**
  Lista simplesmente encadeada com descritor.
 */
class ListaDescritor
{
private:
    Descritor *descritor;
public:
    ListaDescritor();
    bool vazia();
    void insere(int valor);
    void busca(int valor);
    void remove(int valor);
    void imprime();
    virtual ~ListaDescritor() {};
};


#endif
