#ifndef ARVORE_H_INCLUDED
#define ARVORE_H_INCLUDED

#include <iostream>
#include <cstdlib>
#include "../lib/DSGraph.h" //DSGRAPH

/**
* Nó da árvore binária
*/
class No :public DSGraphStr {
    int info;
    No* direito; //no direito da raiz (proximo)
    No* esquerdo; //no esquerdo da raiz (anterior)
public:

    No():DSGraphStr() {};

    void setDireito(No * dir) {
        direito = dir;
    };

    void setEsquerdo(No * esq) {
        esquerdo = esq;
    };

    void setInfo(int i){
        info = i;
    }

    No * getAnt() {
        return esquerdo;
    };

    No * getProx() {
        return direito;
    };

    int getInfo() {
        return info;
    };

    virtual ~No(){};

};

/**
    Árvore binária
 */

class ArvoreBinaria {
private:
    No* raiz;
    bool vazia(No *arv);
    void libera(No *arv);
    void insere(int valor, No *arv);
    No* busca(int valor, No *arv);
    No* remove(int valor, No *arv);

public:
    ArvoreBinaria();
    virtual ~ArvoreBinaria(){};
    void insere(int valor);
    void imprime();
    void busca(int valor);
    void remove(int valor);
};


#endif // ARVORE_H_INCLUDED



