/*
 * =====================================================================================
 *
 *       Filename:  main.h
 *
 *    		 Note:  I created this for my learning purpose. Fixes and modification will be appreciable.
 *
 *        Version:  1.0
 *        Created:  Wednesday 24 December 2014 05:11:23  IST
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
#include	"load.h"

	int main ( )
{

	WINDOW *win[2];
	PANEL *pan[2];
	PANEL *top;

	initscr();

	start_color();
	init_pair(1, LOAD_PANEL_COLOR, COLOR_BLACK);
	init_pair(2, COLOR_BLACK, COLOR_BLACK);
	init_pair(3, LOAD_BOX_COLOR, LOAD_BOX_COLOR);
	init_pair(4, COLOR_BLACK, COLOR_BLACK);

	curs_set(FALSE);
	keypad(stdscr,TRUE);
	noecho();
	cbreak();

	init_window(win,2);
	init_panel (pan,win);
		
	int _x, _y;
	WINDOW *s_win[2];

	getmaxyx(win[1],_y,_x);

	int b_y = (_y - 2 * load_box_height)/2;
	int b_x = (_x - 2 * load_box_width)/2; 
	int e_y = b_y +  1 * load_box_height;
	int e_x = b_x +  1 * load_box_width;

	s_win[0] = derwin(win[1], load_box_height, load_box_width, b_y,b_x);
	s_win[1] = derwin(win[1], load_box_height, load_box_width, e_y, e_x );

	wbkgd(s_win[0],COLOR_PAIR(3));
	wbkgd(s_win[1],COLOR_PAIR(3));

	box(s_win[0],0,0);
	box(s_win[1],0,0);

	wrefresh(s_win[0]);
	wrefresh(s_win[1]);

	doupdate();

	int b_max = e_y;
	int e_startx = e_x;
	int e_min = b_y;
	int b_startx = b_x;

	int loop = 0;
	while(loop!=LOAD_COUNT){

	char string[]= LOAD_TAG;
	int s_len = strlen(string);
	wattron(win[1],A_BOLD);
	mvwprintw(win[1],_y-load_box_height-LOAD_TAG_POSITION,(_x -s_len)/2,"%s",string);
	wattroff(win[1],A_BOLD);
	wrefresh(win[1]);

	if(b_y < b_max){
	b_y++;
	wbkgd(s_win[0],COLOR_PAIR(4));
	wborder(s_win[0], ' ', ' ', ' ',' ',' ',' ',' ',' ');
	wrefresh(s_win[0]);
	delwin(s_win[0]);
	s_win[0] = derwin(win[1], load_box_height, load_box_width, b_y,b_x);
	wbkgd(s_win[0],COLOR_PAIR(3));
	box(s_win[0],0,0);
	wrefresh(s_win[0]);
	}

	else if(b_x< e_startx){
	b_x++;
	wbkgd(s_win[0],COLOR_PAIR(4));
	wborder(s_win[0], ' ', ' ', ' ',' ',' ',' ',' ',' ');
	wrefresh(s_win[0]);
	delwin(s_win[0]);
	s_win[0] = derwin(win[1], load_box_height, load_box_width, b_y,b_x);
	wbkgd(s_win[0],COLOR_PAIR(3));
	box(s_win[0],0,0);
	wrefresh(s_win[0]);
	}

	if (b_y == b_max && b_x == e_startx)
	{
	wbkgd(s_win[0],COLOR_PAIR(4));
	wborder(s_win[0], ' ', ' ', ' ',' ',' ',' ',' ',' ');
	wrefresh(s_win[0]);
	delwin(s_win[0]);
	b_y = (_y - 2 * load_box_height)/2;
	b_x = (_x - 2 * load_box_width)/2;
	s_win[0] = derwin(win[1], load_box_height, load_box_width, b_y,b_x);
	wbkgd(s_win[0],COLOR_PAIR(3));
	box(s_win[0],0,0);
	wrefresh(s_win[0]);
	}

	if(e_y > e_min){
	--e_y;
	wbkgd(s_win[1],COLOR_PAIR(4));
	wborder(s_win[1], ' ', ' ', ' ',' ',' ',' ',' ',' ');
	wrefresh(s_win[1]);
	delwin(s_win[1]);
	s_win[1] = derwin(win[1], load_box_height, load_box_width, e_y,e_x);
	wbkgd(s_win[1],COLOR_PAIR(3));
	box(s_win[1],0,0);
	wrefresh(s_win[1]);
	}

	else if(e_x> b_startx){
	e_x--;
	wbkgd(s_win[1],COLOR_PAIR(4));
	wborder(s_win[1], ' ', ' ', ' ',' ',' ',' ',' ',' ');
	wrefresh(s_win[1]);
	delwin(s_win[1]);
	s_win[1] = derwin(win[1], load_box_height, load_box_width, e_y,e_x);
	wbkgd(s_win[1],COLOR_PAIR(3));
	box(s_win[1],0,0);
	wrefresh(s_win[1]);
	}

	if (e_y == e_min && e_x == b_startx)
	{
	wbkgd(s_win[1],COLOR_PAIR(4));
	wborder(s_win[1], ' ', ' ', ' ',' ',' ',' ',' ',' ');
	wrefresh(s_win[1]);
	delwin(s_win[1]);
	e_y = b_y +  1 * load_box_height;
	e_x = b_x +  1 * load_box_width;
	s_win[1] = derwin(win[1], load_box_height, load_box_width, e_y,e_x);
	wbkgd(s_win[1],COLOR_PAIR(3));
	wbkgd(s_win[0],COLOR_PAIR(3));
	box(s_win[1],0,0);
	box(s_win[0],0,0);
	wrefresh(s_win[0]);
	wrefresh(s_win[1]);
	}
	usleep(LOAD_SPEED);
	++loop;
	}


	sleep(2);
	top = pan[1];
	top = (PANEL *)panel_userptr(top);
	top_panel(top);
	update_panels();
	int row,col;
	getmaxyx(win[0],row,col);

	/********************************
	    Defined in configuration file.
		Edit if number of line increases
	*************************************************************/

	char *str[16]; // The value 16 is the number of line. Must be changed if the number of line increases in configuration file.

/* rearrange lines in descending order if the the lines increase in configuration file*/
	str[0]= line15;
	str[1] = line14;
	str[2] = line13;
	str[3]= line12;
	str[4]= line11;
	str[5]= line10;
	str[6]= line9;
	str[7]= line8;
	str[8]= line7;
	str[9]= line6;
	str[10]= line5;
	str[11]= line4;
	str[12]= line3;
	str[13]= line2;
	str[14]= line1;
	str[15]= line0;
	
	int q = 0;
	while(q!=16){  // The value 16 is the number of line. Must be changed if the number of line increases in configuration file.
	
	/*****************
		 End of Configuration file 
	************************************************************/	

	int s_len = strlen(str[q]);
	wattron(win[0],COLOR_PAIR(1));
	mvwprintw(win[0],(row-2)-q,(col-s_len)/2,str[q]);
	wattron(win[0],COLOR_PAIR(1));
	wrefresh(win[0]);
	++q;
	}

	int ch;
	while((ch=getch())!=113){
	
	switch(ch){
		case 32:
		def_prog_mode();
		endwin();
		if(system(COMMAND)!=-1)
		break;
	}

	doupdate();
}
	
	endwin();
	return 0;
}				/* ----------  end of function main  ---------- */
