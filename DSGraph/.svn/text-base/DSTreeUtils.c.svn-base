#include <stdio.h>
#include <stdlib.h>
#include "DSStructures.h"
#include "DSTreeUtils.h"
#include "DSConstants.h"
#include "DSAllegro.h"
#include "DSGraph.h"
#include <string.h>
#include <math.h>


/**
 * {@inheritDoc}
 */
void initializeQueue(struct Queue *q)
{
    q->head = NULL;
    q->tail = NULL;
}

/**
 * {@inheritDoc}
 */
void enqueue(struct Queue *q, void *str_to_queue)
{
    QueueElement *theElement;
    theElement = (QueueElement*) malloc(sizeof(QueueElement));

    theElement->str_to_queue=str_to_queue;

    if (q->head == NULL)
    {
        q->head = theElement;
        q->tail = theElement;
    }
    else
    {
        q->tail->next = theElement;
        q->tail = theElement;
    }
}

/**
 * {@inheritDoc}
 */
void dequeue(struct Queue *q)
{
    QueueElement *element;
    if (q->head == NULL)
    {
        return;
    }
    else
    {
        element = q->head;
        q->head = q->head->next;
        free(element);
    }
}

/**
 * {@inheritDoc}
 */
void initVector(TREE_NODE *vector, int size)
{
    int i=0;
    int j=0;

    for (i=0; i<size; i++)
    {
        vector[i].isNull=1;
        vector[i].x=0;
        vector[i].y=0;
        vector[i].aux_red_tree=0;
        vector[i].aux_green_tree=0;
        vector[i].aux_blue_tree=0;
        vector[i].boxWithDivision=0;
         for(j = 0; j < 4; j++)
         {
             vector[i].lines[j]=NULL;
             vector[i].plotLine[j]=0;
         }

    }

}

/**
 * {@inheritDoc}
 */
int isEmpty(struct Queue *q)
{
    return (q->head == NULL ? 1:0);
}



/**
 * {@inheritDoc}
 */
int getNumberOfNodes(int dimension, int height)
{
    int i;
    int numberOfNodes = 0;

    for(i = 0; i<=height; i++)
        numberOfNodes += pow(dimension, i);

    return numberOfNodes;
}


/**
 * {@inheritDoc}
 */
void plotElementsOnScreen(BOX *b,TREE_NODE *vector,int numberOfNodes)
{
    int i,j=0;
    for(i=0; i<numberOfNodes; i++)
    {

        if(vector[i].isNull == 0)
        {

            strcpy(b->value,vector[i].value);
            b->x =vector[i].x;
            b->y =vector[i].y;
            b->x_label = getPosCentralizedLabel(b->value,vector[i].x ,$NODE_TREE_WIDTH);
            b->y_label = vector[i].y + 10;
            b->width = $NODE_TREE_WIDTH;
            b->height = $NODE_TREE_HEIGHT;
            b->border_red = $NODEBORDER_TREE_RED ;
            b->border_green = $NODEBORDER_TREE_GREEN;
            b->border_blue = $NODEBORDER_TREE_BLUE;
            b->red   = vector[i].aux_red_tree;
            b->green = vector[i].aux_green_tree;
            b->blue  = vector[i].aux_blue_tree;
            b->font_blue  = b->red==0 && b->green==0 && b->blue==0?255:0 ;
            b->font_green = b->red==0 && b->green==0 && b->blue==0?255:0;
            b->font_red   = b->red==0 && b->green==0 && b->blue==0?255:0;
            if(vector[i].boxWithDivision==1)
               drawBoxWithDivision(b, 0);
              else
                drawBox(b);


            for(j = 0;j < 4; j++)
            {
                if(vector[i].lines[j] != NULL && vector[i].plotLine[j]==1)
                    drawLine(vector[i].lines[j]->points[0].x, vector[i].lines[j]->points[0].y,
                             vector[i].lines[j]->points[1].x, vector[i].lines[j]->points[1].y);
            }

        }
    }
}


