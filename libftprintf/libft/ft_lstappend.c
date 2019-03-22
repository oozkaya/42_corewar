/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstappend.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-verd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 11:59:35 by ade-verd          #+#    #+#             */
/*   Updated: 2017/12/13 12:02:53 by ade-verd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_lstappend(t_list *new, t_list *first_link)
{
	t_list	*current;

	if (first_link && new)
	{
		current = first_link;
		while (current->next != NULL)
			current = current->next;
		current->next = new;
		new->next = NULL;
	}
}
