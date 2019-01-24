/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onahiz <onahiz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 23:03:24 by zoulhafi          #+#    #+#             */
/*   Updated: 2018/10/30 13:42:35 by zoulhafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static t_direction	new_d(int i, int j)
{
	t_direction d;

	d.i = i;
	d.j = j;
	return (d);
}

static t_direction	*get_d(t_direction d0, t_direction d1,
		t_direction d2, t_direction d3)
{
	t_direction	*tab;

	tab = (t_direction*)malloc(sizeof(t_direction) * 4);
	tab[0].i = d0.i;
	tab[0].j = d0.j;
	tab[1].i = d1.i;
	tab[1].j = d1.j;
	tab[2].i = d2.i;
	tab[2].j = d2.j;
	tab[3].i = d3.i;
	tab[3].j = d3.j;
	return (tab);
}

static t_direction	**get_moves(void)
{
	t_direction **moves;

	moves = (t_direction**)malloc(sizeof(t_direction) * 19);
	moves[0] = get_d(new_d(0, 0), new_d(1, 0), new_d(2, 0), new_d(3, 0));
	moves[1] = get_d(new_d(0, 0), new_d(0, 1), new_d(0, 2), new_d(0, 3));
	moves[2] = get_d(new_d(0, 1), new_d(1, 1), new_d(2, 1), new_d(2, 0));
	moves[3] = get_d(new_d(0, 0), new_d(1, 0), new_d(1, 1), new_d(1, 2));
	moves[4] = get_d(new_d(0, 0), new_d(1, 0), new_d(2, 0), new_d(0, 1));
	moves[5] = get_d(new_d(0, 0), new_d(0, 1), new_d(0, 2), new_d(1, 2));
	moves[6] = get_d(new_d(0, 0), new_d(1, 0), new_d(2, 0), new_d(2, 1));
	moves[7] = get_d(new_d(0, 0), new_d(0, 1), new_d(0, 2), new_d(1, 0));
	moves[8] = get_d(new_d(0, 0), new_d(0, 1), new_d(1, 1), new_d(2, 1));
	moves[9] = get_d(new_d(1, 0), new_d(1, 1), new_d(1, 2), new_d(0, 2));
	moves[10] = get_d(new_d(0, 0), new_d(0, 1), new_d(1, 0), new_d(1, 1));
	moves[11] = get_d(new_d(0, 0), new_d(0, 1), new_d(0, 2), new_d(1, 1));
	moves[12] = get_d(new_d(0, 1), new_d(1, 0), new_d(1, 1), new_d(2, 1));
	moves[13] = get_d(new_d(1, 0), new_d(1, 1), new_d(0, 1), new_d(1, 2));
	moves[14] = get_d(new_d(0, 0), new_d(1, 0), new_d(2, 0), new_d(1, 1));
	moves[15] = get_d(new_d(0, 1), new_d(0, 2), new_d(1, 0), new_d(1, 1));
	moves[16] = get_d(new_d(0, 0), new_d(1, 0), new_d(1, 1), new_d(2, 1));
	moves[17] = get_d(new_d(0, 0), new_d(0, 1), new_d(1, 1), new_d(1, 2));
	moves[18] = get_d(new_d(0, 1), new_d(1, 1), new_d(1, 0), new_d(2, 0));
	return (moves);
}

t_tlist				*create_tlist(int pcs[26])
{
	t_tlist		*lst;
	t_tlist		*tmp;
	t_direction **moves;
	int			i;

	moves = get_moves();
	i = -1;
	lst = (t_tlist*)malloc(sizeof(t_tlist));
	tmp = lst;
	while (pcs[++i] > -1)
	{
		tmp->t = pcs[i];
		tmp->m = moves[pcs[i]];
		tmp->alpha = i;
		if (pcs[i + 1] == -1)
			tmp = NULL;
		else
		{
			tmp->next = (t_tlist*)malloc(sizeof(t_tlist));
			tmp = tmp->next;
		}
	}
	return (lst);
}

void				delete_elem(t_tlist **lst, t_tlist *link)
{
	t_tlist		*tmp;
	t_tlist		*begin;

	begin = *lst;
	tmp = NULL;
	while (*lst)
	{
		if (*lst == link)
		{
			if (tmp)
				tmp->next = link->next;
			else
				begin = link->next;
			free(link);
			*lst = begin;
			return ;
		}
		else
			tmp = *lst;
		*lst = (*lst)->next;
	}
}
