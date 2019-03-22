/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c4_unicode_converter.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-verd <ade-verd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 13:21:21 by ade-verd          #+#    #+#             */
/*   Updated: 2018/03/02 13:56:54 by ade-verd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** ft_convert_unicode
** Convert a wchar_t to a char array of 1 to 4 bytes using binaries operations.
*/

void	ft_convert_unicode(t_indic **ind, char **byte, int *i)
{
	int		nb_bits;

	nb_bits = ft_bitlen((*ind)->c);
	if (nb_bits <= 7)
		(*byte)[(*i)++] = (*ind)->c;
	else if (nb_bits <= 11)
	{
		(*byte)[(*i)++] = MASK_BYTE01 | ((*ind)->c >> 6 & RMASK_BYTE01);
		(*byte)[(*i)++] = MASK_BYTE10 | ((*ind)->c & RMASK_BYTE10);
	}
	else if (nb_bits <= 16)
	{
		(*byte)[(*i)++] = MASK_BYTE02 | ((*ind)->c >> 12 & RMASK_BYTE02);
		(*byte)[(*i)++] = MASK_BYTE10 | ((*ind)->c >> 6 & RMASK_BYTE10);
		(*byte)[(*i)++] = MASK_BYTE10 | ((*ind)->c & RMASK_BYTE10);
	}
	else
	{
		(*byte)[(*i)++] = MASK_BYTE03 | ((*ind)->c >> 18 & RMASK_BYTE03);
		(*byte)[(*i)++] = MASK_BYTE10 | ((*ind)->c >> 12 & RMASK_BYTE10);
		(*byte)[(*i)++] = MASK_BYTE10 | ((*ind)->c >> 6 & RMASK_BYTE10);
		(*byte)[(*i)++] = MASK_BYTE10 | ((*ind)->c & RMASK_BYTE10);
	}
}

/*
** ft_checkprecis_and_erase
** If precision cuts the wchar_t, no byte is printed.
*/

void	ft_checkprecis_and_erase(t_indic **ind, char **str, int *i, int i_ref)
{
	if ((*ind)->type == 's' && (*ind)->isprec == 1 && *i > (*ind)->precision)
	{
		while ((*str)[i_ref])
		{
			(*str)[i_ref] = '\0';
			i_ref++;
		}
	}
}

/*
** ft_weard_behavior_on_mac
** On mac implementation, trying to print a char between 0xD800 & 0xDFFF
** generates an error (return -1 and nothing is printed).
*/

void	ft_weard_behavior_on_mac(t_indic **ind, t_buff **buff, char **str)
{
	if ((*ind)->c > 0x10FFFF || ((*ind)->c >= 0xD800 && (*ind)->c <= 0xDFFF))
	{
		ft_error_manager(buff);
		*str[0] = '\0';
	}
}

/*
** ft_unicode_to_str
** Converts wchar_t to char* and appends char **str
*/

void	ft_unicode_to_str(t_indic **ind, t_buff **buff, char **str, int *i)
{
	int		i_ref;

	i_ref = *i;
	if (ft_strcmp((*ind)->size, "l") == 0)
	{
		ft_weard_behavior_on_mac(ind, buff, str);
		ft_convert_unicode(ind, str, i);
		ft_checkprecis_and_erase(ind, str, i, i_ref);
	}
	else
		(*str)[(*i)++] = (*ind)->c;
}
