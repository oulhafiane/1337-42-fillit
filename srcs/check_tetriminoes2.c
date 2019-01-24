/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_tetriminoes2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onahiz <onahiz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 00:27:57 by onahiz            #+#    #+#             */
/*   Updated: 2018/10/30 13:42:02 by zoulhafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		l1j1(int **block, int i)
{
	int j;

	j = -1;
	while (++j < 4)
	{
		if (block[i + 2][j] == 1)
			return (L1);
		if (block[i + 2][j] == 2)
			return (J1);
	}
	return (-1);
}

int		s2z2(int **block, int i)
{
	int j;

	j = -1;
	while (++j < 4)
	{
		if (block[i + 1][j] == 1)
			return (Z2);
		if (block[i + 1][j] == 2)
			return (S2);
	}
	return (-1);
}

int		j2l4(int **block, int i)
{
	int j;

	j = -1;
	while (++j < 4)
	{
		if (block[i + 1][j] == 2 && block[i][j])
			return (J2);
		if (block[i + 1][j] == 2 && block[i][j] == 0)
			return (L4);
	}
	return (-1);
}
