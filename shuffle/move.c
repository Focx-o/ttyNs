/*
 * =====================================================================================
 *
 *       Filename:  load.c
 *
 *    Description:  Move blank space
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

void move_blank(int direction,WINDOW **win, int **s_board, int n, tile *blank){

		tile oldblank = *blank;

	switch(direction)
	{	case UP:
		{	if(blank->x != BLANK)
			{	--blank->x;
				s_board[oldblank.x][oldblank.y] = s_board[blank->x][blank->y];
				s_board[blank->x][blank->y] = BLANK;
				bind(win,s_board,n);
			}
		}
		break;
		case DOWN:
		{	if(blank->x != n - 1)
			{	++blank->x;
				s_board[oldblank.x][oldblank.y] = s_board[blank->x][blank->y];
				s_board[blank->x][blank->y] = BLANK;
				bind(win,s_board,n);
			}
		}
		break;
		case LEFT:
		{	if(blank->y != BLANK)
			{	--blank->y;
				s_board[oldblank.x][oldblank.y] = s_board[blank->x][blank->y];
				s_board[blank->x][blank->y] = BLANK;
				bind(win,s_board,n);
			}
		}
		break;
		case RIGHT:
		{	if(blank->y != n - 1)
			{	++blank->y;
				s_board[oldblank.x][oldblank.y] = s_board[blank->x][blank->y];
				s_board[blank->x][blank->y] = BLANK;
				bind(win,s_board,n);
			}
		}
		break;			
	}
}