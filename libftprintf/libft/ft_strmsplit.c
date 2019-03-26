/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmsplit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-verd <ade-verd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 09:13:43 by ade-verd          #+#    #+#             */
/*   Updated: 2019/03/04 19:11:53 by ade-verd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static	int		ft_count_words(const char *str, char *chars)
{
	int		i;
	int		wds;

	i = 0;
	wds = 0;
	while (str && str[i])
	{
		while (str[i] && ft_strchr(chars, str[i]))
			i++;
		if (str[i])
			wds++;
		while (str[i] && !ft_strchr(chars, str[i]))
			i++;
	}
	return (wds);
}

static	char	*ft_extract_word(const char *str, char *chars, int *i)
{
	char	*word;
	int		j;

	if (!(word = (char*)malloc(sizeof(char) * (ft_strlen(str) + 1))))
		return (NULL);
	j = 0;
	while (str[*i] && !ft_strchr(chars, str[*i]))
	{
		word[j] = str[*i];
		j++;
		*i += 1;
	}
	word[j] = '\0';
	while (str[*i] && ft_strchr(chars, str[*i]))
		*i += 1;
	return (word);
}

char			**ft_strmsplit(const char *str, char *chars)
{
	int		i;
	int		i_tab;
	int		word;
	char	**tab;

	i = 0;
	i_tab = 0;
	word = ft_count_words(str, chars);
	if (!(tab = (char**)malloc(sizeof(char*) * (word + 2))))
		return (NULL);
	while (str[i] && ft_strchr(chars, str[i]))
		i++;
	while (i_tab < word && str[i])
	{
		tab[i_tab] = ft_extract_word(str, chars, &i);
		i_tab++;
	}
	tab[i_tab] = NULL;
	return (tab);
}
