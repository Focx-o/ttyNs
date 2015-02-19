/*
 * =====================================================================================
 *
 *       Filename:  header.h
 *
 *    Description:  Header files included
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

#ifndef _HEADER_H_
#define _HEADER_H_

#include <ncurses.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>


typedef struct _tile {
	int x;
	int y;
}tile;

enum { LEFT, RIGHT, UP, DOWN };

#endif
