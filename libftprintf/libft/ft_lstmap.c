/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-verd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 18:31:09 by ade-verd          #+#    #+#             */
/*   Updated: 2017/11/27 11:59:27 by ade-verd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*f_lst;
	t_list	*f_next;

	if (lst == NULL || f == NULL)
		return (NULL);
	f_lst = NULL;
	f_next = NULL;
	while (lst)
	{
		if (f_lst == NULL)
		{
			f_lst = f(lst);
			f_next = f_lst;
		}
		else
		{
			f_next->next = f(lst);
			f_next = f_next->next;
		}
		lst = lst->next;
	}
	return (f_lst);
}
