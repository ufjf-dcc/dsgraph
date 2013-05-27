#ifndef DSBTREE_H_INCLUDED
#define DSBTREE_H_INCLUDED


#include "DSStructures.h"

/**
* Show a binary tree on screen
* @param: float*param
* @param: int type tree
* @param: int lines
* @param: int columns
* @param: va_list opt_par - list of parameters to be highlighted
*/
void showB(NODE_B_TREE *param, int type_tree, int n_args, va_list opt_par,int NumberOfKeys);

/**
* Init the node  color
* @param: red, green, blue
* @author: sandroacoelho@gmail.com
*/
void setAllegroColorB(int red, int green, int blue);

/**
* Init the node border color
* @param: red, green, blue
* @author: sandroacoelho@gmail.com
*/
void setAllegroBorderColorB(int red, int green, int blue);

/**
* Set if DSGraph need to show the memory address
* @param: value - 0  - doesn't show
*         value - 1  - show
*/
void setBViewAddress(int value);


#endif // DSBTREE_H_INCLUDED
