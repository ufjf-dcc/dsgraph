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
|Objective: Business rules of Stack                                                    |
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
#include <stdlib.h>
#include <stdarg.h>

#include "DSAllegro.h"
#include "DSStructures.h"
#include "DSConstants.h"
#include "DSMessages.h"
#include "DSStack.h"
#include "DSGraph.h"

static int x_stack = 0;
static int y_stack = 0;
static BOX box_stack;
static int aux_red_stack = 0;
static int aux_green_stack = 0;
static int aux_blue_stack = 0;

/**
* Return the structure height
*/
static int getVirtualStackHeight(DATA_STRUCTURE *param)
{
    if (param != NULL)
    {
       return $NODE_STACK_HEIGHT +  getVirtualStackHeight(param -> proximo);
    }

    return 0;

}

/**
* Process the strucutre on the screen
* @param:struct NODE_STRUCTURE *param
* @param: BOX box
*/
static void doProcessStack(DATA_STRUCTURE *param, BOX box, int n_args, DATA_STRUCTURE* vetor_node[])
{

    if (param -> proximo != NULL)
        doProcessStack(param -> proximo, box, n_args, vetor_node);

    int k = 0;

    COLOR* HL_color_stack = (COLOR*)malloc(sizeof(COLOR));

    for(k = 0; k < n_args; k++)
    {
        if(param == vetor_node[k])
        {
            HL_color_stack = getHLColor(k+1);
            box.red   = HL_color_stack->red;
            box.green = HL_color_stack->green;
            box.blue  = HL_color_stack->blue;
            break;
        }
    }

    if (k == n_args)
    {
        box.red   = aux_red_stack;
        box.green = aux_green_stack;
        box.blue  = aux_blue_stack;
    }

    y_stack -=  $NODE_STACK_HEIGHT;

    convertValue(&param->valor,param->valor, box.value);

    box.x = x_stack;
    box.y = y_stack;
    box.x_label = getPosCentralizedLabel(box.value,x_stack ,$NODE_STACK_WIDTH);;
    box.y_label = y_stack + 15;
    box.width = $NODE_STACK_WIDTH;
    box.height = $NODE_STACK_HEIGHT;
    box.border_red = $NODEBORDER_STACK_RED ;
    box.border_green = $NODEBORDER_STACK_GREEN;
    box.border_blue = $NODEBORDER_STACK_BLUE;
    drawBox(&box);


}

/**
 * {@inheritDoc}
 */
void setAllegroColorStack(int red, int green, int blue)
{
    setAllegroColor(red, green, blue);
}

/**
 * {@inheritDoc}
 */
void showStack(DATA_STRUCTURE *param, int n_args, va_list opt_par)
{
    int k = 0;
    int virtualHeight = getVirtualStackHeight(param);

    DATA_STRUCTURE* vetor_node[n_args];

    for(k = 0; k < n_args; k++){
        vetor_node[k] = va_arg(opt_par, DATA_STRUCTURE*);
    }
    va_end(opt_par);

    setTitle($STACK_NAME);

    x_stack = getScreenWidth()/2 - $NODE_STACK_WIDTH /2;
    y_stack = $NODE_STACK_HEIGHT * 2 +  virtualHeight;


    aux_red_stack = getNodeRedColor() == -1 ? $NODE_STACK_RED : getNodeRedColor();
    aux_green_stack = getNodeGreenColor() == -1 ? $NODE_STACK_GREEN : getNodeGreenColor();
    aux_blue_stack = getNodeBlueColor() == -1 ? $NODE_STACK_BLUE : getNodeBlueColor();

    setAllegroColorStack(-1,-1,-1);

    doProcessStack(param, box_stack, n_args, vetor_node);

    waitToContinue();

}

/**
 * {@inheritDoc}
 */
void setAllegroBorderColorStack(int red, int green, int blue)
{
    setAllegroBorderColor(red, green, blue);
}

//EOF
