/*
 * =====================================================================================
 *
 *       Filename:  load.h
 *
 *    Description:  Custom header file
 *
 *        Version:  1.0
 *        Created:  Wednesday 24 December 2014 05:04:16  IST
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Ankan Biswas (talk2ankan), support@ankanbiswas.in
 *        Company:  Bug17, West Bengal
 *
 * =====================================================================================
 */

#ifndef __LOAD_H__
#define __LOAD_H__

void init_win(WINDOW **win, int n);
void init_board(int **board, int n, tile *blank);
void bind(WINDOW **win,int **board,int n);
void move_blank(int direction,WINDOW **win, int **s_board, int n, tile *blank);
bool check_win(int **s_board, int n);

#endif
