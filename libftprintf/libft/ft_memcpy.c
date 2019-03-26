/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-verd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 18:32:49 by ade-verd          #+#    #+#             */
/*   Updated: 2017/11/21 15:48:02 by ade-verd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char	*dst_2;
	char	*src_2;

	dst_2 = dst;
	src_2 = (char*)src;
	while (n--)
		*dst_2++ = *src_2++;
	return (dst);
}
