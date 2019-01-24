/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onahiz <onahiz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 01:17:55 by onahiz            #+#    #+#             */
/*   Updated: 2018/10/30 13:42:56 by zoulhafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		cnt(int **board, int max, int i, int j)
{
	int		count;

	count = 0;
	if (board[i][j] == 0)
	{
		board[i][j] = 3;
		count++;
	}
	if (i < max - 1 && board[i + 1][j] == 0)
		count += cnt(board, max, i + 1, j);
	if (j >= 1 && board[i][j - 1] == 0)
		count += cnt(board, max, i, j - 1);
	if (j < max - 1 && board[i][j + 1] == 0)
		count += cnt(board, max, i, j + 1);
	if (i >= 1 && board[i - 1][j] == 0)
		count += cnt(board, max, i - 1, j);
	return (count);
}

int		fill_empty(int **b, int m)
{
	int i;
	int j;
	int count;
	int	tmp;

	count = 0;
	i = -1;
	while (++i < m)
	{
		j = -1;
		while (++j < m)
		{
			if (i >= 1 && !b[i - 1][j] && (tmp = cnt(b, m, i - 1, j)) >= 4)
				count += tmp;
			if (j >= 1 && !b[i][j - 1] && (tmp = cnt(b, m, i, j - 1)) >= 4)
				count += tmp;
			if (j < m - 1 && !b[i][j + 1] && (tmp = cnt(b, m, i, j + 1)) >= 4)
				count += tmp;
			if (i < m - 1 && !b[i + 1][j] && (tmp = cnt(b, m, i + 1, j)) >= 4)
				count += tmp;
		}
	}
	return (count);
}
