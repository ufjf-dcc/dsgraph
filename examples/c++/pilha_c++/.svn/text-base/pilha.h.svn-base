#ifndef PILHA_H
#define	PILHA_H

#include <iostream>
#include <cstdlib>
#include "../lib/DSGraph.h" //DSGRAPH


/**
  Nó.
 */
class No : public DSGraphStr {
    int info;
    No * proximo;

public:

    No() : DSGraphStr(){};

    void setInfo(int i){
        info = i;
    }

    void setProx(No *prox){
        proximo = prox;
    }

    int getInfo() {
        return info;
    };

    No * getProx() {
        return proximo;
    };
    virtual ~No(){};
};

class Pilha{
private:
    No *topo;
public:
    Pilha();
    bool vazia();
    void empilha(int valor);
    int desempilha();
    void imprime();
    virtual ~Pilha(){};
};

#endif	/* PILHA_H */

