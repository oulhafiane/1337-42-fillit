/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_block.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onahiz <onahiz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/23 04:09:17 by zoulhafi          #+#    #+#             */
/*   Updated: 2018/10/30 13:41:34 by zoulhafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	count_line(int *line)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (i < 4)
	{
		count += line[i];
		i++;
	}
	return (count);
}

static int	check_line(int count[4], int i, int tetriminoes[19])
{
	int		j;
	int		total;

	total = 0;
	j = i - 1;
	while (++j < 4)
		total += count[j];
	if (total != 6 && total != 5)
		return (0);
	if (count[i] == 6)
	{
		tetriminoes[I2] = 1;
		return (1);
	}
	check_line1(count, i, tetriminoes);
	i++;
	if (i < 4)
		check_line2(count, i, tetriminoes);
	i++;
	if (i < 4)
		check_line3(count, i, tetriminoes);
	return (1);
}

static int	get_block_solo(int t[19])
{
	int		i;
	int		res;
	int		count;

	i = -1;
	count = 0;
	while (++i < 19)
	{
		count += t[i];
		if (t[i] != 0)
			res = i;
	}
	if (count == 1)
		return (res);
	return (-1);
}

static int	get_block(int t[19], int **block, int index)
{
	int		i;
	int		res;

	i = -1;
	if ((res = get_block_solo(t)) != -1)
		return (res);
	while (++i < 19)
	{
		if (t[S1] || t[Z1] || t[O1])
			return (s1z1o1(block, index));
		if (t[T2] || t[T4])
			return (t2t4(block, index));
		if (t[L2] || t[J4])
			return (l2j4(block, index));
		if (t[L1] || t[J1])
			return (l1j1(block, index));
		if (t[S2] || t[Z2])
			return (s2z2(block, index));
		if (t[J2] || t[L4])
			return (j2l4(block, index));
	}
	return (-1);
}

int			check_block(int **block)
{
	int		i;
	int		count[4];
	int		tetriminoes[19];

	i = -1;
	while (++i < 19)
		tetriminoes[i] = 0;
	i = -1;
	while (++i < 4)
		count[i] = count_line(block[i]);
	i = -1;
	while (count[++i] == 0)
		;
	if (!check_line(count, i, tetriminoes))
		return (-1);
	return (get_block(tetriminoes, block, i));
}
