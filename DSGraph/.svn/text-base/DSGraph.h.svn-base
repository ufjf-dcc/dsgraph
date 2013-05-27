/*
+--------------------------------------------------------------------------------------+
|Federal University Of Juiz de Fora - UFJF - Minas Gerais - Brazil                     |
|Institute for Exact Sciences - ICE                                                    |
|Computer Science Departament - DCC                                                    |
|Project: Visual library to support Data Structures classes                            |
|Professor:Jairo Francisco de Souza    jairo.souza@ufjf.edu.br                         |
|Students......:Thiago Moratori Peixoto     thiagomoratori@gmail.com	               |
|                 Sandro Athaide Coelho       sandroacoelho@gmail.com                  |
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

#ifndef DSGraph_H
#define DSGraph_H

#include <stdlib.h>
#include "DSStructures.h"

/**
* Initialize the library with the structure
* @param: int typeOfStructure- Type of the structure
*/
void init(int typeOfStructure, ...);

/**
* Show the screen
* @param struct NODE_STRUCTURE *param - the parameter
*/
void show(void *param, int n_args, ...);

/**
* Set the sleep time
* @param seconds
*/
void setSleepTime(int seconds);

/**
* Init the node border color
* @param: red, green, blue
*/
void setBorderColor(int red, int green, int blue);

/**
* Init the node  color
* @param: red, green, blue
*/
void setNodeColor(int red, int green, int blue);

/**
* Set if DSGraphs need to show the memory address
* @param: value - 0  - doesn't show
*         value - 1  - show
*/
void setViewAddress(int value);

/**
* Init the node color
* @param: int node_number
*/
COLOR* getHLColor(int node_number);

/**
* Finalize and clean all used DSGraph resources from memory
*/
void terminateDSGraph();

/**
* Set a text on screen
* @param string - a message
**/
void showComment(const char *string, ...);

/**
* this function turn void pointer converting int, float or char into string
* @param type
* @param value
*/
void convertValue(void *typeAddress , void *type, char *value);

/**
* Get centralized position by string len, box position and
* node size
* @param str - value
* @param pos
* @param node_size
*/
int getPosCentralizedLabel(char *str, int pos, int node_size);


/**
* Set DSGraph data type
*/
#define setDataType(dt) setDSGraphDataType(sizeOf(dt));

/**
* Set DSGraph data type
* @param sizeOfDataType
*/
void setDSGraphDataType(int sizeOfDataType);

/**
*
*/
int getStructure();



#endif
//EOF
