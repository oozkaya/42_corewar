/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-verd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 10:34:11 by ade-verd          #+#    #+#             */
/*   Updated: 2017/11/26 22:30:52 by ade-verd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void			*ft_memmove(void *dst, const void *src, size_t n)
{
	char	*dst_2;
	char	*src_2;

	dst_2 = (char*)dst;
	src_2 = (char*)src;
	while (n--)
		if (src < dst)
			dst_2[n] = src_2[n];
		else
			*dst_2++ = *src_2++;
	return (dst);
}
