/*
 * =====================================================================================
 *
 *       Filename:  load.c
 *
 *    Description:  To get random number in 2D dimention array
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

void init_board(int **s_board, int n, tile *blank){   
int k,i,j;  
int *temp;

temp = (int *)calloc(n * n, sizeof(int));  
	srand(time(NULL));
	
	for(i = 0;i < n * n; ++i)
	{    
repeat :
		k = rand() % (n * n);      
		for(j = 0;j <= i - 1; ++j)	
			if (k == temp[j])     
				goto repeat;
			else
				temp[i] = k;
	}
	k = 0;
	for (i = 0;i < n;++i)
		for(j = 0;j < n; ++j,++k)    
		{	if(temp[k] == 0)
			{	blank->x = i;
				blank->y = j;
			}
			s_board[i][j] = temp[k];
		}
	free(temp);
}