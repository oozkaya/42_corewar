/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnjoinfree.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-verd <ade-verd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/25 13:26:54 by ade-verd          #+#    #+#             */
/*   Updated: 2018/05/25 14:31:22 by ade-verd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnjoinfree(char const *s1, char const *s2, size_t len, int pick)
{
	char	*join;

	if (pick < 0 || pick > 2)
		return (NULL);
	join = ft_strnjoin(s1, s2, len);
	if (pick == 0 || pick == 2)
		ft_memdel((void **)&s1);
	if (pick == 1 || pick == 2)
		ft_memdel((void **)&s2);
	return (join);
}
