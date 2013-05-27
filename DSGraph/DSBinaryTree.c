//BOF
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <math.h>
#include "DSAllegro.h"
#include "DSStructures.h"
#include "DSConstants.h"
#include "DSMessages.h"
#include "DSGraph.h"
#include "DSBinaryTree.h"
#include "DSTreeUtils.h"

static TREE_NODE *bVector = NULL;
static BOX box_btree;
static int aux_red_btree = 0;
static int aux_green_btree = 0;
static int aux_blue_btree = 0;

/**
* Return the head element
* @param q - queue
*/
static DATA_STRUCTURE *frontBTree(struct Queue *q)
{
    return q->head->str_to_queue;
}

/**
 * {@inheritDoc}
 */
void setAllegroColorBTree(int red, int green, int blue)
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

/**
* Put the elements on the vector
//reading transversely on tree
//  Start --->  /A\
//    B\        /C\
//      D      E   F ---> End
*/
static void setArrayValueBTree(DATA_STRUCTURE *param, int size,int type_tree, int n_args, DATA_STRUCTURE* vetor_node[])
{

    DATA_STRUCTURE *currentNode;
    Queue q;
    int index=0;
    int i=0;
    int k = 0;
    COLOR* HL_color_list = (COLOR*)malloc(sizeof(COLOR));

    initializeQueue(&q);

    enqueue(&q, param);



    for(i=0; i<size; i++)
    {
        currentNode = frontBTree(&q);

        if (currentNode !=NULL)
        {
            convertValue(&currentNode->valor,currentNode->valor,  bVector[index].value);
            bVector[index].isNull=0;
            bVector[index].plotLine[0]=currentNode->anterior!=NULL?1:0;
            bVector[index].plotLine[1]=currentNode->proximo!=NULL?1:0;
            bVector[index].boxWithDivision=1;

            //tree black-red
            if(type_tree == $ARVORE_VERMELHO_PRETO )
            {
                if(currentNode->marca == 0)
                {
                    aux_red_btree   = 0;
                    aux_green_btree = 0;
                    aux_blue_btree  = 0;
                }
                else
                {
                    aux_red_btree   = 255;
                    aux_green_btree = 0;
                    aux_blue_btree  = 0;
                }
            }

            bVector[index].aux_blue_tree = aux_blue_btree;
            bVector[index].aux_green_tree = aux_green_btree;
            bVector[index].aux_red_tree = aux_red_btree;

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


        }

        index+=1;

        enqueue(&q, currentNode!=NULL?currentNode->anterior:NULL);

        enqueue(&q, currentNode!=NULL?currentNode->proximo:NULL);

        dequeue(&q);
    }


}

/**
* Set vector position
* @param numberOfNodes
* @param height
*/
static void setVectorPosition(int numberOfNodes ,  int height )
{
    int i,j=0;

    for (i=numberOfNodes/2; i<numberOfNodes ; i++ )
    {
        bVector[i].x = 10 + (i - numberOfNodes/2) * ( 15 + $NODE_TREE_WIDTH ) ;
        bVector[i].y = ($NODE_TREE_HEIGHT+$NODE_TREE_SPACE_HEIGHT)* height;
    }



    for (i=numberOfNodes/2 - 1; i>=0; i-- )
    {
        bVector[i].y = bVector[2 * i + 1].y - $NODE_TREE_HEIGHT - $NODE_TREE_SPACE_HEIGHT;
        bVector[i].x = (bVector[2*i + 1].x + bVector[2*i + 2].x) /2 ;

        for(j = 0; j < 2; j++)
        {

            bVector[i].lines[j] = malloc(sizeof(TREE_LINE));

            if(bVector[i].lines[j] != NULL)
            {
                bVector[i].lines[j]->points[0].x= (bVector[2*i + 1].x + bVector[2*i + 2].x) /2   + j* $NODE_TREE_WIDTH ;
                bVector[i].lines[j]->points[0].y= bVector[2 * i + 1].y - $NODE_TREE_SPACE_HEIGHT - $NODE_TREE_SPACE_HEIGHT/2;

                bVector[i].lines[j]->points[1].x= bVector[2 * i + 1 + j ].x + ($NODE_TREE_WIDTH / 2);
                bVector[i].lines[j]->points[1].y= bVector[2 * i + 1].y;
            }


        }
    }

}

/**
* Which element is max of?
*@param int a
*@param int b
*/
static int max(int a, int b)
{
    if(a > b)
        return a;
    else
        return b;
}

/**
* What's height of the tree?!
* @param DATA_STRUCTURE *param
*/
static int getHeight(DATA_STRUCTURE *param)
{
    if((param == NULL) || (param->anterior == NULL && param->proximo == NULL))
        return 0;
    else
        return 1 + max(getHeight(param->anterior), getHeight(param->proximo));
}


/**
 * {@inheritDoc}
 */
void showBTree(DATA_STRUCTURE *param, int type_tree, int n_args, va_list opt_par)
{


    int k=0;

    DATA_STRUCTURE* vetor_node[n_args];

    for(k = 0; k < n_args; k++)
        vetor_node[k] = va_arg(opt_par, DATA_STRUCTURE*);

    va_end(opt_par);

    if (type_tree == $ARVORE_BINARIA) setTitle($BTREE_NAME);

    if(type_tree == $ARVORE_VERMELHO_PRETO) setTitle($BRTREE_NAME);

    aux_red_btree = getNodeRedColor() == -1 ? $NODE_TREE_RED : getNodeRedColor();
    aux_green_btree = getNodeGreenColor() == -1 ? $NODE_TREE_GREEN : getNodeGreenColor();
    aux_blue_btree = getNodeBlueColor() == -1 ? $NODE_TREE_BLUE : getNodeBlueColor();

    int height = 1 + getHeight(param);

    int numberOfNodes = pow(2,height) - 1;

    malloc_bvector(numberOfNodes);

    initVector(bVector,numberOfNodes);

    setArrayValueBTree(param, numberOfNodes,type_tree, n_args,vetor_node);

    setVectorPosition(numberOfNodes,height);

    plotElementsOnScreen(&box_btree,bVector,numberOfNodes);

    waitToContinue();

    free(bVector);

}

/**
 * {@inheritDoc}
 */
void setAllegroBorderColorBTree(int red, int green, int blue)
{
    setAllegroBorderColor(red, green, blue);
}
/**
 * {@inheritDoc}
 */
void setBTreeViewAddress(int value)
{

}

//EOF

