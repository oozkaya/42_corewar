/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strright.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-verd <ade-verd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 16:11:41 by ade-verd          #+#    #+#             */
/*   Updated: 2018/11/05 19:18:34 by ade-verd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strright(const char *str, const char *right)
{
	size_t l_str;
	size_t l_right;

	l_str = ft_strlen(str);
	l_right = ft_strlen(right);
	if (l_str >= l_right)
		return (ft_memcmp(right, str + (l_str - l_right), l_right) == 0);
	return (0);
}
