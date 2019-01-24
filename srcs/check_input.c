/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onahiz <onahiz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/21 23:14:07 by onahiz            #+#    #+#             */
/*   Updated: 2018/10/30 21:54:36 by onahiz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int		check_line(char *line)
{
	int		len;

	len = 0;
	while (line[len])
	{
		if (line[len] != '.' && line[len] != '#')
			return (0);
		len++;
	}
	return (len == 4);
}

static int		*convert_line(char *line, int *j)
{
	int		i;
	int		*result;

	i = 0;
	result = (int *)malloc(sizeof(int) * 4);
	while (line[i])
	{
		if (line[i] == '#')
			result[i] = 1 + (*j % 2);
		else
			result[i] = 0;
		i++;
		(*j)++;
	}
	return (result);
}

static int		check_bad_block(int **b)
{
	int		i;
	int		j;
	int		count_true;
	int		count_contact;

	count_true = 0;
	count_contact = 0;
	i = -1;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
		{
			if (b[i][j] != 0)
			{
				count_true++;
				if (j < 3 && b[i][j + 1])
					count_contact++;
				if (i < 3 && b[i + 1][j])
					count_contact++;
			}
		}
	}
	return (count_true == 4 && (count_contact == 3 || count_contact == 4));
}

static int		check_input(char *line, int pcs[27], int **block, int cpt)
{
	static int	i = -1;
	static int	j = 0;
	static int	k = 0;

	if (check_line(line) && (cpt % 5) != 0)
	{
		block[++i] = convert_line(line, &j);
		j++;
	}
	else if (*line == '\0' && (cpt % 5) == 0)
	{
		i = -1;
		j = 0;
		block = fix_block(block);
		if (!check_bad_block(block) || (pcs[k++] = check_block(block)) == -1)
			return (0);
		free_block(block);
	}
	else
		return (0);
	return (1);
}

int				get_input(char *input, int pcs[27])
{
	int		cpt;
	int		fd;
	char	*line;
	int		**block;
	int		cpt_block;

	cpt_block = 0;
	cpt = 0;
	line = NULL;
	fd = open(input, O_RDONLY);
	block = (int **)malloc(sizeof(int *) * 4);
	while (get_next_line(fd, &line) > 0)
	{
		if (*line == '\0' && ((cpt + 1) % 5) == 0)
			cpt_block++;
		if (check_input(line, pcs, block, ++cpt) == 0)
			return (0);
	}
	if (*line == '\0' && ((cpt + 1) % 5) == 0)
		cpt_block++;
	if (*line == '\0' && check_input(line, pcs, block, ++cpt) == 0)
		return (0);
	return (cpt_block > 0 && cpt_block <= 26);
}
