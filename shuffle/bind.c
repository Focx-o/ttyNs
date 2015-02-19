/*
 * =====================================================================================
 *
 *       Filename:  header.h
 *
 *    Description:  bind tiles with shuffle numbers (files : tiles.c , shuffle_numbers.c)
 *
 *        Version:  1.0
 *        Created:  Wednesday 24 December 2014 01:47:09  IST
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

void bind(WINDOW **win,int **s_board,int n){

int i,k,j;
int count = 0;
int *temp;
temp = (int *)calloc(n * n , sizeof(int));

start_color();
	/*-- Initialize all the colors --*/
	init_pair(1, COLOR_WHITE, COLOR_RED);
	init_pair(2, COLOR_RED, COLOR_BLACK);

for (k = 0; k < n; ++k)
			for (j = 0; j < n; ++j,++count)
				temp[count] = s_board[k][j];   	

for (i = 0; i < n*n; ++i){

			if(temp[i]==BLANK){          
			wclear(win[i]);				
			mvwprintw(win[i],2,2," ");	
			wbkgd(win[i],COLOR_PAIR(2));
			wnoutrefresh(win[i]);
			}
			else{
			wclear(win[i]);
			wbkgd(win[i],COLOR_PAIR(1));
			wattron(win[i],A_BOLD);	
			mvwprintw(win[i],2,2,"%d",temp[i]);   
			wattroff(win[i],A_BOLD);	
			wnoutrefresh(win[i]);
				}	
	}
}