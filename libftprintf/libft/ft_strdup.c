/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-verd <ade-verd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 17:55:26 by ade-verd          #+#    #+#             */
/*   Updated: 2018/02/15 17:22:58 by ade-verd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char			*ft_strdup(const char *s1)
{
	char	*dest;

	if (!s1)
		return (NULL);
	if ((dest = (char*)malloc(sizeof(char) * (ft_strlen(s1) + 1))) == NULL)
		return (NULL);
	dest = ft_strcpy(dest, s1);
	return (dest);
}
