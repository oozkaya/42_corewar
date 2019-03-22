/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-verd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 16:40:43 by ade-verd          #+#    #+#             */
/*   Updated: 2017/11/21 17:16:08 by ade-verd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int				ft_memcmp(const void *s1, const void *s2, size_t n)
{
	int				i;
	unsigned char	*s1_str;
	unsigned char	*s2_str;

	i = 0;
	s1_str = (unsigned char*)s1;
	s2_str = (unsigned char*)s2;
	while (n--)
	{
		if (s1_str[i] != s2_str[i])
			return (s1_str[i] - s2_str[i]);
		i++;
	}
	return (0);
}
