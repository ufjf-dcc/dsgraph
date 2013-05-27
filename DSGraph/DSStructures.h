#ifndef DSStructures_H
#define DSStructures_H

/**
*Main structure. You need to put it on the DSGraph.h
*/
typedef struct NODE_STRUCTURE
{
    void *valor;  //value (content)
    int marca;   //used on red-black tree
    struct NODE_STRUCTURE *proximo;   //right child
    struct NODE_STRUCTURE *anterior;  //left child
    struct NODE_STRUCTURE *pai; //middle child

} DATA_STRUCTURE;



/**
* Ternary tree structure. You need to put it on the DSGraph.h
*/
typedef struct NODE_TERNARY
{
    void *valor;  //value (content)

    struct NODE_TERNARY *direito;   //right child
    struct NODE_TERNARY *esquerdo ;  //left child
    struct NODE_TERNARY *centro; //middle child

} DATA_TERNARY;


/**
* Quad Tree structure. You need to put it on the DSGraph.h
*/
typedef struct NODE_QUADTREE
{
    void *valor;  //value (content)
    float x;
    float y;
    struct NODE_QUADTREE *filhos[4];   //children

} DATA_QUADTREE;



/**
* Store a Node color
*/
typedef struct NODE_COLOR
{
    int red;
    int green;
    int blue;

} COLOR;

/**
* Internal box structure.
*/
struct BOX_STR
{
    //size of box
    int width;
    int height;

    //border color
    int border_red;
    int border_green;
    int border_blue;

    //color font
    int font_red;
    int font_green;
    int font_blue;

    //box color
    int red;
    int green;
    int blue;

    //value inside the box
    char value[100];

    //pointers: used only on binary tree
    char lvalue[100];
    char rvalue[100];
    //need to show the pointer value? used only on binary tree
    int plotLValue;
    int plotRValue;

    //position on screen (box)
    int x;
    int y;

    //position on screen(labels)
    int x_label;
    int y_label;

};

typedef struct BOX_STR BOX;

/**
Queue Element: used by tries
*/
typedef struct QueueElement
{
    void *str_to_queue;
    struct QueueElement *next;

} QueueElement;

/**
* Queue: used by tries
*/
typedef struct Queue
{
    int height;
    struct QueueElement* head;
    struct QueueElement* tail;

} Queue;


/**
* Point Structure (to store the screen coordenates)
*/
typedef struct TREE_POINT
{
    int x;
    int y;

}TREE_POINT;


/**
* Line Structure (store 2 points)
*/
typedef struct TREE_LINE
{
    TREE_POINT points[2];
}TREE_LINE;


/**
* Trees structure
*/
typedef struct T_NODE
{
    char value[100];
    int x;
    int y;
    int isNull;
    int plotLine[4];
    TREE_LINE *lines[4];
    int aux_red_tree;
    int aux_green_tree;
    int aux_blue_tree;
    int boxWithDivision;

}TREE_NODE;

/**
* Trees structure
*/
typedef struct B_NODE
{
    int isNull;
    char value[100];
    int x;
    int y;
    int aux_red_tree;
    int aux_green_tree;
    int aux_blue_tree;

}B_TREE_NODE;

struct BOX_STR_B
{
    struct B_NODE boxes[99];
    int x;
    int y;
    int plotLine[35];
    TREE_LINE *lines[35];

};

typedef struct BOX_STR_B BOX_B;

/**
* Struct used on B Trees
*/
typedef struct NODE_B_TREE
{
    void *CHAVES[99];
    struct NODE_B_TREE *filhos[100];

}NODE_B_TREE;

#endif
