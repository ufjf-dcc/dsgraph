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
|Objective: Business rules of Pointers                                                 |
|Latest updates                                                                        |
|                                                                                      |
|                                                                                      |
|                                                                                      |
|                                                                                      |
|                                                                                      |
|--------------------------------------------------------------------------------------+
*/
//BOF
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "DSAllegro.h"
#include "DSStructures.h"
#include "DSConstants.h"
#include "DSMessages.h"
#include "DSPointer.h"

static int x_pointer_adress;
static int y_pointer_adress;
static int x_pointer_value;
static int y_pointer_value;

static BOX box_pointer_adress;
static BOX box_pointer_value;

/**
 * {@inheritDoc}
 */
void setAllegroColorPointer(int red, int green, int blue)
{
    setAllegroColor(red, green, blue);
}

/**
 * {@inheritDoc}
 */
void showPointer(void *param){

    float *endereco = (float *) param;
    float valor;
    valor = *endereco;

    setTitle($POINTER_NAME);

    x_pointer_adress = getScreenWidth()/4;
    y_pointer_adress = getScreenHeight()/2;

    x_pointer_value = getScreenWidth()/4 + 200;
    y_pointer_value = getScreenHeight()/2;

    box_pointer_adress.x = x_pointer_adress - 70;
    box_pointer_adress.y = y_pointer_adress;
    box_pointer_adress.x_label = x_pointer_adress + $NODE_POINTER_WIDTH/2 - 100;
    box_pointer_adress.y_label = y_pointer_adress + $NODE_POINTER_HEIGHT/2 - 5;
    box_pointer_adress.width = $NODE_POINTER_WIDTH;
    box_pointer_adress.height = $NODE_POINTER_HEIGHT;
    box_pointer_adress.red = $NODE_POINTER_RED;
    box_pointer_adress.green = $NODE_POINTER_GREEN;
    box_pointer_adress.blue = $NODE_POINTER_BLUE;
    box_pointer_adress.border_red = $NODEBORDER_POINTER_RED ;
    box_pointer_adress.border_green = $NODEBORDER_POINTER_GREEN;
    box_pointer_adress.border_blue = $NODEBORDER_POINTER_BLUE;
    sprintf(box_pointer_adress.value,"%p", endereco);
    drawBox(&box_pointer_adress); /// imprime o endereço da variável pelo ponteiro

    box_pointer_value.x = x_pointer_value + 100;
    box_pointer_value.y = y_pointer_value;
    box_pointer_value.x_label = x_pointer_value + $NODE_POINTER_WIDTH/2 + 80;
    box_pointer_value.y_label = y_pointer_value + $NODE_POINTER_HEIGHT/2 - 5;
    box_pointer_value.width = $NODE_POINTER_WIDTH;
    box_pointer_value.height = $NODE_POINTER_HEIGHT;
    box_pointer_value.red = $NODE_POINTER_VALUE_RED;
    box_pointer_value.green = $NODE_POINTER_VALUE_GREEN;
    box_pointer_value.blue = $NODE_POINTER_VALUE_BLUE;
    box_pointer_value.border_red = $NODEBORDER_POINTER_RED ;
    box_pointer_value.border_green = $NODEBORDER_POINTER_GREEN;
    box_pointer_value.border_blue = $NODEBORDER_POINTER_BLUE;
    sprintf(box_pointer_value.value,"%.2f", valor);
    drawBox(&box_pointer_value); /// imprime o valor apontado pelo ponteiro

    drawLine(box_pointer_adress.x + $NODE_POINTER_WIDTH, box_pointer_adress.y + $NODE_POINTER_HEIGHT/2,box_pointer_value.x, box_pointer_adress.y + $NODE_POINTER_HEIGHT/2);
    drawTriangle(box_pointer_value.x - 5, box_pointer_value.y + $NODE_POINTER_HEIGHT/2 - 5, box_pointer_value.x - 5, box_pointer_value.y + $NODE_POINTER_HEIGHT/2 + 5,  box_pointer_value.x, box_pointer_value.y + $NODE_POINTER_HEIGHT/2);

    box_pointer_adress.x = 100;
    box_pointer_adress.y = 100;
    box_pointer_adress.x_label = x_pointer_adress + $NODE_POINTER_WIDTH/2 - 150;
    box_pointer_adress.y_label = y_pointer_adress - $NODE_POINTER_HEIGHT/4 - 15;
    box_pointer_adress.red = 255;
    box_pointer_adress.green = 255;
    box_pointer_adress.blue = 255;
    box_pointer_adress.border_red = 255;
    box_pointer_adress.border_green = 255;
    box_pointer_adress.border_blue = 255;
    sprintf(box_pointer_adress.value,"Endereco do Ponteiro: %p", &endereco);
    drawBox(&box_pointer_adress);///imprime o endereço de memória do ponteiro

    box_pointer_adress.x = 100;
    box_pointer_adress.y = 100;
    box_pointer_adress.x_label = x_pointer_adress + $NODE_POINTER_WIDTH/2 + 220;
    box_pointer_adress.y_label = y_pointer_adress - $NODE_POINTER_HEIGHT/4 - 15;
    box_pointer_adress.red = 255;
    box_pointer_adress.green = 255;
    box_pointer_adress.blue = 255;
    box_pointer_adress.border_red = 255;
    box_pointer_adress.border_green = 255;
    box_pointer_adress.border_blue = 255;
    sprintf(box_pointer_adress.value,"Endereco da Variavel: %p", endereco);
    drawBox(&box_pointer_adress);///imprime o endereço de memória da variável

    waitToContinue();
}
