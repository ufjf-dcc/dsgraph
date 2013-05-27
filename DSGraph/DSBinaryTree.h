/*
+--------------------------------------------------------------------------------------+
|Federal University Of Juiz de Fora - UFJF - Minas Gerais - Brazil                     |
|Institute for Exact Sciences - ICE                                                    |
|Computer Science Departament - DCC                                                    |
|Project: Visual library to support Data Structures classes                            |
|Professor:Jairo Francisco de Souza    jairo.souza@ufjf.edu.br                         |
|Students......:Thiago Moratori Peixoto     thiagomoratori@gmail.com	               |
|               Sandro Athaide Coelho       sandroacoelho@gmail.com                    |
|Created in......:November/13/2011                                                     |
|Objective: Head of business rules of Btree                                            |
|Latest updates                                                                        |
|                                                                                      |
|                                                                                      |
|                                                                                      |
|                                                                                      |
|                                                                                      |
|--------------------------------------------------------------------------------------+
*/
//BOF

#ifndef DSBinaryTree_H
#define DSBinaryTree_H

#include "DSStructures.h"

/**
* Show a binary tree on screen
* @param: float*param
* @param: int type tree
* @param: int lines
* @param: int columns
* @param: va_list opt_par - list of parameters to be highlighted
*/
void showBTree(DATA_STRUCTURE *param, int type_tree, int n_args, va_list opt_par);

/**
* Init the node  color
* @param: red, green, blue
* @author: sandroacoelho@gmail.com
*/
void setAllegroColorBtree(int red, int green, int blue);

/**
* Init the node border color
* @param: red, green, blue
* @author: sandroacoelho@gmail.com
*/
void setAllegroBorderColorBtree(int red, int green, int blue);

/**
* Set if DSGraph need to show the memory address
* @param: value - 0  - doesn't show
*         value - 1  - show
*/
void setBTreeViewAddress(int value);

#endif
//EOF
