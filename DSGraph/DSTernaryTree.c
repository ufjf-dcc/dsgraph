#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <math.h>
#include "DSAllegro.h"
#include "DSStructures.h"
#include "DSConstants.h"
#include "DSMessages.h"
#include "DSGraph.h"
#include "DSTernaryTree.h"
#include "DSTreeUtils.h"

static TREE_NODE *tVector = NULL;
static BOX box_ttree;
static int aux_red_ttree = 0;
static int aux_green_ttree = 0;
static int aux_blue_ttree = 0;

/**
* Return the head element
* @param q - queue
*/
static struct NODE_TERNARY *frontTTree(struct Queue *q)
{
    return q->head->str_to_queue;
}

/**
* Malloc Ternary Tree
*/
static void malloc_tvector(int size)
{
    tVector = malloc(size * sizeof(TREE_NODE));
    if(tVector==NULL)
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
static void setArrayValueTTree(DATA_TERNARY* param, int size, int n_args, DATA_TERNARY* vetor_node[])
{

    DATA_TERNARY *currentNode;
    Queue q;
    int index=0;
    int i=0;
    int k = 0;
    COLOR* HL_color_list = (COLOR*)malloc(sizeof(COLOR));

    initializeQueue(&q);

    enqueue(&q, param);

    for(i=0; i<size; i++)
    {

        currentNode = frontTTree(&q);

        if(currentNode != NULL)
        {

            convertValue(&currentNode->valor,currentNode->valor,  tVector[index].value);



            tVector[index].plotLine[0]=currentNode->esquerdo!=NULL?1:0;
            tVector[index].plotLine[1]=currentNode->centro!=NULL?1:0;
            tVector[index].plotLine[2]=currentNode->direito!=NULL?1:0;

            tVector[index].aux_blue_tree = aux_blue_ttree;
            tVector[index].aux_green_tree = aux_green_ttree;
            tVector[index].aux_red_tree = aux_red_ttree;

            tVector[index].isNull=0;


            for(k = 0; k < n_args; k++)
            {
                if(param == vetor_node[k])
                {
                    HL_color_list = getHLColor(k+1);
                    tVector[index].aux_red_tree   = HL_color_list->red;
                    tVector[index].aux_green_tree = HL_color_list->green;
                    tVector[index].aux_blue_tree  = HL_color_list->blue;
                    break;
                }
            }
        }

        index +=1;
        enqueue(&q, currentNode!=NULL?currentNode->esquerdo:NULL);
        enqueue(&q, currentNode!=NULL?currentNode->centro:NULL);
        enqueue(&q, currentNode!=NULL?currentNode->direito:NULL);

        dequeue(&q);
    }


}

/**
* Set vector position
* @param numberOfNodes
* @param height
*/
static void setTTreeVectorPosition(int numberOfNodes , int height)
{

    int numberOfNodesLastLine = pow(3, height - 1);

    int lastNodePosition = numberOfNodes - numberOfNodesLastLine;

    int i,j=0;

    for (i = lastNodePosition; i < numberOfNodes; i ++)
    {
        tVector[i].x = 10 + (i- lastNodePosition) * (15 + $NODE_TREE_WIDTH);
        tVector[i].y = ($NODE_TREE_HEIGHT+$NODE_TREE_SPACE_HEIGHT)* height;
    }

    //tem que comentar
    int n = numberOfNodesLastLine - 1 ;

    for (i=lastNodePosition- 1; i>=0; i-- )
    {
        tVector[i].y = tVector[3 * i + 1].y - $NODE_TREE_HEIGHT - $NODE_TREE_SPACE_HEIGHT;
        tVector[i].x = tVector[i + n].x  ;

        for(j = 0; j < 3; j++)
        {

            tVector[i].lines[j] = malloc(sizeof(TREE_LINE));

            if(tVector[i].lines[j] != NULL)
            {
                tVector[i].lines[j]->points[0].x= tVector[i + n].x  + (j* ($NODE_TREE_WIDTH / 2));
                tVector[i].lines[j]->points[0].y= tVector[3 * i + 1].y - $NODE_TREE_SPACE_HEIGHT;

                tVector[i].lines[j]->points[1].x= tVector[3 * i + 1 + j ].x + ($NODE_TREE_WIDTH / 2);
                tVector[i].lines[j]->points[1].y= tVector[3 * i + 1].y;
            }

        }

        n -=2;
    }

}

/**
* Which element is max of?
*@param int a
*@param int b
*/
static int maxTTree(int a, int b, int c)
{
    if(a > b && a > c)
        return a;
    else if(b> c )
        return b;
    else
        return c;
}

/**
* What's height of the tree?!
* @param DATA_TERNARY *param
*/
static int getHeightTTree(DATA_TERNARY *param)
{
    if((param == NULL) || (param->esquerdo == NULL && param->centro == NULL && param->direito == NULL))
        return 0;
    else
        return 1 + maxTTree(getHeightTTree(param->esquerdo), getHeightTTree(param->centro) , getHeightTTree(param->direito));
}

/**
 * {@inheritDoc}
 */
void showTernaryTree(DATA_TERNARY *param, int n_args, va_list opt_par)
{

    int k=0;

    DATA_TERNARY* vetor_node[n_args];

    for(k = 0; k < n_args; k++)
        vetor_node[k] = va_arg(opt_par,DATA_TERNARY*);

    va_end(opt_par);

    setTitle($TTREE_NAME);

    aux_red_ttree = getNodeRedColor() == -1 ? $NODE_TREE_RED : getNodeRedColor();
    aux_green_ttree = getNodeGreenColor() == -1 ? $NODE_TREE_GREEN : getNodeGreenColor();
    aux_blue_ttree = getNodeBlueColor() == -1 ? $NODE_TREE_BLUE : getNodeBlueColor();

    int height = 1 + getHeightTTree(param);

    int numberOfNodes = getNumberOfNodes(3,height -1);

    malloc_tvector(numberOfNodes);

    initVector(tVector,numberOfNodes);

    setArrayValueTTree(param, numberOfNodes, n_args,vetor_node);

    setTTreeVectorPosition(numberOfNodes, height);

    plotElementsOnScreen(&box_ttree,tVector,numberOfNodes);

    waitToContinue();

    free(tVector);

}

/**
 * {@inheritDoc}
 */
void setAllegroColorTTree(int red, int green, int blue)
{
    setAllegroColor(red, green, blue);
}

/**
 * {@inheritDoc}
 */
void setAllegroBorderColorTTree(int red, int green, int blue)
{
    setAllegroBorderColor(red, green, blue);
}

//EOF
