/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-verd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 12:44:57 by ade-verd          #+#    #+#             */
/*   Updated: 2017/11/22 13:25:48 by ade-verd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memalloc(size_t size)
{
	void	*p;
	char	*s;

	if ((p = (void*)malloc(size)) == NULL)
		return (NULL);
	s = (char*)p;
	while (size--)
		*s++ = 0;
	return (p);
}
