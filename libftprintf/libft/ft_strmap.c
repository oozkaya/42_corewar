/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-verd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 15:28:33 by ade-verd          #+#    #+#             */
/*   Updated: 2017/11/28 14:42:35 by ade-verd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char			*ft_strmap(char const *s, char (*f)(char))
{
	char	*new_s;
	int		i;

	if (s == NULL || f == NULL)
		return (NULL);
	if ((new_s = (char*)malloc(sizeof(char) * (ft_strlen(s) + 1))) == NULL)
		return (NULL);
	i = 0;
	while (s[i] != '\0')
	{
		new_s[i] = f(s[i]);
		i++;
	}
	new_s[i] = '\0';
	return (new_s);
}
