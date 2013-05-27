/*
+--------------------------------------------------------------------------------------+
|Federal University Of Juiz de Fora - UFJF - Minas Gerais - Brazil                     |
|Institute for Exact Sciences - ICE                                                    |
|Computer Science Departament - DCC                                                    |
|Project: Visual library to support Data Structures classes                            |
|Professor:Jairo Francisco de Souza    jairo.souza@ufjf.edu.br                         |
|Students......:Thiago Moratori Peixoto     thiagomoratori@gmail.com	               |
|                 Sandro Athaide Coelho       sandroacoelho@gmail.com                  |
|Created in......:April/01/2011                                                        |
|Objective: this file is the head of the Allegro DSGraph directives                    |
|Latest updates                                                                        |
|                                                                                      |
Adding by sandroacoelho@gmail.com in 04/28/2012
void createScrollArea(int Y, int X);
void catch_segfault(int sig);
|--------------------------------------------------------------------------------------+
*/

#ifndef DSAllegro_H
#define DSAllegro_H

#include "DSStructures.h"
//BOF

/**
* Clear the screen
*/
void clearScreen();

/**
* Returns the Allegro init result
*/
int getInitAllegroResult();

/**
* Wait a x seconds to continue the thread
*/
void waitToContinue();

/**
 * Show the window
 */
void *showScreen();

/**
* Finalize and unload Allegro resources
*/
void finalize();

/**
 * Draw the box/cell on the screen
 * @param struct BOX_STR *b
 */
void drawBox(struct BOX_STR *b);

/**
 * Draw the box/cell with division and addresses on the screen
 * @param struct BOX_STR *b
 *               showTheMemoryAddress if 0 doesn't show the adress
 */
void drawBoxWithDivision(struct BOX_STR *b, int showTheMemoryAddress);

/**
* Returns the screen width
*/
int getScreenWidth();

/**
* Returns the screen height
*/
int getScreenHeight();

/**
* Set the structure's name on screen
* @param name
*/
void setTitle(char *name);

/**
* Set the sleep time
* @param seconds
*/
void setAllegroSleepTime(int seconds);

/**
* Init the node border color
* @param: red, green, blue
*/
void setAllegroBorderColor(int red, int green, int blue);

/**
* Init the node  color
* @param: red, green, blue
*/
void setAllegroColor(int red, int green, int blue);

/**
* Gets the red color setted by the user
*/
int getNodeRedColor();

/**
* Gets the green color setted by the user
*/
int getNodeGreenColor();

/**
* Gets the blue color setted by the user
*/
int getNodeBlueColor();

/**
 * Draw a triangle
 * @param int x
 * @param int y
 * @param int x1
 * @param int y1
 * @param int x2
 * @param int y2
 */
void drawTriangle(int x, int y , int x1, int y1, int x2, int y2);

/**
 * Draw a line
 * @param int x
 * @param int y
 * @param int x1
 * @param int y1
 */
void drawLine(int x, int y, int x1, int y1);

/**
* Pause DSGraph/Algorithm execution if isPause == 1
*/
void stopIfPaused();

/**
 * Receive the close event
*/
void close_button_handler(void);

/**
* Set a text on screen
* @param string - a message
**/
void showComment(const char *string, ...);

/**
* Create dynamically the scroll area
* @param Y - number of lines
* @param X - number of columns
*/
void createScrollArea(int Y, int X);

/**
* Catch SIGSEGV when it ocurrs
* @param sig - signal
*/
void catch_segfault(int sig);
#endif
//EOF
