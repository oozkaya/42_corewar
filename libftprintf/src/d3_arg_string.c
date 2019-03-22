/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   d3_arg_string.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-verd <ade-verd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/13 14:12:59 by ade-verd          #+#    #+#             */
/*   Updated: 2018/02/26 14:13:29 by ade-verd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** ft_wslen_bytes
** Counts on how many bytes the character is encoded.
*/

int		ft_wslen_bytes(t_indic **ind)
{
	int		i;
	int		bytes;
	int		nb_bits;

	i = 0;
	bytes = 0;
	while ((*ind)->ws && (*ind)->ws[i])
	{
		nb_bits = ft_bitlen((*ind)->ws[i]);
		if (nb_bits <= 7)
			bytes += 1;
		else if (nb_bits <= 11)
			bytes += 2;
		else if (nb_bits <= 16)
			bytes += 3;
		else if (nb_bits <= 21)
			bytes += 4;
		else
			return (-1);
		if ((*ind)->precision && (*ind)->precision <= bytes)
			return (bytes);
		i++;
	}
	return (bytes);
}

/*
** ft_ws_to_char
** Converts wchar_t* to char* dynamically allocated with malloc(bytes + 1).
*/

void	ft_ws_to_char(t_indic **ind, t_buff **buff, char **str)
{
	int		i;
	int		index;
	int		bytes;

	i = 0;
	index = 0;
	if ((bytes = ft_wslen_bytes(ind)) == -1)
	{
		ft_error_manager(buff);
		*str = NULL;
		return ;
	}
	if (!(*str = ft_strnew(bytes)))
	{
		ft_error_manager(buff);
		return ;
	}
	ft_bzero(*str, bytes);
	while ((*ind)->ws[i] && bytes >= 0)
	{
		if ((*ind)->isprec == 1 && index >= (*ind)->precision)
			return ;
		(*ind)->c = (*ind)->ws[i++];
		ft_unicode_to_str(ind, buff, str, &index);
	}
}

/*
** ft_arg_string_ws
** wchar_t* type: converts, applies indicators and puts in buffer.
*/

void	ft_arg_string_ws(t_indic **ind, t_buff **buff, char **str)
{
	ft_ws_to_char(ind, buff, str);
	ft_indicators_manager(ind, buff, str);
	if (*str)
		ft_putsbuffer(buff, *str);
	if ((*buff)->suffix)
		ft_putsbuffer(buff, (*buff)->suffix);
}

/*
** ft_arg_string
** char* type: applies indicators and puts in buffer.
** wchar_t* type: calls ft_arg_string_ws.
*/

void	ft_arg_string(va_list ap, t_indic **ind, t_buff **buff)
{
	char	*str;

	ft_capital_type(ind);
	ft_get_string(ind, ap, &str);
	if (ft_strcmp((*ind)->size, "l") == 0)
		ft_arg_string_ws(ind, buff, &str);
	else
	{
		ft_indicators_manager(ind, buff, &str);
		if (str)
			ft_putsbuffer(buff, str);
		if ((*buff)->suffix)
			ft_putsbuffer(buff, (*buff)->suffix);
	}
	if (str)
		ft_strdel(&str);
}
