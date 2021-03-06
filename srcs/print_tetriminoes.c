/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_tetriminoes.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onahiz <onahiz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 04:03:22 by zoulhafi          #+#    #+#             */
/*   Updated: 2019/01/24 18:59:32 by zoulhafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "colors.h"
#include <stdio.h>

void					print_result(int **board, int max)
{
	int i;
	int j;

	i = -1;
	while (++i < max)
	{
		j = -1;
		while (++j < max)
		{
			if (board[i][j] == 0)
				printf(YELLOW(" . "));
			else
			{
				if ((board[i][j] - 65) % 4 == 0)
					printf(GREEN(" %c "), board[i][j]);
				else if ((board[i][j] - 65) % 4 == 1)
					printf(RED(" %c "), board[i][j]);
				else if ((board[i][j] - 65) % 4 == 2)
					printf(BLUE(" %c "), board[i][j]);
				else if ((board[i][j] - 65) % 4 == 3)
					printf(MAGENTA(" %c "), board[i][j]);
				else if ((board[i][j] - 65) % 4 == 4)
					printf(CYAN(" %c "), board[i][j]);
				else
					printf(YELLOW(" %c "), board[i][j]);
			}
		}
		printf("\n");
	}
}

void					remove_block(int **board, int max, int alpha)
{
	int i;
	int j;

	i = -1;
	while (++i < max)
	{
		j = -1;
		while (++j < max)
		{
			if (board[i][j] == alpha + 'A')
				board[i][j] = 0;
		}
	}
}

static t_direction		get_max(t_direction moves[4])
{
	t_direction		max;
	int				i;

	i = 0;
	max.i = moves[0].i;
	max.j = moves[0].j;
	while (++i < 4)
	{
		if (max.i < moves[i].i)
			max.i = moves[i].i;
		if (max.j < moves[i].j)
			max.j = moves[i].j;
	}
	return (max);
}

int						is_valid(int **b, t_tlist *l, int i, int j)
{
	int				k;

	k = -1;
	while (++k < 4)
	{
		if (b[i + l->m[k].i][j + l->m[k].j])
			return (0);
	}
	return (1);
}

int						print_tetrimino(int **b, int max, t_tlist *l, int flag)
{
	int				i;
	int				j;
	int				k;
	t_direction		edge;

	init_counter(l, flag);
	i = l->ci - 1;
	edge = get_max(l->m);
	while (++i < max - edge.i)
	{
		j = l->cj - 1;
		while (++j < max - edge.j)
		{
			if (is_valid(b, l, i, j))
			{
				k = -1;
				while (++k < 4)
					b[i + l->m[k].i][j + l->m[k].j] = l->alpha + 'A';
				increment_counter(l, i, j, max - edge.j);
				return (1);
			}
		}
		l->cj = 0;
	}
	return (0);
}
