/*
+-------------------------------------------------------------------------------------------+
|Federal University Of Juiz de Fora - UFJF - Minas Gerais - Brazil                          |
|Institute for Exact Sciences - ICE                                                         |
|Computer Science Departament - DCC                                                         |
|Project: Visual library to support Data Structures classes                                 |
|Professor:Jairo Francisco de Souza    jairo.souza@ufjf.edu.br                              |
|Students......:Thiago Moratori Peixoto     thiagomoratori@gmail.com                        |
|               Sandro Athaide Coelho       sandroacoelho@gmail.com                         |
|Created in......:Sep/26/2011                                                               |
|Objective: this file is the implementation of the head with all methods of  Allegro        |
|DSGraph directives                                                                         |
|Latest updates                                                                             |

 Change the set_color_depth from 32 bits color scheme to desktop_color_depth
 set_color_depth(desktop_color_depth());
 by sandroacoelho@gmail.com in 04/29/2012

 Replace the virtual screen scrolling for tile based scrolling
 by sandroacoelho@gmail.com in 04/28/2012

 Review all the code to
    - prevent memory leak;
    - improve comments;
    - replace wrong approaches (e.g. Use rest_call_back to check input keys);
    - modify the start form (init);
    - put catch signal for SIGSEG occurrences;
    - create dynamically the scroll area;
 by sandroacoelho@gmail.com in 04/28/2012

|                                                                                           |
|-------------------------------------------------------------------------------------------+
*/
//BOF

#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
#include <allegro.h>
#include <unistd.h>
#include "DSConstants.h"
#include "DSMessages.h"
#include "DSStructures.h"
#include <signal.h>
#include <math.h>
#define STEP 10
static int SCREEN_WIDTH = 800;
static int SCREEN_HEIGHT = 600;
static int VERTICAL_TILE = 0;
static int HORIZONTAL_TILE = 0;
static int LAST_VERTICAL_TILE = 0;
static int LAST_HORIZONTAL_TILE = 0;
static int LAST_VERTICAL_TILE_LINE = 0;
static int LAST_HORIZONTAL_TILE_LINE = 0;
static int LAST_VERTICAL_TILE_TRIANGLE = 0;
static int LAST_HORIZONTAL_TILE_TRIANGLE = 0;
static int border_red_color_user_defined = -1;
static int border_blue_color_user_defined = -1;
static int border_green_color_user_defined = -1;
static int node_red_color_user_defined = -1;
static int node_blue_color_user_defined = -1;
static int node_green_color_user_defined = -1;
static volatile int close_button_pressed = 0;
static int initAllegroResult = -2;
static int seconds_to_wait = 2000;//Default wait
static int isPaused = 0;//Flag to pause the exibition on the screen
static int SCREEN_TILES_Y = 0 ;//Coordenates of tiles
static int SCREEN_TILES_X = 0;//Coordenates of tiles
static BITMAP ***scroll  = NULL;//Tiles variable
static int window_x = 0;//position variables
static int window_y = 0;//position variables
static char personalizedMessage[1000];
static int  personalizedMessageX=10;
static int  personalizedMessageY=50;
//Triangle Temp Variables
static int triangle_x_last = 0;
static int triangle_y_last = 0;
static int triangle_x1_last = 0;
static int triangle_y1_last = 0;
static int triangle_x2_last = 0;
static int triangle_y2_last = 0;
//Line Temp Variables
static int line_x_last = 0;
static int line_y_last = 0;
static int line_x1_last = 0;
static int line_y1_last = 0;


/**
* Remove the bitmap area from the memory
*/
static void destroyScrollArea()
{
    int i;
    for(i=0; i<SCREEN_TILES_Y; i++)
        free(scroll[i]);

    free(scroll);
}

/**
 * {@inheritDoc}
 */
void createScrollArea(int Y, int X)
{
    if (close_button_pressed == 1) return;

    SCREEN_TILES_X = X;
    SCREEN_TILES_Y = Y;

    int i,j;

    scroll= malloc( SCREEN_TILES_Y * sizeof( BITMAP ) );

    for(i=0; i<SCREEN_TILES_Y; i++)
        scroll[i]= malloc( SCREEN_TILES_X * sizeof( BITMAP ) );


    if(scroll == NULL)
    {
        allegro_message($MSG_MALLOC_BITMAP );
        close_button_pressed = 1;
    }
    else
    {
        for(i=0; i<SCREEN_TILES_Y; i++)
            for(j=0; j<SCREEN_TILES_X; j++)
                scroll[i][j] = NULL;
    }

}

/**
 * {@inheritDoc}
 */
void finalize()
{
    allegro_exit();
    destroyScrollArea();
#ifdef __unix__
    destroy_bitmap(screen);
#endif
}

/**
* Based on x and y coordinates, this method define what is current tile
* @param int x
* @param int y
*/
void setTile(int x, int y)
{

    if (close_button_pressed == 1) return;


    VERTICAL_TILE =   y/SCREEN_HEIGHT;
    HORIZONTAL_TILE = x/SCREEN_WIDTH;

    if (HORIZONTAL_TILE > SCREEN_TILES_X - 1)
    {
        allegro_message($MSG_LIMIT_TILE);
        close_button_pressed = 1;
    }


    if (VERTICAL_TILE > SCREEN_TILES_Y - 1)
    {
        allegro_message($MSG_LIMIT_TILE);
        close_button_pressed = 1;
    }

}

/**
* Get the current X position
*/
static int getTileXPosition()
{
    return HORIZONTAL_TILE * SCREEN_WIDTH;
}

/**
* Get the current Y position
*/
static int getTileYPosition()
{
    return VERTICAL_TILE * SCREEN_HEIGHT;
}

/**
* CallBackFunction used on the rest_callback.
* rest_callback pause the current execution
*/
static void callBackFunction()
{
}

/**
* Draw the virtual screen on real screen on position x and y
* @param int x
* @param int y
*/
static void doBlit(int x, int y )
{

    if (x<0) x = 0;
    if (y<0) y = 0;


    int vertical_blit   = y/SCREEN_HEIGHT;
    int horizontal_blit = x/SCREEN_WIDTH;


    if (close_button_pressed == 1) return;

    if (scroll[vertical_blit][horizontal_blit] == NULL || close_button_pressed == 1 )  return;


    blit(scroll[vertical_blit][horizontal_blit], screen, (x > SCREEN_WIDTH? x - (SCREEN_WIDTH * horizontal_blit)  : x), y , 0, 0, SCREEN_WIDTH-1, SCREEN_HEIGHT-1);

    if(x==0 && y!=0)
    {
        vertical_blit +=1;

        if (scroll[vertical_blit][horizontal_blit] == NULL || close_button_pressed == 1 )  return;

        draw_sprite(screen,scroll[vertical_blit][horizontal_blit], x , y == SCREEN_HEIGHT ? SCREEN_HEIGHT :
                    y >  SCREEN_HEIGHT ? (SCREEN_HEIGHT * vertical_blit) - y : SCREEN_HEIGHT - y == 0? SCREEN_HEIGHT:SCREEN_HEIGHT - y   );


    }
    else
    {
        if ((x !=0 &&  y ==0) || (x==0 && y ==0))
        {
            if (scroll[vertical_blit][horizontal_blit + 1] == NULL || close_button_pressed == 1 )  return;

            if(SCREEN_TILES_X - (horizontal_blit + 1)>0)
                draw_sprite(screen,scroll[vertical_blit][horizontal_blit + 1], SCREEN_WIDTH - (x > SCREEN_WIDTH? x - (SCREEN_WIDTH * horizontal_blit)  : x) , y == 0? y: y * -1 );

        }
        else
        {
            horizontal_blit +=1;
            if (scroll[vertical_blit][horizontal_blit] == NULL || close_button_pressed == 1 )  return;

            draw_sprite(screen,scroll[vertical_blit][horizontal_blit], SCREEN_WIDTH - (x > SCREEN_WIDTH? x - (SCREEN_WIDTH * horizontal_blit)  : x) , y == 0? y: y * -1 );

            vertical_blit    +=1;
            if (scroll[vertical_blit][horizontal_blit] == NULL || close_button_pressed == 1 )  return;

            draw_sprite(screen,scroll[vertical_blit][horizontal_blit], SCREEN_WIDTH - (x > SCREEN_WIDTH? x - (SCREEN_WIDTH * horizontal_blit)  : x) ,
                        y >  SCREEN_HEIGHT ? SCREEN_HEIGHT * vertical_blit - y :SCREEN_HEIGHT - y );

            horizontal_blit -=1;
            if (scroll[vertical_blit][horizontal_blit] == NULL || close_button_pressed == 1 )  return;

            draw_sprite(screen,scroll[vertical_blit][horizontal_blit], x * -1 , y >  SCREEN_HEIGHT ? SCREEN_HEIGHT * vertical_blit - y :SCREEN_HEIGHT - y   );
        }
    }

}

/**
* Check if some keys are pressed
*   HOME : go to home on virtual screen
*   END  : go to end on virtual screen
*   RIGHT: go to STEP positions to right on virtual screen
*   LEFT : go to STEP positions to left on virtual screen
*   DOWN : go to STEP positions to down on virtual screen
*   UP   : go to STEP positions to up on virtual screen
*   P    : pause screen actions
*   C    : continue screen actions
*/
void getPressedKeys()
{

    if (close_button_pressed == 1) return;

    if (key[KEY_HOME] && keypressed())
    {
        clear_keybuf();
        window_x = 0;
        window_y = 0;

        isPaused= 1;
        doBlit(window_x,window_y);

    }

    if (close_button_pressed == 1) return;

    if (key[KEY_END] && keypressed())
    {
        clear_keybuf();
        window_x = HORIZONTAL_TILE * SCREEN_WIDTH ;
        window_y = 0;
        isPaused= 1;
        doBlit(window_x,window_y);

    }

    if (close_button_pressed == 1) return;

    //check right arrow
    if (key[KEY_RIGHT] && keypressed())
    {
        clear_keybuf();

        if (SCREEN_TILES_X>1)
            window_x += STEP;

        isPaused= 1;

        doBlit(window_x,window_y);

    }

    if (close_button_pressed == 1) return;
    //check left arrow
    if (key[KEY_LEFT]  && keypressed() )
    {
        clear_keybuf();

        if (SCREEN_TILES_X>1)
            window_x -= STEP;

        window_x = window_x<0?0:window_x;

        isPaused= 1;

        doBlit(window_x,window_y);

    }

    if (close_button_pressed == 1) return;

    //check down arrow
    if (key[KEY_DOWN] && keypressed() )
    {
        clear_keybuf();

        if (SCREEN_TILES_Y>1)
            window_y += STEP;

        isPaused= 1;
        doBlit(window_x,window_y);
    }

    if (close_button_pressed == 1) return;

    //check up arrow
    if (key[KEY_UP] && keypressed() )
    {
        clear_keybuf();

        if (SCREEN_TILES_Y>1)
            window_y -= STEP;

        isPaused= 1;

        doBlit(window_x,window_y);
    }

    if (close_button_pressed == 1) return;

    //Flag to pause the exibition on the screen
    if(key[KEY_P])
    {
        isPaused= 1;
    }

    if (close_button_pressed == 1) return;

    if(key[KEY_C])
    {
        isPaused= 0;
    }


}

/**
 * {@inheritDoc}
 */
void stopIfPaused()
{

    if (close_button_pressed == 1) return;

    while (isPaused==1)
    {

        if (close_button_pressed == 1) break;
        if ( close_button_pressed == 0)
        {
            if (scroll[0][0] != NULL)
                textprintf_ex(scroll[0][0], font, 10, 30 , makecol(0,0,0), -1, $MSG_PAUSE);

            if (close_button_pressed == 1) break;
            doBlit(window_x, window_y);

        }

        if (close_button_pressed == 1) break;
        if (keypressed()) getPressedKeys();

        if (close_button_pressed == 1) break;
        textprintf_ex(scroll[0][0], font, 10, 30 , makecol(0,0,0), -1, $MSG_PAUSE);

        if (close_button_pressed == 1) break;
        doBlit(window_x, window_y);

        if (keypressed()) getPressedKeys();

        if (close_button_pressed == 1) break;
        usleep(5);
    }

}

/**
 * {@inheritDoc}
 */
int getInitAllegroResult()
{
    return initAllegroResult;
}

/**
* Put the comment on screen
*/
static void putCommentOnScreen()
{
    if (close_button_pressed == 1) return;

    if (scroll !=NULL && scroll[0][0]!=NULL)
       textprintf_ex(scroll[0][0], font, personalizedMessageX,personalizedMessageY , makecol(0,0,156), -1,"%s", personalizedMessage);
}

/**
 * {@inheritDoc}
 */
void showComment(const char *format, ...)
{

    if (close_button_pressed == 1) return;

    va_list args;
    va_start( args, format );
    vsprintf(personalizedMessage,format, args);
    va_end( args );

    putCommentOnScreen();

}

/**
* Set instructions on screen
*/
void setInfo()
{
    if (scroll[0][0] ==NULL || close_button_pressed == 1) return;
    textprintf_ex(scroll[0][0], font, 10, 10 , makecol(0,0,0), -1, $MSG_SCROLL);

#if defined _WIN32
    textprintf_ex(scroll[0][0], font, 10, 20 , makecol(0,0,0), -1, $MSG_EXIT);
#endif

    if (personalizedMessage!=NULL)
    {
        putCommentOnScreen();
    }

}


/**
* Return a color for Allegro 4 based on RGB standard
* @param int red
* @param int green
* @param int blue
*/
int getColor(int red, int green, int blue)
{

    return makecol(red, green, blue);

}

/**
 * {@inheritDoc}
 */
void drawTriangle(int x, int y , int x1, int y1, int x2, int y2)
{

    if (close_button_pressed == 1) return;

    int tempX =x>x1? x:x1;
    int tempY =y>y1? y:y1;


    setTile(tempX>x2?tempX:x2,tempY>y2?tempY:y2);

    //Check the current and the last tile to draw the triangle on both tiles
    if (LAST_VERTICAL_TILE_TRIANGLE != VERTICAL_TILE || LAST_HORIZONTAL_TILE_TRIANGLE != HORIZONTAL_TILE)
    {
        triangle(scroll[LAST_VERTICAL_TILE_TRIANGLE][LAST_HORIZONTAL_TILE_TRIANGLE], triangle_x_last - getTileXPosition() ,  triangle_y_last - getTileYPosition() ,
                 triangle_x1_last - getTileXPosition(), triangle_y1_last - getTileYPosition(),
                 triangle_x2_last -  getTileXPosition(), triangle_y2_last - getTileYPosition(),getColor(0,0,0) );
        LAST_VERTICAL_TILE_TRIANGLE = VERTICAL_TILE;
        LAST_HORIZONTAL_TILE_TRIANGLE = HORIZONTAL_TILE;

    }
    // Store a current value to paint on the next tile
    triangle_x_last = x;
    triangle_y_last = y;
    triangle_x1_last = x1;
    triangle_y1_last = y1;
    triangle_x2_last = x2;
    triangle_y2_last = y2;


    if (close_button_pressed == 1) return;

    triangle(scroll[VERTICAL_TILE][HORIZONTAL_TILE], x - getTileXPosition(),  y - getTileYPosition(),  x1- getTileXPosition(), y1 -  getTileYPosition(),  x2- getTileXPosition() , y2 -  getTileYPosition(),getColor(0,0,0) );

    doBlit(window_x,window_y);
}


/**
 * {@inheritDoc}
 */
void drawLine(int x, int y, int x1, int y1)
{

    if (close_button_pressed == 1) return;

    setTile(x>x1? x:x1,y>y1?y:y1);


    //@sandro:
    // Todo:  - simplificar esta rotina
    //        - comentar e explicar o porque de tais decisões
    //Check the current and the last tile to draw the line on both tiles
    int dif = (x-x1);
        dif = dif < 0 ? dif * -1: dif;
    if( LAST_HORIZONTAL_TILE_LINE != HORIZONTAL_TILE &&  y != y1 && x!=x1 && x<=x1 && dif< SCREEN_WIDTH)
    {

        int x_tile_position = getTileXPosition();

        int x_pos = 0;

        //Calculating the line inclination to get the correct tile position
        double angle = (double)abs(y-y1);
        angle = angle/ (double)abs(x-x1);
        angle  = atan(angle) * 180.0/$PI;

        double hypotenuse = 90 - angle ;
        hypotenuse = sin((hypotenuse * $PI)/180.0);
        hypotenuse =(double)  (x_tile_position - abs(x<x1? x:x1)) / hypotenuse;

        double height = sin((angle * $PI)/180.0) ;
        height =  height * hypotenuse;

        int y_pos = (y<y1?y:y1) + height;
        int x_pos_last = abs(x>x1? x:x1 - x_tile_position);
        int y_pos_last = y>y1?y:y1 ;

        if (close_button_pressed == 1) return;
        line (scroll[LAST_VERTICAL_TILE_LINE][HORIZONTAL_TILE],x_pos, y_pos ,x_pos_last, y_pos_last,getColor(0,0,0) );
        LAST_VERTICAL_TILE_LINE = VERTICAL_TILE;
        LAST_HORIZONTAL_TILE_LINE = HORIZONTAL_TILE;


    }


    //Line Temp Variables
    line_x_last = x;
    line_y_last = y;
    line_x1_last = x1;
    line_y1_last = y1;
    if (close_button_pressed == 1) return;
    setTile(x<x1? x:x1,y<y1?y:y1);
    line (scroll[VERTICAL_TILE][HORIZONTAL_TILE],x - getTileXPosition(), y -  getTileYPosition(), x1 - getTileXPosition(), y1 -  getTileYPosition(),getColor(0,0,0) );
    doBlit(window_x,window_y);

    if (close_button_pressed == 1) return;
    setTile(line_x_last,line_y_last);

    if (close_button_pressed == 1) return;

    //Check if line is bigger than the screen width. When it occurs, the program need to draw the line along the tiles
    //screen_width - 100 : to detected the borders
    if (x1 - x > (SCREEN_WIDTH -100) && y == y1)
    {
        int firstTile = 1;
        while(1)
        {
            if (close_button_pressed == 1) break;
            setTile(x<x1? x:x1,y<y1?y:y1);
            line (scroll[VERTICAL_TILE][HORIZONTAL_TILE],firstTile?x - getTileXPosition():0, y -  getTileYPosition(),
                  x1 - getTileXPosition(), y1 -  getTileYPosition(),getColor(0,0,0) );
            doBlit(window_x,window_y);
            x+=SCREEN_WIDTH;
            if (x>x1 && firstTile == 0) break;
            firstTile = 0;
        }



    }
    else
    {
        if (close_button_pressed == 1) return;
        line (scroll[VERTICAL_TILE][HORIZONTAL_TILE],x - getTileXPosition(), y -  getTileYPosition(), x1 - getTileXPosition(), y1 -  getTileYPosition(),getColor(0,0,0) );
        doBlit(window_x,window_y);
    }
    if (close_button_pressed == 1) return;
    LAST_VERTICAL_TILE_LINE = VERTICAL_TILE;
    LAST_HORIZONTAL_TILE_LINE = HORIZONTAL_TILE;

    doBlit(window_x,window_y);
}

/**
 * {@inheritDoc}
 */
void setAllegroSleepTime(int seconds)
{
    seconds_to_wait = seconds * 1000;
}

/**
 * {@inheritDoc}
 */
void setAllegroBorderColor(int red, int green, int blue)
{

    if (close_button_pressed == 1) return;
    border_red_color_user_defined   = ( red   <= 255 && red   >= 0) ? red:  -1;
    border_blue_color_user_defined  = ( green <= 255 && green >= 0) ? green:-1;
    border_green_color_user_defined = ( blue  <= 255 && blue  >= 0) ? blue: -1;
}

/**
 * {@inheritDoc}
 */
void setAllegroColor(int red, int green, int blue)
{

    if (close_button_pressed == 1) return;
    node_red_color_user_defined =( red <= 255 && red >= -1) ? red : -1;
    node_blue_color_user_defined =( blue <= 255 && blue >= -1) ? blue : -1;
    node_green_color_user_defined =(  green <= 255 &&  green >= -1) ? green : -1;
}

/**
 * {@inheritDoc}
 */
int getNodeRedColor()
{
    return node_red_color_user_defined;
}

/**
 * {@inheritDoc}
 */
int getNodeGreenColor()
{
    return node_green_color_user_defined;
}

/**
 * {@inheritDoc}
 */
int getNodeBlueColor()
{
    return node_blue_color_user_defined;
}


/**
 * {@inheritDoc}
 */
void setTitle(char *name)
{

    if (close_button_pressed == 1) return;
    set_window_title(name);
}


/**
* Load all necessary addons
*   font addon, true-type font addon
*/
static void loadAddons()
{
    install_keyboard();
    install_timer();
}


/**
* Create the EventQueue element resposible for to notify all events on the
* screen object
*/
int createEventQueue()
{
    return 0;
}

/**
* Set the background color on the screen
* @param red
* @param green
* @param blue
*/
void setColor(int red, int green, int blue)
{
    clear_to_color(screen, getColor(red,green,blue));
}

/**
 * {@inheritDoc}
 */
void close_button_handler(void)
{
    close_button_pressed = 1;
}


/**
 * {@inheritDoc}
 */
void drawBox(struct BOX_STR *b)
{

    if (close_button_pressed == 1) return;
    setTile(b->x + b->width, b->y + b->height);

    stopIfPaused();

    b->border_red   = border_red_color_user_defined    == -1 ? b->border_red   : border_red_color_user_defined;
    b->border_green = border_blue_color_user_defined   == -1 ? b->border_green : border_blue_color_user_defined;
    b->border_blue  = border_green_color_user_defined  == -1 ? b->border_blue  : border_green_color_user_defined;

    b->red   = node_red_color_user_defined   == -1 ? b->red   : node_red_color_user_defined;
    b->green = node_blue_color_user_defined  == -1 ? b->green : node_blue_color_user_defined;
    b->blue  = node_green_color_user_defined == -1 ? b->blue  : node_green_color_user_defined;

    if (close_button_pressed == 1) return;

    //Check if box is on distinct tile and try to draw it on the both tiles

    if ( b != NULL && close_button_pressed == 0 &&
            scroll[VERTICAL_TILE][HORIZONTAL_TILE] != NULL &&
            ( LAST_VERTICAL_TILE != VERTICAL_TILE || LAST_HORIZONTAL_TILE != HORIZONTAL_TILE))
    {
        if (close_button_pressed == 1) return;

        rectfill(scroll[VERTICAL_TILE][HORIZONTAL_TILE],  b->x - getTileXPosition(), b->y - getTileYPosition() ,b->x + b->width - getTileXPosition(),
                 b->y +  b->height - getTileYPosition(),getColor( b->red, b->green, b->blue));


        if (close_button_pressed == 1) return;

        rect(scroll[VERTICAL_TILE][HORIZONTAL_TILE],b->x - getTileXPosition() , b->y - getTileYPosition() ,b->x + b->width - getTileXPosition() ,
             b->y +  b->height - getTileYPosition(),getColor( b->border_red, b->border_green, b->border_blue ));

        if (close_button_pressed == 1) return;

        textprintf_ex(scroll[VERTICAL_TILE][HORIZONTAL_TILE], font,  b->x_label  - getTileXPosition()  ,  b->y_label - getTileYPosition(), makecol(0,0,0), -1,  b->value, 0);

        LAST_VERTICAL_TILE = VERTICAL_TILE;
        LAST_HORIZONTAL_TILE = HORIZONTAL_TILE;

    }


    setTile(b->x, b->y);

    if (scroll[VERTICAL_TILE][HORIZONTAL_TILE] != NULL )
    {
        if (close_button_pressed == 1) return;

        rect(scroll[VERTICAL_TILE][HORIZONTAL_TILE],b->x - getTileXPosition(),b->y - getTileYPosition(),b->x + b->width  - getTileXPosition(),
             b->y + b->height  - getTileYPosition(),getColor(b->border_red,b->border_green,b->border_blue ));

        if (close_button_pressed == 1) return;

        rectfill(scroll[VERTICAL_TILE][HORIZONTAL_TILE], b->x + 1  - getTileXPosition() ,b->y + 1 - getTileYPosition(),b->x + b->width - 1 - getTileXPosition(),
                 b->y + b->height - 1 - getTileYPosition(),getColor(b->red,b->green,b->blue));

        if (close_button_pressed == 1) return;

        textprintf_ex(scroll[VERTICAL_TILE][HORIZONTAL_TILE], font, b->x_label  - getTileXPosition(), b->y_label - getTileYPosition() , makecol(b->font_red,b->font_green,b->font_blue), -1, b->value, 0);

        if (close_button_pressed == 1) return;

        doBlit(window_x,window_y);
    }

    stopIfPaused();
}


/**
 * {@inheritDoc}
 */
void drawBoxWithDivision(struct BOX_STR *b, int showTheMemoryAddress)
{
    if (close_button_pressed == 1) return;

    stopIfPaused();

    drawBox(b);

    drawLine(b->x + 5, b->y  , b->x + 5, b->y + b->height);

    drawLine(b->x + b->width -  5, b->y  , b->x + b->width - 5, b->y + b->height);

    if (close_button_pressed == 1) return;

    if (showTheMemoryAddress ==1)
    {
        if (b->plotLValue==1)
            textprintf_ex(scroll[VERTICAL_TILE][HORIZONTAL_TILE], font, b->x - b->width - 28 , b->y_label ,  makecol(b->font_red,b->font_green,b->font_blue), -1, b->lvalue, 0);

        if (b->plotRValue==1)
            textprintf_ex(scroll[VERTICAL_TILE][HORIZONTAL_TILE], font, b->x + b->width * 1.5 , b->y_label,  makecol(b->font_red,b->font_green,b->font_blue), -1, b->rvalue, 0);

    }

    if (close_button_pressed == 1) return;

    doBlit(window_x,window_y);

    stopIfPaused();
}


/**
 * {@inheritDoc}
 */
void waitToContinue()
{
    stopIfPaused();

    if (close_button_pressed == 1) return;
    rest_callback(seconds_to_wait, *callBackFunction);
}

/**
 * {@inheritDoc}
 */
void catch_segfault(int sig)
{
    printf("+-----------------------------------------------------------------+\n");
    printf($MSG_ERROR_DSGRAPH);
    printf("\n");
    printf($MSG_ERROR_DSGRAPH_1);
    printf("\n");
    printf($MSG_ERROR_DSGRAPH_2);
    printf("\n");
    printf("+-----------------------------------------------------------------+\n");
    // print out all the frames to stderr
    fprintf(stderr, "Error: signal %d:\n", sig);

}



/**
* Continue showing the screen until receive the close event or a mouse click
*/
void continueShowScreen()
{

    signal(SIGSEGV,catch_segfault);

    release_screen();
    initAllegroResult = 0;
    close_button_pressed = 0;

    while (1)
    {
        if(keypressed())
            getPressedKeys();

        if (close_button_pressed ==1 || key[KEY_ESC])
        {
            close_button_pressed =1;
            fade_out(6);
            break;
        }

        usleep(3);
    }

    finalize();

}

/**
 * {@inheritDoc}
 */
int getScreenHeight()
{
    return SCREEN_HEIGHT;
}

/**
 * {@inheritDoc}
 */
int getScreenWidth()
{
    return SCREEN_WIDTH;
}

/**
* Destroy the tiles
*/
static void destroyScrollBitmap()
{

    int i=0;
    int j=0;
    for(i=0; i<SCREEN_TILES_Y; i++)
        for(j=0; j<SCREEN_TILES_X; j++)
        {
            if (scroll[i][j]!=NULL)
                destroy_bitmap(scroll[i][j]);
        }


}

/**
* Create the tiles
*/
static void createScrollBitmap()
{
    int i=0;
    int j=0;

    if (close_button_pressed == 1) return;

    for(i=0; i<SCREEN_TILES_Y; i++)
        for(j=0; j<SCREEN_TILES_X; j++)
        {
            if (close_button_pressed == 1 )  break;
#ifdef __unix__
            scroll[i][j] = create_bitmap_ex(desktop_color_depth(), SCREEN_WIDTH, SCREEN_HEIGHT);
#elif defined _WIN32
            scroll[i][j] = create_system_bitmap(SCREEN_WIDTH, SCREEN_HEIGHT);
#endif

            if (scroll[i][j] == NULL || close_button_pressed == 1 )  break;

            clear_to_color(scroll[i][j], getColor(255,255,255));
        }

}

/**
 * {@inheritDoc}
 */
void clearScreen()
{
    if(close_button_pressed==1 || initAllegroResult !=0) return;
    clear_to_color(screen, getColor(255,255,255));

    if(close_button_pressed==1) return;
    destroyScrollBitmap();

    if(close_button_pressed==1) return;
    createScrollBitmap();

    if(close_button_pressed==1) return;
    setInfo();
}

/**
* Create a window with width and height parameters
* @param width : size of X screen
* @param height: size of Y screen
*/
static int createWindow(int width, int height)
{

    set_color_depth(desktop_color_depth());

#ifdef __unix__
    if (set_gfx_mode(GFX_SAFE, width, height, 0, 0) < 0)
    {
        finalize();
        initAllegroResult = -1;
        return -1;

    }
#elif defined _WIN32

    if (set_gfx_mode(GFX_AUTODETECT_WINDOWED, width, height,0,0) < 0)
    {
        finalize();
        initAllegroResult = -1;
        return -1;

    }

#endif

    set_palette(desktop_palette);
    createScrollBitmap();
    loadAddons();

#ifdef __unix__
    set_close_button_callback(close_button_handler);
    acquire_screen();
#endif

    continueShowScreen();

    return 0;

}

/**
* Initialize the Allegro library
*/
int initAllegro()
{

    int result = 0 ;

    if(allegro_init()!=0)
    {
        fprintf(stderr, $ALLEGRO_INIT_ERROR);
        initAllegroResult = -1;
        finalize();
        return -1;
    }
    result = createWindow(SCREEN_WIDTH,SCREEN_HEIGHT);

    return result;

}

/**
 * {@inheritDoc}
 */
void showScreen()
{
    signal(SIGSEGV,catch_segfault);

    initAllegroResult =  initAllegro();


    if (close_button_pressed == 1) return;

    if (initAllegroResult !=0)
    {
        exit(initAllegroResult);
    }

}
//EOF
