///*
//+--------------------------------------------------------------------------------------+
//|Federal University Of Juiz de Fora - UFJF - Minas Gerais - Brazil                     |
//|Institute for Exact Sciences - ICE                                                    |
//|Computer Science Departament - DCC                                                    |
//|Project: Visual library to support Data Structures classes                            |
//|Professor:Jairo Francisco de Souza    jairo.souza@ufjf.edu.br                         |
//|Students......:Thiago Moratori Peixoto     thiagomoratori@gmail.com	               |
//|               Sandro Athaide Coelho       sandroacoelho@gmail.com                    |
//|               Ana Carolina Gonçalves Fidelis
//|Created in......:Sep/23/2011                                                          |
//|Objective: Business rules of Circular List                                            |
//|Latest updates                                                                        |
//|                                                                                      |
//|                                                                                      |
//|                                                                                      |
//|                                                                                      |
//|                                                                                      |
//|--------------------------------------------------------------------------------------+
//*/
////BOF
//
//#include <stdio.h>
//#include <stdlib.h>
//
//#include "DSAllegroCircularList.h"
//#include "DSAllegro.h"
//
//#include "DSStructures.h"
//#include "DSConstants.h"
//#include "DSMessages.h"
//#include "DSCircularList.h"
//
//int x_circularlist;
//int y_circularlist;
//BOX box_circularlist;
//int aux_red_circularlist;
//int aux_green_circularlist;
//int aux_blue_circularlist;
//
//int first_box;
//
////todo: mudar  fila -> lista... e deixar uma estrutura somente, representando circular, ligada etc
//
//
//void doProcessCircularList(DATA_STRUCTURE *param, BOX box,DATA_STRUCTURE  *node_1, DATA_STRUCTURE  *node_2, DATA_STRUCTURE  *node_3)
//{
//
//    if(node_1!=NULL){
//        if(param -> value == node_1->value){
//            box.red = 255;
//            box.green = 66;
//            box.blue = 10;
//        }
//    }else if(node_2!=NULL) {
//        if(param->value ==node_2->value)
//        {
//            box.red = 255;
//            box.green = 106;
//            box.blue = 10;
//        }
//    }else if(node_3 != NULL){
//
//        if(param -> value == node_3->value)
//        {
//            box.red = 255;
//            box.green = 166;
//            box.blue = 10;
//        }
//    }else{
//        box.red = aux_red_circularlist;
//        box.green = aux_green_circularlist;
//        box.blue = aux_blue_circularlist;
//    }
//
//    x_circularlist +=  $NODE_CIRCULAR_LIST_WIDTH;
//
//    int v = param -> value;
//    sprintf(box.value,"%d", v);
//
//
//    int posY = ($NODE_CIRCULAR_LIST_HEIGHT/2) - 5;
//
//    drawLine(x_circularlist - 20, y_circularlist + posY +20, x_circularlist - 10, y_circularlist + posY + 20);
//    drawTriangle(x_circularlist - 10, y_circularlist + posY +15, x_circularlist - 10, y_circularlist + 10 + posY +15, x_circularlist, y_circularlist + 5 + posY +15);
//
//    box.x = x_circularlist;
//    box.y = y_circularlist;
//    box.x_label = x_circularlist + $NODE_CIRCULAR_LIST_WIDTH / 2 - 5;
//    box.y_label = y_circularlist + $NODE_CIRCULAR_LIST_HEIGHT / 2 - 10;
//    box.width = $NODE_CIRCULAR_LIST_WIDTH;
//    box.height = $NODE_CIRCULAR_LIST_HEIGHT;
//    box.border_red = $NODEBORDER_CIRCULAR_LIST_RED ;
//    box.border_green = $NODEBORDER_CIRCULAR_LIST_GREEN;
//    box.border_blue = $NODEBORDER_CIRCULAR_LIST_BLUE ;
//    drawBoxCircularList(&box);
//
//    x_circularlist += 20;
//
//
//    if(param -> next == NULL)
//      return;
//
//    if (param -> next->next !=NULL && param -> next==param -> next->next)
//    {
//
//        x_circularlist +=  $NODE_CIRCULAR_LIST_WIDTH;
//        drawLine(x_circularlist - 20, y_circularlist + posY +20, x_circularlist - 10, y_circularlist + posY + 20);
//        drawLine(x_circularlist -10 , y_circularlist + posY +50, x_circularlist - 10, y_circularlist + posY + 20);
//        drawLine(first_box -5 , y_circularlist + posY +50, x_circularlist - 10, y_circularlist + posY + 50);
//        drawLine(first_box -5 , y_circularlist + posY +50, first_box - 4, y_circularlist + posY + 40);
//        drawTriangle(first_box - 10, y_circularlist + 25 + posY +20, first_box - 5 , y_circularlist + 35 + posY , first_box , y_circularlist + 25 + posY +20);
//
//    } else
//    {
//
//        doProcessCircularList(param -> next, box, node_1, node_2, node_3);
//
//
//    }
//
//
//}
//
//
///*
//* Init the node  color
//* @param: red, green, blue
//* @author: sandroacoelho@gmail.com
//*/
//void setAllegroColorCircularList(int red, int green, int blue)
//{
//    setAllegroColor(red, green, blue);
//}
//
///*
//* Show the screen
//* @param: struct NODE_STRUCTURE *param
//*/
//void showCircularList(DATA_STRUCTURE *param, DATA_STRUCTURE *node_1, DATA_STRUCTURE *node_2, DATA_STRUCTURE *node_3)
//{
//
//        int result = showScreen();
//
//        if (result !=0) return;
//
//        setTitle($CIRCULAR_LIST_NAME);
//
//        x_circularlist = $NODE_CIRCULAR_LIST_WIDTH / 2;
//        y_circularlist = getScreenHeight() / 2- $NODE_CIRCULAR_LIST_HEIGHT * 3;
//
//        first_box = x_circularlist + ($NODE_CIRCULAR_LIST_WIDTH *1.5 );
//
//
//        aux_red_circularlist = getNodeRedColor() == -1 ? $NODE_CIRCULAR_LIST_RED : getNodeRedColor();
//        aux_green_circularlist = getNodeGreenColor() == -1 ? $NODE_CIRCULAR_LIST_GREEN : getNodeGreenColor();
//        aux_blue_circularlist = getNodeBlueColor() == -1 ? $NODE_CIRCULAR_LIST_BLUE : getNodeBlueColor();
//
//        setAllegroColorCircularList(-1,-1,-1);
//
//        doProcessCircularList(param, box_circularlist, node_1, node_2,node_3);
//
//        continueShowScreen();
//
//}
//
//
///*
//* Init the node border color
//* @param: red, green, blue
//* @author: sandroacoelho@gmail.com
//*/
//void setAllegroBorderColorCircularList(int red, int green, int blue)
//{
//    setAllegroBorderColor(red, green, blue);
//}
//
////EOF

