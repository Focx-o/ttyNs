/*
 * =============================================================================
 *
 *       Filename:  load.c
 *
 *    Description:  Create tiles
 *
 *        Version:  1.0
 *        Created:  Wednesday 24 December 2014 06:04:44  IST
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Ankan Biswas (talk2ankan), support@ankanbiswas.in
 *        Company:  Bug17, West Bengal
 *
 * =============================================================================
 */

#include "header.h"
#include "config.h"

void init_win(WINDOW **win, int n)
{
	int starty, startx, x, y, k = 0, i;
	WINDOW *show;
	starty = (LINES - n * HEIGHT) / 2;
	startx = (COLS - n * WIDTH) / 2;
	x = startx;
	y = starty;

	refresh();

	show = newwin(n * (HEIGHT + 1) + 3, n * (WIDTH + 2) + 4, y - 2, x - 3);

	wattron(show, A_BOLD);
	wattron(show, COLOR_PAIR(2));

	box(show,0,0);

	wattroff(show, COLOR_PAIR(2));
	wattroff(show, A_BOLD);

	wnoutrefresh(show);

	for (i = 0; i < n * n; ++i) {
		win[i] = newwin(HEIGHT, WIDTH, y, x);
		wbkgd(win[i],COLOR_PAIR(1));	
		x += WIDTH + 2;			
		if (i == k + n - 1) {		
			k = k + n;
			y += HEIGHT + 1;
			x = startx;
		}
	}
}
