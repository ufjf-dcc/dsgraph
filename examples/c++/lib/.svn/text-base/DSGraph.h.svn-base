/*
+--------------------------------------------------------------------------------------+
|Federal University Of Juiz de Fora - UFJF - Minas Gerais - Brazil                     |
|Institute for Exact Sciences - ICE                                                    |
|Computer Science Departament - DCC                                                    |
|Project: Visual library to support Data Structures classes                            |
|Professor:Jairo Francisco de Souza    jairo.souza@ufjf.edu.br                         |
|Students......:Thiago Moratori Peixoto     thiagomoratori@gmail.com                   |
|               Sandro Athaide Coelho       sandroacoelho@gmail.com                    |
|               Ana Carolina G. Fidelis     acarolinafg@gmail.com                      |
|               Davi Guimaraes Silva        davi150889@gmail.com		               |
|               Maria Rosangela Almeida     rosangelajf2008@gmail.com                  |
|Created in......:March/31/2011                                                        |
|Objective: this file is the head of the library                                       |
|Latest updates                                                                        |
|                                                                                      |
|                                                                                      |
|                                                                                      |
|                                                                                      |
|                                                                                      |
|--------------------------------------------------------------------------------------+
 */
//BOF
#ifndef DSGRAPH__HEAD_FILE
#define DSGRAPH__HEAD_FILE


/**
 * Set DSGraph data type
 */
#define setDataType(dt) setDSGraphDataType(sizeof(dt));

#ifndef __cplusplus
#include <stdlib.h>
//Main structure. You need to put it on the DSGraph.h

typedef struct NODE_STRUCTURE
{
    void *valor; //value (content)
    int marca; //used on red-black tree
    struct NODE_STRUCTURE *proximo; //right child
    struct NODE_STRUCTURE *anterior; //left child
    struct NODE_STRUCTURE *pai; //middle child

} DATA_STRUCTURE;

// Ternary tree structure. You need to put it on the DSGraph.h

typedef struct NODE_TERNARY
{
    void *valor; //value (content)

    struct NODE_TERNARY *direito; //right child
    struct NODE_TERNARY *esquerdo; //left child
    struct NODE_TERNARY *centro; //middle child

} DATA_TERNARY;


// Quad Tree structure. You need to put it on the DSGraph.h

typedef struct NODE_QUADTREE
{
    void *valor; //value (content)
    float x;
    float y;
    struct NODE_QUADTREE * filhos[4]; //children

} DATA_QUADTREE;

typedef struct NODE_B_TREE
{
    void *CHAVES[99];
    struct NODE_B_TREE *filhos[100];

} NODE_B_TREE;

#endif


#ifdef __cplusplus
extern "C" {
#endif


//STRUCTURES
#define $PILHA                       1
#define $LISTA                       10
#define $VETOR                       20
#define $VETOR_MULTIDIMENSIONAL      30
#define $STRING                      40
#define $PONTEIRO                    50
#define $ARVORE_BINARIA              60
#define $LISTA_DESCRITOR             70
#define $ARVORE_VERMELHO_PRETO       80
#define $POINT_QUADTREE              90
#define $ARVORE_TERNARIA             100
#define $ARVORE_B                    110

//COLOR TREE RED_BLACK
#define $BLACK 1
#define $RED 2

    /*
     * Initialize the library with the structure
     * @param: int typeOfStructure- Type of the structure
     */
    void init(int typeOfStructure, ...);

    /*
     * Show the screen
     * @param struct NODE_STRUCTURE *param - the parameter
     */
    void show(void *param, int n_args, ...);

    /*
     * Set the sleep time
     * @param seconds
     */
    void setSleepTime(int seconds);

    /*
     * Init the node border color
     * @param: red, green, blue
     */
    void setBorderColor(int red, int green, int blue);

    /*
     * Init the node  color
     * @param: red, green, blue
     */
    void setNodeColor(int red, int green, int blue);

    /*
     * Finalize and clean all used DSGraph resources from memory
     */
    void terminateDSGraph();

    /*
     * Set if DSGraphs need to show the memory address
     * @param: value - 0  - doesn't show
     *         value - 1  - show
     */
    void setViewAddress(int value);


    /*
     * Set a text on screen
     * @param string - a message
     **/
    void showComment(const char *string, ...);


    /**
     * Set DSGraph data type
     * @param sizeOfDataType
     */
    void setDSGraphDataType(int sizeOfDataType);


    int getStructure();

#ifdef __cplusplus
}
#endif




#ifdef __cplusplus
using namespace std;


typedef struct NODE_STRUCTURE
{
    void *valor;  //value (content)
    int marca;   //used on red-black tree
    struct NODE_STRUCTURE *proximo;   //right child
    struct NODE_STRUCTURE *anterior;  //left child
    struct NODE_STRUCTURE *pai; //middle child

} NODE_STRUCTURE;


class DSGraphStr
{

public:

    DSGraphStr() {};

    //Destrutor
    virtual ~DSGraphStr() {};

    virtual int getInfo()
    {
        return -1;
    };

    virtual DSGraphStr * getProx()
    {
        return NULL;
    };

    virtual DSGraphStr * getAnt()
    {
        return NULL;
    };

    virtual DSGraphStr * getPai()
    {
        return NULL;
    };

    virtual int getMarca()
    {
        return -1;
    };

};

class DSGraph
{
    DSGraphStr *t;
    DSGraphStr *primeiro;
    NODE_STRUCTURE *ns_primeiro;
    int pLista;

private:

    NODE_STRUCTURE *convertToDsGraph()
    {

        NODE_STRUCTURE *result = new NODE_STRUCTURE();

        int str = getStructure();
        primeiro = t;
        pLista = 0;

        if (str == $LISTA_DESCRITOR)
        {
            return getDescritor(t, result);
        }
        else if ( str == $LISTA)
        {
            return getLista(t, result,result);
        }
        return  getProx(t, result);

    }

    NODE_STRUCTURE * getLista(DSGraphStr *t, NODE_STRUCTURE *result, NODE_STRUCTURE *current_node)
    {
        if (t != NULL )
        {


            if (t->getAnt()!=NULL && t->getAnt()->getProx() == t )
                result->anterior = current_node;


            if(t == primeiro && pLista!=0)
            {
                ns_primeiro->anterior = current_node;
               return ns_primeiro;
            }

            if(t == primeiro && pLista==0)
            {
                pLista +=1;
                ns_primeiro = result;
            }

            result->proximo = getLista(t->getProx(), new NODE_STRUCTURE(), result);

            result->valor = (void*) (intptr_t) getInfo(t);

            return result;
        }

         return NULL;
    }

    NODE_STRUCTURE * getDescritor(DSGraphStr *t, NODE_STRUCTURE *result )
    {
        if (t != NULL )
        {
            result->valor = (void *) (intptr_t) getInfo(t);
            primeiro = t->getProx();
            result->proximo = getProxDesc(t->getProx(), new NODE_STRUCTURE(),result);
            pLista = 0 ;
            result->anterior = getProxDesc(t->getAnt(), new NODE_STRUCTURE(),result);
             return result;
        }
       return NULL;
    }

    int getInfo(DSGraphStr *t)
    {
        try
        {
            return t->getInfo();
        }
        catch (int e)
        {
            return -1;
        }
    }

    NODE_STRUCTURE * getProxDesc(DSGraphStr *t, NODE_STRUCTURE *result, NODE_STRUCTURE *current_node)
    {
        try
        {
            if (t != NULL )
            {

                if(t == primeiro && pLista!=0)
                    return NULL;

                if(t == primeiro && pLista==0)
                    pLista +=1;

                result->proximo = getProxDesc(t->getProx(), new NODE_STRUCTURE(), result);

                if (t->getAnt()!=NULL && t->getAnt()->getProx() == t )
                    result->anterior = current_node;


                result->pai = getPai(t->getPai(), new NODE_STRUCTURE());
                result->marca = getMarca(t);
                result->valor = (void*)(intptr_t) getInfo(t);
                return result;
            }
            return NULL;
        }
        catch (int e)
        {
            return NULL;
        }
    }

    NODE_STRUCTURE * getProx(DSGraphStr *t, NODE_STRUCTURE *result)
    {
        try
        {
            if (t != NULL )
            {
                result->proximo = getProx(t->getProx(), new NODE_STRUCTURE());
                result->anterior = getAnt(t->getAnt(), new NODE_STRUCTURE());
                result->pai = getPai(t->getPai(), new NODE_STRUCTURE());
                result->marca = getMarca(t);
                result->valor = (void *)(intptr_t) getInfo(t);
                return result;
            }
            return NULL;
        }
        catch (int e)
        {
            return NULL;
        }
    }

    NODE_STRUCTURE* getAnt(DSGraphStr *t, NODE_STRUCTURE *result)
    {
        try
        {
            if (t != NULL)
            {
                result->proximo = getProx(t->getProx(), new NODE_STRUCTURE());
                result->anterior = getAnt(t->getAnt(), new NODE_STRUCTURE());
                result->pai = getPai(t->getPai(), new NODE_STRUCTURE());
                result->marca = getMarca(t);
                result->valor = (void *)(intptr_t) getInfo(t);
                return result;
            }

            return NULL;

        }
        catch (int e)
        {
            return NULL;
        }

    }

    NODE_STRUCTURE * getPai(DSGraphStr *t, NODE_STRUCTURE *result )
    {
        try
        {
            if (t != NULL)
            {
                result->proximo = getProx(t->getProx(), new NODE_STRUCTURE());
                result->anterior = getAnt(t->getAnt(), new NODE_STRUCTURE());
                result->pai = getPai(t->getPai(), new NODE_STRUCTURE());
                result->marca = getMarca(t);
                result->valor = (void *) (intptr_t)getInfo(t);
                return result;
            }

            return NULL;
        }
        catch (int e)
        {
            return NULL;
        }

    }

    int getMarca(DSGraphStr *t)
    {
        try
        {
            return t->getMarca();
        }
        catch (int e)
        {
            return -1;
        }

    }

public:

    void showCPP(DSGraphStr *p, int n_args = 0, ...)
    {
        t = p;
        show(convertToDsGraph(), n_args);
    }

};

#endif




#endif

//EOF

