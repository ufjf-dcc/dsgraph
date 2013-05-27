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
|Objective: Business rules of Lists                                                    |
|Latest updates                                                                        |
| Add signs between the boxes June/07/2011 by sandroacoelho@gmail.com                  |
|                                                                                      |
|                                                                                      |
|                                                                                      |
|                                                                                      |
|--------------------------------------------------------------------------------------+
*/
//BOF



#include <stdio.h>
#include <stdlib.h>
#include "DSAllegro.h"
#include "DSStructures.h"
#include "DSConstants.h"
#include "DSMessages.h"
#include "DSList.h"
#include "DSGraph.h"
#include <signal.h>

static int x_list = 0;
static int y_list = 0;
static BOX box_list;
static int aux_red_list = 0;
static int aux_green_list = 0;
static int aux_blue_list = 0;
static int first_box = 0;
static DATA_STRUCTURE *first = NULL;
// Compare if is a circular list only after read the first element
static int bControl = 0;
static int structure = 0;

/**
* Processes the list
* @param DATA_STRUCTURE *param
* @param BOX box
* @param int n_args
* @param  DATA_STRUCTURE* vetor_node[]
*/
static void doProcessList(DATA_STRUCTURE *param, BOX box, int n_args, DATA_STRUCTURE* vetor_node[])
{

    int k = 0;

    int posY = ($NODE_LIST_HEIGHT/2) - 5;

    if (param == NULL) return ;

   if(first->anterior == param && structure != 1)
    {
        x_list+=$NODE_LIST_WIDTH + $NODE_LIST_WIDTH/2;
        drawLine(x_list - $NODE_LIST_WIDTH , y_list + posY -50, x_list - $NODE_LIST_HEIGHT , y_list + posY - 30);
        drawLine(first_box , y_list + posY - 50, x_list - $NODE_LIST_HEIGHT , y_list + posY - 50);
        drawLine(first_box  , y_list + posY - 50, first_box, y_list + posY - 20);
        drawTriangle(x_list - $NODE_LIST_WIDTH -5 , y_list - 35 + posY , x_list - $NODE_LIST_HEIGHT, y_list  - 25 + posY , x_list - $NODE_LIST_HEIGHT + 5  , y_list - 35 + posY);
        x_list-=$NODE_LIST_WIDTH + $NODE_LIST_WIDTH/2;
    }

    if(first == param && bControl==1 && structure != 1)
    {
        drawLine(x_list - 20, y_list + posY +20, x_list - 10, y_list + posY + 20);
        drawLine(x_list -10 , y_list + posY +50, x_list - 10, y_list + posY + 20);
        drawLine(first_box -5 , y_list + posY +50, x_list - 10, y_list + posY + 50);
        drawLine(first_box -5 , y_list + posY +50, first_box - 5, y_list + posY + 40);
        drawTriangle(first_box - 10, y_list + 45 + posY , first_box - 5 , y_list  + 35 + posY , first_box , y_list+ 45 + posY );
        return;
    }

    if((param->proximo !=NULL) || ( param->proximo != first && first->anterior !=  param))
    {
        drawLine    (x_list - 20, y_list + posY +5, x_list - 10, y_list + posY + 5);
        drawTriangle(x_list - 10, y_list + posY, x_list - 10, y_list + 10 + posY, x_list, y_list + 5 + posY);
    }



    COLOR* HL_color_list = (COLOR*)malloc(sizeof(COLOR));

    for(k = 0; k < n_args; k++)
    {
        if(param == vetor_node[k])
        {
            HL_color_list = getHLColor(k+1);
            box.red   = HL_color_list->red;
            box.green = HL_color_list->green;
            box.blue  = HL_color_list->blue;
            break;
        }
    }

    if (k == n_args)
    {
        box.red   = aux_red_list;
        box.green = aux_green_list;
        box.blue  = aux_blue_list;
    }

    convertValue(&param->valor,param->valor,  box.value);



    box.x = x_list;
    box.y = y_list;
    box.x_label =getPosCentralizedLabel(box.value,x_list ,$NODE_LIST_WIDTH);
    box.y_label = y_list + $NODE_LIST_HEIGHT / 2 - 10;
    box.width = $NODE_LIST_WIDTH;
    box.height = $NODE_LIST_HEIGHT;
    box.border_red = $NODEBORDER_LIST_RED ;
    box.border_green = $NODEBORDER_LIST_GREEN;
    box.border_blue = $NODEBORDER_LIST_BLUE ;

    drawBox(&box);

    x_list +=  $NODE_LIST_WIDTH + 20 ;


  if(param->proximo !=NULL &&  param->proximo->anterior == param && param->proximo !=first)
    {
        x_list += 20;
        drawLine(x_list - 30    , y_list + posY +25, x_list - 20, y_list + posY + 25);
        drawTriangle(x_list - 40, y_list + posY + 25, x_list - 30, y_list + 30 + posY, x_list - 30, y_list + 38 );
        x_list -= 20;

    }

    if(param == param->proximo) {
        showComment($MSG_STRUCT_LOOP);
        return; //Prevent user errors
    }

    bControl=1;
    doProcessList(param -> proximo, box, n_args, vetor_node);



}


/**
 * {@inheritDoc}
 */
void setAllegroColorList(int red, int green, int blue)
{
    setAllegroColor(red, green, blue);
}

/**
* Draw descriptor
* @param DATA_STRUCTURE *param
* @param BOX box
* @param int n_args
* @param DATA_STRUCTURE* vetor_node[]
*/
static void drawDescriptor(DATA_STRUCTURE *param, BOX box, int n_args, DATA_STRUCTURE* vetor_node[])
{

    x_list = 75;
    box.red   = aux_red_list;
    box.green = aux_green_list;
    box.blue  = aux_blue_list;
    box.x = x_list;
    box.y = y_list - ($NODE_LIST_HEIGHT * 2);
    box.x_label = $NODE_LIST_WIDTH * 2;
    box.y_label =y_list - ($NODE_LIST_HEIGHT * 2) + $NODE_LIST_HEIGHT/2;
    box.width = $NODE_LIST_WIDTH * 2;
    box.height = $NODE_LIST_HEIGHT;
    box.border_red = $NODEBORDER_LIST_RED ;
    box.border_green = $NODEBORDER_LIST_GREEN;
    box.border_blue = $NODEBORDER_LIST_BLUE ;
    convertValue(&param->valor,param->valor, box.value);

    drawBoxWithDivision(&box, 0);

    if(param->anterior != NULL)
    {

        //Line for First Node
        drawLine(box.x , box.y + ($NODE_LIST_HEIGHT/2), box.x  - 20,box.y + ($NODE_LIST_HEIGHT/2));
        drawLine(box.x - 20 , y_list + ($NODE_LIST_HEIGHT/2),$NODE_LIST_WIDTH + 25,y_list + ($NODE_LIST_HEIGHT/2));
        drawLine(box.x - 20 ,box.y + ($NODE_LIST_HEIGHT/2), box.x - 20,y_list + ($NODE_LIST_HEIGHT/2));
        drawTriangle(box.x  - 10, y_list + ($NODE_LIST_HEIGHT/2) + 5,$NODE_LIST_WIDTH + 25,y_list + ($NODE_LIST_HEIGHT/2), box.x  - 10, y_list + ($NODE_LIST_HEIGHT/2) - 5);


    }

    int boxX = box.x;

    doProcessList(param->anterior, box_list, n_args, vetor_node);

    if(param->proximo != NULL)
    {
        x_list +=$NODE_LIST_WIDTH ;
        //Linha de cima para o ultimo nó
        drawLine(boxX + ($NODE_LIST_WIDTH * 2) , box.y + ($NODE_LIST_HEIGHT/2), x_list ,box.y + ($NODE_LIST_HEIGHT/2));

        //Linha do meio para o último nó
        drawLine(x_list ,box.y + ($NODE_LIST_HEIGHT/2),x_list  ,y_list + ($NODE_LIST_HEIGHT/2));

        //Linha de baixo para o último nó
        drawLine(x_list - ($NODE_LIST_WIDTH + 20) ,y_list + ($NODE_LIST_HEIGHT/2),x_list,y_list + ($NODE_LIST_HEIGHT/2));

        //Triângulo
        drawTriangle(x_list - $NODE_LIST_HEIGHT - 20,y_list + ($NODE_LIST_HEIGHT/2),x_list - $NODE_LIST_HEIGHT - 10, y_list + ($NODE_LIST_HEIGHT/2) + 5 ,    x_list - $NODE_LIST_HEIGHT - 10 ,y_list + ($NODE_LIST_HEIGHT/2) - 5);

        //Cálculo para tornar as linhas dinâmicas
        x_list += ($NODE_LIST_WIDTH + 20);

    }

}


/**
 * {@inheritDoc}
 */
void showList(DATA_STRUCTURE *param, int n_args, va_list opt_par, int str)
{
    int k = 0;


    bControl = 0;
    first = param;

    DATA_STRUCTURE* vetor_node[n_args];

    for(k = 0; k < n_args; k++)
        vetor_node[k] = va_arg(opt_par, DATA_STRUCTURE*);

    va_end(opt_par);

    setTitle($LIST_NAME);

    x_list = 0;
    y_list = getScreenHeight() / 2- $NODE_LIST_HEIGHT * 2;

    first_box = $NODE_LIST_WIDTH/2;

    aux_red_list = getNodeRedColor() == -1 ? $NODE_LIST_RED : getNodeRedColor();
    aux_green_list = getNodeGreenColor() == -1 ? $NODE_LIST_GREEN : getNodeGreenColor();
    aux_blue_list = getNodeBlueColor() == -1 ? $NODE_LIST_BLUE : getNodeBlueColor();

    setAllegroColorList(-1,-1,-1);

    structure = (str ==$LISTA_DESCRITOR);

    if (structure == 1)
        drawDescriptor(param, box_list, n_args, vetor_node);
    else
        doProcessList(param, box_list, n_args, vetor_node);

    waitToContinue();


}


/**
 * {@inheritDoc}
 */
void setAllegroBorderColorList(int red, int green, int blue)
{
    setAllegroBorderColor(red, green, blue);
}

//EOF
