/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stroffset.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-verd <ade-verd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/22 12:43:04 by ade-verd          #+#    #+#             */
/*   Updated: 2018/02/27 15:07:17 by ade-verd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_stroffset(char *str, unsigned int offset)
{
	int		i;

	i = 0;
	if (!str || (offset > ft_strlen(str)))
		return (NULL);
	while (str[i] && str[i + offset])
	{
		str[i] = str[i + offset];
		i++;
	}
	str[i] = '\0';
	return (str);
}
