/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-verd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 18:27:41 by ade-verd          #+#    #+#             */
/*   Updated: 2017/11/28 14:42:55 by ade-verd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t			ft_strlcat(char *dst, const char *src, size_t size)
{
	int		i;
	int		j;
	int		len_src;
	int		len_dst;
	int		ret;

	i = 0;
	j = 0;
	len_src = ft_strlen(src);
	len_dst = ft_strlen(dst);
	ret = ((int)size < len_dst) ? (len_src + (int)size) : (len_dst + len_src);
	while (dst[i] != '\0')
		i++;
	while (src[j] != '\0' && (i + j) < (int)size - 1)
	{
		dst[i + j] = src[j];
		j++;
	}
	dst[i + j] = '\0';
	return (ret);
}
