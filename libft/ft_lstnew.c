/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zoulhafi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/08 02:12:44 by zoulhafi          #+#    #+#             */
/*   Updated: 2018/10/09 05:23:21 by zoulhafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*lst;

	lst = (t_list*)malloc(sizeof(*lst));
	if (lst == NULL)
		return (NULL);
	if (content == NULL)
	{
		lst->content = NULL;
		lst->content_size = 0;
		lst->next = NULL;
		return (lst);
	}
	lst->content = malloc(sizeof(char) * content_size);
	ft_memcpy(lst->content, content, content_size);
	lst->content_size = content_size;
	lst->next = NULL;
	return (lst);
}
