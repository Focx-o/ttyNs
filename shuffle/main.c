/*
 * =====================================================================================
 *
 *       Filename:  main.c
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


int main ( int argc, char *argv[] )
{
	
	int n;  

 	if(argc != 2) {
     printf("Usage: %s <shuffle board order>\n", argv[0]); exit(1);
    }
    
    n = atoi(argv[1]);
     
     if(n < 3) {
    printf(" Cannot be a Charecter and less than 3 \n Usage: %s <shuffle board order>\n", argv[0]); exit(1);
    }

    int i, ch;
   	WINDOW *win[n*n]; 
   	int **s_board;  
   	tile blank;  

repeat:

/*-- shuffle numbers --*/
   	s_board = (int **)calloc(n, sizeof(int *));     
		for(i = 0;i < n; ++i) 						
		    s_board[i] = (int *)calloc(n, sizeof(int));

/*-- initialize shuffle board --*/	
	init_board(s_board,n,&blank);    
	
   	initscr();	
   	curs_set(FALSE);
    noecho();
    keypad(stdscr, TRUE);
    nodelay(stdscr, TRUE);
    cbreak();

/*-- initialize windows or tiles --*/
    init_win(win, n);

/*-- bind tiles and shuffle board --*/     
    bind(win,s_board,n); 

    doupdate();

    while((ch=getch())!=KEY_F(1)){

	/*-- move blank tile --*/
    	switch(ch)
		{	case KEY_LEFT:
				move_blank(RIGHT, win,s_board, n, &blank);
				break;
			case KEY_RIGHT:
				move_blank(LEFT,win, s_board, n, &blank);
				break;
			case KEY_UP:
				move_blank(DOWN,win, s_board, n, &blank);
				break;
			case KEY_DOWN:
				move_blank(UP,win, s_board, n, &blank);
				break;

		/*-- shuffle board --*/
			case 32:
			goto repeat;
			break;
		}

	/*-- Check Victory --*/				
		if(check_win(s_board, n) == TRUE)
		{	
			wbkgd(stdscr,COLOR_PAIR(0));
			attron(COLOR_PAIR(1));
			attron(A_BOLD);
			mvprintw(LINES/2,(COLS-4)/2 , "  You Win !!!\n  ");
			mvprintw(LINES/2 +1,(COLS-8)/2 , "  'SPACEBAR' to shuffle  \n");
			mvprintw(LINES/2+2,(COLS-4)/2, "  'F1' to exit !!!  \n");
			attroff(A_BOLD);
			attroff(COLOR_PAIR(1));
			refresh();

			while(1){
				if((ch=getch())==KEY_F(1)){
					endwin();
					return 0;
				}
				
			/*-- shuffle board --*/
				if((ch=getch())==32){
					wbkgd(stdscr,COLOR_PAIR(2));
					goto repeat;
				}
			}
		}
    mvprintw(LINES-2,(COLS-43)/2,"< 'spacebar' to shuffle > < 'F1' to quit >");
    }
    endwin();
	return 0;
}	

			/* ----------  end of function main  ---------- */

