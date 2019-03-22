/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-verd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 18:57:47 by ade-verd          #+#    #+#             */
/*   Updated: 2017/11/21 15:51:41 by ade-verd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	int				i;
	unsigned char	*dst_2;
	unsigned char	*src_2;
	char			*point;

	i = 0;
	dst_2 = (unsigned char*)dst;
	src_2 = (unsigned char*)src;
	point = NULL;
	while (n--)
	{
		dst_2[i] = src_2[i];
		if (src_2[i] == (unsigned char)c)
		{
			dst_2[i] = (unsigned char)c;
			return (dst + i + 1);
		}
		i++;
	}
	return (point);
}
