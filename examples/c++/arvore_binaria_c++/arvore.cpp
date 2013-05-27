#include "arvore.h"
#include "../lib/DSGraph.h" //DSGRAPH
#include <stdio.h>

using namespace std;

ArvoreBinaria::ArvoreBinaria() {
    this->raiz = NULL;
}

/**
 * Verfica se a árvore está vazia.
 * @param arv
 * @return TRUE (se estiver vazia) ou FALSE(caso contrário)
 */
bool ArvoreBinaria::vazia(No *arv) {
    return arv == NULL;
}

/**
 * Realiza a inserção de valores na árvore
 * @param arv
 * @param valor
 */
void ArvoreBinaria::insere(int valor, No *arv) {
    No *novo = new No;
    novo->setInfo(valor);
    novo->setEsquerdo(NULL);
    novo->setDireito(NULL);
    if (valor < arv->getInfo()) {
        //Inserir a esquerda
        if (arv->getAnt() != NULL) {
            this->insere(valor, arv->getAnt());
        } else {
            arv->setEsquerdo(novo);
        }
    } else {
        //Inserir a direita
        if (arv->getProx() != NULL) {
            this->insere(valor, arv->getProx());
        } else {
            arv->setDireito(novo);
        }
    }

}

No *ArvoreBinaria::busca(int valor, No* arv) {
    if (!this->vazia(arv)) {
        if (valor == arv->getInfo())
            return arv;
        else if (valor < arv->getInfo())
            return this->busca(valor, arv->getAnt()); //buscar a esquerda
        else
            return this->busca(valor, arv->getProx());//buscar a direita

    }
    return NULL;
}

No *ArvoreBinaria::remove(int valor, No* arv) {
    if (this->vazia(arv))
        return NULL;
    else if (valor < arv->getInfo())
        arv->setEsquerdo(this->remove(valor, arv->getAnt()));
    else if (valor > arv->getInfo())
        arv->setDireito(this->remove(valor, arv->getProx()));
    else {
        /* achou o elemento*/
        if (this->vazia(arv->getAnt()) && this->vazia(arv->getProx())) {
            /* elemento sem filhos */
            delete arv;
            arv = NULL;
        } else if (this->vazia(arv->getAnt())) {
            /* só tem filho à direita */
            arv = arv->getProx();
        } else if (this->vazia(arv->getProx())) {
            /* só tem filho à esquerda */
            arv = arv->getAnt();
        } else {
            /* tem os dois filhos */
//            No *pai = arv;
            No *f = arv->getProx();
            while (!this->vazia(f->getAnt())) {
   //             pai = f;
                f = f->getProx();
            }
            arv->setInfo(f->getInfo());
            f->setInfo(valor);
            arv->setDireito(this->remove(valor, arv->getProx()));

        }
    }
    return arv;
}

/**
 * Métodos publicos
 */


void ArvoreBinaria::insere(int valor) {
    if (this->raiz != NULL) {
        this->insere(valor, this->raiz);
    } else {
        this->raiz = new No;
        this->raiz->setInfo(valor);
        this->raiz->setEsquerdo(NULL);
        this->raiz->setDireito(NULL);
    }
}


void ArvoreBinaria::imprime() {
    //DSGRAPH
    DSGraph ds;
    ds.showCPP(this->raiz);
    //DSGRAPH
}

void ArvoreBinaria::busca(int valor) {
    No *result;
    result = this->busca(valor, this->raiz);
    if (result != NULL) {
        //DSGRAPH
        showComment("Elemento %d encontrado.", valor);
        DSGraph ds;
        ds.showCPP(this->raiz, 1, result);
        //DSGRAPH
    } else {
        //DSGRAPH
        showComment("Valor %d nao encontrado.", valor);
        //DSGRAPH
        this->imprime();
    }

}

void ArvoreBinaria::remove(int valor) {
    No *result = this->remove(valor, this->raiz);
    if (result == NULL) {
        //DSGRAPH
        showComment("O elemento %d nao foi encontrado. Remocao nao realizada.", valor);
        //DSGRAPH
    } else {
        //DSGRAPH
        showComment("Elemento removido com sucesso.");
        //DSGRAPH
    }
    this->imprime();
}


