/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-verd <ade-verd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 17:46:00 by ade-verd          #+#    #+#             */
/*   Updated: 2019/03/04 15:39:37 by ade-verd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char			*ft_strtrim(char const *s)
{
	char	*trim;
	int		i;
	int		a;
	int		z;
	int		diff;

	i = 0;
	a = 0;
	if (!s || !*s)
		return (NULL);
	while (s[a] && (s[a] == ' ' || s[a] == '\t' || s[a] == '\n'))
		a++;
	z = ft_strlen(s) - 1;
	while (z >= 0 && s[z] && (s[z] == ' ' || s[z] == '\t' || s[z] == '\n'))
		z--;
	diff = (z < a ? 1 : z - a + 1);
	if ((trim = (char*)malloc(sizeof(char) * (diff + 1))) == NULL)
		return (NULL);
	while (a <= z)
	{
		trim[i++] = s[a];
		a++;
	}
	trim[i] = '\0';
	return (trim);
}
