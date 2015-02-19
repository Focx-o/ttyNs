/*
 * =====================================================================================
 *
 *       Filename:  load.c
 *
 *    Description:  Create windows and panels
 *
 *        Version:  1.0
 *        Created:  Wednesday 24 December 2014 06:04:44  IST
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Ankan Biswas (talk2ankan), support@ankanbiswas.in
 *        Company:  Bug17, West Bengal
 *
 * =====================================================================================
 */


#include	"header.h"
#include	"config.h"

/*  create window */
void init_window (WINDOW **win, int n ){

	int row, col, y, x, i;

	getmaxyx(stdscr,row,col);
	
	y = (row - LOAD_PANEL_HEIGHT)/2;
	x = (col - LOAD_PANEL_WIDTH)/2;

	for (i = 0; i < n; ++i){
		win[i] = newwin(LOAD_PANEL_HEIGHT,LOAD_PANEL_WIDTH,y,x);
		wattron(win[i],COLOR_PAIR(i+1));
		box(win[i],0,0);
		wattroff(win[i],COLOR_PAIR(i+1));
	}
}

/*  create panel */
void init_panel (PANEL **pan, WINDOW **win){

	pan[0] = new_panel(win[0]); 	
	pan[1] = new_panel(win[1]); 

	set_panel_userptr(pan[0], pan[1]);
	set_panel_userptr(pan[1], pan[0]);

	update_panels();

}
