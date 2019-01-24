/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onahiz <onahiz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/23 01:43:10 by onahiz            #+#    #+#             */
/*   Updated: 2019/01/24 18:58:01 by zoulhafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

static int		check_empty(int **board, int max, t_tlist *lst)
{
	int i;
	int j;
	int cpt_b;
	int	cpt;

	cpt = fill_empty(board, max);
	i = -1;
	while (++i < max)
	{
		j = -1;
		while (++j < max)
		{
			if (board[i][j] == 3)
				board[i][j] = 0;
		}
	}
	lst = lst->next;
	cpt_b = 0;
	while (lst)
	{
		cpt_b++;
		lst = lst->next;
	}
	return (cpt_b * 4 <= cpt);
}

static int		get_min_board(int ***board, t_tlist *lst, int start)
{
	int		i;
	int		r;

	i = 0;
	while ((r = print_tetrimino(*board, start, lst, i++)))
	{
		system("clear");
		print_result(*board, start);
		usleep(20000);
		if (check_empty(*board, start, lst) == 0)
		{
			remove_block(*board, start, lst->alpha);
			continue;
		}
		if (lst->next && get_min_board(board, lst->next, start) == 0)
		{
			remove_block(*board, start, lst->alpha);
			continue ;
		}
		else
			return (1);
	}
	return (r);
}

static int		**create_board(int start)
{
	int			i;
	int			j;
	int			**board;

	board = (int**)malloc(sizeof(int*) * start);
	i = -1;
	while (++i < start)
	{
		j = -1;
		board[i] = (int*)malloc(sizeof(int) * start);
		while (++j < start)
			board[i][j] = 0;
	}
	return (board);
}

static void		print_block(int pcs[27])
{
	int			start;
	int			**board;
	int			i;

	i = -1;
	while (pcs[++i] > -1)
		;
	i = i * 4;
	while (!(start = (int)ft_sqrt(i++)))
		;
	board = create_board(start);
	while (!(get_min_board(&board, create_tlist(pcs), start)))
	{
		free(board);
		board = create_board(++start);
	}
	//print_result(board, start);
	free(board);
}

int				main(int ac, char **av)
{
	int pcs[27];
	int i;

	i = -1;
	while (++i < 27)
		pcs[i] = -1;
	if (ac == 2)
	{
		if (check_file(av[1]) && get_input(av[1], pcs) == 1)
			print_block(pcs);
		else
			ft_putendl("error");
	}
	else
		ft_putendl("usage : ./fillit source_file");
	return (0);
}
