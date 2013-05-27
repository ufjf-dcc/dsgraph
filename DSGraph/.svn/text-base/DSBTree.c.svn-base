//BOF
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <math.h>
#include "DSAllegro.h"
#include "DSStructures.h"
#include "DSConstants.h"
#include "DSMessages.h"
#include "DSGraph.h"
#include "DSBinaryTree.h"
#include "DSTreeUtils.h"

static B_TREE_NODE *bVector = NULL;
static BOX_B *mainVector = NULL;
static BOX box_btree;
static int aux_red_btree = 0;
static int aux_green_btree = 0;
static int aux_blue_btree = 0;
static int MAX_FILHOS = 0;


void initBVector(B_TREE_NODE *vector, int size);
int getHeight_B_Tree(NODE_B_TREE *param);
void plotBElementsOnScreen(BOX *b,int numberOfNodes,int mainVectorSize, int NumberOfKeys);
static void setArrayValueBTree(NODE_B_TREE *param, int t, int n_args, NODE_B_TREE* vetor_node[],int numberOfNodes);
void organizaPosicaoBoxes(int mainVectorSize, int NumberOfKeys);


/**
* Return the head element
* @param q - queue
*/
static NODE_B_TREE *frontBTree(struct Queue *q)
{
    return q->head->str_to_queue;
}


/**
 * {@inheritDoc}
 */
void setAllegroColorB(int red, int green, int blue)
{
    setAllegroColor(red, green, blue);
}


/**
* Malloc Binary Tree
*/
static void malloc_bvector(int size)
{
    bVector = malloc(size * sizeof(TREE_NODE));
    if(bVector==NULL)
    {
        printf($MSG_MALLOC_NODE);
        finalize();
    }

}

static void malloc_mainVector(int size)
{
    mainVector = malloc(size * sizeof(BOX_B));
    if(mainVector==NULL)
    {
        printf($MSG_MALLOC_NODE);
        finalize();
    }
}

static int maxBTreeChildren(NODE_B_TREE *param, int MAX_FILHOS)
{

    int i;
    int max = 0;
    for (i=0; i< MAX_FILHOS; i++)
    {
        int atual = getHeight_B_Tree(param->filhos[i]);
        max = (atual > max) ? atual : max;
    }
    return max;
}


int getHeight_B_Tree(NODE_B_TREE *param)
{
    int i;
    int teste = (param == NULL);
    for (i=0; i<MAX_FILHOS; i++)
        teste += (param->filhos[i] == NULL);

    if(teste != 0)
        return 1;
    else
        return 1 + maxBTreeChildren(param, MAX_FILHOS);
}


/**
* Put the elements on the vector
//reading transversely on tree
//  Start --->  /A\
//    B\        /C\
//      D      E   F ---> End
*/
static void setArrayValueBTree(NODE_B_TREE *param, int t, int n_args, NODE_B_TREE* vetor_node[],int numberOfNodes)
{

    int number = numberOfNodes;

    NODE_B_TREE *currentNode;
    Queue q;
    int aux = 0;
    int j=0;
    int k = 0;
    int m = 0;
    int index = 0;
    COLOR* HL_color_list = (COLOR*)malloc(sizeof(COLOR));

    initializeQueue(&q);

    enqueue(&q, param);

    currentNode = frontBTree(&q);

    for(aux = 0; aux <= number; aux++)
    {

        for(j=0; j< t+1; j++)
        {
            if(currentNode != NULL)
                enqueue(&q, currentNode->filhos[j]);
            else
                enqueue(&q, NULL);
        }

        for(m =0; m<t; m++)
        {
            if(currentNode != NULL)
            {

                convertValue(&currentNode->CHAVES[m],currentNode->CHAVES[m],  bVector[index].value);

                bVector[index].isNull = 0;

                bVector[index].aux_blue_tree = aux_blue_btree;
                bVector[index].aux_green_tree = aux_green_btree;
                bVector[index].aux_red_tree = aux_red_btree;
            }

            for(k = 0; k < n_args; k++)
            {
                if(param == vetor_node[k])
                {
                    HL_color_list = getHLColor(k+1);
                    bVector[index].aux_red_tree   = HL_color_list->red;
                    bVector[index].aux_green_tree = HL_color_list->green;
                    bVector[index].aux_blue_tree  = HL_color_list->blue;
                    break;
                }
            }

            index+=1;

        }

        dequeue(&q);

        currentNode = frontBTree(&q);
    }
}

/**
* Set vector position
* @param numberOfNodes
* @param height
*/
static void setMainVectorPosition(int NumberOfKeys,  int height, int mainVectorSize)
{

    int recuo = NumberOfKeys / 2;

    int numeroDeFihos = NumberOfKeys + 1;

    int numberOfNodesLastLine = pow(numeroDeFihos, height - 1);

    int lastNodePosition = (mainVectorSize - numberOfNodesLastLine) + 1;


    int i,j=0;

    //Setando Valores x,y para os nós da ultima linha da árvore
    for (i = lastNodePosition; i <= mainVectorSize; i ++)
    {
        mainVector[i].x = 10 + (i- lastNodePosition) * ((5 + $NODE_BTREE_WIDTH)*NumberOfKeys);
        mainVector[i].y = ($NODE_BTREE_HEIGHT+$NODE_TREE_SPACE_HEIGHT)* height;
    }

    //Para árvores com número de filhos ímpares
    if((NumberOfKeys % 2) == 0)
    {
        int n = numberOfNodesLastLine - recuo;

        for (i=lastNodePosition- 1; i>=0; i-- )
        {
            mainVector[i].y = mainVector[numeroDeFihos * i + 1].y - $NODE_TREE_HEIGHT - $NODE_TREE_SPACE_HEIGHT;
            mainVector[i].x = mainVector[i + n].x ;

            for(j = 0; j < numeroDeFihos; j++)
            {

                mainVector[i].lines[j] = malloc(sizeof(TREE_LINE));

                if(mainVector[i].lines[j] != NULL)
                {
                    mainVector[i].lines[j]->points[0].x= mainVector[i + n].x  + (j* ($NODE_BTREE_WIDTH));
                    mainVector[i].lines[j]->points[0].y= mainVector[numeroDeFihos * i + 1].y - $NODE_BTREE_SPACE_HEIGHT;

                    mainVector[i].lines[j]->points[1].x= mainVector[numeroDeFihos * i + 1 + j ].x + ($NODE_BTREE_WIDTH);
                    mainVector[i].lines[j]->points[1].y= mainVector[numeroDeFihos * i + 1].y;
                }

            }

            n -= NumberOfKeys;

        }


    }
    //Para árvores com número de filhos pares
    else
    {
        //Árvores com 2 filhos
        if(NumberOfKeys == 1)
        {
            for (i = mainVectorSize/2 - 1; i>=0; i-- )
            {
                mainVector[i].y = mainVector[2 * i + 1].y - $NODE_TREE_HEIGHT - $NODE_TREE_SPACE_HEIGHT;
                mainVector[i].x = (mainVector[2*i + 1].x + mainVector[2*i + 2].x) /2 ;

                for(j = 0; j < numeroDeFihos; j++)
                {
                    mainVector[i].lines[j] = malloc(sizeof(TREE_LINE));

                    if(mainVector[i].lines[j] != NULL)
                    {
                        mainVector[i].lines[j]->points[0].x= (mainVector[2*i + 1].x + mainVector[2*i + 2].x) /2   + j* $NODE_BTREE_WIDTH ;
                        mainVector[i].lines[j]->points[0].y= mainVector[2 * i + 1].y - $NODE_BTREE_SPACE_HEIGHT;

                        mainVector[i].lines[j]->points[1].x= mainVector[2 * i + 1 + j ].x + ($NODE_BTREE_WIDTH / 2);
                        mainVector[i].lines[j]->points[1].y= mainVector[2 * i + 1].y;
                    }

                }


            }
        }
        //Árvores com mais de 2 filhos
        else
        {
            int n = numberOfNodesLastLine - recuo ;
            for (i=lastNodePosition- 1; i>=0; i-- )
            {
                mainVector[i].y = mainVector[numeroDeFihos * i + 1].y - $NODE_TREE_HEIGHT - $NODE_TREE_SPACE_HEIGHT;
                mainVector[i].x = (mainVector[i+ n - 1].x + mainVector[i + n].x) /2 ;


                for(j = 0; j < numeroDeFihos; j++)
                {
                    mainVector[i].lines[j] = malloc(sizeof(TREE_LINE));

                    if(mainVector[i].lines[j] != NULL)
                    {

                        mainVector[i].lines[j]->points[0].x= (mainVector[i+ n - 1].x + mainVector[i + n].x) /2 + (j * $NODE_BTREE_WIDTH);
                        mainVector[i].lines[j]->points[0].y= mainVector[numeroDeFihos * i + 1].y - $NODE_BTREE_SPACE_HEIGHT;


                        mainVector[i].lines[j]->points[1].x= mainVector[numeroDeFihos * i + 1 + j ].x + ($NODE_BTREE_WIDTH);
                        mainVector[i].lines[j]->points[1].y= mainVector[numeroDeFihos * i + 1].y;
                    }

                }

                n -= NumberOfKeys;
            }

        }

    }
}

void initMainVector(B_TREE_NODE *vector,int NumberOfKeys, int numberOfNodes, int mainVectorSize)
{

    int i = 0;
    int j = 0;
    int help = 0;
    int l = 0;

    for (i=0; i <= mainVectorSize; i++)
    {

        mainVector[i].x = 0;
        mainVector[i].y = 0;

        for(l = 0; l <= 35; l++)
        {
            mainVector[i].plotLine[l] = 0;
            mainVector[i].lines[l] = NULL;
        }

        for(j = 0; j <NumberOfKeys; j++)
        {
            mainVector[i].boxes[j] = vector[help];
            help++;

        }
    }
}



/**
 * {@inheritDoc}
 */
void showB(NODE_B_TREE *param, int type_tree, int n_args, va_list opt_par,int NumberOfKeys)
{
    int k=0;

    NODE_B_TREE* vetor_node[n_args];

    for(k = 0; k < n_args; k++)
        vetor_node[k] = va_arg(opt_par, NODE_B_TREE*);

    va_end(opt_par);

    if (type_tree == $ARVORE_BINARIA) setTitle($BTREE_NAME);

    if(type_tree == $ARVORE_VERMELHO_PRETO) setTitle($BRTREE_NAME);

    aux_red_btree = getNodeRedColor() == -1 ? $NODE_TREE_RED : getNodeRedColor();
    aux_green_btree = getNodeGreenColor() == -1 ? $NODE_TREE_GREEN : getNodeGreenColor();
    aux_blue_btree = getNodeBlueColor() == -1 ? $NODE_TREE_BLUE : getNodeBlueColor();

    MAX_FILHOS = NumberOfKeys + 1;

    int height = getHeight_B_Tree(param);

    int numberOfNodes = pow((NumberOfKeys + 1),height) - 1;

    int mainVectorSize = getNumberOfNodes(NumberOfKeys + 1,height - 1) - 1;

    malloc_bvector(numberOfNodes);

    malloc_mainVector(mainVectorSize + 1);

    initBVector(bVector,numberOfNodes);

    setArrayValueBTree(param,NumberOfKeys, n_args,vetor_node,numberOfNodes);

    initMainVector(bVector,NumberOfKeys,numberOfNodes,mainVectorSize);

    setMainVectorPosition(NumberOfKeys,height,mainVectorSize);

    organizaPosicaoBoxes(mainVectorSize,NumberOfKeys);

    plotBElementsOnScreen(&box_btree,numberOfNodes,mainVectorSize,NumberOfKeys);

    waitToContinue();

    free(bVector);

}

/**
 * {@inheritDoc}
 */
void setAllegroBorderColorB(int red, int green, int blue)
{
    setAllegroBorderColor(red, green, blue);
}



void initBVector(B_TREE_NODE *vector, int size)
{
    int i = 0;

    for (i=0; i<size; i++)
    {
        vector[i].x=0;
        vector[i].y=0;
        vector[i].aux_red_tree=0;
        vector[i].aux_green_tree=0;
        vector[i].aux_blue_tree=0;
        vector[i].isNull = 1;
    }
}


void organizaPosicaoBoxes(int mainVectorSize, int NumberOfKeys)
{
    int i = 0;
    int j = 0;
    int position = 0;

    for(i = 0; i <= mainVectorSize; i++)
    {
        position = 0;

        for(j = 0; j < NumberOfKeys; j++)
        {

            mainVector[i].boxes[j].y = mainVector[i].y;
            mainVector[i].boxes[j].x = mainVector[i].x + position;
            mainVector[i].plotLine[j] = 1;

            position = position + $NODE_BTREE_WIDTH;

        }
    }
}


void plotBElementsOnScreen(BOX *b,int numberOfNodes,int mainVectorSize, int NumberOfKeys)
{
    int i = 0;
    int j = 0;
    int k = 0;

    int numeroDeFihos = NumberOfKeys + 1;

    for(i = 0; i <= mainVectorSize; i++)
    {
        for(j = 0; j < NumberOfKeys; j++)
        {

            if(mainVector[i].boxes[j].isNull == 0)
            {

                strcpy(b->value,mainVector[i].boxes[j].value);
                b->x = mainVector[i].boxes[j].x;
                b->y = mainVector[i].boxes[j].y;
                b->x_label = getPosCentralizedLabel(b->value,mainVector[i].boxes[j].x,$NODE_BTREE_WIDTH) - 5;
                b->y_label = mainVector[i].boxes[j].y + 10;
                b->width = $NODE_BTREE_WIDTH;
                b->height = $NODE_BTREE_HEIGHT;
                b->border_red = $NODEBORDER_TREE_RED ;
                b->border_green = $NODEBORDER_TREE_GREEN;
                b->border_blue = $NODEBORDER_TREE_BLUE;
                b->red   = aux_red_btree;
                b->green = aux_green_btree;
                b->blue  = aux_blue_btree;

                b->font_blue  = b->red==0 && b->green==0 && b->blue==0?255:0 ;
                b->font_green = b->red==0 && b->green==0 && b->blue==0?255:0;
                b->font_red   = b->red==0 && b->green==0 && b->blue==0?255:0;
                drawBox(b);
            }
        }


        for(k = 0; k < numeroDeFihos; k++)
        {
            if(i > (mainVectorSize/numeroDeFihos) - 1)
                break;

            int posicao = numeroDeFihos * i + 1 + k;

            if(mainVector[i].lines[k] !=NULL && mainVector[posicao].boxes[0].isNull == 0)
            {
                drawLine(mainVector[i].lines[k]->points[0].x, mainVector[i].lines[k]->points[0].y,
                         mainVector[i].lines[k]->points[1].x, mainVector[i].lines[k]->points[1].y);
            }


        }

    }


}

//EOF

