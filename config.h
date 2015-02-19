/*
 * =====================================================================================
 *
 *       Filename:  config.h
 *
 *    Description:  configuration file
 *
 *        Version:  1.0
 *        Created:  Wednesday 24 December 2014 02:07:29  IST
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Ankan Biswas (talk2ankan), support@ankanbiswas.in
 *        Company:  Bug17, West Bengal
 *
 * =====================================================================================
 */

#ifndef __CONFIG_H__
#define __CONFIG_H__

#define LOAD_PANEL_HEIGHT 18    /*  panel height and width */
#define LOAD_PANEL_WIDTH 60     

#define load_box_height 2      /* loading box height and width */
#define load_box_width 4

/*Change Color As Per Your Choise


		COLOR_NAME   COLOR_VALUE
	---------------------------
		COLOR_BLACK   0
        COLOR_RED     1
        COLOR_GREEN   2
        COLOR_YELLOW  3
        COLOR_BLUE    4
        COLOR_MAGENTA 5
        COLOR_CYAN    6
        COLOR_WHITE   7

*/

#define LOAD_PANEL_COLOR COLOR_GREEN  /* give COLOR_VALUE or COLOR_NAME as per your choise */
#define LOAD_BOX_COLOR COLOR_RED 

#define LOAD_SPEED 50000		/* time to load your application */
#define LOAD_COUNT 98           /* number of moves or set the position of the box after loading*/

#define LOAD_TAG "loading..."   /*load name*/
#define LOAD_TAG_POSITION 2     /*load name position, up and down only*/




/*NOTES OR LINES YOUR U WANT TO DISPLAY AFTER THE LOAD*/

#define line0 " "
#define line1 "  Who am i?  "
#define line2 ""
#define line3 "Howdy, I am Ankan Biswas. A linux freak in West Bengal."
#define line4 "I work at nowhere.                                     "
#define line5 " "
#define line6 "------------------------------------------------------"
#define line7 " Version:  1.0                                     "
#define line8 " Created:  Wednesday 24 December 2014 02:07:29  IST"
#define line9 "Compiler:  gcc                                     "
#define line10 "------------------------------------------------------"
#define line11 " Author:  Ankan Biswas (talk2ankan)               "
#define line12 "  Email:  support@ankanbiswas.in                  "
#define line13 "Website:  http://ankanbiswas.in                   "
#define line14 "------------------------------------------------------"
#define line15 " < 'spacebar' to continue > < 'q' to quit >"


/* execute command of shell */
#define COMMAND "./game 3"

#endif
