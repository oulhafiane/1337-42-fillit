/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onahiz <onahiz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/23 01:26:32 by onahiz            #+#    #+#             */
/*   Updated: 2018/10/30 13:42:44 by zoulhafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		free_block(int **block)
{
	int		i;

	i = -1;
	while (++i < 4)
		ft_memdel((void **)&block[i]);
}

static int	block_is_reverse(int **block)
{
	int		i;
	int		j;

	i = -1;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
		{
			if (block[i][j] != 0)
			{
				if (block[i][j] == 2)
					return (1);
				if (block[i][j] == 1)
					return (0);
			}
		}
	}
	return (-1);
}

int			**fix_block(int **block)
{
	int		i;
	int		j;

	i = -1;
	j = -1;
	if (block_is_reverse(block))
	{
		while (++i < 4)
		{
			j = -1;
			while (++j < 4)
			{
				if (block[i][j])
				{
					if (block[i][j] == 2)
						block[i][j] = 1;
					else
						block[i][j] = 2;
				}
			}
		}
	}
	return (block);
}

void		init_counter(t_tlist *lst, int flag)
{
	if (!flag)
	{
		lst->ci = 0;
		lst->cj = 0;
	}
}

void		increment_counter(t_tlist *lst, int i, int j, int max)
{
	lst->cj = j + 1;
	lst->ci = i;
	if (lst->cj >= max)
	{
		lst->cj = 0;
		lst->ci = i + 1;
	}
}
