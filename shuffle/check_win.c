/*
 * =====================================================================================
 *
 *       Filename:  check_win.c
 *
 *    Description:  To check victory
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
#include    "load.h"

 bool check_win(int **s_board, int n){

int i, j, c=0;

	for(i = 0;i < n; ++i)
		for(j = 0;j < n; ++j)
			if(s_board[i][j] == c+1)
			{	
				c+=1;
				mvprintw(0, 0,"");
					if(c==n*n -1){
						if (s_board[n-1][n-1]==BLANK)
						{
							return TRUE;
						}
				}
			}

	return FALSE;
}