/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-verd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 13:15:25 by ade-verd          #+#    #+#             */
/*   Updated: 2017/11/28 14:41:12 by ade-verd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char			*ft_strnew(size_t size)
{
	char	*s;

	if ((s = (char*)ft_memalloc(sizeof(char) * (size + 1))) == NULL)
		return (NULL);
	s[size] = '\0';
	return (s);
}
