/*
+--------------------------------------------------------------------------------------+
|Federal University Of Juiz de Fora - UFJF - Minas Gerais - Brazil                     |
|Institute for Exact Sciences - ICE                                                    |
|Computer Science Departament - DCC                                                    |
|Project: Visual library to support Data Structures classes                            |
|Professor:Jairo Francisco de Souza    jairo.souza@ufjf.edu.br                         |
|Students......:Thiago Moratori Peixoto     thiagomoratori@gmail.com	               |
|               Sandro Athaide Coelho       sandroacoelho@gmail.com                    |
|Created in......:April/13/2011                                                        |
|Objective: Head of business rules of Stack                                            |
|Latest updates                                                                        |
|                                                                                      |
|                                                                                      |
|                                                                                      |
|                                                                                      |
|                                                                                      |
|--------------------------------------------------------------------------------------+
*/
//BOF
#ifndef DSStack_H
#define DSStack_H

#include "DSStructures.h"
#include <stdarg.h>
/**
* Show a stack on screen
* @param: float *param
* @param: int lines
* @param: int columns
* @param: va_list opt_par - list of parameters to be highlighted
*/
void showStack(DATA_STRUCTURE *param, int n_args, va_list opt_par);

/**
* Init the node color
* @param: red, green, blue
*/
void setAllegroColorStack(int red, int green, int blue);

/**
* Init the node border color
* @param: red, green, blue
*/
void setAllegroBorderColorStack(int red, int green, int blue);

#endif

//EOF
