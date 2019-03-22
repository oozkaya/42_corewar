/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   d1_arg_char.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-verd <ade-verd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/08 17:52:58 by ade-verd          #+#    #+#             */
/*   Updated: 2018/02/26 13:37:16 by ade-verd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** ft_arg_char
** Char type: applies indicators and puts in buffer
*/

void	ft_arg_char(va_list ap, t_indic **ind, t_buff **buff)
{
	char	*str;
	int		iszero;
	int		i;

	i = 0;
	if (!(str = ft_strnew(4)))
	{
		ft_error_manager(buff);
		return ;
	}
	ft_bzero(str, 4);
	ft_capital_type(ind);
	if ((*ind)->type == '%')
		(*ind)->c = '%';
	else
		ft_get_string(ind, ap, &str);
	ft_unicode_to_str(ind, buff, &str, &i);
	iszero = (*ind)->c == 0 ? 1 : 0;
	if (iszero == 1)
		str[0] = '.';
	ft_indicators_manager(ind, buff, &str);
	iszero == 1 ? ft_putcbuffer(buff, 0) : ft_putsbuffer(buff, str);
	if ((*buff)->suffix)
		ft_putsbuffer(buff, (*buff)->suffix);
	ft_strdel(&str);
}
