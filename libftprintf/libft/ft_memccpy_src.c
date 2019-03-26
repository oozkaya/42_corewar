/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy_src.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-verd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 16:36:03 by ade-verd          #+#    #+#             */
/*   Updated: 2017/12/07 16:46:27 by ade-verd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void		*ft_memccpy_src(void *dst, void *src, int c, size_t n)
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
			return (src + i + 1);
		}
		i++;
	}
	return (point);
}
