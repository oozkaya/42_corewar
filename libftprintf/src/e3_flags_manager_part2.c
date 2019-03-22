/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   e3_flags_manager_part2.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-verd <ade-verd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 11:01:17 by ade-verd          #+#    #+#             */
/*   Updated: 2018/02/26 14:41:12 by ade-verd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** ft_manage_zero
** The converted value is padded on the left with zeros.
** If the '0' and '-' flags both appear, the '0' flag is ignored.
** If a precision is given with a numeric conversion (d, i, o, u, x, and X),
** the 0 flag is ignored. For other conversions, the behavior is undefined.
*/

void	ft_manage_zero(t_indic **ind, t_buff **buff, char **str)
{
	int		width;
	int		n;
	int		i;

	if (!(*ind)->width || !ft_strchr((*ind)->flags, '0')
			|| ft_strchr((*ind)->flags, '-'))
		return ;
	if ((*ind)->isprec == 1 && ft_strchr("bpdiouxX", (*ind)->type))
		return ;
	width = (*ind)->width - (*buff)->sign_printed;
	n = ft_strlen(*str);
	if ((*ind)->type == 's')
		n = (*ind)->isprec && ((*ind)->precision < n) ? (*ind)->precision : n;
	i = 0;
	while (i < (width - n))
	{
		ft_putcbuffer(buff, '0');
		(*buff)->iszero++;
		(*buff)->sign_printed++;
		i++;
	}
}

/*
** ft_hashtag_oxX
** When type is o, x or X, and the value is not 0,
** the converted value is prefixed respectively by 0 (o), "0x" (x) or "0X" (X)
*/

void	ft_hashtag_oxx(t_indic **ind, t_buff **buff, char **str)
{
	int		base;

	base = (*ind)->type == 'o' ? 10 : 16;
	if (ft_uatoi_base(*str, base) == 0)
		return ;
	(*buff)->prefix[0] = '0';
	(*buff)->sign_printed++;
	if ((*ind)->type == 'o')
		(*buff)->iszero++;
	else
	{
		(*buff)->prefix[1] = (*ind)->type == 'X' ? 'X' : 'x';
		(*buff)->sign_printed++;
	}
}

/*
** ft_manage_hashtag
** Redirects to the right function considering the type.
*/

void	ft_manage_hashtag(t_indic **ind, t_buff **buff, char **str)
{
	int			i;
	const t_ft	tab_ft[] = {{"oxX", NULL, ft_hashtag_oxx, NULL, NULL},
		{0, 0, 0, 0, 0}
	};

	i = 0;
	if (ft_strchr((*ind)->flags, '#'))
	{
		while (tab_ft[i].letter)
		{
			if ((*ind)->type && ft_strchr(tab_ft[i].letter, (*ind)->type))
			{
				tab_ft[i].f2(ind, buff, str);
				break ;
			}
			i++;
		}
	}
}
