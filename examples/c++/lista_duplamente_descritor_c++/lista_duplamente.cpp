#include "lista_duplamente.h"
#include "../lib/DSGraph.h" //DSGRAPH
#include <stdio.h>

using namespace std;

/**
* Cria uma lista duplamente encadeada vazia.
*/
ListaDuplamenteEncadeada::ListaDuplamenteEncadeada()
{
    this->descritor = new Descritor();
    this->descritor->setQuantidade(0);
    this->descritor->setPrimeiro(NULL); //primeiro nó da lista
    this->descritor->setUltimo(NULL); //último nó da lista
}

/**
* Insere um novo valor no ínicio da lista.
* @param valor
*/
void ListaDuplamenteEncadeada::inserirInicio(int valor)
{
    No *novo = new No();
    novo->setInfo(valor);
    novo->setAnt(NULL);

    if(this->descritor->getInfo() == 0)
        this->descritor->setUltimo(novo);
    else
    {
        No *primeiro = this->descritor->getAnt();
        primeiro->setAnt(novo);
        novo->setProx(primeiro);
    }
    this->descritor->setPrimeiro(novo);
    int qtd = this->descritor->getInfo();
    qtd++;
    this->descritor->setQuantidade(qtd);

}

/**
* Inserir um novo nó ao final da lista.
* @param valor
*/
void ListaDuplamenteEncadeada::inserirFinal(int valor)
{
    No *novo = new No();
    novo->setInfo(valor);
    novo->setProx(NULL);
    novo->setAnt(NULL);
    if(this->descritor->getInfo() == 0)
        this->descritor->setPrimeiro(novo);
    else
    {
        No *ultimo = this->descritor->getProx();
        novo->setAnt(ultimo);
        ultimo->setProx(novo);
    }
    this->descritor->setUltimo(novo);
    int qtd = this->descritor->getInfo();
    qtd++;
    this->descritor->setQuantidade(qtd);
}

void ListaDuplamenteEncadeada::imprimir()
{
    //DSGRAPH
    DSGraph ds;
    ds.showCPP(this->descritor);
    //DSGRAPH
}
