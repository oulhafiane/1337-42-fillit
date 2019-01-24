/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_lines.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onahiz <onahiz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/22 05:40:10 by zoulhafi          #+#    #+#             */
/*   Updated: 2018/10/30 21:30:38 by onahiz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	check_line1(int count[4], int i, int tetriminoes[19])
{
	int		j;

	j = -1;
	while (++j < 19)
	{
		if (count[i] == 1 && (j == I1 || j == J2 || j == L4 ||
					j == T3 || j == T4 || j == T2 || j == L1 ||
					j == J1 || j == Z2 || j == S2))
			tetriminoes[j] = 1;
		else if (count[i] == 3 && (j == L3 || j == J3 ||
					j == Z1 || j == S1 || j == O1))
			tetriminoes[j] = 1;
		else if (count[i] == 4 && (j == L2 || j == J4 || j == T1))
			tetriminoes[j] = 1;
		else if (count[i] == 6 && j == I2)
			tetriminoes[j] = 1;
	}
}

void	check_line2(int count[4], int i, int tetriminoes[19])
{
	int		j;

	j = -1;
	while (++j < 19)
	{
		if (tetriminoes[j] != 1)
			continue;
		if (count[i] == 2 && j != L1 && j != J1 && j != J3 &&
				j != I1 && j != L2 && j != J4)
			tetriminoes[j] = 0;
		else if (count[i] == 3 && j != T4 && j != T2 && j != Z1
				&& j != Z2 && j != S1 && j != S2 && j != O1)
			tetriminoes[j] = 0;
		else if (count[i] == 5 && j != J2 && j != L4)
			tetriminoes[j] = 0;
		else if (count[i] == 1 && j != T1 && j != L3)
			tetriminoes[j] = 0;
		else if (count[i] == 4 && j != T3)
			tetriminoes[j] = 0;
	}
}

void	check_line3(int count[4], int i, int tetriminoes[19])
{
	int		j;

	j = -1;
	while (++j < 19)
	{
		if (tetriminoes[j] != 1)
			continue;
		if (count[i] == 1 && j != I1 && j != T4 && j != T2 && j != J3)
			tetriminoes[j] = 0;
		else if (count[i] == 3 && j != L1 && j != J1)
			tetriminoes[j] = 0;
		else if (count[i] == 2 && j != Z2 && j != S2 && j != L3)
			tetriminoes[j] = 0;
	}
}

int		check_file(char *path)
{
	int		fd;
	char	c;

	fd = open(path, O_RDONLY);
	while (read(fd, &c, 1))
		;
	return (c == '\n');
}
