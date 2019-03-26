/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strleft.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-verd <ade-verd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 16:11:41 by ade-verd          #+#    #+#             */
/*   Updated: 2018/11/05 19:19:18 by ade-verd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strleft(const char *str, const char *left)
{
	size_t l_str;
	size_t l_left;

	l_str = ft_strlen(str);
	l_left = ft_strlen(left);
	if (l_str >= l_left)
		return (ft_memcmp(left, str, l_left) == 0 ? 1 : 0);
	return (0);
}
