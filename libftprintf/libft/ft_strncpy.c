/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-verd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 12:26:05 by ade-verd          #+#    #+#             */
/*   Updated: 2017/11/15 13:27:57 by ade-verd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strncpy(char *dest, const char *src, size_t len)
{
	int		i;

	i = 0;
	while (i < (int)len && src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	while (i < (int)len)
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
}
