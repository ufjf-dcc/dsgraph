#include "lista_descritor.h"
#include "../lib/DSGraph.h" //DSGRAPH
#include <stdio.h>

using namespace std;

/**
 * Cria uma lista vazia.
 */
ListaDescritor::ListaDescritor()
{
    this->descritor = new Descritor();
    this->descritor->setInfo(0);
    this->descritor->setPrimeiro(NULL);
    this->descritor->setUltimo(NULL);
}

/**
 * Verifica se a lista está vazia.
 * @return TRUE se verdadeiro e FALSE caso contrário.
 */
bool ListaDescritor::vazia()
{
    return (this->descritor->getInfo() == 0);
}



/**
 * Insere um novo elemento na lista.
 * @param valor
 */
void ListaDescritor::insere(int valor)
{
    No *novo = new No();
    novo->setInfo(valor);
    novo->setProx(NULL);

    if(this->vazia())
    {
        this->descritor->setPrimeiro(novo);
        this->descritor->setUltimo(novo);
    }
    else
    {
        //último nó da lista
        No *ultimo = this->descritor->getProx();
        ultimo->setProx(novo);
        //atualizar o último nó descritor
        this->descritor->setUltimo(novo);
    }

    //atualizar a quantidade de nós da lista;
    int total = this->descritor->getInfo();
    total++;
    this->descritor->setInfo(total);
}

/**
* Realiza a busca de um valor na lista e retorna
* o nó com este valor.
* @param valor
*/
void ListaDescritor::busca(int valor)
{
    No *noBusca = NULL;
    if(this->vazia())
    {
        cout<<"Lista se encontra vazia."<<endl;
        exit(1);
    }
    else if(this->descritor->getAnt()->getInfo() == valor)
    {
        noBusca = this->descritor->getAnt(); //primeiro nó da lista
    }
    else if(this->descritor->getProx()->getInfo() == valor)
    {
        noBusca = this->descritor->getProx(); //ultimo nó da lista
    }
    else
    {
        No *l = this->descritor->getAnt(); // primeiro nó da lista
        while(l!= NULL && l->getInfo()!= valor)
        {
            l = l->getProx();
        }
        noBusca = l;
    }

    //DSGRAPH
    DSGraph ds;
    //DSGRAPH
    if(noBusca != NULL)
    {
        //DSGRAPH
        showComment("Valor %d encontrado...", valor);
        ds.showCPP(this->descritor, 1, noBusca);
        //DSGRAPH
    }
    else
    {
        //DSGRAPH
        showComment("Valor %d nao encontrado...", valor);
        ds.showCPP(this->descritor);
        //DSGRAPH
    }
}


/**
 * Excluir um valor da lista.
 * @param valor
 */
void ListaDescritor::remove(int valor)
{
    No *aux, *l;
    l = this->descritor->getAnt();
    if(l->getInfo() == valor)
    {
        //remover o primeiro nó da lista
        aux = l->getProx();
        this->descritor->setPrimeiro(aux);
        delete l;
    }
    else
    {
        while(l != NULL && l->getInfo() != valor)
        {
            //No anterior
            aux = l;
            l = l->getProx();
        }
        // se existe o valor procurado na lista
        if(l != NULL)
        {
            //verificar se é o último nó
            if(l->getProx() == NULL)
            {
                this->descritor->setUltimo(aux);
                aux->setProx(NULL);
            }
            else
            {
                aux->setProx(l->getProx());
            }

            delete l;
        }
    }

    //atualizar o descritor
    int total = this->descritor->getInfo();
    total--;
    this->descritor->setInfo(total);
}

void ListaDescritor::imprime()
{
    //DSGRAPH
    DSGraph ds;
    ds.showCPP(this->descritor);
    //DSGRAPH
}



