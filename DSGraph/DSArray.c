/*
+--------------------------------------------------------------------------------------+
|Federal University Of Juiz de Fora - UFJF - Minas Gerais - Brazil                     |
|Institute for Exact Sciences - ICE                                                    |
|Computer Science Departament - DCC                                                    |
|Project: Visual library to support Data Structures classes                            |
|Professor:Jairo Francisco de Souza    jairo.souza@ufjf.edu.br                         |
|Students......:Thiago Moratori Peixoto     thiagomoratori@gmail.com	               |
|               Sandro Athaide Coelho       sandroacoelho@gmail.com                    |
|Created in......:June/10/2011                                                         |
|Objective: Implementation of business rules of Array/Multidimensional Array           |
|Latest updates                                                                        |
|03/30/2012 - Fix a bug with negative numbers  - davi150889@gmail.com                                                                                      |
|                                                                                      |
|                                                                                      |
|                                                                                      |
|                                                                                      |
|--------------------------------------------------------------------------------------+
*/
//BOF
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <math.h>

#include "DSAllegro.h"
#include "DSStructures.h"
#include "DSConstants.h"
#include "DSMessages.h"
#include "DSArray.h"
#include "DSGraph.h"

static int x_array=0;
static int y_array=0;
static BOX box_array;

static int aux_red_array=0;
static int aux_green_array=0;
static int aux_blue_array=0 ;
static int isStringArray=0;

/**
* Init some variables
*/
static  void initArray()
{
    x_array = 0;
    y_array = getScreenHeight()/2- $NODE_ARRAY_HEIGHT * 3;
}

/**
 * Get the box to plot on screen
 */
static BOX getBox()
{
    box_array.x = x_array;
    box_array.y = y_array;
    box_array.x_label = x_array;
    box_array.y_label = y_array + $NODE_ARRAY_HEIGHT/2 - 5;
    box_array.width = $NODE_ARRAY_WIDTH;
    box_array.height = $NODE_ARRAY_HEIGHT;
    box_array.border_red = $NODEBORDER_ARRAY_RED ;
    box_array.border_green = $NODEBORDER_ARRAY_GREEN;
    box_array.border_blue = $NODEBORDER_ARRAY_BLUE ;
    box_array.red = $NODE_ARRAY_RED;
    box_array.green = $NODE_ARRAY_GREEN;
    box_array.blue = $NODE_ARRAY_BLUE;

    return box_array;
}


/**
* Here we check if the input vector is of type int or float
* @param: int vInt
* @param: float vFloat
* @param: BOX *box
*/
static void setValue(int vInt, float vFloat, BOX *box)
{
    sprintf(box->value,"% .2f", vFloat);

    if((box->value[3] == '#') || (box->value[3] == 'n') || (round(vFloat) == 0 && vInt !=0))
    {
        sprintf(box->value,"% d", vInt);
    }

}

/**
* Show an  Multi-dimensional Array on screen
* @param: float*param
* @param: int lines
* @param: int columns
*/
void showMultiDimensionalArray(float *param , int *paramInt, char *paramChar,
                               int lines, int columns, int n_args, va_list opt_par)
{

    int i = 0;
    int j = 0;
    int k = 0;

    float* vetor_node[n_args];

    COLOR* HL_color_array = (COLOR*)malloc(sizeof(COLOR));

    for(k = 0; k < n_args; k++)
    {
        vetor_node[k] = va_arg(opt_par, float*);
    }
    va_end(opt_par);

    int posX = x_array;

    for (i = 0; i < lines; i++)
    {
        for (j = 0; j < columns; j++)
        {
            BOX box = getBox();

            for(k = 0; k < n_args; k++)
            {
                if(&((param+i*columns)[j]) == vetor_node[k])
                {
                    HL_color_array = getHLColor(k+1);
                    box.red   = HL_color_array->red;
                    box.green = HL_color_array->green;
                    box.blue  = HL_color_array->blue;
                    break;
                }
            }

            if (k == n_args)
            {
                box.red   = aux_red_array;
                box.green = aux_green_array;
                box.blue  = aux_blue_array;
            }


            if(isStringArray==1)
            {
                char c = (paramChar+i*columns)[j];
                if (c == '\0') sprintf(box.value,"\\0");
                else sprintf(box.value," %c", c);
            }
            else
            {
                int vInt = (int)(paramInt+i*columns)[j];
                float vFloat = (float)(param+i*columns)[j];
                setValue(vInt, vFloat, &box);
            }

            box.x_label=getPosCentralizedLabel(box.value,x_array,$NODE_ARRAY_WIDTH );
            drawBox(&box);
            x_array +=  $NODE_ARRAY_WIDTH;
        }
        y_array+= $NODE_ARRAY_HEIGHT;
        x_array = posX;
    }


}


/**
 * {@inheritDoc}
 */
void showArrayOrMultiArray(void *param, int lines, int columns, int n_args, va_list opt_par)
{
    initArray();

    aux_red_array = getNodeRedColor() == -1 ? $NODE_ARRAY_RED : getNodeRedColor();
    aux_green_array = getNodeGreenColor() == -1 ? $NODE_ARRAY_GREEN : getNodeGreenColor();
    aux_blue_array = getNodeBlueColor() == -1 ? $NODE_ARRAY_BLUE : getNodeBlueColor();

    if (lines - 1 == 0)
        setTitle($ARRAY_NAME);
    else
        setTitle($MULTIDIMENSIONALARRAY_NAME);

    isStringArray = 0;
    showMultiDimensionalArray((float*)param, (int*)param, (char *)param, lines, columns, n_args, opt_par);
    waitToContinue();
}

/**
 * {@inheritDoc}
 */
void showString(void *param, int lines, int columns, int n_args, va_list opt_par)
{

    initArray();

    aux_red_array   = getNodeRedColor()   == -1 ? $NODE_ARRAY_RED   : getNodeRedColor();
    aux_green_array = getNodeGreenColor() == -1 ? $NODE_ARRAY_GREEN : getNodeGreenColor();
    aux_blue_array  = getNodeBlueColor()  == -1 ? $NODE_ARRAY_BLUE  : getNodeBlueColor();

    setTitle($STRING_NAME);

    isStringArray=1;
    showMultiDimensionalArray((float*)param, (int*)param, (char *)param, lines, columns, n_args, opt_par);

    waitToContinue();
}

//EOF
