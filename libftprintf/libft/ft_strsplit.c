/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-verd <ade-verd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 09:13:43 by ade-verd          #+#    #+#             */
/*   Updated: 2019/03/04 19:08:01 by ade-verd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static	int		ft_count_words(const char *str, char c)
{
	int		i;
	int		word;

	i = 0;
	word = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == c && str[i + 1] != c)
			word++;
		i++;
	}
	if (str[0] != '\0')
		word++;
	return (word);
}

static	char	*ft_extract_word(const char *str, char c, int *i)
{
	char	*word;
	int		j;

	if (!(word = (char*)malloc(sizeof(char) * (ft_strlen(str) + 1))))
		return (NULL);
	j = 0;
	while (str[*i] != c && str[*i])
	{
		word[j] = str[*i];
		j++;
		*i += 1;
	}
	word[j] = '\0';
	while (str[*i] == c && str[*i])
		*i += 1;
	return (word);
}

char			**ft_strsplit(const char *str, char c)
{
	int		i;
	int		i_tab;
	int		word;
	char	**tab;

	i = 0;
	i_tab = 0;
	word = ft_count_words(str, c);
	if (!(tab = (char**)malloc(sizeof(char*) * (word + 2))))
		return (NULL);
	while (str[i] == c && str[i])
		i++;
	while (i_tab < word && str[i])
	{
		tab[i_tab] = ft_extract_word(str, c, &i);
		i_tab++;
	}
	tab[i_tab] = NULL;
	return (tab);
}

void			ft_freetab_strsplit(char **tab)
{
	int		i;

	i = 0;
	while (tab && tab[i])
	{
		ft_memdel((void**)&tab[i]);
		i++;
	}
	if (tab)
	{
		free(tab);
		tab = NULL;
	}
}
