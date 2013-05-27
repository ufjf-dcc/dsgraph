
/*
+--------------------------------------------------------------------------------------+
|Federal University Of Juiz de Fora - UFJF - Minas Gerais - Brazil                     |
|Institute for Exact Sciences - ICE                                                    |
|Computer Science Departament - DCC                                                    |
|Project: Visual library to support Data Structures classes                            |
|Professor:Jairo Francisco de Souza    jairo.souza@ufjf.edu.br                         |
|Students......:Thiago Moratori Peixoto     thiagomoratori@gmail.com	               |
|               Sandro Athaide Coelho       sandroacoelho@gmail.com                    |
|Created in......:March/31/2011                                                        |
|Objective: this file is the implementation of the head with all methods to support our|
|           project                                                                    |
|Latest updates                                                                        |
|                                                                                      |
|                                                                                      |
|                                                                                      |
|                                                                                      |
|                                                                                      |
|--------------------------------------------------------------------------------------+
*/

//BOF
#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
#include <signal.h>
#include <math.h>
#include <string.h>
#include "DSStructures.h"
#include "DSConstants.h"
#include "DSGraph.h"
#include "DSArray.h"
#include "DSList.h"
#include "DSStack.h"
#include "DSPointer.h"
#include "DSBinaryTree.h"
#include "DSTernaryTree.h"
#include "DSQuadPointTree.h"
#include "DSAllegro.h"
#include "DSBTree.h"

#ifdef __unix__
#include <pthread.h>
#elif defined _WIN32
#include <windows.h>
#endif


static int structure = 0;
static int lines = 1;
static int columns = 1;
static COLOR* aux_color = NULL;
static int hasCreated = 0;
static int NumberOfKeys = 0;


#ifdef __unix__
static pthread_t pth;
#elif defined _WIN32
static HANDLE hThread;
static DWORD dwGenericThread;
#endif

static int datatype_defined_by_user=sizeof(int);


/**
 * {@inheritDoc}
 */
int getStructure()
{
    return structure;
}


/**
 * {@inheritDoc}
 */
void setDSGraphDataType(int sizeOfDataType)
{
    datatype_defined_by_user = sizeOfDataType;
}


/**
 * {@inheritDoc}
 */
void init(int typeOfStructure, ...)
{
    va_list opt_par;
    va_start(opt_par, typeOfStructure);
    int numberLines = va_arg(opt_par, int);

    NumberOfKeys = numberLines;

    int numberColumns = va_arg(opt_par, int);
    va_end(opt_par);

    structure = typeOfStructure;
    if(numberLines != 1) lines = numberLines;
    if(numberColumns != 1) columns = numberColumns;
    if(structure == $VETOR || structure == $STRING)
    {
        columns = lines;
        lines = 1;
    }

    aux_color = (COLOR*)malloc(sizeof(COLOR));

#ifdef __unix__
    pthread_create(&pth,NULL,showScreen,NULL);
#elif defined _WIN32
    hThread = CreateThread(NULL,0,(LPTHREAD_START_ROUTINE)showScreen,NULL,0,&dwGenericThread);
#endif
    //Wait thread showScreen to continue
    while (getInitAllegroResult()==-2)
        { }

}



/**
 * {@inheritDoc}
 */
void show(void *param, int n_args, ...)
{

    signal(SIGSEGV,catch_segfault);

    va_list opt_par;
    va_start(opt_par, n_args);

    if (structure==$PILHA)
    {
        if (hasCreated == 0 ) createScrollArea($MAX_SCREEN_TILES_Y,1);
        clearScreen();
        showStack((DATA_STRUCTURE*)param, n_args, opt_par);

    }

    if ( (structure ==$LISTA) || (structure == $LISTA_DESCRITOR))
    {
        if (hasCreated == 0 ) createScrollArea(1,$MAX_SCREEN_TILES_X);
        clearScreen();
        showList((DATA_STRUCTURE*)param, n_args, opt_par, structure);


    }
    if ((structure == $VETOR) || (structure == $VETOR_MULTIDIMENSIONAL))
    {
        if ( structure == $VETOR && hasCreated == 0)
            createScrollArea(1,$MAX_SCREEN_TILES_X);

        if (structure == $VETOR_MULTIDIMENSIONAL && hasCreated == 0)
            createScrollArea(5,10);

        clearScreen();

        showArrayOrMultiArray(param, lines, columns, n_args, opt_par);

    }

    if (structure==$STRING)
    {
        if (hasCreated == 0 ) createScrollArea(1,$MAX_SCREEN_TILES_X);
        clearScreen();
        showString(param, lines, columns, n_args, opt_par);

    }

    if (structure==$PONTEIRO)
    {
        if (hasCreated == 0 ) createScrollArea(1,2);
        clearScreen();
        showPointer(param);

    }

    if ((structure==$ARVORE_BINARIA) || (structure==$ARVORE_VERMELHO_PRETO))
    {
        if (hasCreated == 0 ) createScrollArea(2,10);
        clearScreen();
        showBTree((DATA_STRUCTURE*)param, structure, n_args, opt_par);

    }

    if(structure == $ARVORE_B)
    {
        if (hasCreated == 0 ) createScrollArea(2,10);
        clearScreen();
        showB((NODE_B_TREE*)param, structure, n_args, opt_par,NumberOfKeys);

    }


    if (structure==$ARVORE_TERNARIA)
    {
        if (hasCreated == 0 ) createScrollArea(3,7);
        clearScreen();
        showTernaryTree( (DATA_TERNARY*) param , n_args, opt_par);

    }


    if (structure ==$POINT_QUADTREE)
    {
        if (hasCreated == 0 ) createScrollArea(3,7);
        clearScreen();
        showQuadPointTree((DATA_QUADTREE*) param, n_args, opt_par);

    }


    stopIfPaused();
    hasCreated = 1;
}

/**
 * {@inheritDoc}
 */
void setSleepTime(int seconds)
{
    setAllegroSleepTime(seconds);
}

/**
 * {@inheritDoc}
 */
void setBorderColor(int red, int green, int blue)
{

    if (structure == $PILHA)
        setAllegroBorderColorStack(red, green, blue);

    if (structure == $LISTA)
        setAllegroBorderColorList(red, green, blue);

    /*    if (structure == $VETOR || structure == $VETOR_MULTIDIMENSIONAL || structure == $STRING )
            setAllegroBorderColorVector(red, green, blue);

        if(structure == $ARVORE_BINARIA )
           setAllegroBorderColorBtree(red, green, blue);
    */
    if(structure == $ARVORE_TERNARIA )
        setAllegroBorderColorTTree(red, green, blue);

    if(structure ==  $POINT_QUADTREE)
        setAllegroBorderColorQTree(red, green, blue);


}

/**
 * {@inheritDoc}
 */
void setNodeColor(int red, int green, int blue)
{
    if (structure == $PILHA)
        setAllegroColorStack(red, green, blue);

    if (structure == $LISTA || structure == $LISTA_DESCRITOR)
        setAllegroColorList(red, green, blue);

    if (structure == $PONTEIRO)
        setAllegroColorPointer(red, green, blue);

    /*    if (structure == $VETOR || structure == $VETOR_MULTIDIMENSIONAL || structure == $STRING )
            setAllegroColorVector(red, green, blue);



        if(structure == $ARVORE_BINARIA )
           setAllegroColorBtree(red, green, blue);

        if(structure == $ARVORE_TERNARIA )
           setAllegroColorTTree(red, green, blue);

        if(structure ==  $POINT_QUADTREE)
           setAllegroColorQTree(red, green, blue);
    */


}

/**
 * {@inheritDoc}
 */
COLOR* getHLColor(int node_number)
{
    switch(node_number)
    {
    case(1):
    {
        aux_color->red   = $HIGHLIGHT_RED_COLOR_1;
        aux_color->green = $HIGHLIGHT_GREEN_COLOR_1;
        aux_color->blue  = $HIGHLIGHT_BLUE_COLOR_1;
        break;
    }

    case(2):
    {
        aux_color->red   = $HIGHLIGHT_RED_COLOR_2;
        aux_color->green = $HIGHLIGHT_GREEN_COLOR_2;
        aux_color->blue  = $HIGHLIGHT_BLUE_COLOR_2;
        break;
    }

    default:
    {
        aux_color->red   = $HIGHLIGHT_RED_COLOR_3;
        aux_color->green = $HIGHLIGHT_GREEN_COLOR_3;
        aux_color->blue  = $HIGHLIGHT_BLUE_COLOR_3;
    }
    }
    return aux_color;
}

/**
 * {@inheritDoc}
 */
void terminateDSGraph()
{
    close_button_handler();
 #ifdef __unix__
   pthread_join(pth, NULL);
#elif defined _WIN32
   WaitForSingleObject(hThread, INFINITE);
#endif


}


/**
 * {@inheritDoc}
 */
void setViewAddress(int value)
{
    setBTreeViewAddress(value);
}

/**
 * {@inheritDoc}
 */
int isString(char *str)
{
    int result = 1;
    int i=0;

    if (strlen(str) == 0)return 0;
    for(i=0; i<strlen(str); i++)
    {
        if ((str[i]<32) && (str[i]>0))
        {
            result=0;
            break;
        }
    }

    return result;
}

/**
 * {@inheritDoc}
 */
void convertValue(void *typeAddress,void *type,char *value)
{
    if (typeAddress == NULL && type == NULL) return;


    if (datatype_defined_by_user == sizeof(int) ||  datatype_defined_by_user == sizeof(float))
    {

        float vFloat = *(float *)  typeAddress;
        int vInt     = *(int *) typeAddress;

        sprintf(value,"% .2f", vFloat);
        if((value[3] == '#') || (value[3] == 'n')|| (round(vFloat) == 0 && vInt !=0))
            sprintf(value ,"% d", vInt);

        return;
    }

    if (datatype_defined_by_user == sizeof(char))
    {
        char *string = (char *) typeAddress;

#if defined _WIN32
        int v[3]= {94,38,64};
#endif
        int i;
        for(i=0; i<3; i++){
#ifdef __unix__
            if(strlen(string)>1)
            {
                string = (char *)type;
                break;

            }
#elif defined _WIN32
            if (string[i] == v[i])
            {
                string = (char *)type;
                break;
            }
#endif

        }


        sprintf(value,"%s", string);
        return;
    }


    if (datatype_defined_by_user == sizeof(double))
    {
        double vDouble = *(double *)  typeAddress;
        sprintf(value,"% .2f", vDouble);
        return;
    }

}

/**
 * {@inheritDoc}
 */
int getPosCentralizedLabel(char *str, int pos, int node_size)
{
    int stringLen = 2;

    if (str!=NULL) stringLen = strlen(str);
    stringLen = stringLen<=1?2:stringLen;

    return pos + node_size/stringLen - 5;
}


//EOF
