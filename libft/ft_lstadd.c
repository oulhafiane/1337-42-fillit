/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zoulhafi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/08 02:55:26 by zoulhafi          #+#    #+#             */
/*   Updated: 2018/10/09 05:24:48 by zoulhafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd(t_list **alst, t_list *new)
{
	if (alst == NULL || new == NULL)
		return ;
	if (alst[0] != NULL)
	{
		new->next = *alst;
		*alst = new;
	}
	else
	{
		new->next = NULL;
		*alst = new;
	}
}
