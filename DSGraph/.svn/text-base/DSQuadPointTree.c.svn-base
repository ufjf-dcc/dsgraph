#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <math.h>
#include "DSAllegro.h"
#include "DSStructures.h"
#include "DSConstants.h"
#include "DSMessages.h"
#include "DSGraph.h"
#include "DSQuadPointTree.h"
#include "DSTreeUtils.h"

static TREE_NODE *qVector = NULL;
static BOX box_qtree;
static int aux_red_qtree = 0;
static int aux_green_qtree = 0;
static int aux_blue_qtree = 0;


/**
* Return the head element
*/
static DATA_QUADTREE *frontQPTree(struct Queue *q)
{
    return q->head->str_to_queue;
}

/**
* Init the node  color
* @param: red, green, blue
*/
void setAllegroColorQTree(int red, int green, int blue)
{
    setAllegroColor(red, green, blue);
}

/**
* Malloc a Quad Point Tree
*/
static void malloc_qvector(int size)
{
    qVector = malloc(size * sizeof(TREE_NODE));
    if(qVector==NULL)
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
static void setArrayValueQTree(DATA_QUADTREE* param, int size, int n_args, DATA_QUADTREE* vetor_node[])
{

    DATA_QUADTREE *currentNode;
    Queue q;
    int index=0;
    int i=0;
    int j=0;
    int k = 0;
    COLOR* HL_color_list = (COLOR*)malloc(sizeof(COLOR));



    initializeQueue(&q);

    enqueue(&q, param);

    for(i=0; i<size; i++)
    {

        currentNode = frontQPTree(&q);

        if(currentNode != NULL)
        {
            convertValue(&currentNode->valor,currentNode->valor,  qVector[index].value);

            for(j=0; j < 4; j++)
                qVector[index].plotLine[j]=currentNode->filhos[j]!=NULL?1:0;

            qVector[index].isNull=0;
            qVector[index].aux_blue_tree = aux_blue_qtree;
            qVector[index].aux_green_tree = aux_green_qtree;
            qVector[index].aux_red_tree = aux_red_qtree;


            for(k = 0; k < n_args; k++)
            {
                if(param == vetor_node[k])
                {
                    HL_color_list = getHLColor(k+1);
                    qVector[index].aux_red_tree   = HL_color_list->red;
                    qVector[index].aux_green_tree = HL_color_list->green;
                    qVector[index].aux_blue_tree  = HL_color_list->blue;
                    break;
                }
            }



        }

        index+=1;

        for(j=0; j < 4; j++)
            enqueue(&q, currentNode!=NULL?currentNode->filhos[j]:NULL);



        dequeue(&q);
    }


}

/**
* Set vector position
* @param numberOfNodes
*/
static void setQTreeVectorPosition(int numberOfNodes, int height)
{
    int numberOfNodesLastLine = pow(4, height - 1);

    int lastNodePosition = numberOfNodes - numberOfNodesLastLine;

    int i,j=0;

    for (i = lastNodePosition; i < numberOfNodes; i ++)
    {
        qVector[i].x = 10 + (i- lastNodePosition) * (15 + $NODE_TREE_WIDTH);
        qVector[i].y = ($NODE_TREE_HEIGHT+$NODE_TREE_SPACE_HEIGHT)* height;
    }

    //tem que comentar
    int n = numberOfNodesLastLine - 1 ;

    for (i=lastNodePosition- 1; i>=0; i-- )
    {
        qVector[i].y = qVector[4 * i + 1].y - $NODE_TREE_HEIGHT - $NODE_TREE_SPACE_HEIGHT;
        qVector[i].x = (qVector[i+ n - 1].x + qVector[i + n].x) /2  ;

        for(j = 0; j < 4; j++)
        {

            qVector[i].lines[j] = malloc(sizeof(TREE_LINE));

            if(qVector[i].lines[j] != NULL)
            {
                qVector[i].lines[j]->points[0].x= (qVector[i+ n - 1].x + qVector[i + n].x) /2 + ($NODE_TREE_WIDTH / 2);
                qVector[i].lines[j]->points[0].y= qVector[4 * i + 1].y - $NODE_TREE_SPACE_HEIGHT;

                qVector[i].lines[j]->points[1].x= qVector[4 * i + 1 + j ].x + ($NODE_TREE_WIDTH / 2);
                qVector[i].lines[j]->points[1].y= qVector[4 * i + 1].y;
            }


        }
        n -=3;
    }

}

/**
* Which element is max of?
*@param int a
*@param int b
*/
static int maxQTree(int a, int b, int c, int d)
{
    if(a > b && a > c && a >d)
        return a;
    else if(b>a && b>c && b>d )
        return b;
    else if (c>d && c >a && c >b)
        return c;
    else
        return d;
}

/**
* What's height of the tree?!
* @param DATA_STRUCTURE *param
*/
static int getHeightQTree(DATA_QUADTREE *param)
{
    if((param == NULL) || (param->filhos[0] == NULL && param->filhos[1] == NULL && param->filhos[2] == NULL && param->filhos[3] == NULL))
        return 0;
    else
        return 1 + maxQTree(getHeightQTree(param->filhos[0]), getHeightQTree(param->filhos[1]) , getHeightQTree(param->filhos[2]), getHeightQTree(param->filhos[3]));
}


/**
 * {@inheritDoc}
 */
void showQuadPointTree(DATA_QUADTREE *param, int n_args, va_list opt_par)
{


    int k=0;

    DATA_QUADTREE* vetor_node[n_args];

    for(k = 0; k < n_args; k++)
        vetor_node[k] = va_arg(opt_par,DATA_QUADTREE*);

    va_end(opt_par);

    setTitle($QTREE_NAME);


    aux_red_qtree = getNodeRedColor() == -1 ? $NODE_TREE_RED : getNodeRedColor();
    aux_green_qtree = getNodeGreenColor() == -1 ? $NODE_TREE_GREEN : getNodeGreenColor();
    aux_blue_qtree = getNodeBlueColor() == -1 ? $NODE_TREE_BLUE : getNodeBlueColor();

    int height = 1 + getHeightQTree(param);

    int numberOfNodes = getNumberOfNodes(4,height -1);

    malloc_qvector(numberOfNodes);

    initVector(qVector,numberOfNodes);

    setArrayValueQTree(param, numberOfNodes,n_args,vetor_node);

    setQTreeVectorPosition(numberOfNodes, height);

    plotElementsOnScreen(&box_qtree,qVector,numberOfNodes);

    waitToContinue();

    free(qVector);

}

/**
 * {@inheritDoc}
 */
void setAllegroBorderColorQTree(int red, int green, int blue)
{
    setAllegroBorderColor(red, green, blue);
}

//EOF
