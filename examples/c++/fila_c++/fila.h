#ifndef FILA_H
#define	FILA_H

#include <iostream>
#include <cstdlib>
#include "../lib/DSGraph.h" //DSGRAPH


/**
  Nó.
 */
class No : public DSGraphStr
{
    int info;
    No *proximo;

public:
    No():DSGraphStr() {};

    void setInfo(int i)
    {
        info = i;
    }

    void setProx(No *prox)
    {
        proximo = prox;
    }

    int getInfo()
    {
        return info;
    };

    No * getProx()
    {
        return proximo;
    };

    virtual ~No() {};
};


class Fila
{
private:
    No *inicio;
    No *fim;
public:
    Fila();
    bool vazia();
    void enfileira(int valor);
    int desenfileira();
    void imprime();
    virtual ~Fila() {};
};


#endif	/* FILA_H */

