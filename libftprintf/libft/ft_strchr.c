/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-verd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 16:11:41 by ade-verd          #+#    #+#             */
/*   Updated: 2017/11/20 11:24:15 by ade-verd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*point;

	i = 0;
	point = NULL;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			return (point = (char*)&s[i]);
		i++;
	}
	if (s[i] == c)
		return (point = (char*)&s[i]);
	return (point);
}
