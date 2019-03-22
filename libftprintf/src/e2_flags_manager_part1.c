/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   e2_flags_manager_part1.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-verd <ade-verd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/16 17:58:47 by ade-verd          #+#    #+#             */
/*   Updated: 2018/03/02 11:37:41 by ade-verd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** ft_manage_plus_signed
** The converted value is right ajusted according to width and str's length.
** Used with signed conversion.
*/

void	ft_manage_plus_signed(t_indic **ind, t_buff **buff, char **str)
{
	int		w;
	int		n;
	int		i;
	int		isminus_or_is0;

	n = ft_strchr("+-", *str[0]) ? ft_strlen(*str) - 1 : ft_strlen(*str);
	w = ((*ind)->precision < n) ? ((*ind)->width - (*buff)->sign_printed)
			: ((*ind)->width - (*buff)->sign_printed - ((*ind)->precision - n));
	n = ft_strlen(*str);
	i = 0;
	isminus_or_is0 = 0;
	if ((ft_strchr((*ind)->flags, '-')
			|| (ft_strchr((*ind)->flags, '0') && (*ind)->isprec == 0)))
		isminus_or_is0 = 1;
	if (ft_strchr((*ind)->flags, '+')
			&& (*ind)->nb >= 0 && (*buff)->sign_printed == 0)
		n++;
	while (i++ < (w - n) && isminus_or_is0 != 1)
		ft_putcbuffer(buff, ' ');
	if (ft_strchr((*ind)->flags, '+')
		&& (*ind)->nb >= 0 && (*buff)->sign_printed == 0)
	{
		ft_putcbuffer(buff, '+');
		(*buff)->sign_printed++;
	}
}

/*
** ft_manage_plus_unsigned
** The converted value is right ajusted according to width and str's length
** Used with unsigned conversion.
*/

void	ft_manage_plus_unsigned(t_indic **ind, t_buff **buff, char **str)
{
	int		w;
	int		n;
	int		i;
	int		isminus_or_is0;

	n = ft_strlen(*str);
	w = ((*ind)->precision < n) ? ((*ind)->width - (*buff)->sign_printed)
		: ((*ind)->width - (*buff)->sign_printed - ((*ind)->precision - n));
	i = 0;
	isminus_or_is0 = 0;
	if ((ft_strchr((*ind)->flags, '-')
		|| (ft_strchr((*ind)->flags, '0') && (*ind)->isprec == 0)))
		isminus_or_is0 = 1;
	while (i++ < (w - n) && isminus_or_is0 != 1)
		ft_putcbuffer(buff, ' ');
}

/*
** ft_manage_plus_string
** The converted value is right ajusted according to width and str's length
** Used with string and char conversion.
*/

void	ft_manage_plus_string(t_indic **ind, t_buff **buff, char **str)
{
	int		w;
	int		n;
	int		i;
	int		isminus_or_is0;

	n = ft_strlen(*str);
	if ((*ind)->type == 's')
		n = (*ind)->isprec && ((*ind)->precision < n) ? (*ind)->precision : n;
	w = (*ind)->width;
	i = 0;
	isminus_or_is0 = 0;
	if ((ft_strchr((*ind)->flags, '-')
		|| (ft_strchr((*ind)->flags, '0'))))
		isminus_or_is0 = 1;
	while (i++ < (w - n) && isminus_or_is0 != 1)
		ft_putcbuffer(buff, ' ');
}

/*
** ft_manager_minus
** The converted value is left ajusted according to width and str's length
*/

void	ft_manage_minus(t_indic **ind, t_buff **buff, char **str)
{
	int		w;
	int		n;
	int		i;

	if (!(*ind)->width || !ft_strchr((*ind)->flags, '-'))
		return ;
	w = (*ind)->width;
	n = ft_strlen(*str) + (*buff)->printed;
	i = 0;
	if ((*ind)->type == 'n')
	{
		while (i++ < (w - n))
			ft_putcbuffer(buff, ' ');
	}
	else
	{
		if (w > n)
		{
			if (!((*buff)->suffix = ft_strnew(w - n)))
				return ;
			while (i < (w - n))
				(*buff)->suffix[i++] = ' ';
		}
	}
}

/*
** ft_print_sign_before
** Print sign '+' '-' before '0' or string
** Flag ' ' (whitespace) is managed here
*/

void	ft_print_sign_before(t_indic **ind, t_buff **buff, char **str)
{
	int		nb_ref;

	nb_ref = (*buff)->index;
	if ((*ind)->type && ft_strchr("di", (*ind)->type))
	{
		if (ft_strchr((*ind)->flags, '0')
				&& (*ind)->isprec == 0)
		{
			if ((*ind)->nb <= 0 && *str[0] == '-')
				ft_putcbuffer(buff, '-');
			if ((*ind)->nb >= 0 && *str[0] == '+')
				ft_putcbuffer(buff, '+');
		}
		if (ft_strchr((*ind)->flags, ' ') && *str[0] != '+'
				&& !ft_strchr((*ind)->flags, '+') && *str[0] != '-')
		{
			ft_putcbuffer(buff, ' ');
			(*buff)->sign_printed++;
		}
	}
	if (nb_ref != (*buff)->index && ft_strchr_pos("+-", *str[0]) != -1)
	{
		ft_stroffset(*str, 1);
		(*buff)->sign_printed++;
	}
}
