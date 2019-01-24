/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_tetriminoes1.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onahiz <onahiz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/23 22:11:25 by zoulhafi          #+#    #+#             */
/*   Updated: 2018/10/30 13:41:50 by zoulhafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		s1z1o1(int **block, int i)
{
	int j;

	j = -1;
	while (++j < 4)
	{
		if (block[i][j] == 1)
		{
			if (j < 3 && block[i][j + 1] == 2 &&
					i < 3 && block[i + 1][j] == 0)
				return (Z1);
			else if (j < 3 && block[i][j + 1] == 2 &&
					i < 3 && block[i + 1][j] == 2 &&
					block[i + 1][j + 1] == 1)
				return (O1);
			else if (j < 3 && block[i][j + 1] == 2 &&
					i < 3 && block[i + 1][j] == 2 &&
					block[i + 1][j + 1] == 0)
				return (S1);
		}
	}
	return (-1);
}

int		t2t4(int **block, int i)
{
	int j;

	j = -1;
	while (++j < 4)
	{
		if (block[i][j] == 1)
		{
			if (i < 3 && block[i + 1][j - 1] == 1)
				return (T2);
			if (j < 3 && i < 3 && block[i + 1][j + 1] == 1)
				return (T4);
		}
	}
	return (-1);
}

int		l2j4(int **block, int i)
{
	int j;

	j = -1;
	while (++j < 4)
	{
		if (block[i][j] == 1)
		{
			if (i < 3 && block[i + 1][j] == 0)
				return (J4);
			if (i < 3 && block[i + 1][j] == 2)
				return (L2);
		}
	}
	return (-1);
}
