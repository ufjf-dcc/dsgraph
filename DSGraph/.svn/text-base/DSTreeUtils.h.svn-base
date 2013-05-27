#ifndef DSTREEUTILS_H_INCLUDED
#define DSTREEUTILS_H_INCLUDED
#include <stdio.h>
#include "DSStructures.h"

/**
* Initialize a struct Queue
* @param: struct Queue *q
*/
void initializeQueue(struct Queue *q);

/**
* Put a node value on the queue
*@param Queue *q
*@param struct NODE_STRUCT node
*/
void enqueue(struct Queue *q,void *str_to_queue);

/**
* Remove a node value from the queue
* @param Queue *q
*/
void dequeue(struct Queue *q);

/**
* this function returns the number of nodes of any tree with dimension and height.
* @param dimension
* @param height
*/
int getNumberOfNodes(int dimension, int height);

/**
* Check if the queue is empty
*@param Queue *q
*/
int isEmpty(struct Queue *q);

/**
* Initialize the common tree structure
* @param TREE_NODE  Tree structure
* @param size      size of complete tree
*/
void initVector(TREE_NODE *bVector, int size);

/**
*Plot the tree on scree
*@param BOX b
*@param TREE_NODE Tree structure
*@param numberOfNodes
*/
void plotElementsOnScreen(BOX *b,TREE_NODE *vector,int numberOfNodes);

#endif // DSTREEUTILS_H_INCLUDED
