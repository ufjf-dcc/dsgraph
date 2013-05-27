#ifndef LISTA_DUPLAMENTE_H_INCLUDED
#define LISTA_DUPLAMENTE_H_INCLUDED

#include <iostream>
#include <cstdlib>
#include "../lib/DSGraph.h" //DSGRAPH

/**
  Nó da lista duplamente encadeada.
 */
class No : public DSGraphStr
{
    int info;
    No * proximo;
    No * anterior;
public:

    No():DSGraphStr()
    {};

    void setInfo(int i)
    {
        info = i;
    };

    int getInfo()
    {
        return info;
    };

    void setProx(No * prox)
    {
        proximo = prox;
    };

    No * getProx()
    {
        return proximo;
    };

    void setAnt(No * ant)
    {
        anterior = ant;
    };

    No *getAnt()
    {
        return anterior;
    }
    virtual ~No() {};

};

/**
* Descritor da lista
*/
class Descritor: public DSGraphStr
{
    int quantidade;
    No *primeiro;
    No *ultimo;

public:
    Descritor():DSGraphStr()
    {};

    void setQuantidade(int qtd)
    {
        quantidade = qtd;
    };

    int getInfo()
    {
        return quantidade;
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

class ListaDuplamenteEncadeada
{
private:
    Descritor *descritor;

public:
    ListaDuplamenteEncadeada();
    void inserirInicio(int valor);
    void inserirFinal(int valor);
    void buscar(int valor);
    void remover(int valor);
    void imprimir();
    virtual ~ListaDuplamenteEncadeada() {};
};


#endif // LISTA_DUPLAMENTE_H_INCLUDED
