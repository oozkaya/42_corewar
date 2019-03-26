/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-verd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 12:16:31 by ade-verd          #+#    #+#             */
/*   Updated: 2017/11/28 13:40:31 by ade-verd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	int		i;
	int		j;
	int		start;
	char	*point;

	i = 0;
	point = NULL;
	if (ft_strlen(needle) == 0)
		return ((char*)haystack);
	while (haystack[i] != '\0')
	{
		j = 0;
		start = i;
		while (haystack[i + j] == needle[j])
		{
			if (needle[j + 1] == '\0')
				return (point = (char*)&haystack[start]);
			j++;
		}
		i++;
	}
	return (point);
}
